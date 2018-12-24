/*
Example for HallCurrent3 Click

    Date          : jul 2018.
    Author        : Katarina Perendic

Test configuration PIC32 :
    
    MCU                : P32MX795F512L
    Dev. Board         : EasyPIC Fusion v7
    PIC32 Compiler ver : v4.0.0.0

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
    mikrobus_logInit( _LOG_USBUART_A, 115200 );
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