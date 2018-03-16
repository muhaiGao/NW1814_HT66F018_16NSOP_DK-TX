#ifndef __ADC_H__
#define __ADC_H__

#include "MyDefine.h"
#include "variants.h"

unsigned int ADC_GetChannelVal(unsigned int R_AdcChannel);
void NTC_AD_Dete(void);
void ResAD_Dete(void);
void BatAD_Dete(void);
#endif//__ADC_H__ 		