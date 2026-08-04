add_library(common_pico INTERFACE)
target_sources(common_pico INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/i_glob.c
        ${CMAKE_CURRENT_LIST_DIR}/i_input.c
        ${CMAKE_CURRENT_LIST_DIR}/i_system.c
        ${CMAKE_CURRENT_LIST_DIR}/piconet.c
        ${CMAKE_CURRENT_LIST_DIR}/i_timer.c
        ${CMAKE_CURRENT_LIST_DIR}/i_video.c
        ${CMAKE_CURRENT_LIST_DIR}/stubs.c

        ${CMAKE_CURRENT_LIST_DIR}/i_picosound.c
)
if (PICO_ON_DEVICE)
    target_sources(common_pico INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/blit.S
            ${CMAKE_CURRENT_LIST_DIR}/picoflash.c
            ${CMAKE_CURRENT_LIST_DIR}/picofs.c
            )
    pico_wrap_function(common_pico malloc)
    pico_wrap_function(common_pico calloc)
    pico_wrap_function(common_pico free)
    target_compile_definitions(common_pico INTERFACE
            PICO_HEAP_SIZE=0
            USE_ZONE_FOR_MALLOC=1
    )
    
    target_link_libraries(common_pico INTERFACE  hardware_i2c)
endif()
target_include_directories(common_pico INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/..
        ${CMAKE_CURRENT_LIST_DIR}/../../textscreen
        )

target_compile_definitions(common_pico INTERFACE
        NO_USE_MOUSE=1
        YELLOW_SUBMARINE=0
        #dahai
        #PICO_AUDIO_I2S_PIO=1
        PICO_AUDIO_I2S_PIO=2
        PICO_AUDIO_I2S_DMA_IRQ=1
        )

pico_generate_pio_header(common_pico ${CMAKE_CURRENT_LIST_DIR}/video_doom.pio)
target_link_libraries(common_pico INTERFACE pico_stdlib pico_multicore pico_scanvideo_dpi)

add_library(pico_cd INTERFACE)
if (TARGET tinyusb_host)
    target_link_libraries(pico_cd INTERFACE tinyusb_host)
endif()

#
#
#
#dahai, nocomake
# disable scanvideo's pin, but keep i2s audio on pins 26+27, 28
target_compile_definitions(common_pico INTERFACE
    PICO_SCANVIDEO_COLOR_PIN_BASE=30
    PICO_SCANVIDEO_SYNC_PIN_BASE=30
    PICO_AUDIO_I2S_DATA_PIN=28
    PICO_AUDIO_I2S_CLOCK_PIN_BASE=26
)

target_link_libraries(common_pico INTERFACE hardware_spi)

set(SD_SPI "spi1" CACHE STRING "Specify the SPI bus for the SD card")
set(SD_CS "13" CACHE STRING "Specify the Chip Select GPIO pin for the SD card")
set(SD_SCK "10" CACHE STRING "Specify de Clock GPIO pin for the SD card")
set(SD_MOSI "11" CACHE STRING "Select the Master Out Slave In GPIO pin for the SD card")
set(SD_MISO "12" CACHE STRING "Select the Master In Slave Out GPIO pin for the SD card")

set(LCD_CONTROLLER "ILI9341" CACHE STRING "Select the LCD controller type")
#ig
# set(LCD_CONTROLLER "ST7789" CACHE STRING "Select the LCD controller type")
#ig
#set(LCD_SPI "spi0")
#set(LCD_DC "20")
#set(LCD_CS "17")
#set(LCD_CLK "18")
#set(LCD_MOSI "19")
#set(LCD_RST "21")
#set(LCD_BL "22")
#set(LCD_MISO "-1")

# Waveshare Pico-ResTouch-LCD-2.8 (ST7789, 320x240)
# https://www.waveshare.com/wiki/Pico-ResTouch-LCD-2.8
set(LCD_SPI "spi1")
set(LCD_DC "8")
set(LCD_CS "9")
set(LCD_CLK "10")
set(LCD_MOSI "11")
set(LCD_RST "15")  # LCD_RST -> GP15 (Low active)
set(LCD_BL "13")   # LCD_BL  -> GP13 (Backlight control)
set(LCD_MISO "-1")

# Touch controller XPT2046
set(TOUCH_CS "16")  # TP_CS -> GP16 (Low active)
set(TOUCH_IRQ "17") # TP_IRQ -> GP17 (Low active, interrupt)

# SD card CS - disable by keeping high (inactive)
set(SDCARD_DISABLE_PIN "22") # SD_CS/D3 -> GP22 (Low active)

