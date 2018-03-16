#ifndef __INITIAL_H__
#define __INITIAL_H__

#include "MyDefine.h"
#include "Variants.h"

//*********��������*****************************
//--0---- ������������ -------------------------
void Sys_Init(void);
void RAM_Init(void);
void User_Init(void);
void initINT(void);
void TimeSet_Init(void);
void Variable_Init(void);

//--1---- �ⲿ�������� -------------------------
extern void PWMChange(u16 Period,u8 DutyCycle);
extern void Power_StatusDete(void);
extern void BatAD_Dete(void);

#endif 	//__INITIAL_H__
