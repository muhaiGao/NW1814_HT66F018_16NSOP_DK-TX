#ifndef __MYDEFINE__
#define __MYDEFINE__
#include <HT66F018.h>
//================== macro define ================
typedef unsigned char __sfr_byte;
typedef unsigned int	uint;
typedef unsigned char	uchar;

typedef struct {
	unsigned char b0 : 1;
	unsigned char b1 : 1;
	unsigned char b2 : 1;
	unsigned char b3 : 1;
	unsigned char b4 : 1;
	unsigned char b5 : 1;
	unsigned char b6 : 1;
	unsigned char b7 : 1;
} __flag_bits;

typedef union {
	__flag_bits bits;
	__sfr_byte	byte;
} __flag_type;

//IO Define
//#define  L6         	_pa0
#define  COM3       	_pa1
//#define  ZD         	_pa2
#define  COM2       	_pa3
#define  NTC_AD     	_pa4
#define  L3         	_pa5
#define  L4         	_pa6
#define  P_LED        	_pa7 //0:On,	 1:Off
#define  P_LED_C        _pac7//0:output, 1:input
#define  LED_PWM_T1CP   _t1cp//TP1(PWM) 引脚控制位:=0 除能, =1 使能;
#define  LED_PWM_T1ON   _t1on//TM1 使能位:=0 除能，=1 使能;

#define  BT_AD      	_pb0
#define  P_POWER_IN  	_pb1
#define  RES_AD     	_pb2
#define  L7        	 	_pb3
#define  L5         	_pb4
#define  L1         	_pb5
#define  P_HEATING    	_pb6
#define  P_HEATING_C    _pbc6

#define  L2         	_pc0
#define  L6         	_pc1
#define  COM1       	_pc2

//Mode Define
#define	c_ModeInit			0//初始状态.
#define	c_ModeHeating		1//加热.
#define c_ModeBatterLow		2//电压低.
#define c_ModeSleep		    3//关机.

/*********************** TIME ***********************/
#define	C_50MS				 25		//2mS*25=50MS
#define	C_100MS				 75		//2mS*50=150MS
#define	C_150MS				 75		//2mS*75=150MS
#define	C_700MS				 14		//50mS*14=700MS
#define	C_1S				 500	//2mS*500=2S
#define	C_2S				 40		//50mS*40=2S
#define	C_2MIN_BAT_LOW_SLEEP 60		//2S*60=2min
/************************ TIME ****************************/

/************************ LED ****************************/
#define C_LED_OFF					0
#define C_LED_ON					1
#define C_LED_FLASH					2
#define C_LED_BREATH				3
#define C_LED_BREATH_SPEED 		    17   //Breathing light 呼吸灯亮灭速度控制 值越小速度越快.
//Period周期单位为2uS,Period取值范围是1~1024,DutyCycle取值范围是0~Period
#define C_PWM_PERIO_INIT			200
#define C_PWM_DUTY_INIT				200

/************************ LED ****************************/


/************************ DigitalTube ****************************/
#define C_DIGITAL_TUBE_LOOP  		6
/************************ DigitalTube ****************************/



//Battery 电量监测.
#define BATTERY_GAP 		15//15
#define BATTERY_GAP1 		27//20
#define BATTERY_CHGGAP 		270//75 //U:0.1V <--> AD:27
#define BAT_LVL_MAX  		10//11//电池.
#define BAT_CHGLVL_MAX  	10//11//插充电器.

//Res AD 温度设置.
#define TEMP_SET_MAX		260//要求最高温度
#define TEMP_SET_MIN		60//要求设置最低温度
#define TABLE_RES_MAX  		202 //RES AD 数组大小.
#define RES_ARRAY_ADJ  	    59//温度设置为:60~260(201个),而温度档位数组下标为:0~201(202个),对应起来需要调整.
#define RES_AD_MIN  	    257  //最小档位的AD值:      60摄氏度.
#define RES_AD_MAX  	    4076 //最大档位的AD值:      260摄氏度.
#define RES_AD_GAP  	    10   //设置温度时，档位调节时AD至小相差RES_AD_GAP才确认更改设置温度.
#define RES_AD_GAP1  	    10//(RES_AD_GAP-4)
#define RES_AD_GAP2  	    47//(RES_AD_GAP<<2)

//NTC AD 温度监测.
#define NTC_AD_DETE  	    4075//4040//判断是否插上NTC，大于NTC_AD_DETE时，没NTC(加热片).细微调整.测试空载:4018-4023
#define TABLE_NTC_MAX  		253//213  //NTC AD 数组大小.
/*NTC_ARRAY_ADJ
 *温度设置为:60~260(201个),而NTC数组下标为:0~212(213个),50摄氏度到260摄氏度，
 *另外有两个数用来调整加热,对应起来需要调整.
 */
#define NTC_ARRAY_ADJ  	    10//50
#define NTC_AD_GAP	  	    10


/************************ ADC ************************************/
#define C_ADC_CH0		 	0b00010000//AN0 _pb0
#define C_ADC_CH2		 	0b00010010//AN2 _pb2
#define C_ADC_CH3		 	0b00010011//AN3 _pa4
/************************ ADC ************************************/

#endif//__MYDEFINE__
