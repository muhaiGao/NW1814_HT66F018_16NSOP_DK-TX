#ifndef 		__EERPOM_H__
#define 		__EERPOM_H__

#include	"MyDefine.h"
#include	"Variants.h"

//*********全局变量声明*****************************
//--0---- 本部全局变量声明 -------------------------

//--1---- 外部全局变量声明 -------------------------


//*********函数声明*****************************
//--0---- 本部函数声明 -------------------------

//--1---- 外部函数声明 -------------------------
uchar EEPROM_Read (unsigned char addr_data);
void EEPROM_Write (unsigned char addr_data,unsigned char data);

#endif 			//__EERPOM_H__