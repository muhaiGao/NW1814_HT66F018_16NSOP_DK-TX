#ifndef 		__EERPOM_H__
#define 		__EERPOM_H__

#include	"MyDefine.h"
#include	"Variants.h"

//*********ȫ�ֱ�������*****************************
//--0---- ����ȫ�ֱ������� -------------------------

//--1---- �ⲿȫ�ֱ������� -------------------------


//*********��������*****************************
//--0---- ������������ -------------------------

//--1---- �ⲿ�������� -------------------------
uchar EEPROM_Read (unsigned char addr_data);
void EEPROM_Write (unsigned char addr_data,unsigned char data);

#endif 			//__EERPOM_H__