#include "Function.h"

//===============================================================
//function: Function_Task.
//input   : NULL.
//output  : NULL.
//description: none.
//===============================================================
void Function_Task(void)
{

}

#if 0
void Mode_Set(unsigned char new_mode)
{
	prev_mode = R_WorkMode;
	R_WorkMode = new_mode;
}

 unsigned char Mode_Get(void)
{
	return R_WorkMode;
}
 
 unsigned char PrevMode_Get(void)
 {
	 return prev_mode;
 }
#endif
//===============================================================
//function: HaltMode_Init.
//input   : NULL.
//output  : NULL.
//description: none.
//===============================================================
void HaltMode_Init(void)
{
	GCC_CLRWDT();
	/* I/O Initial */
	//pa0:NULL, pa1:O, pa2:NULL, pa3:O, pa4:I AD, pa5:O, pa6:O, pa7:TP1(PWM)O
	_pa = 0xFF;//PA7(TP1)PWM ���.
	_pac = 0xFF;
	_papu = 0x00;
	//pb0:I AD, pb1:I (INT1), pb2:I AD, pb3~pb6:O
	_pb = 0xBF;
	_pbc = 0xBF;
	_pbpu = 0x02;
	// pc0~pc2:O	 
	_pc = 0xFF;
	_pcc = 0xFF;
	_pcpu = 0x00;

	// in adcr0
	_adoff = 1;				//close	adc
	
	_tmpc = 0x00;
	_t0on =	0;
	_t1on =	0;
	_tbon =	0;
}

//===============================================================
//function: Halt_Sleep0.
//input   : NULL.
//output  : NULL.
//description: none.
//===============================================================
void Halt_Sleep0(void)
{
	_idlen = 0;
	_lvden = 0;
	/*��������ģʽ0,CPU��fSUB �� fS ֹͣ���У����Ź���ʱ�����ܳ��ܡ�*/
	GCC_HALT();
}

//===============================================================
//function: ModeSleep.
//input   : NULL.
//output  : NULL.
//description: �͵�ѹ2min��������ģʽ.
//===============================================================
void ModeSleep(void)
{
	fg_TempSet = 0;
	//�رռ���Ƭ.
	if(P_HEATING)P_HEATING = 0;//�رռ���.
#if 1
	//Digital tube	& LED
	if(LED_PWM_T1ON){
		LED_PWM_T1CP = 0;
		LED_PWM_T1ON = 0;
	}
	if(!P_LED)P_LED = 1;//P_LED Off
	fg_BlinkDigitalTube = 0;
	COM1 = COM2 = COM3 = 0;
#endif
	HaltMode_Init();
	//INT1S1��INT1S0��INT1(PB1)���жϱ��ؿ���λ,01:�������ж�.
	_int1s1 = 0;
	_int1s0 = 1;
	_int1e = 1;//INT1 �жϿ���λ,=1 ʹ��.
	_int1f = 0;//INT1 �ж������־λ,��0.
	Halt_Sleep0();
	//���߻��Ѻ�,����HALTָ����濪ʼִ��.
	_int1e = 0;//INT1 �жϿ���λ,=0 ����.
	_int1f = 0;//INT1 �ж������־λ,��0.
	
	fg_ModeUpdate = 1;
//	if(P_LED )P_LED = 0;
}

//===============================================================
//function: Power_StatusDete ��������
//input   :	NULL.
//output  :	NULL.
//description: x ms����ִ��һ�δ˺���.��־F_power_in=1 ����������F_power_in=0 û������.
//===============================================================
void Power_StatusDete(void)
{
	if(1 == P_POWER_IN){
		if(R_PowerInCount<5){
			R_PowerInCount++;
			if(R_PowerInCount>=3){
				fg_PowerIn = 1;
			}
		}
	}else{
		if(R_PowerInCount){
			R_PowerInCount--;
		}else{
			fg_PowerIn = 0;
		}
	}
}

