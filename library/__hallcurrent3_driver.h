/*
    __hallcurrent3_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __hallcurrent3_driver.h
@brief    HallCurrent3 Driver
@mainpage HallCurrent3 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   HALLCURRENT3
@brief      HallCurrent3 Click Driver
@{

| Global Library Prefix | **HALLCURRENT3** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **jul 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _HALLCURRENT3_H_
#define _HALLCURRENT3_H_

/** 
 * @macro T_HALLCURRENT3_P
 * @brief Driver Abstract type 
 */
#define T_HALLCURRENT3_P    const uint8_t*

/** @defgroup HALLCURRENT3_COMPILE Compilation Config */              /** @{ */

//  #define   __HALLCURRENT3_DRV_SPI__                            /**<     @macro __HALLCURRENT3_DRV_SPI__  @brief SPI driver selector */
   #define   __HALLCURRENT3_DRV_I2C__                            /**<     @macro __HALLCURRENT3_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __HALLCURRENT3_DRV_UART__                           /**<     @macro __HALLCURRENT3_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup HALLCURRENT3_VAR Variables */                           /** @{ */



                                                                       /** @} */

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup HALLCURRENT3_INIT Driver Initialization */              /** @{ */

#ifdef   __HALLCURRENT3_DRV_SPI__
void hallcurrent3_spiDriverInit(T_HALLCURRENT3_P gpioObj, T_HALLCURRENT3_P spiObj);
#endif
#ifdef   __HALLCURRENT3_DRV_I2C__
void hallcurrent3_i2cDriverInit(T_HALLCURRENT3_P gpioObj, T_HALLCURRENT3_P i2cObj, uint8_t slave);
#endif
#ifdef   __HALLCURRENT3_DRV_UART__
void hallcurrent3_uartDriverInit(T_HALLCURRENT3_P gpioObj, T_HALLCURRENT3_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void hallcurrent3_gpioDriverInit(T_HALLCURRENT3_P gpioObj);
                                                                       /** @} */
/** @defgroup HALLCURRENT3_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Reads current in mA
 *
 * @return current value
 */
float hallcurrent3_getCurrent();

/**
 * @brief Reads current data
 *
 * @return current (12 bits) adc value
 *
 * The value of 2048 is 0A.
 * Bipolar current sensor -- 0A at 50% Vdd -- nominal 80mV/A or ±25A full scale
 */
uint16_t hallcurrent3_readData(uint8_t reg);



                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_HallCurrent3_STM.c
    @example Click_HallCurrent3_TIVA.c
    @example Click_HallCurrent3_CEC.c
    @example Click_HallCurrent3_KINETIS.c
    @example Click_HallCurrent3_MSP.c
    @example Click_HallCurrent3_PIC.c
    @example Click_HallCurrent3_PIC32.c
    @example Click_HallCurrent3_DSPIC.c
    @example Click_HallCurrent3_AVR.c
    @example Click_HallCurrent3_FT90x.c
    @example Click_HallCurrent3_STM.mbas
    @example Click_HallCurrent3_TIVA.mbas
    @example Click_HallCurrent3_CEC.mbas
    @example Click_HallCurrent3_KINETIS.mbas
    @example Click_HallCurrent3_MSP.mbas
    @example Click_HallCurrent3_PIC.mbas
    @example Click_HallCurrent3_PIC32.mbas
    @example Click_HallCurrent3_DSPIC.mbas
    @example Click_HallCurrent3_AVR.mbas
    @example Click_HallCurrent3_FT90x.mbas
    @example Click_HallCurrent3_STM.mpas
    @example Click_HallCurrent3_TIVA.mpas
    @example Click_HallCurrent3_CEC.mpas
    @example Click_HallCurrent3_KINETIS.mpas
    @example Click_HallCurrent3_MSP.mpas
    @example Click_HallCurrent3_PIC.mpas
    @example Click_HallCurrent3_PIC32.mpas
    @example Click_HallCurrent3_DSPIC.mpas
    @example Click_HallCurrent3_AVR.mpas
    @example Click_HallCurrent3_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __hallcurrent3_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */