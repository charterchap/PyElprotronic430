/****************************************************************************/
//
//  MSP430 Flash Programmer - Multi API-DLL software
//  Author: Gregory Czajkowski
//  Elprotronic Inc. 2003-2018
//  
/****************************************************************************/
// THIS PROGRAM IS PROVIDED "AS IS". ELPROTRONIC INC. MAKES NO WARRANTIES OR
// REPRESENTATIONS, EITHER EXPRESS, IMPLIED OR STATUTORY, 
// INCLUDING ANY IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS 
// FOR A PARTICULAR PURPOSE, LACK OF VIRUSES, ACCURACY OR 
// COMPLETENESS OF RESPONSES, RESULTS AND LACK OF NEGLIGENCE. 
// ELPROTRONIC INC. DISCLAIMS ANY WARRANTY OF TITLE, QUIET ENJOYMENT, QUIET 
// POSSESSION, AND NON-INFRINGEMENT OF ANY THIRD PARTY 
// INTELLECTUAL PROPERTY RIGHTS WITH REGARD TO THE PROGRAM OR 
// YOUR USE OF THE PROGRAM.
//
// IN NO EVENT SHALL ELPROTRONIC INC. BE LIABLE FOR ANY SPECIAL, INCIDENTAL, 
// CONSEQUENTIAL OR INDIRECT DAMAGES, HOWEVER CAUSED, ON ANY 
// THEORY OF LIABILITY AND WHETHER OR NOT ELPROTRONIC INC. HAS BEEN ADVISED 
// OF THE POSSIBILITY OF SUCH DAMAGES, ARISING IN ANY WAY OUT 
// OF THIS AGREEMENT, THE PROGRAM, OR YOUR USE OF THE PROGRAM. 
// EXCLUDED DAMAGES INCLUDE, BUT ARE NOT LIMITED TO, COST OF 
// REMOVAL OR REINSTALLATION, COMPUTER TIME, LABOR COSTS, LOSS 
// OF GOODWILL, LOSS OF PROFITS, LOSS OF SAVINGS, OR LOSS OF 
// USE OR INTERRUPTION OF BUSINESS. 
//
// Unless otherwise stated, the Program written and copyrighted 
// by Elprotronic Inc. is distributed as "freeware".  You may, 
// only under Elprotronic's Inc. copyright in the Program, use and modify the 
// Program without any charge or restriction.  You may 
// distribute to third parties, provided that you transfer a 
// copy of this license to the third party and the third party 
// agrees to these terms by its first use of the Program. You 
// must reproduce the copyright notice and any other legend of 
// ownership on each copy or partial copy, of the Program.
//
// You acknowledge and agree that the Program contains 
// copyrighted material, trade secrets and other Elprotronic Inc. proprietary 
// information and is protected by copyright laws, 
// international copyright treaties, and trade secret laws, as 
// well as other intellectual property laws.  To protect Elprotronic's Inc. 
// rights in the Program, you agree not to decompile, reverse 
// engineer, disassemble or otherwise translate any object code 
// versions of the Program to a human-readable form.  You agree 
// that in no event will you alter, remove or destroy any 
// copyright notice included in the Program.  Elprotronic Inc. reserves all 
// rights not specifically granted under this license. Except 
// as specifically provided herein, nothing in this agreement 
// shall be construed as conferring by implication, estoppel, 
// or otherwise, upon you, any license or other right under any 
// Elprotronic Inc. patents, copyrights or trade secrets.
//
/****************************************************************************/

// ------  MSPPrg-Dll.h  header file -----------
#ifndef MSPPRG_DLL_H
#define MSPPRG_DLL_H

#ifndef __GNUC__
#define MSWIN_API               //comment out for Borland, DOS applications  etc if the CString is not supported

#ifdef  MSPPRG_DLL
   #define MSPPRG_API __declspec(dllexport)
#else
   #define MSPPRG_API __declspec(dllimport)
#endif

#ifdef  MSWIN_API
  #define               CSTRING_EN
#endif

#else //__GNUC__
#define MSPPRG_API __attribute__ ((visibility("default")))
#define __stdcall  __attribute__ ((visibility("default")))
#endif//__GNUC__
typedef         int               LONG_X;
typedef         int               INT_X;             
typedef         unsigned char     BYTE;
#ifndef __GNUC__
typedef         unsigned _int64   ULONG64;
#else//__GNUC__
typedef         unsigned long long ULONG64;
#endif//__GNUC__

#define     REPORT_MESSAGE_MAX_SIZE     2000
#define     MAX_USB_DEV_NUMBER          64
#define     MAX_FPA_INDEX               64
#define     ALL_ACTIVE_FPA              0
#define     FPA_UNMATCHED_RESULTS       -1
#define     FPA_INVALID_NO              -2

#define     PRG_ADAPTER_NOT_DETECTED    0x4 
#define     TERMINATED_VCC_BELOW_2V7    0x20
#define     FLASH_END_ADDR              0x8FFFF

#define     CODE_IN_ROM             0x10    
#define     CODE_IN_RAM             0x20
#define     CODE_OUT_OF_FLASH       0x40
#define     CODE_OVERWRITTEN        0x80
#define     PASSWORD_NOT_FOUND      0x100
#define     INVALID_CODE_FILE       0x200
#define     OPEN_FILE_OR_READ_ERR   0x8
#define     FILE_TI_FORMAT              1
#define     FILE_ASCII_HEX_FORMAT       1
#define     FILE_MOTOROLA_FORMAT        2
#define     FILE_INTEL_FORMAT           3
#define     FILE_IAR_D43_FORMAT         4
#define     FILE_DEBUG_A43_FORMAT       5
#define     MAX_FILE_FORMAT_INDEX   FILE_DEBUG_A43_FORMAT
#define     FILE_TI_EXT               "txt"     //all lower case
#define     FILE_MOTOROLA_EXT         "srec"        //all lower case
#define     FILE_MOTOROLA_EXT1        "s19"     //all lower case
#define     FILE_MOTOROLA_EXT2        "s28"     //all lower case
#define     FILE_MOTOROLA_EXT3        "s37"     //all lower case
#define     FILE_INTEL_EXT            "hex"     //all lower case
#define     FILE_IAR_D43_EXT          "d43"     //all lower case
#define     FILE_DEBUG_A43_EXT        "a43"     //all lower case
#define     FILE_ASCII_HEX_EXT        "ahx"     //all lower case

typedef struct      //old style - do not use. Structore do not contains all CFG parameters
{
    INT_X Interface;
    INT_X uProcIndex;
    INT_X PowerTargetEn;
    INT_X CommSpeedIndex;
    INT_X ResetTimeIndex;
    INT_X FlashEraseModeIndex;
    INT_X EraseInfoSegmA;
    INT_X EraseInfoSegmB;
    INT_X EraseFlashStartAddr;
    INT_X EraseFlashStopAddr;
    INT_X FlashReadModeIndex;
    INT_X ReadInfoSegmA;
    INT_X ReadInfoSegmB;
    INT_X ReadStartAddr;
    INT_X ReadStopAddr;
    INT_X VerifyModeIndex;
    INT_X BlowFuseEn;
    INT_X ApplicationStartEn;
    INT_X BeepEnable;
    INT_X EraseInfoSegmC;
    INT_X EraseInfoSegmD;
    INT_X DefEraseMainMemEn;
    INT_X ReadInfoSegmC;
    INT_X ReadInfoSegmD;
    INT_X JtagSpeedIndex;
    INT_X VccIndex;
    INT_X CustomResetPulseTime;
    INT_X CustomResetIdleTime;
    INT_X RstVccToggleTime;
    INT_X ApplResetVccTime;
} CONFIG_BLOCK;

