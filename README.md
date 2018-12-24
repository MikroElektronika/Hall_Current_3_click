![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# HallCurrent3 Click

- **CIC Prefix**  : HALLCURRENT3
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : jul 2018.

---

### Software Support

We provide a library for the HallCurrent3 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2502/hallcurrent-3-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

This library provides basic functionality for reading the current value and controlling the click board.

Key functions :

- ``` float hallcurrent3_getCurrent() ``` - Reads current in mA
- ``` uint16_t hallcurrent3_readData(uint8_t reg) ``` - Reads current data

**Examples Description**

The application is composed of three sections :

- System Initialization - Initialization of the I2C module
- Application Initialization - Driver initialization
- Application Task - (code snippet) - Reads the current from a bipolar current sensor and logs to USBUART every 1 second.

```.c
void applicationTask()
{
    Current_data = hallcurrent3_getCurrent();
    
    FloatToStr(Current_data, demoText);
    mikrobus_logWrite("Current : ", _LOG_TEXT);
    mikrobus_logWrite(demoText, _LOG_TEXT);
    mikrobus_logWrite(" mA", _LOG_LINE);
    Delay_ms( 1000 );
}
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2502/hallcurrent-3-click) page.

Other mikroE Libraries used in the example:

- I2C
- Conversions

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
### Architectures Supported

#### mikroC

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroBasic

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroPascal

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

---
---