//===============================================================
//function: Battery_LevelPro
//input   :	NULL.
//output  :	NULL.
//description: ���µ����ȼ�R_BatLevelUp:0~10.
//===============================================================
void Battery_LevelPro(void)
{
	if (fg_BatLvlInitStart){
		if(R_BatLevelUp != R_BatLevel){
			if(R_BatLevelUp < R_BatLevel){
				if(BAT_LVL_MAX > R_BatLevelUp)R_BatLevelUp++;
			}else{
				if(R_BatLevelUp) R_BatLevelUp--;
			}
		}else{
			fg_BatLvlInitStart = 0;
		}
	}
}

//===============================================================
//function: TempDisplay_LevelPro
//input   :	NULL.
//output  :	NULL.
//description: �����¶ȵȼ� R_intTempDisplayLevel,����Ҫ����ʱ��Ҫ��һ��ʱ��������һ��.
//===============================================================
void TempDisplay_LevelPro(void)
{
	if (!fg_NoNTC){
		if(fg_TempDisplay){
			if (R_intTempDisplayLevel != R_intRESTempSet){
				if (R_intTempDisplayLevel < R_intRESTempSet){
					R_intTempDisplayLevel++;
				}else{
					if(R_intTempDisplayLevel)R_intTempDisplayLevel--;
				}
			}else{
				fg_TempDisplay = 0;
			}
		}
	}
}

//===============================================================
//function: LEDDisplay
//input   :	NULL.
//output  :	NULL.
//description: P_LED=0 On, P_LED=1 Off.
//===============================================================
void LEDDisplay(void)
{
	if(c_ModeSleep == R_WorkMode)
	{ 		
		//Digital tube	& LED
		if(LED_PWM_T1ON){
			LED_PWM_T1CP = 0;
			LED_PWM_T1ON = 0;
		}
		if(!P_LED)P_LED = 1;//P_LED Off
		fg_BlinkDigitalTube = 0;
		COM1 = COM2 = COM3 = 0;
		return;
	}
	
	if (C_LED_BREATH != R_LedMode){
		if(LED_PWM_T1ON){
			LED_PWM_T1CP = 0;
			LED_PWM_T1ON = 0;
		}
	}
	if(C_LED_FLASH != R_LedMode)	fg_BlinkDigitalTube = 0;
	
	switch (R_LedMode)
	{
		case C_LED_ON://LED On,����.
			if(P_LED)P_LED = 0;
			break;
			
		case C_LED_BREATH://������.
			if(!LED_PWM_T1ON){
				P_LED = 0;
				LED_PWM_T1CP = 1;
				LED_PWM_T1ON = 1;
				PWMChange(C_PWM_PERIO_INIT,C_PWM_DUTY_INIT);//Ϊ�˼���LED������������ģʽ�л�ʱ����˸��,PWMռ�ձȳ�ʼΪ100%.
			}
			break;
			
		case C_LED_FLASH://��˸.
			P_LED = 1;
			fg_BlinkDigitalTube = 1;
			break;
		
		case C_LED_OFF://LED Off,��
			if(!P_LED )P_LED = 1;
			break;
			
		default:
			break;
	}
}

//===============================================================
//function: PWMChange
//input   :	Period,R_LedDutyCycle.
//output  :	NULL.
//description: PWM���ں�ռ�ձȵ���.
//===============================================================
void PWMChange(unsigned int Period,unsigned char DutyCycle)
{
 	//Period���ڵ�λΪ2uS,Periodȡֵ��Χ��1~1024,DutyCycleȡֵ��Χ��1~100
	unsigned int Duty;
	_tm1rpl = Period%256;		//���ڼĴ���
	_tm1rph = Period>>8;// 256		

	Duty = Period*DutyCycle/100;
	_tm1al = Duty%256 ;
	_tm1ah = Duty>>8 ;// 256   //ռ�ձȼĴ���					
}