enum    CFG_INDEXES
{
    CFG_INTERFACE           =0,
    CFG_MICROCONTROLLER     =1,
    CFG_POWERTARGETEN       =2,
    CFG_COMMSPEED           =3,
    CFG_RESETTIME           =4,
    CFG_FLASHERASEMODE      =5, 
    CFG_ERASEINFOA          =6, 
    CFG_ERASEINFOB          =7, 
    CFG_ERASESTARTADDR      =8, 
    CFG_ERASESTOPADDR       =9, 
    CFG_FLASHREADMODE       =10,    
    CFG_READINFOA           =11,
    CFG_READINFOB           =12,    
    CFG_READSTARTADDR       =13,
    CFG_READSTOPADDR        =14,    
    CFG_VERIFYMODE          =15,    
    CFG_BLOWFUSE            =16,    
    CFG_APPLSTARTEN         =17,    
    CFG_BEEPEN              =18,    
    CFG_ERASEINFOC          =19,    
    CFG_ERASEINFOD          =20,    
    CFG_DEFERASEMAINEN      =21,    
    CFG_READINFOC           =22,    
    CFG_READINFOD           =23,    
    CFG_JTAGSPEEDINDEX      =24,    
    CFG_VCCINDEX            =25,
    CFG_CUSTOMRESETPULSETIME =26,
    CFG_CUSTOMRESETIDLETIME  =27,
    CFG_RSTVCCTOGGLETIME    =28,
    CFG_APPLRESETVCCTIME    =29,
    CFG_POP_UP_EN           =30,
    CFG_JTAG_SPEED          =31,
    CFG_BSL_ENH_ENABLE      =32,
    CFG_BSL_ENH_INDEX       =33,
    CFG_RETAIN_CAL_DATA_INDEX   =34,
    CFG_RETAIN_DEF_DATA_INDEX   =35,
    CFG_RETAIN_START_ADDR_INDEX =36,
    CFG_RETAIN_STOP_ADDR_INDEX  =37,
    CFG_APPLPRGRUNTIME          =38,
    CFG_RELEASEJTAGSTATE        =39,
    CFG_RUNTIMETDIGENEN         =40,
    CFG_RUNTIMETDIGENDIV        =41,
    CFG_RUNTIMETDIGENPRESCALER  =42,
    CFG_DCO1_CAL_ENABLE         =43,
    CFG_DCO2_CAL_ENABLE         =44,
    CFG_DCO3_CAL_ENABLE         =45,
    CFG_DCO4_CAL_ENABLE         =46,
    CFG_DCO5_CAL_ENABLE         =47,
    CFG_DCO6_CAL_ENABLE         =48,
    CFG_DCO7_CAL_ENABLE         =49,
    CFG_DCO8_CAL_ENABLE         =50,
    CFG_DCO1_CAL_FREQ_INDEX     =51,
    CFG_DCO2_CAL_FREQ_INDEX     =52,
    CFG_DCO3_CAL_FREQ_INDEX     =53,
    CFG_DCO4_CAL_FREQ_INDEX     =54,
    CFG_DCO5_CAL_FREQ_INDEX     =55,
    CFG_DCO6_CAL_FREQ_INDEX     =56,
    CFG_DCO7_CAL_FREQ_INDEX     =57,
    CFG_DCO8_CAL_FREQ_INDEX     =58,
    CFG_DCO_DEFINED_ADDR_EN     =59,
    CFG_DCO_DEFINED_ADDRESS     =60,
    CFG_RUNTIMEBSLTXGENEN       =61,
    CFG_RESERVED_1              =62,  //empty - for compatibility with GangPro430
    CFG_MASSERASE_AND_INFOA_EN  =63,
    CFG_DCO_CONST_2XX_VERIFY_EN =64,
    CFG_DCOCAL_2XX_EN           =65,
    CFG_FIRST_BSL_PASSW_INDEX   =66,
    CFG_FREE67                  =67,
    CFG_FREE68                  =68,
    CFG_CS_TYPE_INDEX           =69,
    CFG_CS_INIT_INDEX           =70,
    CFG_CS_RESULT_INDEX         =71,
    CFG_CS_CODE_OVERWIRIE_EN    =72,
    CFG_CS_POLYNOMINAL          =73,
    CFG_CS1_CALC_EN             =74,
    CFG_CS1_START_ADDR          =75,
    CFG_CS1_END_ADDR            =76,
    CFG_CS1_RESULT_ADDR         =77,
    CFG_CS2_CALC_EN             =78,
    CFG_CS2_START_ADDR          =79,
    CFG_CS2_END_ADDR            =80,
    CFG_CS2_RESULT_ADDR         =81,
    CFG_CS3_CALC_EN             =82,
    CFG_CS3_START_ADDR          =83,
    CFG_CS3_END_ADDR            =84,
    CFG_CS3_RESULT_ADDR         =85,
    CFG_CS4_CALC_EN             =86,
    CFG_CS4_START_ADDR          =87,
    CFG_CS4_END_ADDR            =88,
    CFG_CS4_RESULT_ADDR         =89,
    CFG_BSL_FLASH_WR_EN         =90,
    CFG_BSL_FLASH_RD_EN         =91,
    CFG_DCO_EXT_RESISTOR_EN     =92,
    CFG_INCLUDE_BLANK_CHECK     =93,
    CFG_VCC_IN_MVOLTS           =94,
    CFG_RST_3ST_MODE_EN         =95,
    CFG_BSL_RST_VIA_TDIO        =96,
    CFG_SBWDAT_VIA_FPA_RST      =97,
    CFG_FILE_FLAG_INDEX         =1001
};

// -------------- CONFIG_BLOCK - definitions ----

//  Interface;              // 1-BSL, 0-JTAG
enum CFG_INTERFACE
{
    INTERFACE_JTAG  =0,     //JTAG - 4 wires
    INTERFACE_BSL   =1,     //Boot Strap Loader
    INTERFACE_SBW   =3,     //Spy-By-Wire  - 2 wires
};

//  int  uProcIndex;            // see MSPlist.ini file order - 1-> MSP430F110, 2-> ...1101, 3->...1101A etc.
#define     MSP430_ANY      0

//  int  PowerTargetEn;         //Power target from adapter  0->disable, 1->Enable
//      0 -> PowerTarget Disable
//      1 -> PowerTarget Enable

//  int  CommSpeedIndex;        //BSL communication speed 
#define COMM_SPEED_9k6_INDEX    0   //standard BSL communication
#define COMM_SPEED_75k_INDEX    1   //Parallel Port adapter only
#define COMM_SPEED_300k_INDEX   2   //300 kb/s in PP, 350 kB/s in USB-FPA


