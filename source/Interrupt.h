#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

#include "MyDefine.h"
#include "Variants.h"

//*********全局变量声明*****************************
//--0---- 本部全局变量声明 -------------------------


//--2---- 外部全局位变量声明 -----------------------


//*********函数声明*****************************
//--0---- 本部函数声明 -------------------------
DEFINE_ISR(MF0_ISR,   0x0C);
DEFINE_ISR(MF1_ISR,   0x10);


#endif 	//__INTERRUPT_H__
