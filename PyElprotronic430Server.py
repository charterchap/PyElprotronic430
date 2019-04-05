#!/usr/bin/env python3
"""
author Jeff Charter Chapman

See DLL-User-Guide.pdf from Elprotronic's website

See also MSPPrg-Dll.h from Elprotronic
"""
from msl.loadlib import Server32
import os
from enum import Enum
import ctypes

class CFG(Enum):
    CFG_INTERFACE = 0
    CFG_MICROCONTROLLER = 1
    CFG_POWERTARGETEN = 2
    CFG_COMMSPEED = 3
    CFG_RESETTIME = 4
    CFG_FLASHERASEMODE = 5
    CFG_ERASEINFOA = 6
    CFG_ERASEINFOB = 7
    CFG_ERASESTARTADDR = 8
    CFG_ERASESTOPADDR = 9
    CFG_FLASHREADMODE = 10
    CFG_READINFOA = 11
    CFG_READINFOB = 12
    CFG_READSTARTADDR = 13
    CFG_READSTOPADDR = 14
    CFG_VERIFYMODE = 15
    CFG_BLOWFUSE = 16
    CFG_APPLSTARTEN = 17
    CFG_BEEPEN = 18
    CFG_ERASEINFOC = 19
    CFG_ERASEINFOD = 20
    CFG_DEFERASEMAINEN = 21
    CFG_READINFOC = 22
    CFG_READINFOD = 23
    CFG_JTAGSPEEDINDEX = 24
    CFG_VCCINDEX = 25
    CFG_CUSTOMRESETPULSETIME = 26
    CFG_CUSTOMRESETIDLETIME = 27
    CFG_RSTVCCTOGGLETIME = 28
    CFG_APPLRESETVCCTIME = 29
    CFG_POP_UP_EN = 30
    CFG_JTAG_SPEED = 31
    CFG_BSL_ENH_ENABLE = 32
    CFG_BSL_ENH_INDEX = 33
    CFG_RETAIN_CAL_DATA_INDEX = 34
    CFG_RETAIN_DEF_DATA_INDEX = 35
    CFG_RETAIN_START_ADDR_INDEX = 36
    CFG_RETAIN_STOP_ADDR_INDEX = 37
    CFG_APPLPRGRUNTIME = 38
    CFG_RELEASEJTAGSTATE = 39
    CFG_RUNTIMETDIGENEN = 40
    CFG_RUNTIMETDIGENDIV = 41
    CFG_RUNTIMETDIGENPRESCALER = 42
    CFG_DCO1_CAL_ENABLE = 43
    CFG_DCO2_CAL_ENABLE = 44
    CFG_DCO3_CAL_ENABLE = 45
    CFG_DCO4_CAL_ENABLE = 46
    CFG_DCO5_CAL_ENABLE = 47
    CFG_DCO6_CAL_ENABLE = 48
    CFG_DCO7_CAL_ENABLE = 49
    CFG_DCO8_CAL_ENABLE = 50
    CFG_DCO1_CAL_FREQ_INDEX = 51
    CFG_DCO2_CAL_FREQ_INDEX = 52
    CFG_DCO3_CAL_FREQ_INDEX = 53
    CFG_DCO4_CAL_FREQ_INDEX = 54
    CFG_DCO5_CAL_FREQ_INDEX = 55
    CFG_DCO6_CAL_FREQ_INDEX = 56
    CFG_DCO7_CAL_FREQ_INDEX = 57
    CFG_DCO8_CAL_FREQ_INDEX = 58
    CFG_DCO_DEFINED_ADDR_EN = 59
    CFG_DCO_DEFINED_ADDRESS = 60
    CFG_RUNTIMEBSLTXGENEN = 61
    CFG_RESERVED_1 = 62
    CFG_MASSERASE_AND_INFOA_EN = 63
    CFG_DCO_CONST_2XX_VERIFY_EN = 64
    CFG_DCOCAL_2XX_EN = 65
    CFG_FIRST_BSL_PASSW_INDEX = 66
    CFG_FREE67 = 67
    CFG_FREE68 = 68
    CFG_CS_TYPE_INDEX = 69
    CFG_CS_INIT_INDEX = 70
    CFG_CS_RESULT_INDEX = 71
    CFG_CS_CODE_OVERWIRIE_EN = 72
    CFG_CS_POLYNOMINAL = 73
    CFG_CS1_CALC_EN = 74
    CFG_CS1_START_ADDR = 75
    CFG_CS1_END_ADDR = 76
    CFG_CS1_RESULT_ADDR = 77
    CFG_CS2_CALC_EN = 78
    CFG_CS2_START_ADDR = 79
    CFG_CS2_END_ADDR = 80
    CFG_CS2_RESULT_ADDR = 81
    CFG_CS3_CALC_EN = 82
    CFG_CS3_START_ADDR = 83
    CFG_CS3_END_ADDR = 84
    CFG_CS3_RESULT_ADDR = 85
    CFG_CS4_CALC_EN = 86
    CFG_CS4_START_ADDR = 87
    CFG_CS4_END_ADDR = 88
    CFG_CS4_RESULT_ADDR = 89
    CFG_BSL_FLASH_WR_EN = 90
    CFG_BSL_FLASH_RD_EN = 91
    CFG_DCO_EXT_RESISTOR_EN = 92
    CFG_INCLUDE_BLANK_CHECK = 93
    CFG_VCC_IN_MVOLTS = 94
    CFG_RST_3ST_MODE_EN = 95
    CFG_BSL_RST_VIA_TDIO = 96
    CFG_SBWDAT_VIA_FPA_RST = 97
    CFG_FILE_FLAG_INDEX = 1001


