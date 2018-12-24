#line 1 "D:/Clicks_git/H/Hall_Current_3_Click/SW/example/c/ARM/STM/Click_HallCurrent3_STM.c"
#line 1 "d:/clicks_git/h/hall_current_3_click/sw/example/c/arm/stm/click_hallcurrent3_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "d:/clicks_git/h/hall_current_3_click/sw/example/c/arm/stm/click_hallcurrent3_config.h"
#line 1 "d:/clicks_git/h/hall_current_3_click/sw/example/c/arm/stm/click_hallcurrent3_types.h"
#line 3 "d:/clicks_git/h/hall_current_3_click/sw/example/c/arm/stm/click_hallcurrent3_config.h"
const uint32_t _HALLCURRENT3_I2C_CFG[ 1 ] =
{
 100000
};
#line 1 "d:/clicks_git/h/hall_current_3_click/sw/library/__hallcurrent3_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 71 "d:/clicks_git/h/hall_current_3_click/sw/library/__hallcurrent3_driver.h"
void hallcurrent3_i2cDriverInit( const uint8_t*  gpioObj,  const uint8_t*  i2cObj, uint8_t slave);
#line 78 "d:/clicks_git/h/hall_current_3_click/sw/library/__hallcurrent3_driver.h"
void hallcurrent3_gpioDriverInit( const uint8_t*  gpioObj);



float hallcurrent3_getCurrent();

uint16_t hallcurrent3_readData(uint8_t reg);
#line 30 "D:/Clicks_git/H/Hall_Current_3_Click/SW/example/c/ARM/STM/Click_HallCurrent3_STM.c"
float Current_data;
char demoText[ 50 ];

void systemInit()
{
 mikrobus_i2cInit( _MIKROBUS1, &_HALLCURRENT3_I2C_CFG[0] );
 mikrobus_logInit( _LOG_USBUART_A, 115200 );
 Delay_ms( 100 );
 mikrobus_logWrite(" --- System init ---", _LOG_LINE);
}

void applicationInit()
{
 hallcurrent3_i2cDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_I2C, 0x4D );
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
