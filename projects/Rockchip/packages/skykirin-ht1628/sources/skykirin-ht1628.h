#ifndef SKYKIRIN_HT1628_H
#define SKYKIRIN_HT1628_H



#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <time.h>


//
//       A
//      ____
//    |      |
//  F |   G  |  B
//     ______
//    |      |
//  E |      |  C
//      ____
//        D



#define S7_A    0x001 
#define S7_B    0x002
#define S7_C    0x004
#define S7_D    0x008 
#define S7_E    0x010
#define S7_F    0x020
#define S7_G    0x040

//Mask for blending out and setting 7 segments digits
#define MASK_7S_ALL = (S7_A | S7_B | S7_C | S7_D | S7_E | S7_F | S7_G}

//Icons Grid 1
#define S7_LD2  0x0001
#define S7_LD1  0x0002
#define S7_CD   0x0008
#define S7_DVD  0x0010
#define S7_PSE  0x0020
#define S7_PLY  0x0040
#define S7_COL2 0x0080
#define S7_MP4  0x0100
#define S7_MP3  0x0200
#define S7_ICON_GR1 (S7_LD2 | S7_LD1 | S7_CD | S7_DVD | S7_PSE | S7_PLY | S7_COL2 | S7_MP4 | S7_MP3)

//Icons Grid 2
#define S7_ICON_GR2 (0x0000)

//Icons Grid 3
#define S7_ICON_GR3 (0x0000)

//Icons Grid 4
#define S7_ICON_GR4 (0x0000)

//Icons Grid 5
#define S7_ICON_GR5 (0x0000)

//Icons Grid 6
#define S7_ICON_GR6 (0x0000)

//Icons Grid 7
#define S7_ICON_GR7 (0x0000)

//Mask for blending out and restoring Icons
//One mask pattern will be sufficient assuming that all digits use the same mapping.
//#define S_ICON_MSK (0x0000)

//Mask for blending out and restoring Icons
extern const char MASK_ICON_GRID[][2]; 

// ASCII Font definitions for segments in each character
//
//32 0x20  Symbols
#define C7_SPC  (0x0000)
//#define C_CMA  (S_DP)
//#define C_DPT  (S_DP)
#define C7_MIN  (S7_G)

//48 0x30 digits
#define C7_0    (S7_A | S7_B | S7_C | S7_D | S7_E | S7_F)
#define C7_1    (S7_B | S7_C)
#define C7_2    (S7_A | S7_B | S7_D | S7_E | S7_G)
#define C7_3    (S7_A | S7_B | S7_C | S7_D | S7_G)
#define C7_4    (S7_B | S7_C | S7_F | S7_G)
#define C7_5    (S7_A | S7_C | S7_D | S7_F | S7_G)
#define C7_6    (S7_A | S7_C | S7_D | S7_E | S7_F | S7_G)
#define C7_7    (S7_A | S7_B | S7_C)
#define C7_8    (S7_A | S7_B | S7_C | S7_D | S7_E | S7_F | S7_G)
#define C7_9    (S7_A | S7_B | S7_C | S7_D | S7_F | S7_G)
//64 0x40
#define C7_A    (S7_A | S7_B | S7_C | S7_E | S7_F | S7_G )  // Upper case alphabet
#define C7_B    (S7_C | S7_D | S7_E | S7_F | S7_G)
#define C7_C    (S7_A | S7_D | S7_E | S7_F)
#define C7_D    (S7_B | S7_C | S7_D | S7_E | S7_G)
#define C7_E    (S7_A | S7_D | S7_E | S7_F | S7_G)
#define C7_F    (S7_A | S7_E | S7_F | S7_G)
#define C7_G    (S7_A | S7_B | S7_C | S7_F | S7_G)
#define C7_H    (S7_B | S7_C | S7_E | S7_F | S7_G)
#define C7_I    (S7_B | S7_C)
#define C7_J    (S7_B | S7_C | S7_D)
#define C7_K    (S7_E | S7_F | S7_G)
#define C7_L    (S7_D | S7_E | S7_F)
#define C7_M    (S7_C | S7_E | S7_G)
#define C7_N    (S7_C | S7_E | S7_G)
#define C7_O    (S7_A | S7_B | S7_C | S7_D | S7_E | S7_F)
#define C7_P    (S7_A | S7_B | S7_E | S7_F | S7_G)
#define C7_Q    (S7_A | S7_B | S7_C | S7_F | S7_G)
#define C7_R    (S7_E | S7_G)
#define C7_S    (S7_A | S7_C | S7_D | S7_F | S7_G)
#define C7_T    (S7_D | S7_E | S7_F | S7_G)
#define C7_U    (S7_B | S7_C | S7_D | S7_E | S7_F)
#define C7_Y    (S7_B | S7_C | S7_D | S7_F | S7_G)
#define C7_Z    (S7_A | S7_B | S7_D | S7_E | S7_G)

