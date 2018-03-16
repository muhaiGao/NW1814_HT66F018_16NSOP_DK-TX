#include "ADC.h"

//===================================================================
//function: unsigned int ADC_GetChannelVal(unsigned int R_AdcChannel)
//input   :	R_AdcChannel:ADC����ͨ��
//output  :	u16_12ADCTemp: 12λ��ADֵ
//description:ÿ����һ��,ADC����    ReadADC_Cnt��,ȥ�����ֵ����Сֵ,��ȡƽ��ֵ.
//====================================================================
unsigned int ADC_GetChannelVal(unsigned int R_AdcChannel)
{
	unsigned char ReadADC_Cnt = 4;
	unsigned int u16_12ADCTemp = 0;
	unsigned int ADC_Sum = 0,R_ADC_Max = 0,R_ADC_Min = 0xfffe;
	
	switch(R_AdcChannel)
	{
		case C_ADC_CH0:
			_adcr0 = C_ADC_CH0;
			break;
		case C_ADC_CH2:
			_adcr0 = C_ADC_CH2;
			break;
		case C_ADC_CH3:
			_adcr0 = C_ADC_CH3;
			break;
		default:
			return 0;
			break;
	}
	_adoff = 0;//��ADC��Դת��.
//	//��һ��ת�����洢
//	_start = 0;
//	GCC_NOP();
//	_start = 1;
//	GCC_NOP();
//	_start = 0;
//	GCC_NOP();
//	while (_eocb);
	while(ReadADC_Cnt--)
	{
		_start = 0;
		GCC_NOP();
		_start = 1;
		GCC_NOP();
		_start = 0;
		GCC_NOP();
		while (_eocb);
		u16_12ADCTemp = (unsigned int)_adrl;
		u16_12ADCTemp |= (unsigned int)((_adrh&0x0f)<<8);
		ADC_Sum += u16_12ADCTemp;
		if(R_ADC_Max < u16_12ADCTemp) R_ADC_Max = u16_12ADCTemp;
		if(R_ADC_Min > u16_12ADCTemp) R_ADC_Min = u16_12ADCTemp;
		GCC_CLRWDT();
	}
	_adoff = 1;
	ADC_Sum = ADC_Sum - R_ADC_Max - R_ADC_Min;
	u16_12ADCTemp = ADC_Sum >> 1;
	return	u16_12ADCTemp;
}

