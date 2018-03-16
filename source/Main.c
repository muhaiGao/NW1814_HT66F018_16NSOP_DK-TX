//**************************************************************************************
//                                                                                     *
//                    ProductName:	HT66F018-20NSOP DK_TX(典控檀香控制器)                     *
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
//HT66F018-16NSOP 典控檀香控制器-NW1814-Checksum-版本号

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
					P_HEATING = 0;//关闭加热.
//					BatAD_Dete();//电压检测.
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
		
			/* 计时函数 */
			Time_Base();
		
			ResAD_Dete();
		
			NTC_AD_Dete();
			
			/*********************************************************************************
			 *函数内嵌太多,代码移到此处,目前函数内嵌2层.
			 *fg_1s:定时1s;
			 *P_HEATING:=0 关闭加热片,=1加热;
			 *R_intHeatingPWM2ms:1s(500*2ms)时间内,当计数值R_intTime1sCount大于等于hot_pwm_data时开始加热.
			 *			   R_intHeatingPWM2ms=0 一直加热,>=500 关闭加热.
			 *BatAD_Dete():电量检测.
			 **********************************************************************************/
			R_intTime1sCount++;
			if(R_intTime1sCount >= C_1S){//Timing 1s
				R_intTime1sCount = 0;
				fg_1s = 1;
				P_HEATING = 0;//关闭加热.
				BatAD_Dete();//关闭加热后电池电压检测.
			}
			if((c_ModeHeating == R_WorkMode) || (c_ModeBatterLow == R_WorkMode)){
				if (R_intTime1sCount >= R_intHeatingPWM2ms){
					P_HEATING = 1;//加热.
				}
			}else{
				P_HEATING = 0;//关闭加热.
			}
		}
		
		if(fg_50ms){
			fg_50ms = 0;
			Power_StatusDete();
		
			DataProcessing();
		}
		//显示温度,控制按一定的相隔时间显示到设置的温度.		
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

