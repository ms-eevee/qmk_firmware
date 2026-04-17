#pragma once

#include_next <mcuconf.h>

#undef STM32_SERIAL_USE_USART1
#define STM32_SERIAL_USE_USART1 TRUE

#ifdef ENABLE_KEEB_RGB
#undef STM32_I2C_USE_I2C2
#define STM32_I2C_USE_I2C2 TRUE
#endif
