_systemInit:
;Click_HallCurrent3_STM.c,33 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_HallCurrent3_STM.c,35 :: 		mikrobus_i2cInit( _MIKROBUS1, &_HALLCURRENT3_I2C_CFG[0] );
MOVW	R0, #lo_addr(__HALLCURRENT3_I2C_CFG+0)
MOVT	R0, #hi_addr(__HALLCURRENT3_I2C_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_i2cInit+0
;Click_HallCurrent3_STM.c,36 :: 		mikrobus_logInit( _LOG_USBUART_A, 115200 );
MOV	R1, #115200
MOVS	R0, #32
BL	_mikrobus_logInit+0
;Click_HallCurrent3_STM.c,37 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_HallCurrent3_STM.c,38 :: 		mikrobus_logWrite(" --- System init ---", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr1_Click_HallCurrent3_STM+0)
MOVT	R0, #hi_addr(?lstr1_Click_HallCurrent3_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_HallCurrent3_STM.c,39 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_HallCurrent3_STM.c,41 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_HallCurrent3_STM.c,43 :: 		hallcurrent3_i2cDriverInit( (T_HALLCURRENT3_P)&_MIKROBUS1_GPIO, (T_HALLCURRENT3_P)&_MIKROBUS1_I2C, 0x4D );
MOVS	R2, #77
MOVW	R1, #lo_addr(__MIKROBUS1_I2C+0)
MOVT	R1, #hi_addr(__MIKROBUS1_I2C+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_hallcurrent3_i2cDriverInit+0
;Click_HallCurrent3_STM.c,44 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_HallCurrent3_STM.c,46 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_HallCurrent3_STM.c,48 :: 		Current_data = hallcurrent3_getCurrent();
BL	_hallcurrent3_getCurrent+0
MOVW	R1, #lo_addr(_Current_data+0)
MOVT	R1, #hi_addr(_Current_data+0)
STR	R0, [R1, #0]
;Click_HallCurrent3_STM.c,49 :: 		FloatToStr(Current_data, demoText);
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_FloatToStr+0
;Click_HallCurrent3_STM.c,50 :: 		mikrobus_logWrite("Current : ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr2_Click_HallCurrent3_STM+0)
MOVT	R0, #hi_addr(?lstr2_Click_HallCurrent3_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_HallCurrent3_STM.c,51 :: 		mikrobus_logWrite(demoText, _LOG_TEXT);
MOVS	R1, #1
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_HallCurrent3_STM.c,52 :: 		mikrobus_logWrite(" mA", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr3_Click_HallCurrent3_STM+0)
MOVT	R0, #hi_addr(?lstr3_Click_HallCurrent3_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_HallCurrent3_STM.c,53 :: 		Delay_ms( 1000 );
MOVW	R7, #6911
MOVT	R7, #183
NOP
NOP
L_applicationTask2:
SUBS	R7, R7, #1
BNE	L_applicationTask2
NOP
NOP
NOP
;Click_HallCurrent3_STM.c,54 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_HallCurrent3_STM.c,56 :: 		void main()
;Click_HallCurrent3_STM.c,58 :: 		systemInit();
BL	_systemInit+0
;Click_HallCurrent3_STM.c,59 :: 		applicationInit();
BL	_applicationInit+0
;Click_HallCurrent3_STM.c,61 :: 		while (1)
L_main4:
;Click_HallCurrent3_STM.c,63 :: 		applicationTask();
BL	_applicationTask+0
;Click_HallCurrent3_STM.c,64 :: 		}
IT	AL
BAL	L_main4
;Click_HallCurrent3_STM.c,65 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
