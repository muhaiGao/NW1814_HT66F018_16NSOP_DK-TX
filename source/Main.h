#ifndef __MAIN_H__
#define __MAIN_H__

#include "MyDefine.h"
#include "Variants.h"

//*********函数声明*****************************
//--0---- 本部函数声明 -------------------------

//--1---- 外部函数声明 -------------------------
//in Initial.c
extern void 	Sys_Init(void);
extern void 	RAM_Init(void);
extern void 	User_Init(void);

//in Interrupt.c
extern void MF0_ISR(void);

//in Function.c
extern void Function_Task(__flag_type flag);
//extern void Mode_Set(unsigned char new_mode);
//extern unsigned char Mode_Get(void);
//extern unsigned char PrevMode_Get(void);
extern void ModeSleep(void);
extern void Power_StatusDete(void);
extern void Battery_LevelPro(void);
extern void TempDisplay_LevelPro(void);
extern void LEDDisplay(void);
extern void PWMChange(u16 Period,u8 DutyCycle);
extern void DataProcessing(void);
extern void Time_Base(void);

//in ADC.c
extern void NTC_AD_Dete(void);
extern void ResAD_Dete(void);
extern void BatAD_Dete(void);


#endif 	//__MAIN_H__
