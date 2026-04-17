#pragma once

#define HAL_USE_SERIAL TRUE

#ifdef ENABLE_KEEB_RGB
#define HAL_USE_I2C TRUE
#endif

#include_next <halconf.h>


