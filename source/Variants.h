#ifndef __VARIANTS_H__
#define __VARIANTS_H__
#include "MyDefine.h"

extern volatile __flag_type  _flag0;
#define flag0Byte            _flag0.byte
#define fg_BatFirstShow	     _flag0.bits.b0//no use 初始化后显示电池电量
#define fg_BatLvlInitStart   _flag0.bits.b1//初始化后顺序显示电池电量的开始标志.R_intTempDisplayLevel =1 开始更新.
#define fg_BatShow	    	 _flag0.bits.b2//no use 显示电池电量标志,=1 显示电池电量.
#define fg_BatDetePowerOn    _flag0.bits.b3//是否插入充电器标志,=0 没有插充电器,=1插入充电器.
#define fg_TempDisplay 		 _flag0.bits.b4//控制按一定的相隔时间显示到设置的温度 fg_TempDisplay:=1需要更新R_intTempDisplay变量.
#define fg_TempLock			 _flag0.bits.b5//no use 锁定温度
#define fg_TempUp			 _flag0.bits.b6//no use 温度加
#define fg_TempDown			 _flag0.bits.b7//no use 温度减

extern volatile __flag_type  _flag1;
#define flag1Byte            _flag1.byte
#define fg_NoNTC   			 _flag1.bits.b0//判断是否插上NTC(或者说加热片).fg_NoNTC=0 有NTC, =1 没有NTC.
#define fg_BlinkDigitalTube	 _flag1.bits.b1//LED跟数码管都要同时闪.
#define fg_PowerIn      	 _flag1.bits.b2//是否插入充电器标志,=0 没有插充电器,=1插入充电器.
#define fg_ModeUpdate        _flag1.bits.b3//fg_ModeUpdate: =0 不需更新模式, =1 需要更新模式.
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
#define fg_2minBatLowPowerOff _TimeFlag0.bits.b5//电池低电2min后关机.
#define fg_1s                 _TimeFlag0.bits.b6
#define fg_2s                 _TimeFlag0.bits.b7


extern volatile __flag_type   _LedFlag;//fg_LedByte专门用来控制LED的标志位,fg_LedByte会清0.
#define fg_LedByte            _LedFlag.byte
#define fg_LED_Off            _LedFlag.bits.b0//LED 关闭
#define fg_LED_On             _LedFlag.bits.b1//LED 常亮
#define fg_LED_Blink          _LedFlag.bits.b2//LED 闪烁
#define fg_LED_BreathingLight _LedFlag.bits.b3//LED 呼吸灯

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
extern unsigned char R_LedMode;		//LED 显示模式.
extern unsigned char R_LedDirFlag;           //呼吸灯亮灭方向标志
extern unsigned char R_LedDutyCycle;         //用于存放占空比

//Temperature
extern unsigned int  R_intTempDisplayLevel;//显示温度,控制按一定的相隔时间显示到设置的温度.

//==============Timing==================//
extern unsigned char R_Time100msCount;//时间计数器
extern unsigned char R_Time50msCount;//时间计数器
extern unsigned char R_Time150msCount;//时间计数器
extern unsigned char R_Time700msCount;//时间计数器
extern unsigned int  R_intTime1sCount;
extern unsigned char R_Time2sCount;

//Resistance AD Seting Temp value display.
extern unsigned int  R_intResAD_Value,R_intResAD_ValueBak;
extern unsigned int  R_intRESTempSet, R_intRESTempSetCopy;//设置的温度值.
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
///////////volatile static unsigned int  R_intNTC_CurrentTemp __attribute__((at(0x1b8)));//NTC 当前温度值.
///////////volatile static unsigned char R_NTC_AD_Count __attribute__((at(0x1ba)));
//volatile static unsigned int ntc_ad_data_cmp __attribute__((at(0x1bb)));
///////////volatile static unsigned char R_Time2Min_BTLow __attribute__((at(0x1bd)));
//volatile static unsigned int ntc_ad_data __attribute__((at(0x1be)));
extern unsigned int  R_intHeatingPWM2ms;
extern unsigned int  R_intNTC_CurrentTemp;//NTC 当前温度值.
extern unsigned char R_NTC_AD_Count;
extern unsigned char R_Time2Min_BTLow;


//Table表声明.
extern const unsigned char Table_DigitalTube[13];
extern const unsigned int  Table_BatChargeLevel[BAT_CHGLVL_MAX];
extern const unsigned int  Table_BatLevel[BAT_LVL_MAX];
extern const unsigned int  Table_ResData[TABLE_RES_MAX];
extern const unsigned int  Table_NTC_Data[TABLE_NTC_MAX];
//extern const unsigned int  Table_NTC_Data[251];
extern const unsigned int  Table_HeatingTimeData[26];

#if 0
README:
	1.升温速率：30秒可达额定温度工作温度，90秒可达最高温度.
功能说明:
	1.此产品在充电或不充电状态下均可使用。
	2.在充电状态下，而且未充满时LED由亮到灭再由灭到亮（渐变的频率参考样机），充满电或不充电LED长亮。
	3.旋扭电位器总共分260档平均分配，（0-59）档的位置为显示电量状态，（电量第一次显示需做一个动态显示）参考样机。
	4.当旋扭从开机就旋转到>=60度时，就先显示电量，再显示温度（参考样机）。
	5.电量显示为：（负号+电量）总共11档（-00，-01，-02，-03，-04，-05，-06，-07，-08，-09，-10）。
	  -00为没电，-10为满电。
	6.在放电过程中，快没有电的时候，指示灯要警示灯闪（LED跟数码管都要闪），每2秒闪一下。
	  电量显示为-00警示2分钟后断电（警示的时候加热块还是有电的）
	7.线路板要支持1度1度的调。
	8.调整的温度精度需要2度以内。
	9.当电池的电量在下降的时候，设置的温度不能变化。
#endif

#endif //__VARIANTS_H__
