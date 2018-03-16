#ifndef __VARIANTS_H__
#define __VARIANTS_H__
#include "MyDefine.h"

extern volatile __flag_type  _flag0;
#define flag0Byte            _flag0.byte
#define fg_BatFirstShow	     _flag0.bits.b0//no use ��ʼ������ʾ��ص���
#define fg_BatLvlInitStart   _flag0.bits.b1//��ʼ����˳����ʾ��ص����Ŀ�ʼ��־.R_intTempDisplayLevel =1 ��ʼ����.
#define fg_BatShow	    	 _flag0.bits.b2//no use ��ʾ��ص�����־,=1 ��ʾ��ص���.
#define fg_BatDetePowerOn    _flag0.bits.b3//�Ƿ����������־,=0 û�в�����,=1��������.
#define fg_TempDisplay 		 _flag0.bits.b4//���ư�һ�������ʱ����ʾ�����õ��¶� fg_TempDisplay:=1��Ҫ����R_intTempDisplay����.
#define fg_TempLock			 _flag0.bits.b5//no use �����¶�
#define fg_TempUp			 _flag0.bits.b6//no use �¶ȼ�
#define fg_TempDown			 _flag0.bits.b7//no use �¶ȼ�

extern volatile __flag_type  _flag1;
#define flag1Byte            _flag1.byte
#define fg_NoNTC   			 _flag1.bits.b0//�ж��Ƿ����NTC(����˵����Ƭ).fg_NoNTC=0 ��NTC, =1 û��NTC.
#define fg_BlinkDigitalTube	 _flag1.bits.b1//LED������ܶ�Ҫͬʱ��.
#define fg_PowerIn      	 _flag1.bits.b2//�Ƿ����������־,=0 û�в�����,=1��������.
#define fg_ModeUpdate        _flag1.bits.b3//fg_ModeUpdate: =0 �������ģʽ, =1 ��Ҫ����ģʽ.
#define fg_TempSet			 _flag1.bits.b4
#define fg_Led_PWM_On 		 _flag1.bits.b5
//_flag1.bits.b6
//_flag1.bits.b7

//Timing
extern volatile __flag_type   _TimeFlag0;
#define TimeFlag0Byte         _TimeFlag0.byte
#define fg_2ms           	  _TimeFlag0.bits.b0
#define fg_50ms               _TimeFlag0.bits.b1
#define fg_100ms              _TimeFlag0.bits.b2//no use
#define fg_150ms 			  _TimeFlag0.bits.b3
#define fg_700ms 			  _TimeFlag0.bits.b4
#define fg_2minBatLowPowerOff _TimeFlag0.bits.b5//��ص͵�2min��ػ�.
#define fg_1s                 _TimeFlag0.bits.b6
#define fg_2s                 _TimeFlag0.bits.b7


extern volatile __flag_type   _LedFlag;//fg_LedByteר����������LED�ı�־λ,fg_LedByte����0.
#define fg_LedByte            _LedFlag.byte
#define fg_LED_Off            _LedFlag.bits.b0//LED �ر�
#define fg_LED_On             _LedFlag.bits.b1//LED ����
#define fg_LED_Blink          _LedFlag.bits.b2//LED ��˸
#define fg_LED_BreathingLight _LedFlag.bits.b3//LED ������

extern volatile __flag_type  _display_data1;
#define display_data1              _display_data1.byte
#define F_display_data1_l1         _display_data1.bits.b0
#define F_display_data1_l2         _display_data1.bits.b1
#define F_display_data1_l3         _display_data1.bits.b2
#define F_display_data1_l4         _display_data1.bits.b3
#define F_display_data1_l5         _display_data1.bits.b4
#define F_display_data1_l6         _display_data1.bits.b5
#define F_display_data1_l7         _display_data1.bits.b6

extern volatile __flag_type  _display_data2;
#define display_data2              _display_data2.byte
#define F_display_data2_l1         _display_data2.bits.b0
#define F_display_data2_l2         _display_data2.bits.b1
#define F_display_data2_l3         _display_data2.bits.b2
#define F_display_data2_l4         _display_data2.bits.b3
#define F_display_data2_l5         _display_data2.bits.b4
#define F_display_data2_l6         _display_data2.bits.b5
#define F_display_data2_l7         _display_data2.bits.b6

extern volatile __flag_type  _display_data3;
#define display_data3              _display_data3.byte
#define F_display_data3_l1         _display_data3.bits.b0
#define F_display_data3_l2         _display_data3.bits.b1
#define F_display_data3_l3         _display_data3.bits.b2
#define F_display_data3_l4         _display_data3.bits.b3
#define F_display_data3_l5         _display_data3.bits.b4
#define F_display_data3_l6         _display_data3.bits.b5
#define F_display_data3_l7         _display_data3.bits.b6

extern unsigned char R_WorkMode/*,prev_mode*/;

//LED
extern unsigned char R_LedMode;		//LED ��ʾģʽ.
extern unsigned char R_LedDirFlag;           //�������������־
extern unsigned char R_LedDutyCycle;         //���ڴ��ռ�ձ�

//Temperature
extern unsigned int  R_intTempDisplayLevel;//��ʾ�¶�,���ư�һ�������ʱ����ʾ�����õ��¶�.

//==============Timing==================//
extern unsigned char R_Time100msCount;//ʱ�������
extern unsigned char R_Time50msCount;//ʱ�������
extern unsigned char R_Time150msCount;//ʱ�������
extern unsigned char R_Time700msCount;//ʱ�������
extern unsigned int  R_intTime1sCount;
extern unsigned char R_Time2sCount;

//Resistance AD Seting Temp value display.
extern unsigned int  R_intResAD_Value,R_intResAD_ValueBak;
extern unsigned int  R_intRESTempSet, R_intRESTempSetCopy;//���õ��¶�ֵ.
extern unsigned char R_UpdateTempSetCount;
extern unsigned char R_Low60Count;
extern unsigned char R_ResADCount;
extern unsigned char R_ModeChgCount;
extern unsigned char R_TimeResTempSetDisplay;

//Battery AD 
extern unsigned int  R_intBatADValue;
extern unsigned char R_BatLevel_Count0;
extern unsigned char R_BatLevel_Count1;
extern unsigned char R_BatLevel_Count2;
extern unsigned char R_BatLevel_Count3;
extern unsigned char R_BatLevel,R_BatLevelUp;

//NTC AD
//extern unsigned char R_NTCTempCECount;
extern unsigned char R_NoNTCCount;
extern unsigned int  R_intNTC_ADVal;

extern unsigned char R_PowerInCount;
extern unsigned char R_DigitalTubeDisplayLoop;
extern unsigned char led_display_data1,led_display_data2,led_display_data3;

//volatile static unsigned int Table_bt_ad_data[9]__attribute__((at(0x1a0))); 
//volatile static unsigned int Table_res_ad_data[9]__attribute__((at(0x1c0))); 
//volatile static unsigned int Table_ntc_ad_data[9]__attribute__((at(0x1e0))); 
//volatile static unsigned int T_1000ms __attribute__((at(0x1f5))); 
//volatile static unsigned int T_hot_plus __attribute__((at(0x1f8))); 
//volatile static unsigned int  no_ntc_hot_sp __attribute__((at(0x1fc)));
///////////volatile static unsigned int  R_intHeatingPWM2ms __attribute__((at(0x1b5)));
//volatile static unsigned char T_8ms __attribute__((at(0x1b7)));
///////////volatile static unsigned int  R_intNTC_CurrentTemp __attribute__((at(0x1b8)));//NTC ��ǰ�¶�ֵ.
///////////volatile static unsigned char R_NTC_AD_Count __attribute__((at(0x1ba)));
//volatile static unsigned int ntc_ad_data_cmp __attribute__((at(0x1bb)));
///////////volatile static unsigned char R_Time2Min_BTLow __attribute__((at(0x1bd)));
//volatile static unsigned int ntc_ad_data __attribute__((at(0x1be)));
extern unsigned int  R_intHeatingPWM2ms;
extern unsigned int  R_intNTC_CurrentTemp;//NTC ��ǰ�¶�ֵ.
extern unsigned char R_NTC_AD_Count;
extern unsigned char R_Time2Min_BTLow;


//Table������.
extern const unsigned char Table_DigitalTube[13];
extern const unsigned int  Table_BatChargeLevel[BAT_CHGLVL_MAX];
extern const unsigned int  Table_BatLevel[BAT_LVL_MAX];
extern const unsigned int  Table_ResData[TABLE_RES_MAX];
extern const unsigned int  Table_NTC_Data[TABLE_NTC_MAX];
//extern const unsigned int  Table_NTC_Data[251];
extern const unsigned int  Table_HeatingTimeData[26];

#if 0
README:
	1.�������ʣ�30��ɴ��¶ȹ����¶ȣ�90��ɴ�����¶�.
����˵��:
	1.�˲�Ʒ�ڳ��򲻳��״̬�¾���ʹ�á�
	2.�ڳ��״̬�£�����δ����ʱLED�����������������������Ƶ�ʲο���������������򲻳��LED������
	3.��Ť��λ���ܹ���260��ƽ�����䣬��0-59������λ��Ϊ��ʾ����״̬����������һ����ʾ����һ����̬��ʾ���ο�������
	4.����Ť�ӿ�������ת��>=60��ʱ��������ʾ����������ʾ�¶ȣ��ο���������
	5.������ʾΪ��������+�������ܹ�11����-00��-01��-02��-03��-04��-05��-06��-07��-08��-09��-10����
	  -00Ϊû�磬-10Ϊ���硣
	6.�ڷŵ�����У���û�е��ʱ��ָʾ��Ҫ��ʾ������LED������ܶ�Ҫ������ÿ2����һ�¡�
	  ������ʾΪ-00��ʾ2���Ӻ�ϵ磨��ʾ��ʱ����ȿ黹���е�ģ�
	7.��·��Ҫ֧��1��1�ȵĵ���
	8.�������¶Ⱦ�����Ҫ2�����ڡ�
	9.����صĵ������½���ʱ�����õ��¶Ȳ��ܱ仯��
#endif

#endif //__VARIANTS_H__