//97 0x61  Lower case alphabet
#define C7_a     C7_A
#define C7_b     C7_B
#define C7_c     C7_C
#define C7_d     C7_D
#define C7_e     C7_E
#define C7_f     C7_H
#define C7_g     C7_G
#define C7_h     C7_H
#define C7_i     C7_I
#define C7_j     C7_J
#define C7_k     C7_K
#define C7_l     C7_L
#define C7_m     C7_M
#define C7_n     C7_N
#define C7_o     C7_O
#define C7_p     C7_P
#define C7_q     C7_Q
#define C7_r     C7_R
#define C7_s     C7_S
#define C7_t     C7_T
#define C7_u     C7_U
#define C7_y     C7_Y
#define C7_z     C7_Z



const unsigned short HT1628_DIG_REG[8] = {0xC0,0xC2,0xC4,0xC6,0xC8,0x0,0x0,0x0};
//                                 0   1   2     3    4    5    6    7   8    9    A   B   C   D   E  F
const unsigned short display_num[16] = {0x3F,0x6,0x5B,0x4F,0x66,0x6D,0x7D,0x7,0x7F,0x6F,C7_A,C7_B,C7_C,C7_D,C7_E,C7_F};

//                                     A   B   C   D     E     F    G    T   L
const unsigned short display_letter[26] = {C7_A,C7_B,C7_C,C7_D,C7_E,C7_F,C7_G,C7_H,C7_I,C7_J,C7_K,C7_L,C7_M,C7_N,C7_O,C7_P,C7_Q,C7_R,C7_S,C7_T,C7_U,0x0,0x0,0x0,C7_Y,C7_Z};

#define IOCTL_MAGIC 'k'
#define DISPLAY_OFF 10
#define DISPLAY_ON 9
#define DISPLAY_LAN_ON 7 
#define DISPLAY_LAN_OFF 8 
#define DISPLAY_WIFI_ON_1 3 
#define DISPLAY_WIFI_ON_2 4
#define DISPLAY_WIFI_ON_3 5 
#define DISPLAY_WIFI_ON_4 6
#define DISPLAY_DOT_ON 2
#define DISPLAY_SET_UNKNOWN 0
#define DISPLAY_SET_TIME 1
#define DISPLAY_WIFI_ON_HALF 11
#define DISPLAY_WIFI_ON_FULL 12
#define DISPLAY_WIFI_OFF 13
#define DISPLAY_POWER_ON 14









//the ioctl use in ioctl function

#define HT1628_DISP_ON     _IO(IOCTL_MAGIC,DISPLAY_ON)
#define HT1628_DISP_OFF    _IO(IOCTL_MAGIC,DISPLAY_OFF)
#define HT1628_DISP_SET_LAN_ON _IO(IOCTL_MAGIC,DISPLAY_LAN_ON)
#define HT1628_DISP_SET_LAN_OFF _IO(IOCTL_MAGIC,DISPLAY_LAN_OFF)
#define HT1628_DISP_WIFI_ON_L3 _IO(IOCTL_MAGIC,DISPLAY_WIFI_ON_3)
#define HT1628_DISP_WIFI_ON_L4 _IO(IOCTL_MAGIC,DISPLAY_WIFI_ON_4)
#define HT1628_DISP_DOT_ON     _IO(IOCTL_MAGIC,DISPLAY_DOT_ON)
#define HT1628_DISP_SET_TIME   _IOW(IOCTL_MAGIC,DISPLAY_SET_TIME,unsigned long)
#define HT1628_DISP_SET_UNKNOWN _IOW(IOCTL_MAGIC,DISPLAY_SET_UNKNOWN,unsigned long)
#define HT1628_DISP_WIFI_ON_FULL _IO(IOCTL_MAGIC,DISPLAY_WIFI_ON_FULL) //wifi 2 on
#define HT1628_DISP_WIFI_ON_HALF _IO(IOCTL_MAGIC,DISPLAY_WIFI_ON_HALF) //wifi 1 on
#define HT1628_DISP_WIFI_OFF     _IO(IOCTL_MAGIC,DISPLAY_WIFI_OFF) //wifi 2 off
#define HT1628_DISP_POWER_ON	_IO(IOCTL_MAGIC,DISPLAY_POWER_ON) //poweron


























#endif
