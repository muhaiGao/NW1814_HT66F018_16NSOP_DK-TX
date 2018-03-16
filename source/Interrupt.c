#include "Interrupt.h"
//#pragma vector INT0_ISR   @0x04
//#pragma vector CP_ISR     @0x08
//#pragma vector MF0_ISR    @0x0C//TM0
//#pragma vector MF1_ISR    @0x10//TM1,TM2
//#pragma vector MF2_ISR 	@0x14//LVD,EEPROM
//#pragma vector ADC_ISR    @0x18
//#pragma vector TB0_ISR    @0x1C
//#pragma vector TB1_ISR    @0x20
//#pragma vector INT1_ISR   @0x24
//void __attribute((interrupt(0x0C))) MF0_ISR(void)

//===============================================================
//function: MF0_ISR
//input   :	NULL.
//output  :	NULL.
//description:中断2ms,Timing.
// 			   3组合数码管,共阳. 7段:a,b,c,a,e,f,g.
//			   eg:数码管1的a段亮-->P_DT_COM1=1,P_DT_L1=0.
//===============================================================
void MF0_ISR(void)
{
	_t0af=0;                    //清定时标志位
	fg_2ms=1;                //标志位置1

	P_DT_COM1=P_DT_COM2=P_DT_COM3=0;
	P_DT_L1=P_DT_L2=P_DT_L3=P_DT_L4=P_DT_L5=P_DT_L6=P_DT_L7=1;
	if(c_ModeSleep == R_WorkMode) return;
	if (!fg_BlinkDigitalTube){
		
		if(++R_DigitalTubeDisplayLoop>C_DIGITAL_TUBE_LOOP){
			R_DigitalTubeDisplayLoop=0x00;
		}
		switch(R_DigitalTubeDisplayLoop)
		{
			case 0x00:
				if(F_display_data1_l1)
					P_DT_COM1=1;
				if(F_display_data2_l1)
					P_DT_COM2=1;
				if(F_display_data3_l1)
					P_DT_COM3=1;
				P_DT_L1=0;
				break;
			case 0x01:
				if(F_display_data1_l2)
					P_DT_COM1=1;
				if(F_display_data2_l2)
					P_DT_COM2=1;
				if(F_display_data3_l2)
					P_DT_COM3=1;
				P_DT_L2=0;
				break;
			case 0x02:
				if(F_display_data1_l3)
					P_DT_COM1=1;
				if(F_display_data2_l3)
					P_DT_COM2=1;
				if(F_display_data3_l3)
					P_DT_COM3=1;
			  	P_DT_L3=0;
				break;
			case 0x03:
				if(F_display_data1_l4)
					P_DT_COM1=1;
				if(F_display_data2_l4)
					P_DT_COM2=1;
				if(F_display_data3_l4)
					P_DT_COM3=1;
				P_DT_L4=0;
				break;
			case 0x04:
				if(F_display_data1_l5)
					P_DT_COM1=1;
				if(F_display_data2_l5)
					P_DT_COM2=1;
				if(F_display_data3_l5)
					P_DT_COM3=1;
				else
					P_DT_COM3=0;
				P_DT_L5=0;
				break;
			case 0x05:
				if(F_display_data1_l6)
					P_DT_COM1=1;
				if(F_display_data2_l6)
					P_DT_COM2=1;
				if(F_display_data3_l6)
					P_DT_COM3=1;
				P_DT_L6=0;
				break;
			case 0x06:
				if(F_display_data1_l7)
					P_DT_COM1=1;
				if(F_display_data2_l7)
					P_DT_COM2=1;
				if(F_display_data3_l7)
					P_DT_COM3=1;
				P_DT_L7=0;
				break;
			default:
			  	break;
		}
	}
}

//===============================================================
//function: MF1_ISR
//input   :	NULL.
//output  :	NULL.
//description:PWM占空比调整.8us中断一次.
//===============================================================
void MF1_ISR(void)
{
    static u8 i = 0;	
	_t1af=0; //清除中断标志位	
	if(_t1pf){
		_t1pf = 0;
		i++;
		if(i>=C_LED_BREATH_SPEED){
			i = 0;
			if(R_LedDirFlag == 1){
			     R_LedDutyCycle++;
			     _tm1al = R_LedDutyCycle ;
				 _tm1ah = 0;   //占空比寄存器
			     if(R_LedDutyCycle>=185){//C_PWM_PERIO_INIT
			     	R_LedDirFlag = 0;		
			     }
			}else{
				R_LedDutyCycle--;
				_tm1al = R_LedDutyCycle ;
				_tm1ah = 0;   //占空比寄存器
				if(R_LedDutyCycle <= 4){
					R_LedDirFlag = 1;		
				}		
			}			
		}				
	}
}