//===============================================================
//function: DataProcessing
//input   :	NULL.
//output  :	NULL.
//description: ��Ҫ��ʾ�����ݴ���.
//===============================================================
void DataProcessing(void)
{

	switch (R_WorkMode)
	{
		case c_ModeInit:
			if (R_BatLevelUp >= R_BatLevel){
				R_BatLevelUp = R_BatLevel;
			}
			led_display_data1=R_BatLevelUp%10;
			led_display_data2=(R_BatLevelUp%100)/10;
			led_display_data3=0x0a;//��ʾ����(0x0a:'-')(����Ť�ӿ�������ת��>=60��ʱ��������ʾ����������ʾ�¶ȣ�
			break;
			
		case c_ModeBatterLow:
			led_display_data1=R_BatLevel%10;
			led_display_data2=(R_BatLevel%100)/10;
			led_display_data3=0x0a;
			break;
			
		case c_ModeHeating:
			if (R_intRESTempSet<TEMP_SET_MIN){
				led_display_data1=R_BatLevel%10;
				led_display_data2=(R_BatLevel%100)/10;
				led_display_data3=0x0a;
			}else{
				if(R_TimeResTempSetDisplay < 80 || fg_NoNTC)
				{
					//��ʾ�����¶�
					led_display_data1=R_intRESTempSet%10;
					led_display_data2=(R_intRESTempSet%100)/10;
					led_display_data3=R_intRESTempSet/100;
					R_intTempDisplayLevel = R_intNTC_CurrentTemp;
				}
				else
				{
					fg_TempSet = 1;
					fg_TempDisplay = 1;
					#if 0
					//��ʾ��ǰʵʱ�¶�
					led_display_data1=R_intNTC_CurrentTemp%10;
					led_display_data2=(R_intNTC_CurrentTemp%100)/10;
					led_display_data3=R_intNTC_CurrentTemp/100;//��ʾ��ǰ�¶�
					#else
					//��ʾ�¶�
					led_display_data1=R_intTempDisplayLevel%10;
					led_display_data2=(R_intTempDisplayLevel%100)/10;
					led_display_data3=R_intTempDisplayLevel/100;
					#endif
				}
				
				if(0 >= led_display_data3 )
				{
					led_display_data3=0x0C;
				}
			}
			break;
						
		case c_ModeSleep:
	        led_display_data1=0X0C;
	        led_display_data2=0X0C;
	        led_display_data3=0X0C;
			break;
			
		default:
			led_display_data1=R_BatLevel%10;
			led_display_data2=(R_BatLevel%100)/10;
			led_display_data3=0x0a;
			break;
	}
	
	display_data1=Table_DigitalTube[led_display_data1];
	display_data2=Table_DigitalTube[led_display_data2];
	display_data3=Table_DigitalTube[led_display_data3];
}

//===============================================================
//function: Time_Base
//input   :	NULL.
//output  :	NULL.
//description:ÿ2ms���뺯��ִ��һ��.
//===============================================================
void Time_Base(void)
{		
	if(fg_BlinkDigitalTube){
		if (++R_Time100msCount >= C_100MS){
			R_Time100msCount = 0;
			fg_100ms = 1;
			if(c_ModeSleep != R_WorkMode) P_LED = 0;
			fg_BlinkDigitalTube = 0;
		}
	}else{		
		R_Time100msCount = 0;
	}
	
	if (++R_Time150msCount >= C_150MS){
		R_Time150msCount = 0;
		fg_150ms = 1;
	}
	
	if(++R_Time50msCount >= C_50MS)
	{
		R_Time50msCount = 0x00;
		fg_50ms = 1;

		if (++R_Time700msCount >= C_700MS){
			R_Time700msCount = 0;
			fg_700ms = 1;
		}
		
		if (++R_Time2sCount >= C_2S){
			R_Time2sCount = 0;
			fg_2s = 1;

			if(c_ModeBatterLow == R_WorkMode){
				if(++R_Time2Min_BTLow >= C_2MIN_BAT_LOW_SLEEP){
					R_Time2Min_BTLow = C_2MIN_BAT_LOW_SLEEP;
					fg_2minBatLowPowerOff = 1;
				}
			}else{
				R_Time2Min_BTLow = 0;
			}
		}
		
		if(R_TimeResTempSetDisplay<250){
		    ++R_TimeResTempSetDisplay;
		}
	}
}