//============================================================================
//function: NTC_AD_Dete
//input   :	NULL
//output  :	NULL
//description:����NTC��ADֵ,���Table_NTC_Data�ж϶�Ӧ���¶�,�������������¶�.
//============================================================================
void NTC_AD_Dete(void)
{
	unsigned int ntc_ad_data = ADC_GetChannelVal(C_ADC_CH3);
		
	//�ж��Ƿ����NTC(����˵����Ƭ).
	if(ntc_ad_data >= NTC_AD_DETE){//4060
		if(++R_NoNTCCount >= 8){
			R_NoNTCCount = 3;
			fg_NoNTC = 1;
		}
	}else{
		if(R_NoNTCCount){
			R_NoNTCCount--;
			if(R_NoNTCCount <= 1){
				R_NoNTCCount = 3;
				fg_NoNTC = 0;
			}
		}
	}

	//�ε�����Ƭʱ,�ر����,������ģʽ����ʾ�����¶�.
	if (fg_NoNTC){
		R_intHeatingPWM2ms = C_1S;
		R_intTempDisplayLevel = R_intRESTempSet;
		return;
	}

	//�����¶�С��60���϶�,������,ֱ���˳�����.
	if(R_intRESTempSet < TEMP_SET_MIN){
		R_intHeatingPWM2ms = C_1S;
		return;
	}
	
	R_intNTC_ADVal += ntc_ad_data;
	if(++R_NTC_AD_Count >= 8)
	{
		unsigned char i,tmp;
		R_NTC_AD_Count = 0;
		R_intNTC_ADVal = R_intNTC_ADVal>>3;
		ntc_ad_data = R_intNTC_ADVal;

		if(fg_NoNTC==0)
		{		
			//Ϊ�˽�ʡ����ʱ��,���ȷּ���.
			#if 1
				if(R_intNTC_ADVal >= Table_NTC_Data[50]){ i = 0; tmp = 50;}
				else if(R_intNTC_ADVal >= Table_NTC_Data[75]){ i = 50; tmp = 75;}
				else if(R_intNTC_ADVal >= Table_NTC_Data[100]){ i = 75; tmp = 100;}
				else if(R_intNTC_ADVal >= Table_NTC_Data[125]){ i = 100; tmp = 125;}
				else if(R_intNTC_ADVal >= Table_NTC_Data[150]){ i = 125; tmp = 150;}
				else if(R_intNTC_ADVal >= Table_NTC_Data[175]){ i = 150; tmp = 175;}
				else if(R_intNTC_ADVal >= Table_NTC_Data[200]){ i = 175; tmp = 200;}
				else { i = 200; tmp = TABLE_NTC_MAX;}
			#else
				if(R_intNTC_ADVal >= Table_NTC_Data[125]){
					if(R_intNTC_ADVal >= Table_NTC_Data[125]){i = 100; tmp = 125;}
					else if(R_intNTC_ADVal >= Table_NTC_Data[150]){ i = 125; tmp = 150;}
					else if(R_intNTC_ADVal >= Table_NTC_Data[175]){ i = 150; tmp = 175;}
					else if(R_intNTC_ADVal >= Table_NTC_Data[200]){ i = 175; tmp = 200;}
					else { i = 200; tmp = TABLE_NTC_MAX;}
				}else{
						if(R_intNTC_ADVal >= Table_NTC_Data[50]){ i = 0; tmp = 50;}
						else if(R_intNTC_ADVal >= Table_NTC_Data[75]){ i = 50; tmp = 75;}
						else{ i = 75; tmp = 100;}
				}
			#endif
			for(;i<tmp;i++)
			{
				if(R_intNTC_ADVal > Table_NTC_Data[i])
				{
					R_intNTC_CurrentTemp = i+NTC_ARRAY_ADJ;
					break;
				}
			}

			if(TEMP_SET_MAX < R_intNTC_CurrentTemp){
				R_intNTC_CurrentTemp = TEMP_SET_MAX;
			}

			/*˵��:
			*	1.(R_intRESTempSet-NTC_ARRAY_ADJ):�����¶�gR_intRES12AD_TempSet���ӦTable_NTC_Data���еĵ�(R_intRESTempSet-NTC_ARRAY_ADJ)ADֵ.
			*	2.(R_intRESTempSet/10-4):��ӦTable_HeatingTimeData�����еĵ�(R_intRESTempSet/10-4)������ʱ��.
			*	3.(R_intRESTempSet/10-4) +/- n :��ӦTable_HeatingTimeData����������Χ,��(+/- n)��Χ�ڵ�������ʱ��,���������¶�.
			*/
			i = (R_intRESTempSet-NTC_ARRAY_ADJ);
			tmp = (R_intRESTempSet/10-4);
//			if(ntc_ad_data > (Table_NTC_Data[i] + NTC_AD_GAP))
//			if(ntc_ad_data > Table_NTC_Data[i])
			if((R_intRESTempSet > R_intNTC_CurrentTemp)||(ntc_ad_data > Table_NTC_Data[i]))
			{
				if((R_intRESTempSet-3) >= R_intNTC_CurrentTemp){
					if(R_intHeatingPWM2ms){
						R_intHeatingPWM2ms--;
					}
				}else{
				
					if(R_intHeatingPWM2ms < Table_HeatingTimeData[tmp+3]){
						R_intHeatingPWM2ms = Table_HeatingTimeData[tmp+3];
					}
						
					if(R_intHeatingPWM2ms > Table_HeatingTimeData[tmp+3]){
						--R_intHeatingPWM2ms;
					}
				}
			}
			else
			{
//				if (ntc_ad_data < (Table_NTC_Data[i+2])){
				if((R_intRESTempSet+2 <= R_intNTC_CurrentTemp)||(ntc_ad_data < (Table_NTC_Data[i+2]))){
					if(250 <= R_intRESTempSet){
						if(((R_intRESTempSet+3) <= R_intNTC_CurrentTemp) &&\
						   ((R_intRESTempSet+5) >= R_intNTC_CurrentTemp)){
							R_intHeatingPWM2ms = Table_HeatingTimeData[tmp-2];
						}else if((R_intRESTempSet+6) <= R_intNTC_CurrentTemp){
							R_intHeatingPWM2ms = 250;
						} 
					}else if(200 <= R_intRESTempSet){
						if(((R_intRESTempSet+2) <= R_intNTC_CurrentTemp) &&\
						   ((R_intRESTempSet+4) >= R_intNTC_CurrentTemp)){
							R_intHeatingPWM2ms = 300;
						}else if((R_intRESTempSet+6) <= R_intNTC_CurrentTemp){
							R_intHeatingPWM2ms = C_1S;
						} 
					}else  if(110 <= R_intRESTempSet){
						R_intHeatingPWM2ms = Table_HeatingTimeData[tmp-2];
						if((R_intRESTempSet+3) <= R_intNTC_CurrentTemp){
							R_intHeatingPWM2ms = C_1S;
						}
					}else{
						R_intHeatingPWM2ms = C_1S;
					}
					
					if(R_intHeatingPWM2ms < Table_HeatingTimeData[tmp-2]){
						++R_intHeatingPWM2ms;
					}
				}else{
					if(R_intRESTempSet >= 200){
						if(((R_intRESTempSet+2) <= R_intNTC_CurrentTemp)\
							&&((R_intRESTempSet+3) >= R_intNTC_CurrentTemp)){
							//���¶Ƚϸ�ʱ,ֻҪ�رռ���1s����,�ͻᵼ���¶�һ���ӽ��ͺܶ�.���Ƿ�ֹ���������¶Ȳ������.
							R_intHeatingPWM2ms = Table_HeatingTimeData[tmp-1];
						}
					}
					
					if(R_intHeatingPWM2ms > Table_HeatingTimeData[tmp-2]){
						R_intHeatingPWM2ms = Table_HeatingTimeData[tmp-2];
					}
					
					if(R_intHeatingPWM2ms < Table_HeatingTimeData[tmp-2]){
						++R_intHeatingPWM2ms;
					}
					
					if((R_intRESTempSet+5) <= R_intNTC_CurrentTemp){
						R_intHeatingPWM2ms = C_1S;
					} 
				}
			}
			
			if(TEMP_SET_MAX <= R_intNTC_CurrentTemp){
				if(ntc_ad_data < (Table_NTC_Data[TEMP_SET_MAX-1])){
					R_intHeatingPWM2ms = 250;
				}
			}
		}
		R_intNTC_ADVal = 0;
	}
}