//  int  ResetTimeIndex;
#define RESET_50MS_INDEX            0   // 50 ms in PP, 10 ms in USB-FPA
#define RESET_100MS_INDEX           1
#define RESET_200MS_INDEX           2
#define RESET_500MS_INDEX           3
#define RESET_CUSTOM_INDEX          4
#define RESET_TOGGLE_VCC_INDEX      5
#define RESET_SOFT_JTAG_INDEX       6

//  int  FlashEraseModeIndex;
#define ERASE_NONE_MEM_INDEX        0
#define ERASE_ALL_MEM_INDEX         1
#define ERASE_PRG_ONLY_MEM_INDEX    2
#define ERASE_INFILE_MEM_INDEX      3
#define ERASE_DEF_CM_INDEX          4

//  int  EraseSegmA;            // Erase - write Info Segment (0x1080-0x10Ff) Enable/Disable
                                //                  (in F2xx) (0x10C0-0x10Ff) Enable/Disable
//  int  EraseSegmB;            // Erase - write Info Segment (0x1000-0x107f) Enable/Disable
                                //                  (in F2xx) (0x1080-0x10bf) Enable/Disable
//  int  EraseSegmC;            // Erase - in F2xx only       (0x1040-0x107f) Enable/Disable
//  int  EraseSegmD;            // Erase - in F2xx only       (0x1000-0x103f) Enable/Disable
//   0-disable, 1-enable

//  long EraseFlashStartAddr;   //  Erase and write start address: address must be even
//  long EraseFlashStopAddr;    //  Erase and write stop address:  address must be odd
//  any Programm Flash address without info (0x1000..0x10FF) memory  
//  addresses from 0x1100...0x1FFFF

//  int  FlashReadModeIndex;
#define READ_ALL_MEM_INDEX          0
#define READ_PRGMEM_ONLY_INDEX      1
#define READ_INFOMEM_ONLY_INDEX     2
#define READ_DEF_MEM_INDEX          3

//  int  ReadSegmA;
//  int  ReadSegmB;
//  int  ReadSegmC;
//  int  ReadSegmD;
//   0-disable, 1-enable

//  long ReadStartAddr;     // address must be even
//  long ReadStopAddr;      // address must be odd
//  any Programm Flash address without info (0x1000..0x10FF) memory  
//  addresses from 0x1100...0x1FFFF

//  int  VerifyModeIndex;
#define VERIFY_NONE_INDEX           0
#define VERIFY_STD_INDEX            1
#define VERIFY_FAST_INDEX           2

//  int  BlowFuseEn;
//   0-disable, 
//   1-enable   - only when function  F_Blow_Fuse()  is called;
//   3-enable   - when function F_AutoProgram(..) or F_Blow_Fuse()is called;

//  int  ApplicationStartEn;
//  CFG_APPLSTARTEN         17  
#define APPLICATION_KEEP_RESET      0       //Hardware Reset Line permanent LOW
#define APPLICATION_TOGGLE_RESET    1       //Hardware Reset (Pulse Low)
#define APPLICATION_TOGGLE_VCC      2       //Toggle VCC Reset
#define APPLICATION_JTAG_RESET      3       //JTAG software reset

//  int  BeepEnable;
//   0-disable, 1-enable

//  CFG_JTAGSPEEDINDEX      24  
//  CFG_JTAG_SPEED          31
#define JTAG_SPEED_1MB_INDEX        0       // USB model only - available in the API-DLL 
#define JTAG_SPEED_4MB_INDEX        1       // USB model only - available in the API-DLL 
#define JTAG_SPEED_400K_INDEX       2       // USB model only - available in the API-DLL 

//  CFG_VCCINDEX            25
#define VCC_2V2_INDEX               0       //available on the USB-MSP430-FPA version 2.x, version 3.x  
#define VCC_2V4_INDEX               1       //  -----,,,----
#define VCC_2V6_INDEX               2       //  -----,,,----    
#define VCC_2V8_INDEX               3       //  -----,,,----    
#define VCC_3V0_INDEX               4       //  -----,,,----    
#define VCC_3V2_INDEX               5       //  -----,,,----, default on the USB-MSP430-FPA version 1.x
#define VCC_3V4_INDEX               6       //  -----,,,----    
#define VCC_3V6_INDEX               7       //  -----,,,----    

//  LONG_X CustomResetPulseTime;
// CFG_CUSTOMRESETPULSETIME  26

// CFG_CUSTOMRESETIDLETIME   27
//  LONG_X CustomResetIdleTime;

//  INT_X  RstVccToggleTime;
// CFG_RSTVCCTOGGLETIME      28

//  INT_X  ApplResetVccTime;
// CFG_APPLRESETVCCTIME      29

// CFG_POP_UP_EN            30  
#define POP_UP_WARNING_DISABLE      0   
#define POP_UP_WARNING_ENABLE       1   
#define POP_UP_ALL_DISABLE          2


//  CFG_BSL_ENH_ENABLE      32
//   0-disable,  1-enable

//  CFG_BSL_ENH_INDEX       33      //valid only with the TI's MSP430 BSL version 2.0 and higher
#define BSL_ENH_DISABLE             0   //Disable access via BSL    
#define BSL_ENH_NONE                1   //Do not erase flash if the BSL password is invalid (allows to make a next try)
#define BSL_ENH_ERASE               2   //Erase whole flash if the BSL password is invalid (one try only)


//  CFG_RETAIN_CAL_DATA_INDEX   34
//   0-disable,  1-enable

//  CFG_RETAIN_DEF_DATA_INDEX   35
//   0-disable,  1-enable

//  CFG_RETAIN_START_ADDR_INDEX 36
//    data - EVEN FLASH ADDRESS

//  CFG_RETAIN_STOP_ADDR_INDEX  37
//    data - ODD FLASH ADDRESS  ( STOPADDR - STARTADDR < 256)

//  CFG_APPLPRGRUNTIME          38
//    data 0  - unlimited taime
//         1 to 120 seconds - (limited time

//  CFG_RELEASEJTAGSTATE        39
#define DEFAULT_JTAG_3ST            0
#define DEFAULT_JTAG_HI             1
#define DEFAULT_JTAG_LO             2

//  CFG_RUNTIMETDIGENEN         40
//   0-disable,  1-enable

//  CFG_RUNTIMETDIGENDIV        41
//   data 1 to 255

//  CFG_RUNTIMETDIGENPRESCALER  42
#define RUNTIMETDIPRESCALER_6MHZ        0
#define RUNTIMETDIPRESCALER_2MHZ        1

//  CFG_DCO1_CAL_ENABLE         43
//  CFG_DCO2_CAL_ENABLE         44
//  CFG_DCO3_CAL_ENABLE         45
//  CFG_DCO4_CAL_ENABLE         46
//  CFG_DCO5_CAL_ENABLE         47
//  CFG_DCO6_CAL_ENABLE         48
//  CFG_DCO7_CAL_ENABLE         49
//  CFG_DCO8_CAL_ENABLE         50
//   0-disable,  1-enable

