//**************************************************************************************
//                                                                                     *
//                    ProductName:	HT66F018-20NSOP DK_TX(���̴�������)                     *
//                    MCU Body:		HT66F018-20NSOP 		                   	       *
//                    HT-IDE3000:   V7.94	                                           *
//                    Date:         2018/01/18                                   	   *
//                    Author:       DANNY                                              *
//                    Company:      New Wave Eelectronics (ShenZhen) LTD.              *
//                                                                                     *
//**************************************************************************************
//                                                                                     *
//              	 	Files Required:  											   *
//                                                                                     *
//**************************************************************************************
//   Configuration Option Setting:                                                     *
//**************************************************************************************
//                                                                                     *
//   		 		Notes: 	1.Fsys = 8M(HIRC) 										   *
//						   	2.VDD =	5V											       *
//						   	3.WDT ENABLE	(4S)									   *
//							                                                           *
//**************************************************************************************
//
//	Revision History:
//			1.Initial on 2018/01/18
//			2.Completed on 2018/02/6
//HT66F018-16NSOP ���̴�������-NW1814-Checksum-�汾��

#include "Main.h"
void main(void)
{
//=========== System Reset =======================
	Sys_Init();
	if (!_to)
	{
		RAM_Init();
		User_Init();
	}
//=========== Main Loop ==========================
	while(1)
	{
		GCC_CLRWDT();
		switch (R_WorkMode)
		{
			case c_ModeInit:
				if(fg_150ms){
					fg_150ms = 0;
					P_HEATING = 0;//�رռ���.
//					BatAD_Dete();//��ѹ���.
					Battery_LevelPro();
					if(R_BatLevelUp >= R_BatLevel){
						if(fg_ModeUpdate){
							fg_ModeUpdate = 0;
							R_WorkMode = c_ModeHeating;
						}
					}
				}
				break;
				
			case c_ModeHeating:
				if(fg_ModeUpdate){
					fg_ModeUpdate = 0;
					R_WorkMode = c_ModeInit;
				}
				break;
				
			case c_ModeBatterLow:
				if (fg_2minBatLowPowerOff){
					fg_2minBatLowPowerOff = 0;
					R_WorkMode = c_ModeSleep;
				}
				if(fg_ModeUpdate){
					fg_ModeUpdate = 0;
					R_WorkMode = c_ModeInit;
				}
				break;
				
			case c_ModeSleep:
				ModeSleep();
				if(fg_ModeUpdate){
					fg_ModeUpdate = 0;
					R_WorkMode = c_ModeInit;
				//=========== System Reset =======================
					Sys_Init();
					RAM_Init();
					User_Init();
				}
				break;
				
			default:
				R_WorkMode = c_ModeInit;
				break;
		}
		
		if(fg_2ms){
			fg_2ms = 0;
		
			/* ��ʱ���� */
			Time_Base();
		
			ResAD_Dete();
		
			NTC_AD_Dete();
			
			/*********************************************************************************
			 *������Ƕ̫��,�����Ƶ��˴�,Ŀǰ������Ƕ2��.
			 *fg_1s:��ʱ1s;
			 *P_HEATING:=0 �رռ���Ƭ,=1����;
			 *R_intHeatingPWM2ms:1s(500*2ms)ʱ����,������ֵR_intTime1sCount���ڵ���hot_pwm_dataʱ��ʼ����.
			 *			   R_intHeatingPWM2ms=0 һֱ����,>=500 �رռ���.
			 *BatAD_Dete():�������.
			 **********************************************************************************/
			R_intTime1sCount++;
			if(R_intTime1sCount >= C_1S){//Timing 1s
				R_intTime1sCount = 0;
				fg_1s = 1;
				P_HEATING = 0;//�رռ���.
				BatAD_Dete();//�رռ��Ⱥ��ص�ѹ���.
			}
			if((c_ModeHeating == R_WorkMode) || (c_ModeBatterLow == R_WorkMode)){
				if (R_intTime1sCount >= R_intHeatingPWM2ms){
					P_HEATING = 1;//����.
				}
			}else{
				P_HEATING = 0;//�رռ���.
			}
		}
		
		if(fg_50ms){
			fg_50ms = 0;
			Power_StatusDete();
		
			DataProcessing();
		}
		//��ʾ�¶�,���ư�һ�������ʱ����ʾ�����õ��¶�.		
		if(fg_700ms){
			fg_700ms = 0;
			TempDisplay_LevelPro();
		}
		
		if(fg_1s){
			fg_1s = 0;
		}
		
		if(fg_2s){
			fg_2s = 0;
			LEDDisplay();
		}
	}
}