//===================================================================
//function: ResAD_Dete
//input   :	NULL
//output  :	NULL
//description:�����¶ȵĵ�λ����.
//====================================================================
unsigned int R_ADC_Max = 0,R_ADC_Min = 0xfffe;
void ResAD_Dete(void)
{
	unsigned int i,k;
	unsigned int u16_12ADCTemp;
	u16_12ADCTemp = ADC_GetChannelVal(C_ADC_CH2);
	R_intResAD_Value += u16_12ADCTemp;
	if(R_ADC_Max < u16_12ADCTemp) R_ADC_Max = u16_12ADCTemp;
	if(R_ADC_Min > u16_12ADCTemp) R_ADC_Min = u16_12ADCTemp;
	if(++R_ResADCount >= 10)
	{
		R_ResADCount = 0;
		R_intResAD_Value = R_intResAD_Value - R_ADC_Max - R_ADC_Min;
		R_intResAD_Value >>= 3;
		R_ADC_Max = 0;
		R_ADC_Min = 0xfffe;
		if(RES_AD_MIN <  R_intResAD_Value){//>257:60���϶�. 
			if(c_ModeInit == R_WorkMode){
				if(0 <= R_ModeChgCount){
					R_ModeChgCount++;
					if(20 <= R_ModeChgCount){
						R_ModeChgCount = 10;
//						R_WorkMode = c_ModeHeating;
						fg_ModeUpdate = 1;
					}
				}
			}
		}else{
			if(R_ModeChgCount){
				R_ModeChgCount--;
			}else{
				if(c_ModeHeating == R_WorkMode){
//					R_WorkMode = c_ModeInit;//0~59���϶�,��ʾ��ص���.
					fg_ModeUpdate = 1;
				}
				R_intRESTempSet = 0;
			}
		}
		
		if ((c_ModeHeating == R_WorkMode) || (c_ModeBatterLow == R_WorkMode))
		{
			/*��ʾ��ǰ�¶�ʱ,�ж������¶ȷ�ΧAD����Щʱ�Ÿ��������¶�,
			 *��ֹ��AD����������ʾ��ǰ�¶�ʱ�������������¶�ģʽ.
			 */
			if(fg_TempSet){
				if((R_intResAD_Value>(R_intResAD_ValueBak+RES_AD_GAP2))\
					||((R_intResAD_Value+RES_AD_GAP2)<R_intResAD_ValueBak)\
					||((R_intResAD_Value>=RES_AD_MAX)&&(R_intRESTempSet!=TEMP_SET_MAX)))
					fg_TempSet = 0;
			}
			
			if((0 == fg_TempSet)\
 				&&((R_intResAD_Value > (R_intResAD_ValueBak+RES_AD_GAP1))\
 				||((R_intResAD_Value+RES_AD_GAP1) < R_intResAD_ValueBak)\
 				||((R_intResAD_Value>=RES_AD_MAX) && (R_intRESTempSet!=TEMP_SET_MAX))))
			{
				if(++R_UpdateTempSetCount>=2)
				{
					R_UpdateTempSetCount = 0;
					R_intResAD_ValueBak=R_intResAD_Value;
					
					//Ϊ�˽�ʡ����ʱ��,���ȷּ���.
					if(R_intResAD_Value<=Table_ResData[40]){ i = 0; k = 40;}
					else if(R_intResAD_Value <= Table_ResData[80]){ i = 40; k = 80;}
					else if(R_intResAD_Value <= Table_ResData[120]){ i = 80; k = 120;}
					else if(R_intResAD_Value <= Table_ResData[160]){ i = 120; k = 160;}
					else { i = 160; k = TABLE_RES_MAX;}
					for(;i<k;i++)
					{
						if(R_intResAD_Value<Table_ResData[i]){
							if(i > R_intRESTempSetCopy){
								if(R_intResAD_Value > (Table_ResData[R_intRESTempSetCopy] + RES_AD_GAP))
									R_intRESTempSetCopy = i;
							}
							if(i < R_intRESTempSetCopy){
								if(R_intResAD_Value < (Table_ResData[R_intRESTempSetCopy] - RES_AD_GAP))
									R_intRESTempSetCopy = i;
							}
							break;
						}
				    }
					if(TABLE_RES_MAX <= R_intRESTempSetCopy){
						R_intRESTempSetCopy = TABLE_RES_MAX-1;
					}
					
				    if((R_intRESTempSetCopy+RES_ARRAY_ADJ) != R_intRESTempSet)
			     	{
			     		if(1 > R_intRESTempSetCopy){
							if(++R_Low60Count >= 10){
								R_Low60Count = 0;
								R_intRESTempSet = R_intRESTempSetCopy+RES_ARRAY_ADJ;
								R_TimeResTempSetDisplay = 0x00;
								R_intTempDisplayLevel = R_intNTC_CurrentTemp;
							}
						}else{
							R_Low60Count = 0;
							R_intRESTempSet = R_intRESTempSetCopy+RES_ARRAY_ADJ;
							R_TimeResTempSetDisplay = 0x00;
							R_intTempDisplayLevel = R_intNTC_CurrentTemp;
						}
				    }
			    }
			}else{
				R_UpdateTempSetCount = 0;
			}
		}
		R_intResAD_Value = 0;
	}
}