R = { # R for return value. Most of the api calls follow this for return types
    # Although some do not
    -1: "UART not supported",
    -2: "FPA_INVALID_NO",
    0: "FALSE",
    1: "TRUE",
    2: "JTAG security blown - communication failed",
    3: "???",
    4: "Programming adapter not detected.",
}

class FileTypes(Enum):
    # _settings_ = NoAlias # allow for duplicate values
    FILE_TI_FORMAT = 1
    FILE_ASCII_HEX_FORMAT = 1
    FILE_MOTOROLA_FORMAT = 2
    FILE_INTEL_FORMAT = 3
    FILE_IAR_D43_FORMAT = 4
    FILE_DEBUG_A43_FORMAT = 5


class PyElprotronic430Server(Server32):
    def __init__(self, host, port, quiet, **kwargs):
        __dll_file_name = os.path.join('C:\\', 'Program Files (x86)', 
            'Elprotronic', 'MSP430', 'USB FlashPro430', 'API-DLL', 'MSP430FPA1.dll')

        if not os.path.isfile(__dll_file_name):
            __dll_file_name = os.path.join(os.path.dirname(__file__), 'Elprotronic', 'MSP430FPA1.dll')

        super(PyElprotronic430Server, self).__init__(__dll_file_name, 'cdll', host, port, quiet)


    def F_Power_Target(self, on=True):
        """
        """
        return self.lib.F_Power_Target(int(on))


    def F_GetConfig(self, cfg):
        return self.lib.F_GetConfig(cfg.value)


    def F_SetConfig(self, cfg, data):
        return self.lib.F_SetConfig(cfg.value, data)


    def F_Close_All(self):
        return self.lib.F_Close_All()


    def F_ReadCodeFile(self, file_format, filename):
        """
        :param file_format - example FileTypes.FILE_TI_FORMAT
        :param filename - a python str
        """
        return self.lib.F_ReadCodeFile(file_format.value, bytes(filename, encoding="ascii"))


    def F_ConfigFileLoad(self, filename):
        """
        Loads an ini config file
        :param filename - path to .ini file *you can get one from flashPro430
                by doing an save config. filename is a normal python string, but
                should be ascii only
        """
        return self.lib.F_ConfigFileLoad(bytes(filename, encoding="ascii"))


    def F_AutoProgram(self, mode):
        """
        :param mode -> 0   value 1..up  reserved... whatever that means?
        """
        return self.lib.F_AutoProgram(mode)


    def F_Memory_Erase(self, mode):
        """
        :param mode -> 0 -> erase space specify by the FlashEraseModeIndex
               mode-> 1 -> erase all Flash memory, regardless FlashEraseModeIndex

        """
        return self.lib.F_Memory_Erase(mode)


    def F_Memory_Blank_Check(self):
        return self.lib.F_Memory_Blank_Check()


    def F_Memory_Write(self, mode):
        """
        :param mode -> 0   value 1..up  reserved... whatever that means?
        """
        return self.lib.F_Memory_Write(mode)


    def F_Memory_Verify(self, mode):
        """
        :param mode -> 0   value 1..up  reserved... whatever that means?
        """
        return self.lib.F_Memory_Verify(mode)


    def F_Segment_Erase(self, address):
        """
        """
        return self.lib.F_Segment_Erase(address)


    def F_Get_Sector_Size(self, address):
        """
        returns <sector size> for sector that includes given address
        returns 0 for incorrect addresses (address that does not fit within any sector)
        """
        return self.lib.F_Get_Sector_Size(address)


    def F_Sectors_Blank_Check(self, start_addr, stop_addr):
        """
        """
        return self.lib.F_Sectors_Blank_Check(start_addr, stop_addr)


    def F_Memory_Write_Data(self, start_addr, size, data_bytes):
        """
        :param size - e.g. 2
        :param data_bytes - e.g. bytes([0x01,0x2])
        """
        return self.lib.F_Memory_Write_Data(start_addr, size, data_bytes)


    def F_Memory_Read_Data(self, start_addr, size):
        """
        :param size - e.g. 2
        :param data_bytes - e.g. bytes([0x01,0x2])
        """
        sbuf = ctypes.create_string_buffer(size)

        ret_val = self.lib.F_Memory_Read_Data(start_addr, size, sbuf)
        return sbuf.raw


    def F_Read_Word(self, addr):
        """
        """
        return self.lib.F_Read_Word(addr)


    def F_Memory_Read(self, mcu_size=0x1F380):
        """
        mcu_size -> see "DEVICE_MAIN_FLASH_END_ADDR"
        """
        sbuf = ctypes.create_string_buffer(mcu_size)
        self.lib.F_Memory_Read(sbuf)
        return sbuf.raw


    def F_Get_Device_Info(self, index):
        """
          fpa = 1....MAX_FPA_INDEX
          return  -1 if invalid data
           or 
            index - 0 to 19  -> device name - char by char starting from 
             index->0 => M eg.  MSP430F149
               index 0 -> 'M'
               index 1 -> 'S'
               index 2 -> 'P'
               index 3 -> '4'
               index 4 -> '3'
               index 5 -> '0'
               index 6 -> 'F'
               index 7 -> '1'
               index 8 -> '4'
               index 9 -> '9'
               index 10 -> 0x0000  -> end of string
            index 20 -> MAIN Flash Start Address  eg 0x1100  (for F149)
            index 21 -> MAIN Flash End  Address   eg 0xFFFF  (for F149)
            index 22 -> INFO start address        eg 0x1000
            index 23 -> INFO segment size         eg 0x0080  (for F149)
            index 24 -> No of INFO segments       eg 0x0002  (for F149)
            index 25 -> RAM size                  eg 0x0800  (for F149)
            index 26 -> MCU Group                 eg 0x0001  (for F1xx)
            index 27 -> MCU already defined (other ID for the same MCU)  eg 0x0000  (for F149)
        """
        return self.lib.F_Get_Device_Info(index)


    def getAllDeviceInfo(self):
        """
        """
        # DEVICE_NAME                     = 0,
        # DEVICE_NAME_SIZE                = 20,
        # DEVICE_MAIN_FLASH_START_ADDR    = 20,
        # DEVICE_MAIN_FLASH_END_ADDR      = 21,
        # DEVICE_INFO_START_ADDR          = 22,
        # DEVICE_INFO_SEGM_SIZE           = 23,
        # DEVICE_NO_INFO_SEGMENTS         = 24,
        # DEVICE_RAM_SIZE                 = 25,
        # DEVICE_GROUP                    = 26,
        # DEVICE_ALREADY_DEFINED          = 27,
        # DEVICE_FAMILY                   = 28,
        # DEVICE_HW_REVISION              = 29,
        # DEVICE_FW_REVISION              = 30
        info = dict()

        b = bytearray()
        for i in range(0, 19):
            b.append(self.lib.F_Get_Device_Info(i))
        info["DEVICE_NAME"] = b.decode("ascii") 

        info["DEVICE_MAIN_FLASH_START_ADDR"] = self.lib.F_Get_Device_Info(20)
        info["DEVICE_MAIN_FLASH_END_ADDR"] = self.lib.F_Get_Device_Info(21)
        info["DEVICE_INFO_START_ADDR"] = self.lib.F_Get_Device_Info(22)
        info["DEVICE_INFO_SEGM_SIZE"] = self.lib.F_Get_Device_Info(23)
        info["DEVICE_NO_INFO_SEGMENTS"] = self.lib.F_Get_Device_Info(24)
        info["DEVICE_RAM_SIZE"] = self.lib.F_Get_Device_Info(25)
        info["DEVICE_GROUP"] = self.lib.F_Get_Device_Info(26)
        info["DEVICE_ALREADY_DEFINED"] = self.lib.F_Get_Device_Info(27)

        return info


    def F_OpenInstances(self, no):
        """
        """
        return self.lib.F_OpenInstances(no)


    def F_CloseInstances(self):
        """
        """
        return self.lib.F_CloseInstances()


    def F_OpenInstances_AndFPAs(self, filename):
        """
        """
        return self.lib.F_OpenInstances_AndFPAs(bytes(filename, encoding="ascii"))


    def F_OpenInstancesAndFPAs(self, filename):
        """
        """
        return self.lib.F_OpenInstancesAndFPAs(bytes(filename, encoding="ascii"))


    def F_Set_FPA_index(self, fpa):
        """
        """
        return self.lib.F_Set_FPA_index(fpa)


    def F_Check_FPA_index(self):
        """
        """
        return self.lib.F_Check_FPA_index()


    def F_LastStatus(self, fpa):
        """
        """
        return self.lib.F_LastStatus(fpa)


    def F_DLLTypeVer(self):
        """
        """
        return self.lib.F_DLLTypeVer()


    def F_Multi_DLLTypeVer(self):
        """
        """
        return self.lib.F_Multi_DLLTypeVer()


    def F_Get_FPA_Label(self, fpa, label):
        """
        """
        return self.lib.F_Get_FPA_Label(fpa, label)


    def F_Initialization(self):
        """
        """
        return self.lib.F_Initialization()


    def F_Use_Config_INI(self, use):
        """
        Configure F_Initialization to use (default) or skip config.ini file
            input 1 to use config.ini, input 0 to skip
        when skipping config.ini it is necessary to use ConfigFileLoad or SetConfig functions to
        configure the adapter.
            return      0 - state unchanged
                        1 - state changed to input parameter
        """
        return self.lib.F_Use_Config_INI(use)


    def F_DispSetup(self):
        """
        """
        return self.lib.F_DispSetup()


    def F_Get_Device_Info(self, index):
        """
        """
        return self.lib.F_Get_Device_Info()


    def F_Close_All(self):
        """
        """
        return self.lib.F_Close_All()


    def F_Reset_Target(self):
        """
        """
        return self.lib.F_Reset_Target()


    def F_init_parallel_port(self, Parallel_Port_no):
        """
        """
        return self.lib.F_init_parallel_port(Parallel_Port_no)


    def F_Read_PasswFile(self, file_format, filename):
        """
        :param file_format - example FileTypes.FILE_TI_FORMAT
        :param filename - a python str
        """
        return self.lib.F_Read_PasswFile(file_format.value, bytes(filename, encoding="ascii"))


    def F_ReadPasswFile(self, file_format, FileName ):
        """
        :param file_format - example FileTypes.FILE_TI_FORMAT
        :param filename - a python str
        """
        return self.lib.F_ReadPasswFile(file_format.value, bytes(filename, encoding="ascii"))


    def F_Set_MCU_Name(self, MCU_name):
        """
        :param MCU_Name - string
        """
        return self.lib.F_Set_MCU_Name(bytes(MCU_name, encoding="ascii"))


    def F_Put_Byte_to_Buffer(self, addr, data):
        """
        """
        return self.lib.F_Put_Byte_to_Buffer(addr, data)


    def F_Copy_Buffer_to_Flash(self, start_addr, size):
        """
        """
        return self.lib.F_Copy_Buffer_to_Flash(start_addr, size)


    def F_Copy_Flash_to_Buffer(self, start_addr, size):
        """
        """
        return self.lib.F_Copy_Flash_to_Buffer(start_addr, size)


    def F_Clr_Code_Buffer(self):
        """
        """
        return self.lib.F_Clr_Code_Buffer()


    def F_Put_Byte_to_Code_Buffer(self, addr, data):
        """
        """
        return self.lib.F_Put_Byte_to_Code_Buffer(addr, data)


    def F_Put_Byte_to_Password_Buffer(self, addr, data):
        """
        """
        return self.lib.F_Put_Byte_to_Password_Buffer(addr, data)


    def F_Get_Byte_from_Code_Buffer(self, addr):
        """
        """
        return self.lib.F_Get_Byte_from_Code_Buffer(addr)


    def F_Get_Byte_from_Password_Buffer(self, addr):
        """
        """
        return self.lib.F_Get_Byte_from_Password_Buffer(addr)


    def F_VerifyFuseOrPassword(self):
        """
        """
        return self.lib.F_VerifyFuseOrPassword()


    def F_Copy_All_Flash_to_Buffer(self):
        """
        """
        return self.lib.F_Copy_All_Flash_to_Buffer(self)


    def F_Restore_JTAG_Security_Fuse(self):
        """
        """
        return self.lib.F_Restore_JTAG_Security_Fuse()


    def F_Open_Target_Device(self):
        """
        """
        return self.lib.F_Open_Target_Device()


    def F_Close_Target_Device(self):
        """
        """
        return self.lib.F_Close_Target_Device()


    def F_Blow_Fuse(self):
        """
        """
        return self.lib.F_Blow_Fuse()


    def F_Write_Word(self, addr, data):
        """
        """
        return self.lib.F_Write_Word(addr, data)


    def F_Write_Byte(self, addr, data):
        """
        """
        return self.lib.F_Write_Byte(addr, data)


    def F_Read_Byte(self, addr):
        """
        return the specified byte

        read byte from any location of RAM, Flash, registers etc.
        valid with JTAG communication only
        """
        return self.lib.F_Read_Byte(addr)


    def F_Copy_Buffer_to_RAM(self, start_addr, size):
        """
        """
        return self.lib.F_Copy_Buffer_to_RAM(start_addr, size)


    def F_Copy_RAM_to_Buffer(self, start_addr, size):
        """
        """
        return self.lib.F_Copy_RAM_to_Buffer(start_addr, size)


    def F_Set_PC_and_RUN(self, PC_addr):
        """
        """
        return self.lib.F_Set_PC_and_RUN(PC_addr)


    def F_Capture_PC_Addr(self):
        """
        """
        return self.lib.F_Capture_PC_Addr()


    def F_Synch_CPU_JTAG(self):
        """
        """
        return self.lib.F_Synch_CPU_JTAG()


    def F_Adj_DCO_Frequency(self, freq_Hz):
        """
        """
        return self.lib.F_Adj_DCO_Frequency(freq_Hz)


    def F_Test_DCO_Frequency(self, DCO_constant):
        """
        """
        return self.lib.F_Test_DCO_Frequency(DCO_constant)


    def F_Get_Targets_Vcc(self):
        """
        """
        return self.lib.F_Get_Targets_Vcc()


    def F_Set_fpa_io_state(self, jtag, reset, VccOn):
        """
        """
        return self.lib.F_Set_fpa_io_state(jtag, reset, VccOn)


    def F_Customize(self, dest, data):
        """
        """
        return self.lib.F_Customize(dest, data)


    def F_custom_jtag_stream(self, mode, size, data_out, data_in):
        """
        """
        return self.lib.F_custom_jtag_stream(mode, size, 
            ctypes.pointer(data_out), ctypes.pointer(data_in))


    def F_Custom_Function(self, type_):
        """
        CUSTOM_FUNCTION_UART_9600   =   1,
        CUSTOM_FUNCTION_UART_57K6   =   2,
        UART_TX_SIZE_ADDR           =   0,
        UART_RX_SIZE_ADDR           =   1,
        UART_BUFFER_START_ADDR      =   0x10,
        UART_BUFFER_SIZE            =   56
        """
        return self.lib.F_Custom_Function(type_)