//  CFG_DCO1_CAL_FREQ_INDEX     51
//  CFG_DCO2_CAL_FREQ_INDEX     52
//  CFG_DCO3_CAL_FREQ_INDEX     53
//  CFG_DCO4_CAL_FREQ_INDEX     54
//  CFG_DCO5_CAL_FREQ_INDEX     55
//  CFG_DCO6_CAL_FREQ_INDEX     56
//  CFG_DCO7_CAL_FREQ_INDEX     57
//  CFG_DCO8_CAL_FREQ_INDEX     58
//    range from 100 to 16000 (100kHz to 16 MHz)
//      see the MSP430 data sheet for acceptable freq range.    

//  CFG_FIRST_BSL_PASSW_INDEX   66

#define FIRST_BSL_PASSW_DEFAULT             0
#define FIRST_BSL_PASSW_FROM_PASSW_FILE     1
#define FIRST_BSL_PASSW_FROM_CODE_FILE      2
#define FIRST_BSL_PASSW_EMPTY               3

//  CFG_CS_TYPE_INDEX           69
#define CS_TYPE_NONE_INDEX              0
#define CS_TYPE_ARYTHMETIC_8r16         1
#define CS_TYPE_ARYTHMETIC_8r32         2
#define CS_TYPE_ARYTHMETIC_16r16        3
#define CS_TYPE_ARYTHMETIC_16r32        4
#define CS_TYPE_CRC16_P11021            5
#define CS_TYPE_CRC16_DEF               6
#define CS_TYPE_CRC32_STD               7
#define CS_TYPE_CRC32_DEF               8


//  CFG_CS_INIT_INDEX           70
#define CS_INIT_VALUE_0_INDEX           0
#define CS_INIT_VALUE_1_INDEX           1
#define CS_INIT_VALUE_ADDR_INDEX        2

//  CFG_CS_RESULT_INDEX         71
//    0 - "as Is", 1 - Inverted 

//  CFG_CS_CODE_OVERWIRIE_EN    72
//    0 - disable, 1 - enable

//  CFG_CS_POLYNOMINAL          73
//    Poly value

//  CFG_CS1_CALC_EN             74
//  CFG_CS2_CALC_EN             78
//  CFG_CS3_CALC_EN             82
//  CFG_CS4_CALC_EN             86
//    0 - disable, 1 - enable

//  CFG_CS1_START_ADDR          75
//  CFG_CS2_START_ADDR          79
//  CFG_CS3_START_ADDR          83
//  CFG_CS4_START_ADDR          87
//    start address value

//  CFG_CS1_END_ADDR            76
//  CFG_CS2_END_ADDR            80
//  CFG_CS3_END_ADDR            84
//  CFG_CS4_END_ADDR            88
//    end address value

//  CFG_CS1_RESULT_ADDR         77
//  CFG_CS2_RESULT_ADDR         81
//  CFG_CS3_RESULT_ADDR         85
//  CFG_CS4_RESULT_ADDR         89
//    result address value


//  CFG_FILE_FLAG_INDEX         1001
#define CFG_IGNORE_FILES            0
#define CFG_ENABLE_FILES            1


// -------- Endo of CONFIG_BLOCK - definitions ----

