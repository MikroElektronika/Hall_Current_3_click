/*
Example for HallCurrent3 Click

    Date          : jul 2018.
    Author        : Katarina Perendic

Test configuration PIC :
    
    MCU             : P18F87K22
    Dev. Board      : EasyPIC PRO v7
    PIC Compiler ver : v7.2.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initialization of the I2C module
- Application Initialization - Driver initialization
- Application Task - (code snippet) - Reads the current from a bipolar current sensor and logs to USBUART every 1 second.

*/

#include "Click_HallCurrent3_types.h"
#include "Click_HallCurrent3_config.h"

float Current_data;
char demoText[ 50 ];

void systemInit()
{
    mikrobus_i2cInit( _MIKROBUS1, &_HALLCURRENT3_I2C_CFG[0] );
    mikrobus_logInit( _LOG_USBUART, 115200 );
    mikrobus_logWrite(" --- System init ---", _LOG_LINE);
    Delay_ms( 100 );
}

void applicationInit()
{
    hallcurrent3_i2cDriverInit( (T_HALLCURRENT3_P)&_MIKROBUS1_GPIO, (T_HALLCURRENT3_P)&_MIKROBUS1_I2C, 0x4D );
}

void applicationTask()
{
    Current_data = hallcurrent3_getCurrent();
    
    FloatToStr(Current_data, demoText);
    mikrobus_logWrite("Current : ", _LOG_TEXT);
    mikrobus_logWrite(demoText, _LOG_TEXT);
    mikrobus_logWrite(" mA", _LOG_LINE);
    Delay_ms( 1000 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}