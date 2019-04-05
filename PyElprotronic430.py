#!/usr/bin/env python3
"""
author Jeff Charter Chapman

See DLL-User-Guide.pdf from Elprotronic's website

See main for example usage
"""
import os
from msl.loadlib import Client64
from enum import Enum
from PyElprotronic430Server import CFG, R, FileTypes

import configparser

class PyElprotronic430(Client64):
    def __init__(self):
        super(PyElprotronic430, self).__init__(module32='PyElprotronic430Server.py')

    def __getattr__(self, method32):
        def send(*args, **kwargs):
            return self.request32(method32, *args, **kwargs)
        return send


if __name__ == "__main__":
    # This shows a brief example usage, only read operations.
    # simply run this file

    import time
    import re

    def dump_mem(byte_array):
        """
        super simple hex dump thing
        """
        for chunk in zip(*[iter(byte_array)]*16):
            if not any(chunk):
                # skip anything that is all zeros
                continue
            for b in chunk:
                print("%02x" % b, end=" ")
            print("|", end=" ")
            as_text = re.sub(r"\s+", " ",bytearray(chunk).decode('ascii',errors='replace'))
            print(as_text)


    elpro = PyElprotronic430()
    r = elpro.F_Initialization()
    print(R[r])


    print("Config loaded?: %s." % R[elpro.F_ConfigFileLoad(".\\Elprotronic\\config.ini")] )

    print("Power on?: %s." % (R[elpro.F_Power_Target(True)]))
    time.sleep(.2)

    device_info = elpro.getAllDeviceInfo()
    print(device_info)

    databuf = elpro.F_Memory_Read_Data(device_info["DEVICE_MAIN_FLASH_START_ADDR"], 512*2)
    dump_mem(databuf)

    print(elpro.F_Read_Word(0x3100))

    print("sector size %d" % elpro.F_Get_Sector_Size(0x1000))
    print("sector size %d" % elpro.F_Get_Sector_Size(0x3000))
    print("sector size %d" % elpro.F_Get_Sector_Size(0x8000))

    memdump = elpro.F_Memory_Read(device_info["DEVICE_MAIN_FLASH_END_ADDR"])
    dump_mem(memdump)

    r = elpro.F_Close_All()