extern "C"
{
// ------------------   generic functions ----------------------------

  void   MSPPRG_API F_Trace_ON( void );
  void   MSPPRG_API F_Trace_OFF( void );

  INT_X  MSPPRG_API F_OpenInstances( BYTE no );
        //  number of instances to be open - from 1 to 8
        //  return   number of opened instances
  INT_X  MSPPRG_API F_CloseInstances( void );

#ifdef CSTRING_EN
  INT_X  MSPPRG_API F_OpenInstances_AndFPAs( CString FileName );
#endif
  INT_X  MSPPRG_API F_OpenInstancesAndFPAs( char * FileName );
        //  number of instances and FPA's assigment - vs FPA's Serial Number.
        //  FPAs configuration specified in the file "FileName" - full access path
        //  return   number of opened instances
        //
        //  Syntax of the FPAs configuration specified
        //  FPA-x   Serial Number
        //  where  FPA-x can be  FPA-1, FPA-2, FPA-3 .... up to FPA-8
        //   e.g  (without semicolon  - comment)
        //  FPA-1   20050116
        //  FPA-3   20050199
        //  FPA-5   20050198
        //  return   number of opened instances

  INT_X  MSPPRG_API F_Set_FPA_index( BYTE fpa );
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA

  BYTE   MSPPRG_API F_Get_FPA_index( void );
        //  return  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA

  INT_X  MSPPRG_API F_Check_FPA_index( void );
        //like F_Get_FPA_index(), but when the fpa is invalid,
        // then return FPA_INVALID_NO

  INT_X  MSPPRG_API F_LastStatus( BYTE fpa );
        //  return   last status taken from the selected fpa (fpa = 1..MAX_FPA_INDEX)
        //  fpa = 1....MAX_FPA_INDEX

  INT_X  MSPPRG_API F_DLLTypeVer( void );
        //  return   Type + Version 
        //           Type   0x1000 - Parallel Port type  
        //                  0x2000 - USB type  
        //           Version = 0x0FFF & version
        //  extra message in the report buffer 
  INT_X  MSPPRG_API F_Multi_DLLTypeVer( void );

  LONG_X MSPPRG_API F_Check_FPA_access( INT_X index );
        //  input - USB index number - 1..8
        //  return   0 - Adapter not detected   
        //           >0 - Detected's Adapter Serial Number
        //  fpa = 1....MAX_FPA_INDEX

  LONG_X MSPPRG_API F_Get_FPA_SN( BYTE fpa );
        //  return   0 - Adapter not detected   
        //           >0 - Active Adapter's Serial Number
        //  fpa = 1....MAX_FPA_INDEX

  INT_X  MSPPRG_API F_Get_FPA_Label( BYTE fpa, BYTE * label );
        //  fpa = 1....MAX_FPA_INDEX

#define ADAPTER_HARDWARE_PN_SIZE        16  
#define ADAPTER_DESCRIPTION_SIZE        32
#define FPA_LABEL_SIZE  ((ADAPTER_HARDWARE_PN_SIZE + ADAPTER_DESCRIPTION_SIZE)*sizeof(char) + 12*sizeof(BYTE) + sizeof(long))
//union FPA_LABEL
//{
//  BYTE    bytes[ FPA_LABEL_SIZE ];
//  struct
//  {
//      long  SN;
//      BYTE  hardware_ID;
//      BYTE  hardware_SubID;
//      BYTE  full_access;
//      BYTE  Interface_Type;
//      BYTE  Valid_access_key;
//      BYTE  spare3;
//      BYTE  spare4;
//      BYTE  spare5;
//      BYTE  spare6;
//      BYTE  spare7;
//      BYTE  spare8;
//      BYTE  spare9;
//      char  adapter_hardware_PN[ ADAPTER_HARDWARE_PN_SIZE ];
//      char  adapter_description[ ADAPTER_DESCRIPTION_SIZE ];
//  }x;
//};

  INT_X MSPPRG_API F_Get_Power_Results(double *xs_adc);
  #define   XS_ADC_NUM_MEMBERS 15
  /* copies members double array into xs_adc double array    
    union XS_ADC
    {
        double  members[ XS_ADC_NUM_MEMBERS ];
        struct
        {
            double ExtVcc;
            double Vcc;
            double Vpp;
            double ExtVccMin;
            double ExtVccMax;
            double VccMin;
            double VccMax;
            double Icc_mA;
            double Icc_mA_av4;
            double Icc_mA_av16;
            double Icc_mA_min;
            double Icc_mA_max;
            double Temperature;
        } data;
    };
    */


#ifdef CSTRING_EN
  void   MSPPRG_API F_API_DLL_Directory( CString APIDLLpath );
#endif
  void   MSPPRG_API F_APIDLL_Directory( char *  APIDLLpath );

  INT_X  MSPPRG_API F_Initialization( void );
        //  return   0 - FALSE
        //           1 - TRUE
        //           4 - Programmer adatper is not detected
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
        //automatically loads configuration from local config.ini file
  INT_X  MSPPRG_API F_Use_Config_INI(BYTE use);
  //Configure F_Initialization to use (default) or skip config.ini file
  //    input 1 to use config.ini, input 0 to skip
  //when skipping config.ini it is necessary to use ConfigFileLoad or SetConfig functions to
  //configure the adapter.
  //    return      0 - state unchanged
  //                1 - state changed to input parameter

  INT_X  MSPPRG_API F_ConfigSetup( CONFIG_BLOCK config );
        //  return   1 - TRUE
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
  INT_X  MSPPRG_API F_GetSetup( CONFIG_BLOCK *config );
        //  return   1 - TRUE
        //  fpa = 1....MAX_FPA_INDEX
  INT_X  MSPPRG_API F_DispSetup( void );
        //  return   1 - TRUE
        //  fpa = 1....MAX_FPA_INDEX

  INT_X  MSPPRG_API F_Get_Device_Info( INT_X index );
enum    DEVICE_INFO
{
    DEVICE_NAME                     = 0,
    DEVICE_NAME_SIZE                = 20,
    DEVICE_MAIN_FLASH_START_ADDR    = 20,
    DEVICE_MAIN_FLASH_END_ADDR      = 21,
    DEVICE_INFO_START_ADDR          = 22,
    DEVICE_INFO_SEGM_SIZE           = 23,
    DEVICE_NO_INFO_SEGMENTS         = 24,
    DEVICE_RAM_SIZE                 = 25,
    DEVICE_GROUP                    = 26,
    DEVICE_ALREADY_DEFINED          = 27,
    DEVICE_FAMILY                   = 28,
    DEVICE_HW_REVISION              = 29,
    DEVICE_FW_REVISION              = 30
};

        //  fpa = 1....MAX_FPA_INDEX
        //  return  -1 if invalid data
        //   or 
        //    index - 0 to 19  -> device name - char by char starting from index->0 => M eg.  MSP430F149   
        //       index 0 -> 'M'
        //       index 1 -> 'S'
        //       index 2 -> 'P'
        //       index 3 -> '4'
        //       index 4 -> '3'
        //       index 5 -> '0'
        //       index 6 -> 'F'
        //       index 7 -> '1'
        //       index 8 -> '4'
        //       index 9 -> '9'
        //       index 10 -> 0x0000  -> end of string
        //    index 20 -> MAIN Flash Start Address  eg 0x1100  (for F149)
        //    index 21 -> MAIN Flash End  Address   eg 0xFFFF  (for F149)
        //    index 22 -> INFO start address        eg 0x1000
        //    index 23 -> INFO segment size         eg 0x0080  (for F149)
        //    index 24 -> No of INFO segments       eg 0x0002  (for F149)
        //    index 25 -> RAM size                  eg 0x0800  (for F149)
        //    index 26 -> MCU Group                 eg 0x0001  (for F1xx)
        //    index 27 -> MCU already defined (other ID for the same MCU)  eg 0x0000  (for F149)

  INT_X  MSPPRG_API F_Close_All( void );
        //  return   1 - TRUE
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
  INT_X  MSPPRG_API F_Power_Target( INT_X OnOff );
        //  return   1 - TRUE
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
  INT_X  MSPPRG_API F_Reset_Target( void );
        //  return   1 - TRUE
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
  void   MSPPRG_API F_ReportMessage( char * text );
        //  fpa = 1....MAX_FPA_INDEX
  MSPPRG_API char* F_Report_Message( void );
        //  fpa = 1....MAX_FPA_INDEX

  INT_X  MSPPRG_API F_init_parallel_port( INT_X Parallel_Port_no );   
  // Parallel_Port_no = 0 -> LPT1,
  // Parallel_Port_no = 1 -> LPT2,
  // addresses of the LPT1 and LPT2 must be specify first in pport.ini file.
  //  return   0 - FALSE
  //           1 - TRUE   ( Parallel_Port_open )
        //  fpa = 1....MAX_FPA_INDEX

#ifdef CSTRING_EN
  INT_X  MSPPRG_API F_Read_CodeFile( INT_X file_format, CString FileName );
        //  like a F_ReadCodeFile, but with the CString - FileName
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
#endif

  INT_X  MSPPRG_API F_ReadCodeFile( INT_X file_format, char * FileName );
   // file_format   FILE_TI_FORMAT, FILE_MOTOROLA_FORMAT or FILE_INTEL_FORMAT
   // FileName - full name including path, file name and extantion
   // 
   //  return: (0xFFFe & info) | state
   //   state   0 - FALSE,  1 - TRUE           
   //   info  - warning ->  CODE_IN_ROM, CODE_IN_RAM, CODE_OUT_OF_FLASH, CODE_OVERWRITTEN
   //   info  - error ->    INVALID_CODE_FILE, OPEN_FILE_OR_READ_ERR
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA

  LONG_X MSPPRG_API F_Get_CodeCS( INT_X dest );
    // dest - 1  -> get code from the Code buffer   
    //   other dest -> reserved for future expansion  
    // return - code CS or FPA_INVALID_NO (-2, 0xFFFFFFFE)
        //  fpa = 1....MAX_FPA_INDEX

#ifdef CSTRING_EN
  INT_X  MSPPRG_API F_Read_PasswFile( INT_X file_format, CString FileName );
        //  like a F_ReadPasswFile, but with the CString - FileName
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
#endif

  INT_X  MSPPRG_API F_ReadPasswFile( INT_X file_format, char * FileName );
   // file_format   FILE_TI_FORMAT, FILE_MOTOROLA_FORMAT or FILE_INTEL_FORMAT
   // FileName - full name including path, file name and extantion
   //  return: (0xFFFe & info) | state
   //   state   0 - FALSE,  1 - TRUE           
   //   info  - error ->    INVALID_CODE_FILE, OPEN_FILE_OR_READ_ERR, PASSWORD_NOT_FOUND
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA

#ifdef CSTRING_EN  
  INT_X  MSPPRG_API F_Config_FileLoad( CString FileName );
        //  like a F_ConfigFileLoad, but with the CString - FileName
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
#endif

  INT_X  MSPPRG_API F_ConfigFileLoad( char * filename );
   // filename - full name including path, file name and extantion
   //  return: (0xFFFe & info) | state
   //   state   0 - FALSE,  1 - TRUE           
   //   info  - error ->    OPEN_FILE_OR_READ_ERR
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA

//----  generic functions - cont. - ( also some replacement for Visual Basic --------

  INT_X  MSPPRG_API F_SetConfig( INT_X index, LONG_X data );
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
  INT_X  MSPPRG_API F_Set_MCU_Name( char * MCU_name );
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
  LONG_X MSPPRG_API F_GetConfig( INT_X index );
        //  fpa = 1....MAX_FPA_INDEX
  INT_X  MSPPRG_API F_Put_Byte_to_Buffer( LONG_X addr, BYTE data );
     //  return:  0 - FALSE, 1-TRUE
            //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
  INT_X  MSPPRG_API F_Copy_Buffer_to_Flash( LONG_X start_addr, LONG_X size );
     //  return:  0 - FALSE, 1-TRUE
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
  INT_X  MSPPRG_API F_Copy_Flash_to_Buffer( LONG_X start_addr, LONG_X size );
     //  return:  0 - FALSE, 1-TRUE
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
  BYTE   MSPPRG_API F_Get_Byte_from_Buffer( LONG_X addr );
        //  fpa = 1....MAX_FPA_INDEX
  BYTE   MSPPRG_API F_GetReportMessageChar( INT_X index );
        //  fpa = 1....MAX_FPA_INDEX
  INT_X  MSPPRG_API F_Clr_Code_Buffer( void  );
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
  INT_X  MSPPRG_API F_Put_Byte_to_Code_Buffer( LONG_X addr, BYTE data );
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
  INT_X  MSPPRG_API F_Put_Byte_to_Password_Buffer( LONG_X addr, BYTE data );
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
  INT_X  MSPPRG_API F_Get_Byte_from_Code_Buffer( LONG_X addr );
        //  fpa = 1....MAX_FPA_INDEX
  INT_X  MSPPRG_API F_Get_Byte_from_Password_Buffer( LONG_X addr );
        //  fpa = 1....MAX_FPA_INDEX
  
//--------  encapsulated functions ----------------
// powering device, initialization access, fuse/password verification, 
// selected action execution, closing targed device communication

  INT_X  MSPPRG_API F_AutoProgram( INT_X mode );        // mode -> 0   value 1..up  reserved
   //  return:  0 - FALSE, 1-TRUE
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
  INT_X  MSPPRG_API F_VerifyFuseOrPassword( void );
   //  return:  0 - FALSE, 1-TRUE
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
  INT_X  MSPPRG_API F_Memory_Erase( INT_X mode );       //mode-> 0 -> erase space specify by the FlashEraseModeIndex;
                                                    //mode-> 1 -> erase all Flash memory, regardless FlashEraseModeIndex;
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
   //  return:  0 - FALSE, 1-TRUE
  INT_X  MSPPRG_API F_Memory_Blank_Check( void );
   //  return:  0 - FALSE, 1-TRUE
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
  INT_X  MSPPRG_API F_Memory_Write( INT_X mode );       // mode -> 0   value 1..up  reserved
   //  return:  0 - FALSE, 1-TRUE
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
  INT_X  MSPPRG_API F_Memory_Verify( INT_X mode );  // mode -> 0   value 1..up  reserved
   //  return:  0 - FALSE, 1-TRUE
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
  INT_X  MSPPRG_API F_Memory_Read( unsigned char * data );
     //  return:  0 - FALSE, 1-TRUE
        //  fpa = 1....MAX_FPA_INDEX
  INT_X  MSPPRG_API F_Copy_All_Flash_to_Buffer( void );
     //  return:  0 - FALSE, 1-TRUE
     //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
     //  similar to F_Memory_Read(..) but results are in the internal buffers
     //  use F_Set_FPA_index( BYTE fpa );
     //  and F_Get_Byte_from_Buffer( LONG_X addr ) to read contents;

  INT_X  MSPPRG_API F_Restore_JTAG_Security_Fuse( void );
     //  return:  0 - FALSE, 1-TRUE
     //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA

//--------  end of encapsulated functions ---------

  INT_X  MSPPRG_API F_Open_Target_Device( void );
  INT_X  MSPPRG_API F_Open_Targed_Device( void );   //keeped for back compatible
   //  return:  0 - FALSE, 1-TRUE, 2-JTAG security fuse blown
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
  INT_X  MSPPRG_API F_Close_Target_Device( void );
  INT_X  MSPPRG_API F_Close_Targed_Device( void );
     //  return:  0 - FALSE, 1-TRUE
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA

//--------  sequential functions ----------------
//  F_Open_Targed_Device( void ) must be called first

  INT_X  MSPPRG_API F_Segment_Erase( LONG_X address );
     //  return:  0 - FALSE, 1-TRUE
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
  INT_X  MSPPRG_API F_Get_Sector_Size( LONG_X address );
  //returns <sector size> for sector that includes given address
  //returns 0 for incorrect addresses (address that does not fit within any sector)

  INT_X  MSPPRG_API F_Sectors_Blank_Check( LONG_X start_addr, LONG_X stop_addr );
   //  return:  0 - FALSE, 1-TRUE
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
  INT_X  MSPPRG_API F_Memory_Write_Data( LONG_X start_addr, INT_X size, unsigned char *data );
     //  return:  0 - FALSE, 1-TRUE
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
  INT_X  MSPPRG_API F_Memory_Read_Data( LONG_X start_addr, INT_X size, unsigned char *data );
     //  return:  0 - FALSE, 1-TRUE
        //  fpa = 1....MAX_FPA_INDEX
  INT_X  MSPPRG_API F_Blow_Fuse( void );
     //  return:  0 - FALSE, 1-TRUE
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA

     //---- functions prepared for access the test/calibration routines -----

  INT_X  MSPPRG_API F_Write_Word( LONG_X addr, INT_X data );
    // write word to any location of RAM, registers etc. Write to flash space has no effect 
    // valid with JTAG communication only
    //  return:  0 - FALSE, 1-TRUE
    //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA

  INT_X  MSPPRG_API F_Read_Word( LONG_X addr );
    // read word from any location of RAM, Flash, registers etc.
    // valid with JTAG communication only
    //  return:  data
    //  fpa = 1....MAX_FPA_INDEX

  INT_X  MSPPRG_API F_Write_Byte( LONG_X addr, BYTE data );
    // write byte to any location of RAM, registers etc. Write to flash space has no effect 
    // valid with JTAG communication only
    //  return:  0 - FALSE, 1-TRUE
    //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA

  BYTE   MSPPRG_API F_Read_Byte( LONG_X addr );
    // read byte from any location of RAM, Flash, registers etc.
    // valid with JTAG communication only
    //  return:  data
    //  fpa = 1....MAX_FPA_INDEX

  INT_X  MSPPRG_API F_Copy_Buffer_to_RAM( LONG_X start_addr, LONG_X size );
     //  return:  0 - FALSE, 1-TRUE
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA
  INT_X  MSPPRG_API F_Copy_RAM_to_Buffer( LONG_X start_addr, LONG_X size );
     //  return:  0 - FALSE, 1-TRUE
        //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA

  INT_X  MSPPRG_API F_Set_PC_and_RUN( LONG_X PC_addr );
    // valid with JTAG communication only
    //  return:  0 - FALSE, 1-TRUE
    //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA

  INT_X  MSPPRG_API F_Capture_PC_Addr( void );
    // valid with JTAG communication only
    //  return:  0 - FALSE, >0  Captured PC address
    //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA

  INT_X  MSPPRG_API F_Synch_CPU_JTAG( void );
    // valid with JTAG communication only
    //  return:  0 - FALSE, 1-TRUE
    //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA

     //---- misc functions  -----

  INT_X  MSPPRG_API F_Adj_DCO_Frequency( INT_X freq_Hz );
    //  freq_Hz - requested DCO freq. in Hz  - range 100000 to 16000000  (0.1 to 16 MHz)
    //  return:  DCO register value or -1 - FALSE
    //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA

  INT_X  MSPPRG_API F_Test_DCO_Frequency( INT_X  DCO_constant );
    //  test the DCO freq for the DCO_constant word (2 bytes).  
    //   DCO_constant in the same order as it is saved in INFO-A
    //  return:  frequency in Hz or -1 ->FALSE
    //  fpa = 1....MAX_FPA_INDEX  or  0 -> ALL_ACTIVE_FPA

  INT_X  MSPPRG_API F_Get_Targets_Vcc( void );
        //  return   -1 - no communication with FPA
        //  return   0 and up - Vcc in milivolts
        //  fpa = 1....MAX_FPA_INDEX

  void   MSPPRG_API F_Disable_FPA_index( BYTE fpa );
        // FPA - index no (1..MAX_FPA_INDEX)
  void   MSPPRG_API F_Enable_FPA_index( BYTE fpa );
        // FPA - index no (1..MAX_FPA_INDEX)

  INT_X  MSPPRG_API F_Set_fpa_io_state( BYTE jtag, BYTE reset, BYTE VccOn );
        //  jtag ->  TMS, TCK, TDI (output from FPA)
        //          DEFAULT_JTAG_3ST   ( 0 )
        //          DEFAULT_JTAG_HI    ( 1 )
        //          DEFAULT_JTAG_LO    ( 2 )
        // reset ->  0  -> output from FPA RESET - LO 
        //           1  -> output from FPA RESET - HI 
        // VccOn ->  0  -> output Vcc from FPA - OFF
        //           1  -> output Vcc from FPA - ON (level 2.2V to 3.6V set in CFG_VCCINDEX )

  INT_X  MSPPRG_API F_Customize( INT_X dest, INT_X data );

  void  MSPPRG_API  F_init_custom_jtag( INT_X state, INT_X Vcc_index );
        //  fpa = 1....MAX_FPA_INDEX

  INT_X  MSPPRG_API F_custom_jtag_stream( INT_X mode, INT_X size, BYTE * data_out, BYTE * data_in );
     //  return:  0 - FALSE, 1-TRUE
     //  fpa = 1....MAX_FPA_INDEX

  INT_X  MSPPRG_API F_Custom_Function( INT_X type );
enum    CUSTOM_FUNCTION
{
    CUSTOM_FUNCTION_UART_9600   =   1,
    CUSTOM_FUNCTION_UART_57K6   =   2,
    UART_TX_SIZE_ADDR           =   0,
    UART_RX_SIZE_ADDR           =   1,
    UART_BUFFER_START_ADDR      =   0x10,
    UART_BUFFER_SIZE            =   56
};
     // type    1 - UART  9.6 kb/s
     //         2 - UART 38.4 kb/s
     //return:  0 - FALSE, 1-TRUE,   -1 (0xFFFFFFFF) -not supported
     //   fpa = 1....MAX_FPA_INDEX

    //Iterate over configuration names, starting from <index> 0.  Increase <index> until return is "\0".
    //Will return char array with name of config parameter or "\0" once <index> is too high.
    MSPPRG_API char *   F_Get_Config_Name_List( INT_X index );

    //Use F_Get_Config_Name_List to get configuration parameter names, then use them as input 
    //to this function.  Select type to determine action:
    //#define       CONFSEL_VALIDATE    0 - returns TRUE if <name> was found in config list
    //#define       CONFSEL_VALUE       1 - returns current value of config parameter
    //#define       CONFSEL_MIN         2 - returns minimum value that this config parameter can have
    //#define       CONFSEL_MAX         3 - returns maximum value that this config parameter can have
    //#define       CONFSEL_DEFAULT     4 - returns default value for this parameter if not set by user/file
    //returns FALSE if invalid <name> given
    unsigned int MSPPRG_API F_Get_Config_Value_By_Name(char *name, int type);

    //Use F_Get_Config_Name_List to get configuration parameter names, then use them as input 
    //to this function.  Use F_Get_Config_Value_By_Name to get proper ranges for config values.
    //
    //Set new value for configuration parameter identified by <name>.
    //If the config parameter is out of range, it will be reset to default value.
    //Returns TRUE if <name> was a valid, or FALSE if <name> was invalid
    //Run F_Get_Config_Value_By_Name(<name>, CONFSEL_VALUE) after to verify change of configuration parameter.
    INT_X   MSPPRG_API F_Set_Config_Value_By_Name(char *name, unsigned int newValue);
    //--------  end of sequential functions ---------

    INT_X  MSPPRG_API   F_GetProgressBar( BYTE fpa );
    //Only for encapsulated functions
    //General function that only reads current value of progress bar between 0 and 100.  Thread-safe
    //One thread can call F_AutoProgram (for example) and another thread can monitor progress by calling
    //F_GetProgressBar
  
    INT_X  MSPPRG_API   F_GetLastOpCode( BYTE fpa );
    #define PROG_OPCODE_VERIFY_ACCESS               1
    #define PROG_OPCODE_FLASH_ERASE                 2
    #define PROG_OPCODE_FLASH_BLANK_CHECK           3
    #define PROG_OPCODE_FLASH_SELECTED_BLANK_CHECK  4
    #define PROG_OPCODE_FLASH_WRITE                 5
    #define PROG_OPCODE_FLASH_VERIFY                6
    #define PROG_OPCODE_FLASH_READ                  7
    #define PROG_OPCODE_LOCK_MCU                    8
    #define PROG_OPCODE_UNLOCK_MCU                  9
    #define PROG_OPCODE_START_APP                   10
    //Only for ecapsulated functions
    //General function that reads code for last operation performed. Useful for providing comments for ProgressBar and 
    //when AutoProgram fails half way to indicate which sub-operation failed. Thread-safe
    //
    //One thread can call F_AutoProgram (for example) and another thread can monitor progress of sub-operations
    //by calling F_GetProgressBar and F_GetLastOpCode. F_AutoProgram will usually go through all of these sub-operations 
    //in seqeuence, each progressing from 0 to 100. If the blank-check sub-operation fails in F_AutoProgram, then this 
    //function will keep returning PROG_OPCODE_FLASH_BLANK_CHECK after F_AutoProgram returns FAIL.
}

