#ifndef __I_MAGC__
#define __I_MAGC__

typedef unsigned int    UINT;   /* int must be 16-bit or 32-bit */
typedef unsigned char   BYTE;   /* char must be 8-bit */
typedef uint16_t        WORD;   /* 16-bit unsigned integer */
typedef uint32_t        DWORD;  /* 32-bit unsigned integer */
typedef uint64_t        QWORD;  /* 64-bit unsigned integer */
typedef WORD            WCHAR;  /* UTF-16 character type */

#include "pico.h"

/*
 *
 */
#define DCS_SOFT_RESET                 0x01
#define DCS_EXIT_SLEEP_MODE            0x11
#define DCS_EXIT_INVERT_MODE           0x20
#define DCS_ENTER_INVERT_MODE          0x21
#define DCS_SET_DISPLAY_ON             0x29
#define DCS_SET_COLUMN_ADDRESS         0x2A
#define DCS_SET_PAGE_ADDRESS           0x2B
#define DCS_WRITE_MEMORY_START         0x2C
#define DCS_SET_ADDRESS_MODE           0x36
#define DCS_SET_PIXEL_FORMAT           0x3A
#define DCS_WRITE_DISPLAY_BRIGHTNESS    0x51
#define DCS_GAMMA_SET                   0x26

#define DCS_PIXEL_FORMAT_16BIT         0x55 /* 0b01010101 */
#define DCS_PIXEL_FORMAT_8BIT          0x22 /* 0b00100010 */

#define DCS_ADDRESS_MODE_MIRROR_Y      0x80
#define DCS_ADDRESS_MODE_MIRROR_X      0x40
#define DCS_ADDRESS_MODE_SWAP_XY       0x20
#define DCS_ADDRESS_MODE_BGR           0x08
#define DCS_ADDRESS_MODE_RGB           0x00
#define DCS_ADDRESS_MODE_FLIP_X        0x02


//ig #define    DISPLAY_SPI_CLOCK_SPEED_HZ 63000000
#define    DISPLAY_SPI_CLOCK_SPEED_HZ 60000000

#define    DISPLAY_PIXEL_FORMAT DCS_PIXEL_FORMAT_16BIT

// #ifdef ILI9341
// #define    DISPLAY_ADDRESS_MODE DCS_ADDRESS_MODE_RGB | DCS_ADDRESS_MODE_SWAP_XY
// #endif
// #ifdef ST7789
// //#define    DISPLAY_ADDRESS_MODE DCS_ADDRESS_MODE_RGB | DCS_ADDRESS_MODE_SWAP_XY | DCS_ADDRESS_MODE_MIRROR_Y
// // #define    DISPLAY_ADDRESS_MODE  DCS_ADDRESS_MODE_BGR | DCS_ADDRESS_MODE_SWAP_XY | DCS_ADDRESS_MODE_MIRROR_Y
// //#define    DISPLAY_ADDRESS_MODE DCS_ADDRESS_MODE_RGB | DCS_ADDRESS_MODE_SWAP_XY
// #define    DISPLAY_ADDRESS_MODE DCS_ADDRESS_MODE_BGR | DCS_ADDRESS_MODE_SWAP_XY |DCS_ADDRESS_MODE_MIRROR_Y
// #endif

// #define    DISPLAY_OFFSET_X 0
// #define    DISPLAY_OFFSET_Y 0

// #ifdef ILI9341
// #define    DISPLAY_WIDTH 320
// #define    DISPLAY_HEIGHT 240
// #endif
// #ifdef ST7789
// //#define    DISPLAY_WIDTH 160
// //#define    DISPLAY_HEIGHT 128
// #define    DISPLAY_WIDTH 320
// #define    DISPLAY_HEIGHT 240

// #endif



#define    DISPLAY_ADDRESS_MODE DCS_ADDRESS_MODE_RGB | DCS_ADDRESS_MODE_SWAP_XY |DCS_ADDRESS_MODE_MIRROR_X |DCS_ADDRESS_MODE_MIRROR_Y
#define    DISPLAY_OFFSET_X 0
#define    DISPLAY_OFFSET_Y 0
#define    DISPLAY_WIDTH 320
#define    DISPLAY_HEIGHT 240
#define    DISPLAY_INVERT true


const uint LED_PIN = PICO_DEFAULT_LED_PIN;

/*
 *
 */
// wv 2.8
 // ig added sd 5  18 19 20 21 22
// ig added ts 16 17
// ig added lcd 8 9 10 11 12 13 15
//#define UP 9 lcd cs

// wv 1.69 6,7 21-24 tp
// 2 buzz 
// 18 buzz 
//23 24 int1 int2
//i2c1 6,7
// 14 15 sys out en
// 29 bat
// pins 0,1 16,17 20,26,27,28
// #define UP 21
#define UP 0 // was 21 but tp
//ig #define DN 5 is it cs for sd
#define DN 1 // was 5 unused
// #define LT 8 lcd_cd
#define LT 14 // moved from 16 (touch CS)
#define RT 18 // moved from 17 (touch IRQ)
#define SL 5  // moved from 28 (I2S DATA)
#define ST 6  // moved from 27 (I2S LRCK)
#define A 7   // moved from 26 (I2S BCK)
#define B 20 // was 3 unused

#endif
