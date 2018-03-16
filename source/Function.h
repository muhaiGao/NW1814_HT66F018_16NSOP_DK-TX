#ifndef __FUNCTION_H__
#define __FUNCTION_H__
#include "MyDefine.h"
#include "Variants.h"

//0--------本部函数---------//
void Function_Task(void);
//void Mode_Set(unsigned char new_mode);
//unsigned char Mode_Get(void);
//unsigned char PrevMode_Get(void);
void HaltMode_Init(void);
void Halt_Sleep0(void);
void ModeSleep(void);
void Power_StatusDete(void);
void Battery_LevelPro(void);
void TempDisplay_LevelPro(void);
void LEDDisplay(void);
void PWMChange(unsigned int Period,unsigned char DutyCycle);
void DataProcessing(void);
void TimingFun(void);

//1-------外部函数--------//
extern void BatAD_Dete(void);


#endif//__FUNCTION_H__