#ifndef __GNUC__
#ifdef  MSWIN_API
  BOOL   __stdcall  DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved);
#endif  

// list of instruction used in Visual Basic -
// comments - see list instructions above with the same name 
//   with prefix F_ instead VB_ 

INT_X   __stdcall   VB_OpenInstances( BYTE no );
INT_X   __stdcall   VB_CloseInstances( void );
#ifdef CSTRING_EN  
INT_X   __stdcall   VB_OpenInstances_AndFPAs( CString FileName );
#endif
INT_X   __stdcall   VB_OpenInstancesAndFPAs( char * FileName );
INT_X   __stdcall   VB_Set_FPA_index( BYTE fpa );
BYTE    __stdcall   VB_Get_FPA_index( void );
INT_X   __stdcall   VB_Check_FPA_index( void );
INT_X   __stdcall   VB_LastStatus( BYTE fpa );
INT_X   __stdcall   VB_DLLTypeVer( void );
INT_X   __stdcall   VB_Multi_DLLTypeVer( void );
LONG_X  __stdcall   VB_Check_FPA_access( INT_X index );
LONG_X  __stdcall   VB_Get_FPA_SN( BYTE fpa );
INT_X   __stdcall   VB_Get_FPA_Label( BYTE fpa, BYTE * label );
INT_X   __stdcall   VB_Initialization( void );
INT_X   __stdcall   VB_DispSetup( void );
INT_X   __stdcall   VB_Get_Device_Info( INT_X index );
INT_X   __stdcall   VB_Close_All( void );
INT_X   __stdcall   VB_Power_Target( INT_X OnOff );
INT_X   __stdcall   VB_Reset_Target( void );
INT_X   __stdcall   VB_init_parallel_port( INT_X Parallel_Port_no );   
#ifdef CSTRING_EN  
INT_X   __stdcall   VB_Read_CodeFile( INT_X file_format, CString FileName );
#endif
LONG_X  __stdcall   VB_Get_CodeCS( INT_X dest );
INT_X   __stdcall   VB_ReadCodeFile( INT_X file_format, char * FileName );
#ifdef CSTRING_EN  
INT_X   __stdcall   VB_Read_PasswFile( INT_X file_format, CString FileName );
#endif
INT_X   __stdcall   VB_ReadPasswFile( INT_X file_format, char * FileName );
#ifdef CSTRING_EN 
INT_X   __stdcall   VB_Config_FileLoad( CString filename );
#endif
INT_X   __stdcall   VB_ConfigFileLoad( char * filename );
INT_X   __stdcall   VB_AutoProgram( INT_X mode );
INT_X   __stdcall   VB_VerifyFuseOrPassword( void );
INT_X   __stdcall   VB_Memory_Erase( INT_X mode );
INT_X   __stdcall   VB_Memory_Blank_Check( void );
INT_X   __stdcall   VB_Memory_Write( INT_X mode );
INT_X   __stdcall   VB_Memory_Verify( INT_X mode );
INT_X   __stdcall   VB_Restore_JTAG_Security_Fuse( void );
INT_X   __stdcall   VB_Open_Target_Device( void );
INT_X   __stdcall   VB_Open_Targed_Device( void );      //keeped for back compatible
INT_X   __stdcall   VB_Close_Target_Device( void );
INT_X   __stdcall   VB_Close_Targed_Device( void );     //keeped for back compatible
INT_X   __stdcall   VB_Segment_Erase( LONG_X address );
INT_X   __stdcall   VB_Get_Sector_Size( LONG_X address );
INT_X   __stdcall   VB_Sectors_Blank_Check( LONG_X start_addr, LONG_X stop_addr );
INT_X   __stdcall   VB_Blow_Fuse( void );
INT_X   __stdcall   VB_Write_Word( LONG_X addr, INT_X data );
INT_X   __stdcall   VB_Read_Word( LONG_X addr );
INT_X   __stdcall   VB_Write_Byte( LONG_X addr, BYTE data );
BYTE    __stdcall   VB_Read_Byte( LONG_X addr );
INT_X   __stdcall   VB_SetConfig( INT_X index, LONG_X data );
INT_X   __stdcall   VB_Set_MCU_Name( char * MCU_name );
LONG_X  __stdcall   VB_GetConfig( INT_X index );
INT_X   __stdcall   VB_Put_Byte_to_Buffer( LONG_X addr, BYTE data );
INT_X   __stdcall   VB_Copy_Buffer_to_Flash( LONG_X start_addr, LONG_X size );
INT_X   __stdcall   VB_Copy_Flash_to_Buffer( LONG_X start_addr, LONG_X size );
INT_X   __stdcall   VB_Copy_All_Flash_to_Buffer( void );
BYTE    __stdcall   VB_Get_Byte_from_Buffer( LONG_X addr );
BYTE    __stdcall   VB_GetReportMessageChar( INT_X index );
INT_X   __stdcall   VB_Clr_Code_Buffer( void );
INT_X   __stdcall   VB_Put_Byte_to_Code_Buffer( LONG_X addr, BYTE data );
INT_X   __stdcall   VB_Put_Byte_to_Password_Buffer( LONG_X addr, BYTE data );
INT_X   __stdcall   VB_Get_Byte_from_Code_Buffer( LONG_X addr );
INT_X   __stdcall   VB_Get_Byte_from_Password_Buffer( LONG_X addr );
INT_X   __stdcall   VB_Copy_Buffer_to_RAM( LONG_X start_addr, LONG_X size );
INT_X   __stdcall   VB_Copy_RAM_to_Buffer( LONG_X start_addr, LONG_X size );
INT_X   __stdcall   VB_Set_PC_and_RUN( LONG_X PC_addr );
INT_X   __stdcall   VB_Capture_PC_Addr( void );
INT_X   __stdcall   VB_Synch_CPU_JTAG( void );
INT_X   __stdcall   VB_Get_Targets_Vcc( void );
void    __stdcall   VB_Disable_FPA_index( BYTE fpa );
void    __stdcall   VB_Enable_FPA_index( BYTE fpa );
INT_X   __stdcall   VB_Set_fpa_io_state( BYTE jtag, BYTE reset, BYTE VccOn );
void    __stdcall   VB_Trace_ON( void );
void    __stdcall   VB_Trace_OFF( void );
void    __stdcall   VB_init_custom_jtag( INT_X state, INT_X Vcc_index );
BYTE    __stdcall   VB_custom_jtag_stream( INT_X mode, INT_X size, char * data_out );
INT_X   __stdcall   VB_Custom_Function( INT_X type );
INT_X   __stdcall   VB_Adj_DCO_Frequency( INT_X freq_Hz );
INT_X   __stdcall   VB_Test_DCO_Frequency( INT_X DCO_constant );
INT_X   __stdcall   VB_Customize( INT_X dest, INT_X data );
INT_X   __stdcall   VB_Get_Power_Results(double *xs_adc);
INT_X   __stdcall   VB_GetProgressBar( BYTE fpa );
INT_X   __stdcall   VB_GetLastOpCode( BYTE fpa );  

#endif//__GNUC__
#endif
