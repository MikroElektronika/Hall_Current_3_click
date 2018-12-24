/*
    __hallcurrent3_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__hallcurrent3_driver.h"
#include "__hallcurrent3_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __HALLCURRENT3_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __HALLCURRENT3_DRV_SPI__

void hallcurrent3_spiDriverInit(T_HALLCURRENT3_P gpioObj, T_HALLCURRENT3_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __HALLCURRENT3_DRV_I2C__

void hallcurrent3_i2cDriverInit(T_HALLCURRENT3_P gpioObj, T_HALLCURRENT3_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __HALLCURRENT3_DRV_UART__

void hallcurrent3_uartDriverInit(T_HALLCURRENT3_P gpioObj, T_HALLCURRENT3_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

uint16_t hallcurrent3_readData(uint8_t reg)
{
    uint8_t writeReg[ 1 ];
    uint8_t readReg[ 2 ];
    uint16_t _data;
    
    writeReg[ 0 ] = reg;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 1, END_MODE_RESTART);
    hal_i2cRead(_slaveAddress, readReg, 2, END_MODE_STOP);

    _data = readReg[ 0 ];
    _data = _data << 8;
    _data = _data | readReg[ 1 ];
    
    return _data;
}

float hallcurrent3_getCurrent()
{
    float voltage;
    double sumCurrent = 0.0;
    uint16_t readData;
    uint8_t cnt = 10;
    uint8_t flag = 0;
    
    while(cnt > 0)
    {
        readData = hallcurrent3_readData(0x00);

        /* Bipolar current sensor */
        if(readData < 2048 )
        {
            voltage = 2048 - readData;
            flag = 1;
        }
        else
        {
            voltage = readData - 2048;
        }
        voltage = voltage * (float)( 5000 / 4095); // 5V / 12bit resolution
        voltage = (voltage * 1000) / 65.57; // 56.57 -> nominal 80mV/A or ±25A full scale
        sumCurrent += voltage;
        cnt--;
    }
    
    sumCurrent = (sumCurrent - 100) / 10.0;
    sumCurrent = sumCurrent;
    
    if( flag == 1)
    {
        return (-sumCurrent);
    }
    /* Currrent in mA */
    return sumCurrent;
}


/* -------------------------------------------------------------------------- */
/*
  __hallcurrent3_driver.c

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