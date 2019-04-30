#!/usr/bin/env python3
"""
author Jeff Charter Chapman

See DLL-User-Guide.pdf from Elprotronic's website

See main for example usage
"""
import os
from msl.loadlib import Client64
from PyElprotronic430Server import CFG, R, FileTypes

import configparser
import re
import bisect
from itertools import zip_longest
import logging
log = logging.getLogger(__name__)


def elprotronic_sequential(func):
    """
    Wrapper around custom routines that require sequential calls
    """
    def wrapper(*args, **kwargs):
        elpro = ElprotronicClient()
        if not hasattr(elpro, '_seq'): # this allows nested routines to also be sequential
            print("Power On?: %s." % (R[elpro.F_Power_Target(True)]))
            print("Open Target?: %s" % elpro.F_Open_Target_Device())
            setattr(ElprotronicClient(), '_seq', [])
        elpro._seq.append(True)

        func(*args, **kwargs)

        elpro._seq.pop()
        if len(elpro._seq) == 0:
            print("Power Off?: %s." % (R[elpro.F_Power_Target(False)]))
            print("Close target?: %s" % elpro.F_Close_Target_Device())
            delattr(elpro, '_seq')
    return wrapper


def dump_struct(s):
    for field_name, field_type in s._fields_:
        print(field_name, '\t', getattr(s, field_name), hex(getattr(s, field_name)) )


class Singleton(type):
    _instances = {}
    def __call__(cls, *args, **kwargs):
        if cls not in cls._instances:
            cls._instances[cls] = super(Singleton, cls).__call__(*args, **kwargs)
        return cls._instances[cls]



class PyElprotronic430(Client64, metaclass=Singleton):
    def __init__(self):
        super(PyElprotronic430, self).__init__(module32='PyElprotronic430Server.py')

    def __getattr__(self, method32):
        if method32.startswith('_'):
            return super().__getattr__(method32)
        else:
            def send(*args, **kwargs):
                return self.request32(method32, *args, **kwargs)
            return send


    def auto_write(self, address, data):
        """
        Runs through all steps needed to write to Flash

        1. Capture existing data in segment
        2. Erase segment
        3. Write segment combining segment data with data passed to auto_write
        """

        info = self.getAllDeviceInfo()
        log.debug(info)

        segment_size = self.F_Get_Sector_Size(address)

        info_end_address = info['DEVICE_INFO_START_ADDR'] + \
            (info['DEVICE_INFO_SEGM_SIZE'] * info['DEVICE_NO_INFO_SEGMENTS'])

        if( info['DEVICE_MAIN_FLASH_START_ADDR'] <= address <= info['DEVICE_MAIN_FLASH_END_ADDR'] and
           info['DEVICE_MAIN_FLASH_START_ADDR'] <= address + len(data) <= info['DEVICE_MAIN_FLASH_END_ADDR']):

            start = info['DEVICE_MAIN_FLASH_START_ADDR']
            end = info['DEVICE_MAIN_FLASH_END_ADDR']

        elif( info['DEVICE_INFO_START_ADDR'] <= address <=  info_end_address and
             info['DEVICE_INFO_START_ADDR'] <= address + len(data) <= info_end_address):

            start = info['DEVICE_INFO_START_ADDR']
            end = info_end_address
        else:
            raise Exception("I don't handle data that spans differing segment sizes yet")

        log.debug("Segment size: %d" % segment_size)
        log.debug("Start: %4X" % start)
        all_starting_segments = [x for x in range(start,end)][::segment_size]
        # for x in all_starting_segments:
        #     print("0x%4X" % x)

        first_seg_i = bisect.bisect_right(all_starting_segments, address) - 1
        last_seg_i = bisect.bisect_left(all_starting_segments, address + len(data))

        log.debug("First seg address %04x:" % all_starting_segments[first_seg_i])
        log.debug("End seg address %04x:" % all_starting_segments[last_seg_i])

        size = all_starting_segments[last_seg_i] - all_starting_segments[first_seg_i]
        log.debug("Total size to write: %d" % size)

        readdata = self.F_Memory_Read_Data(all_starting_segments[first_seg_i], size)
        print("Initial Data Read: (len %d)" % len(readdata))
        self.dump_mem(readdata, all_starting_segments[first_seg_i])
        if len(readdata) < size:
            raise Exception('failed to retrieve initial data')

        offset = address - all_starting_segments[first_seg_i]

        data_to_write = readdata[0:offset] + data + readdata[offset+len(data):]
        print("data_to_write:")
        self.dump_mem(data_to_write, all_starting_segments[first_seg_i])


        for s, seg_add in enumerate(all_starting_segments[first_seg_i:last_seg_i]):
            a = s * segment_size
            b = (s+1) * segment_size

            print("----------------------------------------------------------")
            print("Erasing Segment at %04x." % seg_add)
            print("Also Erasing Segment at %04x." % (seg_add + segment_size//2))
            r = self.F_Segment_Erase(seg_add)
            # I don't understand why this is needed
            r |= self.F_Segment_Erase((seg_add + segment_size//2))
            if r != 1: raise Exception("Erase Failed: %s" % R[r])

            # # blankcheck = self.F_Memory_Read_Data(seg_add, segment_size)
            # # print("Blank Check:")
            # # self.dump_mem(blankcheck, seg_add)

            r = self.F_Sectors_Blank_Check(seg_add, seg_add+segment_size-1)
            if r != 1: raise Exception("Blank Check Failed: erase failed")

            print("Writing Data Segment %04x:" % (seg_add))
            self.dump_mem(data_to_write[a:b], seg_add)
            r = self.F_Memory_Write_Data(seg_add, segment_size, data_to_write[a:b])
            if r != 1: raise Exception("Write failed")

            verifydata = self.F_Memory_Read_Data(seg_add, segment_size)
            print("Verify:")
            self.dump_mem(verifydata, seg_add)
            if verifydata != data_to_write[a:b]:
                log.warning("Soft fail, verify failed at 0x%02X" % seg_add)

            print("Completed write %d of %d" % (s+1,len(all_starting_segments[first_seg_i:last_seg_i])))


    def dump_mem(self, byte_array, start_addr=None):
        """
        super simple hex dump thing
        """
        for chunk in zip_longest(*[iter(byte_array)]*16, fillvalue=(0x00)):

            # if not any(chunk):
                  # start_addr += 16
            #     # skip anything that is all zeros
            #     continue

            if start_addr is not None:
                print("@%05X | " % start_addr, end="")
                start_addr += 16

            for b in chunk:
                print("%02x" % b, end=" ")
            print("|", end=" ")
            as_text = re.sub(r"\s+", " ",bytearray(chunk).decode('ascii',errors='replace'))
            print(as_text)


if __name__ == "__main__":
    # This shows a brief example usage, only read operations.
    # simply run this file
    import time
    import re

    elpro = PyElprotronic430()
    r = elpro.F_Initialization()
    print(R[r])


    print("Config loaded?: %s." % R[elpro.F_ConfigFileLoad(".\\Elprotronic\\config.ini")] )

    print("Power on?: %s." % (R[elpro.F_Power_Target(True)]))
    time.sleep(.2)
    print("open target?: %s" % elpro.F_Open_Target_Device())

    device_info = elpro.getAllDeviceInfo()
    print(device_info)

    databuf = elpro.F_Memory_Read_Data(device_info["DEVICE_MAIN_FLASH_START_ADDR"], 512*2)
    elpro.dump_mem(databuf)

    print(elpro.F_Read_Word(0x3100))

    print("sector size %d" % elpro.F_Get_Sector_Size(0x1000))
    print("sector size %d" % elpro.F_Get_Sector_Size(0x3000))
    print("sector size %d" % elpro.F_Get_Sector_Size(0x8000))

    memdump = elpro.F_Memory_Read(device_info["DEVICE_MAIN_FLASH_END_ADDR"])
    elpro.dump_mem(memdump)

    r = elpro.F_Close_All()