//===================================================================
//function: BatAD_Dete
//input   :	NULL
//output  :	NULL
//description:��ѹ���.��ѹ�ȼ�����͸��ݵ�ѹ�ȼ���ֵLED��ʾģʽ
//====================================================================
void BatAD_Dete(void)
{
	unsigned char i;
	R_intBatADValue = ADC_GetChannelVal(C_ADC_CH0);

		if(fg_PowerIn){
			
			//��������.
			if(fg_BatDetePowerOn){
				if(R_intBatADValue < Table_BatChargeLevel[1]){
					R_BatLevel_Count1 = 0;
					R_BatLevel_Count2++;
					if(R_BatLevel_Count2 >= 5){
						R_BatLevel_Count2 = 0;
						R_BatLevel = BAT_LVL_MIN;
					}
				}else{
				    R_BatLevel_Count2 = 0;
					R_BatLevel_Count1++;
					if(R_BatLevel_Count1 >= 5){
						R_BatLevel_Count1 = 0;
						fg_BatDetePowerOn = 0;
					    R_BatLevel = 1;
					}
				}
			}else{
				if(R_intBatADValue >= Table_BatChargeLevel[BAT_CHGLVL_MAX]){
					R_BatLevel_Count1++;
					if(R_BatLevel_Count1 >= 5){
						R_BatLevel_Count1 = 0;
						R_BatLevel = BAT_CHGLVL_MAX;
					}
				}else{
				     R_BatLevel_Count1 = 0;
					for(i=0; i<=BAT_CHGLVL_MAX; i++)
					{
						if(R_intBatADValue <= Table_BatChargeLevel[i]){
							if(i > R_BatLevel){
								if(R_intBatADValue > (Table_BatChargeLevel[R_BatLevel] + BATTERY_GAP)){
									R_BatLevel_Count2++;
									if(R_BatLevel_Count2 >= 5){
										R_BatLevel_Count2 = 0;
										R_BatLevel = i;
									}
								}
							}else{
								R_BatLevel_Count2 = 0;
							}
							
							if(i < R_BatLevel){
								if(R_intBatADValue < (Table_BatChargeLevel[R_BatLevel] - BATTERY_CHGGAP)){
									R_BatLevel_Count3++;
									if(R_BatLevel_Count3 >= 5){
										R_BatLevel_Count3 = 0;
										R_BatLevel = i;
									}
								}
							}else{
								R_BatLevel_Count3 = 0;
							}
							break;
						}
					}
					if ((c_ModeBatterLow == R_WorkMode) ||(c_ModeSleep == R_WorkMode)){
						if ((R_intBatADValue < Table_BatChargeLevel[1])){
							R_BatLevel = BAT_LVL_MIN;
						}
					}
				}
			}
			
		}else{
		
			//û��������,ֻ�е��.
			if(fg_BatDetePowerOn){
				if(R_intBatADValue < Table_BatLevel[1]){
					R_BatLevel_Count1 = 0;
					R_BatLevel_Count2++;
					if(R_BatLevel_Count2 >= 5){
						R_BatLevel_Count2 = 0;
						R_BatLevel = BAT_LVL_MIN;
					}
				}else{
				    R_BatLevel_Count2 = 0;
					R_BatLevel_Count1++;
					if(R_BatLevel_Count1 >= 5){
						R_BatLevel_Count1 = 0;
						fg_BatDetePowerOn = 0;
					}
				}
			}else{
				if(R_intBatADValue >= Table_BatLevel[BAT_LVL_MAX]){
					R_BatLevel_Count1++;
					if(R_BatLevel_Count1 >= 5){
						R_BatLevel_Count1 = 0;
						R_BatLevel = BAT_LVL_MAX;
					}
				}else{
					R_BatLevel_Count1 = 0;
					for(i=0; i<=BAT_LVL_MAX; i++)
					{
						if(R_intBatADValue < Table_BatLevel[i]){
							if(i > R_BatLevel){
								if(R_intBatADValue > (Table_BatLevel[R_BatLevel] + BATTERY_GAP1)){
									R_BatLevel_Count2++;
									if(R_BatLevel_Count2 >= 5){
										R_BatLevel_Count2 = 0;
										R_BatLevel = i;
									}
								}
							}else{
								R_BatLevel_Count2 = 0;
							}
							if(i < R_BatLevel){
								if(R_intBatADValue < (Table_BatLevel[R_BatLevel] - BATTERY_GAP)){
									R_BatLevel_Count3++;
									if(R_BatLevel_Count3 >= 5){
										R_BatLevel_Count3 = 0;
										R_BatLevel = i;
									}
								}
							}else{
								R_BatLevel_Count3 = 0;
							}
							break;
						}
					}
					if ((c_ModeBatterLow == R_WorkMode) ||(c_ModeSleep == R_WorkMode)){
						if ((R_intBatADValue < Table_BatLevel[1])){
							R_BatLevel = BAT_LVL_MIN;
						}
					}
				}
			}
		}
		
		if (R_BatLevel){
			R_BatLevel_Count0 = 0;
			fg_BatLvlInitStart = 1;
		}

//		if((fg_PowerIn) && (R_BatLevel >= 1) && (R_BatLevel <= 9)){
		if((fg_PowerIn) && (R_BatLevel < BAT_LVL_MAX)){
			if((c_ModeInit == R_WorkMode) ||(c_ModeBatterLow == R_WorkMode)){
			   //���ڳ��,LED������.
			   R_LedMode = C_LED_BREATH;
			   if (BAT_LVL_MIN == R_BatLevel){
				   fg_BatDetePowerOn = 1;
			   }
			}else{
			   //����״̬�³���.
			   R_LedMode = C_LED_ON;
			}
			
			if(c_ModeBatterLow == R_WorkMode){
				fg_ModeUpdate = 1;
				//R_WorkMode = c_ModeInit;
			}
			
		}else if((R_BatLevel >= BAT_LVL_MAX) ||((0 == fg_PowerIn) && (R_BatLevel > BAT_LVL_MIN) && (R_BatLevel < BAT_LVL_MAX))){
		   //������򲻳�絫����>=1,LED����.
		   R_LedMode = C_LED_ON;
		}else{
			if(c_ModeSleep != R_WorkMode){
			   //����=0.������,LED�������ͬʱ��˸.
			   R_BatLevel_Count0++;
			   if(R_BatLevel_Count0 >= 5){
				   R_BatLevel_Count0 = 0;
				   R_LedMode = C_LED_FLASH;
				   R_WorkMode = c_ModeBatterLow;
			   }
			}
		}

		if(((c_ModeSleep == R_WorkMode)||(c_ModeBatterLow == R_WorkMode))&&(R_BatLevel > BAT_LVL_MIN)){
			R_WorkMode = c_ModeInit;
		}
		R_intBatADValue = 0;
}