# Button pins (defaults for Waveshare Pico-ResTouch-LCD-2.8)
#set(BUTTON_UP "0")   # UP  -> GP0
#set(BUTTON_DN "1")   # DN  -> GP1
set(BUTTON_UP "0")   # UP  -> GP0
set(BUTTON_DN "1")   # DN  -> GP1
set(BUTTON_LT "14")  # LT  -> GP14 (moved from touch pin 16)
set(BUTTON_RT "18")  # RT  -> GP18 (moved from touch pin 17)
set(BUTTON_SL "5")   # SL  -> GP5 (moved from I2S pin 28)
set(BUTTON_ST "6")   # ST  -> GP6 (moved from I2S pin 27)
#set(BUTTON_A "7")    # A   -> GP7 (moved from I2S pin 26)
set(BUTTON_A "24")    # A   -> GP7 (moved from I2S pin 26)
set(BUTTON_B "20")     # B   -> GP20 (changed to use GPIO 2 for USB D+ instead of default GP19/D- and GP20/D+) 


message("SD card SPI         : ${SD_SPI}")
message("SD card CS          : ${SD_CS}")
message("SD card SCK         : ${SD_SCK}")
message("SD card MOSI        : ${SD_MOSI}")
message("SD card MISO        : ${SD_MISO}")
message("LCD CONTROLLER      : ${LCD_CONTROLLER}")
message("LCD SPI             : ${LCD_SPI}")
message("LCD DC              : ${LCD_DC}")
message("LCD CS              : ${LCD_CS}")
message("LCD CLK             : ${LCD_CLK}")
message("LCD MOSI            : ${LCD_MOSI}")
message("LCD RST             : ${LCD_RST}")
message("LCD BL              : ${LCD_BL}")
message("LCD MISO            : ${LCD_MISO}")
message("TOUCH CS            : ${TOUCH_CS}")
message("TOUCH IRQ           : ${TOUCH_IRQ}")
message("SDCARD DISABLE PIN  : ${SDCARD_DISABLE_PIN}")
message("BUTTON UP           : ${BUTTON_UP}")
message("BUTTON DN           : ${BUTTON_DN}")
message("BUTTON LT           : ${BUTTON_LT}")
message("BUTTON RT           : ${BUTTON_RT}")
message("BUTTON SL           : ${BUTTON_SL}")
message("BUTTON ST           : ${BUTTON_ST}")
message("BUTTON A            : ${BUTTON_A}")
message("BUTTON B            : ${BUTTON_B}")
target_compile_definitions(common_pico INTERFACE
    SDCARD_SPI_BUS=${SD_SPI}
    SDCARD_PIN_SPI0_CS=${SD_CS}
    SDCARD_PIN_SPI0_SCK=${SD_SCK}
    SDCARD_PIN_SPI0_MOSI=${SD_MOSI}
    SDCARD_PIN_SPI0_MISO=${SD_MISO}
    DISPLAY_SPI_PORT=${LCD_SPI}
    DISPLAY_PIN_DC=${LCD_DC}
    DISPLAY_PIN_CS=${LCD_CS}
    DISPLAY_PIN_CLK=${LCD_CLK}
    DISPLAY_PIN_MOSI=${LCD_MOSI}
    DISPLAY_PIN_RST=${LCD_RST}
    DISPLAY_PIN_BL=${LCD_BL}
    DISPLAY_PIN_MISO=${LCD_MISO}
    TOUCH_CS=${TOUCH_CS}
    TOUCH_IRQ=${TOUCH_IRQ}
    SDCARD_DISABLE_PIN=${SDCARD_DISABLE_PIN}
    BTN_UP=${BUTTON_UP}
    BTN_DN=${BUTTON_DN}
    BTN_LT=${BUTTON_LT}
    BTN_RT=${BUTTON_RT}
    BTN_SL=${BUTTON_SL}
    BTN_ST=${BUTTON_ST}
    BTN_A=${BUTTON_A}
    BTN_B=${BUTTON_B}
)

    #target_link_libraries(common_pico INTERFACE  hardware_pwm)
    #target_link_libraries(common_pico INTERFACE  pico_audio_pwm)
target_compile_definitions(common_pico INTERFACE
        #PICO_AUDIO_PWM_PIO=7
        #USE_CUSTOM_AUDIO_PWM=1
        USE_AUDIO_I2S=1
        #USE_AUDIO_PWM=1
)
if(LCD_CONTROLLER STREQUAL "ILI9341")
    add_compile_definitions(ILI9341)
    target_compile_definitions(common_pico INTERFACE
        ILI9341=1
        )
elseif(LCD_CONTROLLER STREQUAL "ST7789")
    add_compile_definitions(ST7789)
    target_compile_definitions(common_pico INTERFACE
        ST7789=1
        )
endif()


