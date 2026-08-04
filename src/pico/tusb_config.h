/* 
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Ha Thach (tinyusb.org)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#ifndef _TUSB_CONFIG_H_
#define _TUSB_CONFIG_H_

#ifdef __cplusplus
 extern "C" {
#endif

//--------------------------------------------------------------------
// COMMON CONFIGURATION
//--------------------------------------------------------------------

#ifndef CFG_TUSB_MCU
  #define CFG_TUSB_MCU OPT_MCU_RP2350
#endif

// Вмикаємо режим HOST, оскільки ви використовуєте TinyUSB для підключення пристроїв (миші/клавіатури)
#define CFG_TUSB_RHPORT0_MODE       OPT_MODE_HOST

// --- НАЛАШТУВАННЯ PIO-USB ---
// Вказуємо, що порт 0 працює через програмний драйвер PIO-USB
#define CFG_TUSB_RHPORT0_PIO_USB    1

// Налаштування пінів для Pico-PIO-USB
#ifndef PICO_DEFAULT_PIO_USB_DP_PIN
  #define PICO_DEFAULT_PIO_USB_DP_PIN   2   // D+ на GP2 (D- автоматично стане на GP3)
#endif
// ----------------------------

#ifndef CFG_TUSB_OS
#define CFG_TUSB_OS                 OPT_OS_NONE
#endif

// CFG_TUSB_DEBUG is defined by compiler in DEBUG build
// #define CFG_TUSB_DEBUG           0

/* USB DMA on some MCUs can only access a specific SRAM region with restriction on alignment.
 * Tinyusb use follows macros to declare transferring memory so that they can be put
 * into those specific section.
 * e.g
 * - CFG_TUSB_MEM SECTION : __attribute__ (( section(".usb_ram") ))
 * - CFG_TUSB_MEM_ALIGN   : __attribute__ ((aligned(4)))
 */
#ifndef CFG_TUSB_MEM_SECTION
#define CFG_TUSB_MEM_SECTION
#endif

#ifndef CFG_TUSB_MEM_ALIGN
#define CFG_TUSB_MEM_ALIGN          __attribute__ ((aligned(4)))
#endif

#define USB_MAX_ENDPOINTS 4

//--------------------------------------------------------------------
// CONFIGURATION (HOST MODE)
//--------------------------------------------------------------------

#define CFG_TUH_ENUMERATION_BUFSIZE 256  // Збільшено для кращої сумісності з пристроями

#define CFG_TUH_HUB                 1
#define CFG_TUH_CDC                 0
#define CFG_TUH_MSC                 0
#define CFG_TUH_VENDOR              0

// Налаштування для підтримки клавіатури/миші (HID)
#define CFG_TUH_DEVICE_MAX          (CFG_TUH_HUB ? 4 : 1) 
#define CFG_TUH_HID                 4 

//------------- HID -------------//
#define CFG_TUH_HID_EPIN_BUFSIZE    64
#define CFG_TUH_HID_EPOUT_BUFSIZE   64

#ifdef __cplusplus
 }
#endif

#endif /* _TUSB_CONFIG_H_ */