# void   MSPPRG_API F_Trace_ON( void );
# void   MSPPRG_API F_Trace_OFF( void );
# void   MSPPRG_API F_API_DLL_Directory( CString APIDLLpath );
# void   MSPPRG_API F_APIDLL_Directory( char *  APIDLLpath );
# void   MSPPRG_API F_ReportMessage( char * text );
# void   MSPPRG_API F_Disable_FPA_index( BYTE fpa );
# void   MSPPRG_API F_Enable_FPA_index( BYTE fpa );
# BYTE   MSPPRG_API F_Get_FPA_index( void );
# BYTE   MSPPRG_API F_Get_Byte_from_Buffer( LONG_X addr );
# BYTE   MSPPRG_API F_GetReportMessageChar( INT_X index );
# unsigned int MSPPRG_API F_Get_Config_Value_By_Name(char *name, int type);

# CONFIG_BLOCK
# def F_ConfigSetup(self, config):
#     """
#
#     """
#     return self.lib.F_ConfigSetup(config_block)

# def F_GetSetup(self,  *config ):
#     """
#     """
#     return self.lib.F_GetSetup()





# class CONFIG_BLOCK:
#     Interface = 0
#     uProcIndex = 0
#     PowerTargetEn = 0
#     CommSpeedIndex = 0
#     ResetTimeIndex = 0
#     FlashEraseModeIndex = 0
#     EraseInfoSegmA = 0
#     EraseInfoSegmB = 0
#     EraseFlashStartAddr = 0
#     EraseFlashStopAddr = 0
#     FlashReadModeIndex = 0
#     ReadInfoSegmA = 0
#     ReadInfoSegmB = 0
#     ReadStartAddr = 0
#     ReadStopAddr = 0
#     VerifyModeIndex = 0
#     BlowFuseEn = 0
#     ApplicationStartEn = 0
#     BeepEnable = 0
#     EraseInfoSegmC = 0
#     EraseInfoSegmD = 0
#     DefEraseMainMemEn = 0
#     ReadInfoSegmC = 0
#     ReadInfoSegmD = 0
#     JtagSpeedIndex = 0
#     VccIndex = 0
#     CustomResetPulseTime = 0
#     CustomResetIdleTime = 0
#     RstVccToggleTime = 0
#     ApplResetVccTime = 0
