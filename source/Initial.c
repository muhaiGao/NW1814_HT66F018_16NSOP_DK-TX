#include "Initial.h"

//===============================================================
// void Sys_Init (void)
//===============================================================
void Sys_Init(void)
{	 
	/* I/O Initial */
	//pa0:NULL, pa1:O, pa2:NULL, pa3:O, pa4:I AD, pa5:O, pa6:O, pa7:TP1(PWM)O
	_pa = 0xF0;//PA7(TP1)PWM 输出.
	_pac = 0x00;
	_papu = 0x00;
	//pb0:I AD, pb1:I (INT1), pb2:I AD, pb3~pb6:O
	_pb = 0x1F;
	_pbc = 0x07;
	_pbpu = 0x02;
	// pc0~pc2:O	 
	_pc = 0x03;
	_pcc = 0x00; 
	_pcpu = 0x00;

/*
	WDTC 寄存器
	Bit 7~3 WE4~WE0：WDT 软件控制位
		10101：除能
		01010：使能
		其它值：MCU 复位
		若因外部环境噪声使 WE[4:0] 值发生改变，则在 2~3 个 LIRC 周期后产生复位，
		复位后 CTRL 寄存器中的 WRF 标志位会被置位。
	Bit 2~0 WS2~WS0：WDT 溢出周期选择位
		000：2^8/fS
		001：2^10/fS
		010：2^12/fS
		011：2^14/fS
		100：2^15/fS
		101：2^16/fS
		110：2^17/fS
		111：2^18/fS
	*/
	_wdtc = 0b01010110;//使能,2^17/fS 4s溢出
		
	/*      
	_____________________________________
	|	TM0		|	TM1		|	TM2		|
    |-----------|-----------|-----------|
	|16-bit STM |10-bit PTM |16-bit CTM |
	|-----------|-----------|-----------|
		TM 名称 / 类型参考
    ___________________________
	| CTM | STM | PTM | 寄存器|
	|-------------------------|
	| TP2 | TP0 | TP1 | TMPC  |
	|-------------------------|
		TM 输出引脚
	*/
	/*TMPC
	Bit 7 CLOP：CLO 引脚控制位
		0：除能
		1：使能
	Bit 6~3 未使用，读为“0”
	Bit 2 T2CP：TP2 引脚控制位
		0：除能
		1：使能
	Bit 1 T1CP：TP1 引脚控制位
		0：除能
		1：使能
	Bit 0 T0CP：TP0 引脚控制位
		0：除能
		1：使能
	*/
	//TP,PWM
	_tmpc   = 0x02;			//TP1(PA7) for PWM 用作呼吸灯.
	/*
	TM0C0
	Bit 7 TnPAU：TMn 计数器暂停控制位
		0：运行
		1：暂停
		通过设置此位为高可使计数器暂停，清零此位恢复正常计数器操作。当处于暂
		停条件时，TM 保持上电状态并继续耗电。当此位由低到高转换时，计数器将保
		留其剩余值，直到此位再次改变为低电平，并从此值开始继续计数。
	Bit 6~4 TnCK2~TnCK0：选择 TMn 计数时钟位
		000：fSYS/4
		001：fSYS
		010：fH/16
		011：fH/64
		100：fTBC
		101：fH/8
		110：TCKn 上升沿时钟
		111：TCKn 下降沿时钟
		此三位用于选择 TM 的时钟源。外部引脚时钟源能被选择在上升沿或下降沿有
		效。fSYS 是系统时钟，fH 和 fTBC 是其它的内部时钟源，细节方面请参考振荡器章
		节。
	Bit 3 TnON：TMn 计数器 On/Off 控制位
		0：Off
		1：On
		此位控制 TM 的总开关功能。设置此位为高则使能计数器使其运行，清零此位
		则除能 TM。清零此位将停止计数器并关闭 TM 减少耗电。当此位经由低到高转
		换时，内部计数器将被清零，当此位经由高到低转换时，内部计数器将保持其
		剩余值，直到此位再次改变为高电平。
		若 TM 处于比较匹配输出模式时 ( 通过 TnOC 位指定 )，当 TnON 位经由低到高
		的转换时，TM 输出脚将重置其初始值。
	Bit 2~0 未定义，读为“0”

	//TM0C1
	Bit 7~6 TnM1~TnM0：选择 TMn 工作模式位
		00：比较匹配输出模式
		01：捕捉输入模式
		10：PWM 模式或单脉冲输出模式
		11：定时 / 计数器模式
		这两位设置 TM 需要的工作模式。为了确保操作可靠，TM 应在 TnM1 和 TnM0
		位有任何改变前先关掉。在定时 / 计数器模式，TM 输出脚控制必须除能。
	Bit 5~4 TnIO1~TnIO0：选择 TPn 输出功能位
		比较匹配输出模式
		00：无变化
		01：输出低
		10：输出高
		11：输出翻转
		PWM 模式 / 单脉冲输出模式
		00：强制无效状态
		01：强制有效状态
		10：PWM 输出
		11：单脉冲输出
		捕捉输入模式
		00：在 TM 捕捉输入脚上升沿输入捕捉
		01：在 TM 捕捉输入脚下降沿输入捕捉
		10：在 TM 捕捉输入脚双沿输入捕捉
		11：输入捕捉除能
		定时 / 计数器模式
		未使用
	Bit 3 TnOC：TPn 输出控制位
		比较匹配输出模式
		0：初始低
		1：初始高
		PWM 模式 / 单脉冲输出模式
		0：低有效
	1：高有效
	Bit 2 TnPOL：TPn 输出极性控制位
		0：同相
		1：反相
		此位控制 TPn 输出脚的极性。此位为高时 TM 输出脚反相，为低时 TM 输出脚
		同相。若 TM 处于定时 / 计数器模式时其不受影响。
	Bit 1 TnDPX：TMn PWM 周期 / 占空比控制位
		0：CCRP - 周期；CCRA - 占空比
		1：CCRP - 占空比；CCRA - 周期
		此位决定 CCRA 与 CCRP 寄存器哪个被用于 PWM 波形的周期和占空比控制。
	Bit 0 TnCCLR：选择 TMn 计数器清零条件位
		0：TMn 比较器 P 匹配
		1：TMn 比较器 A 匹配

	*/
	/*TM0: Timming*/
	_tm0c0 = 0x30; //运行,clk:fH/64,  PTnON:Off
	_tm0c1 = 0xc1; //定时,TM0 比较器 A 匹配.
	_tm0al = 0xFA;//0xFA=250,FptmClk = fH/64;Tn = T*ARR(自动装载数),125:1ms,250:2ms
	_tm0ah = 0x00; 
	_t0on = 0; 
	
	/*TM1C0
	Bit 7 TnPAU：TMn 计数器暂停控制位
		0：运行
		1：暂停
		通过设置此位为高可使计数器暂停，清零此位恢复正常计数器操作。当处于暂
		停条件时，TM 保持上电状态并继续耗电。当此位由低到高转变时，计数器将保
		留其剩余值，直到此位再次改变为低电平，并从此值开始继续计数。
	Bit 6~4 TnCK2~TnCK0：选择 TMn 计数时钟位
		000：fSYS/4
		001：fSYS
		010：fH/16
		011：fH/64
		100：fTBC
		101：fH
		110：TCKn 上升沿
		111：TCKn 下降沿
		此三位用于选择 TM 的时钟源。外部引脚时钟源能被选择在上升沿或下降沿有
		效。fSYS 是系统时钟，fH 和 fTBC 是其它的内部时钟源，细节方面请参考振荡器章
		节。
	Bit 3 TnON：TMn 计数器 On/Off 控制位
		0：Off
		1：On
		此位控制 TM 的总开关功能。设置此位为高则使能计数器使其运行，清零此位
		则除能 TM。清零此位将停止计数器并关闭 TM 减少耗电。当此位经由低到高转
		变时，内部计数器将复位清零；当此位经由高到低转换时，内部计数器将保持
		其剩余值，直到此位再次改变为高电平。
		若 TM 处于比较匹配输出模式时 ( 通过 TnOC 位指定 )，当 TnON 位经由低到高
		的转变时，TM 输出脚将重置其初始值。
	Bit 2~0 未定义，读为“0”

	//TM1C1
	Bit 7~6 TnM1~TnM0：选择 TMn 工作模式位
		00：比较匹配输出模式
		01：捕捉输入模式
		10：PWM 模式或单脉冲输出模式
		11：定时 / 计数器模式
		这两位设置 TM 需要的工作模式。为了确保操作可靠，TM 应在 TnM1 和 TnM0
		位有任何改变前先关掉。在定时 / 计数器模式，TM 输出脚控制必须除能。
	Bit 5~4 TnIO1~TnIO0：选择 TPn 输出功能位
		比较匹配输出模式
		00：无变化
		01：输出低
		10：输出高
		11：输出翻转
		PWM 模式 / 单脉冲输出模式
		00：强制无效状态
		01：强制有效状态
		10：PWM 输出
		11：单脉冲输出
		捕捉输入模式
		00：在 TPn 或 TCKn 上升沿输入捕捉
		01：在 TPn 或 TCKn 下降沿输入捕捉
		10：在 TPn 或 TCKn 双沿输入捕捉
		11：输入捕捉除能
		定时 / 计数器模式
		未使用
	Bit 3 TnOC：TPn 输出控制位
		比较匹配输出模式
		0：初始低
		1：初始高
		PWM 模式 / 单脉冲输出模式
		0：低有效
		1：高有效
	Bit 2 TnPOL：TPn 输出极性控制位
		0：同相
		1：反相
		此位控制 TPn 输出脚的极性。此位为高时 TM 输出脚反相，为低时 TM 输出脚
		同相。若 TM 处于定时 / 计数器模式时其不受影响。
	Bit 1 TnCAPTS：选择 TMn 捕捉触发源
		0：来自 TPn 引脚
		1：来自 TCKn 引脚
	Bit 0 TnCCLR：选择 TMn 计数器清零条件位
		0：TMn 比较器 P 匹配
		1：TMn 比较器 A 匹配

	*/
	/*TM1初始化用于呼吸灯控制.*/
	_tm1c0  = 0x30;			//TM1计数时钟选择fSYS/64，Off.
	_tm1c1  = 0xAC;			//PWM 模式或单脉冲输出模式,	PWM 模式 / 单脉冲输出模式,PWM 模式 高有效,反相,TMn 比较器 P 匹配			
	_tm1rpl  = 200;		//rp 周期寄存器   
	_tm1rph  = 0;         
	_tm1al = 1 ;			//ra 占空比寄存器	
	_tm1ah = 0; 			

	//AD Set
	/*
	● ACERL 寄存器
	Bit 7 ACE7：定义 PB3 是否为 A/D 输入
		0：不是 A/D 输入
		1：A/D 输入，AN7
	Bit 6 ACE6：定义 PA7 是否为 A/D 输入
		0：不是 A/D 输入
		1：A/D 输入，AN6
	Bit 5 ACE5：定义 PA6 是否为 A/D 输入
		0：不是 A/D 输入
		1：A/D 输入，AN5
	Bit 4 ACE4：定义 PA5 是否为 A/D 输入
		0：不是 A/D 输入
		1：A/D 输入，AN4
	Bit 3 ACE3：定义 PA4 是否为 A/D 输入
		0：不是 A/D 输入
		1：A/D 输入，AN3
	Bit 2 ACE2：定义 PB2 是否为 A/D 输入
		0：不是 A/D 输入
		1：A/D 输入，AN2
	Bit 1 ACE1：定义 PB1 是否为 A/D 输入
		0：不是 A/D 输入
		1：A/D 输入，AN1
	Bit 0 ACE0：定义 PB0 是否为 A/D 输入
		0：不是 A/D 输入
		1：A/D 输入，AN0

	//CPC 寄存器
	Bit7 CSEL：比较器引脚或 I/O 引脚选择位
		0：输入 / 输出引脚
		1：比较器输入引脚
		此位为比较器引脚或输入 / 输出引脚选择位。为“1”时，比较器输入引脚使能。
		此时，引脚的输入 / 输出功能失效，与比较器共用引脚的上拉电阻配置选项将
		自动失效。
	Bit 6 CEN：比较器开 / 关控制位
		0：关闭
		1：开启
		此位为比较器开 / 关控制位。为“0”时，比较器关闭，即使其引脚上加有模拟
		电压也不会产生功耗。对功耗要求严格的应用中，当比较器未使用或单片机进
		入休眠或空闲模式之前，此位应清零。
	Bit 5 CPOL：比较器输出极性位
		0：输出同相
		1：输出反相
		此位决定比较器极性。为“0”时，COUT 位与比较器输出条件同相；为“1”时，
		COUT 位与比较器输出条件反相。
		Bit 4 COUT：比较器输出位
		CPOL=0
		0：C+ < C-
		1：C+ > CCPOL=1
		0：C+ > C-
		1：C+ < C-
		此位为比较器输出位。此位的极性由比较器输入电压和 CPOL 位的状态决定。
	Bit3 COS：输出路径选择位
		0：CX 引脚
		1：内部使用
	Bit 2~1 未使用，读为“0”
	Bit 0 CHYEN：迟滞控制位
		0：关闭
		1：开启

	*/
	_acerl = 0x0D;//DAN0,AN2,AN3 TO AD,OTHER TO IO
	_cpc = 0x08;//C+/C-/CX for IO
	/*
	● ADCR0 寄存器
	Bit 7 START：启动 A/D 转换位
		0 → 1 → 0：启动
		0 → 1：重置 A/D 转换，并且设置 EOCB 为“1”
		此位用于初始化 A/D 转换过程。通常此位为低，但如果设为高再被清零，将初
		始化 A/D 转换过程。当此位为高，将重置 A/D 转换器。
	Bit 6 EOCB：A/D 转换结束标志
		0：A/D 转换结束
		1：A/D 转换中
		此位用于表明 A/D 转换过程的完成。当转换正在进行时，此位为高。
	Bit 5 ADOFF：ADC 模块电源开 / 关控制位
		0：ADC 模块电源开
		1：ADC 模块电源关
		此位控制 A/D 内部功能的电源。该位被清零将使能 A/D 转换器。如果该位设为
		高将关闭 A/D 转换器以降低功耗。由于 A/D 转换器在不执行转换动作时都会产
		生一定的功耗，所以这在电源敏感的电池应用中需要多加注意。
		注：1. 建议在进入空闲 / 休眠模式前，设置 ADOFF=1 以减少功耗。
		2. ADOFF=1 将关闭 ADC 模块的电源。
	Bit 4 ADRFS：ADC 数据格式控制位
		0：ADC 数据高字节是 ADRH 的 bit 7~bit 0，低字节是 ADRL 的 bit 7~bit 4
		1：ADC 数据高字节是 ADRH 的 bit 3~bit 0，低字节是 ADRL 的 bit 7~bit 0
		此位控制存放在两个 A/D 数据寄存器中的 12 位 A/D 转换结果的格式。细节方
		面请参考 A/D 数据寄存器章节。
	Bit 3 未定义，读为“0”
	Bit 2~0 ACS2，ACS1，ACS0：选择 A/D 通道 (ACS4 为“0”) 位
	 	000：AN0
	 	001：AN1
	 	010：AN2
	 	011：AN3
	 	100：AN4
	 	101：AN5
	 	110：AN6
	 	111：AN7

	● ADCR1 寄存器
	Bit 7 ACS4：选择内部带隙电压作为 ADC 输入控制位
		0：除能
		1：使能
		此位使能带隙电压连接到 A/D 转换器。VBGEN 位必须先被置位使能带隙电路被
		用于 A/D 转换器。当 ACS4 设为高，带隙电压将连接到 A/D 转换器，其它 A/D
		输入通道断开。
	Bit 6 VBGEN：内部带隙电压控制位
		0：除能
		1：使能
		此位控制连接到 A/D 转换器的内部带隙电路开 / 关功能。当此位设为高，带隙
		电压连接至 A/D 转换器。
	Bit 5 未定义，读为“0”
	Bit 4 VREFS：选择 ADC 参考电压
		0：内部 ADC 电源
		1：VREF 引脚
		此位用于选择 A/D 转换器的参考电压。如果该位设为高，A/D 转换器参考电
		压来源于外部 VREF 引脚。如果该位设为低，内部参考电压来源于电源电压
		VDD。当选择为 VREF 引脚时，与此引脚共用的其它功能将被除能。
	Bit 3 未定义，读为“0”
	Bit 2~0 ADCK2，ADCK1，ADCK0：选择 ADC 时钟源
		000：fSYS
		001：fSYS/2
		010：fSYS/4
		011：fSYS/8
		100：fSYS/16
		101：fSYS/32
		110：fSYS/64
		111：未定义
		这三位用于选择 A/D 转换器的时钟源
		
	● ACERL 寄存器
	Bit 7 ACE7：定义 PB3 是否为 A/D 输入
		0：不是 A/D 输入
		1：A/D 输入，AN7
	Bit 6 ACE6：定义 PA7 是否为 A/D 输入
		0：不是 A/D 输入
		1：A/D 输入，AN6
	Bit 5 ACE5：定义 PA6 是否为 A/D 输入
		0：不是 A/D 输入
		1：A/D 输入，AN5
	Bit 4 ACE4：定义 PA5 是否为 A/D 输入
		0：不是 A/D 输入
		1：A/D 输入，AN4
	Bit 3 ACE3：定义 PA4 是否为 A/D 输入
		0：不是 A/D 输入
		1：A/D 输入，AN3
	Bit 2 ACE2：定义 PB2 是否为 A/D 输入
		0：不是 A/D 输入
		1：A/D 输入，AN2
	Bit 1 ACE1：定义 PB1 是否为 A/D 输入
		0：不是 A/D 输入
		1：A/D 输入，AN1
	Bit 0 ACE0：定义 PB0 是否为 A/D 输入
		0：不是 A/D 输入
		1：A/D 输入，AN0

	*/
	_adcr0 = 0x12;				//ADC 模块电源关;ADC 数据高字节是 ADRH 的 bit 3~bit 0，低字节是 ADRL 的 bit 7~bit 0,AD2
	_adcr1 = 0x00;
	_acerl = 0x0D;				//AN0 _pb0, 	AN2 _pb2,	 AN3 _pa4	
	_adrfs = 1; 				//AD转换数据格式：SADOH=D[3:0]；SADOL=D[7:0]
	
	initINT();
}

//===================================================================
//function: initINT
//input   :	NULL
//output  :	NULL
//description:中断初始化.
//====================================================================
void initINT(void)
{
	//Interrupted
	/*
	INTEG 寄存器
	Bit 7~4 未使用，读为“0”
	Bit 3~2 INT1S1，INT1S0：INT1 脚中断边沿控制位
		00：除能
		01：上升沿
		10：下降沿
		11：双沿
	Bit 1~0 INT0S1，INT0S0：INT0 脚中断边沿控制位
		00：除能
		01：上升沿
		10：下降沿
		11：双沿
	*/
	_integ = 0;
	
	/*
	INTC0 寄存器
	Bit 7 未使用，读为“0”
	Bit 6 MF0F：多功能中断 0 中断请求标志位
		0：无请求
		1：中断请求
	Bit 5 CPF：比较器中断请求标志位
		0：无请求
		1：中断请求
	Bit 4 INT0F：INT0 中断请求标志位
		0：无请求
		1：中断请求
	Bit 3 MF0E：多功能中断 0 中断控制位
		0：除能
		1：使能
	Bit 2 CPE：比较器中断控制位
		0：除能
		1：使能
	Bit 1 INT0E：INT0 中断控制位
		0：除能
		1：使能
	Bit 0 EMI：总中断控制位
		0：除能
		1：使能
	*/
	_intc0 = 0x08;//mf0f=0,_mf0e=1,_emi=0;
	
	/*
	INTC1 寄存器
	Bit 7 TB0F：时基 0 中断请求标志位
		0：无请求
		1：中断请求
	Bit 6 ADF：A/D 转换器中断请求标志位
		0：无请求
		1：中断请求
	Bit 5 MF2F：多功能中断 2 中断请求标志位
		0：无请求
		1：中断请求
	Bit 4 MF1F：多功能中断 1 中断请求标志位
		0：无请求
		1：中断请求
	Bit 3 TB0E：时基 0 中断控制位
		0：除能
		1：使能
	Bit 2 ADE：A/D 转换器中断控制位
		0：除能
		1：使能
	Bit 1 MF2E：多功能中断 2 中断控制位
		0：除能
		1：使能
	Bit 0 MF1E：多功能中断 1 中断控制位
		0：除能
		1：使能
	*/
	_intc1 = 0x01;//_mf1e=1;

	/*
	INTC2 寄存器
	Bit 7~6 未使用，读为“0”
	Bit 5 INT1F：INT1 中断请求标志位
		0：无请求
		1：中断请求
	Bit 4 TB1F：时基 1 中断请求标志位
		0：无请求
		1：中断请求
	Bit 3~2 未使用，读为“0”
	Bit 1 INT1E：INT1 中断控制位
		0：除能
		1：使能
	Bit 0 TB1E：时基 1 中断控制位
		0：除能
		1：使能
	*/
	_intc2 = 0x00;

	/*
	MFI0 寄存器
	Bit 7~6 未使用，读为“0”
	Bit 5 T0AF：TM0 比较器 A 匹配中断请求标志位
		0：无请求
		1：中断请求
	Bit 4 T0PF：TM0 比较器 P 匹配中断请求标志位
		0：无请求
		1：中断请求
	Bit 3~2 未使用，读为“0”
	Bit 1 T0AE：TM0 比较器 A 匹配中断控制位
		0：除能
		1：使能
	Bit 0 T0PE：TM0 比较器 P 匹配中断控制位
		0：除能
		1：使能
	*/
	_mfi0 = 0x02;//_t0af=0,_t0ae=1;

	/*
	MFI1 寄存器
	Bit 7 T2AF：TM2 比较器 A 匹配中断请求标志位
		0：无请求
		1：中断请求
	Bit 6 T2PF：TM2 比较器 P 匹配中断请求标志位
		0：无请求
		1：中断请求
	Bit 5 T1AF：TM1 比较器 A 匹配中断请求标志位
		0：无请求
		1：中断请求
	Bit 4 T1PF：TM1 比较器 P 匹配中断请求标志位
		0：无请求
		1：中断请求
	Bit 3 T2AE：TM2 比较器 A 匹配中断控制位
		0：除能
		1：使能
	Bit 2 T2PE：TM2 比较器 P 匹配中断控制位
		0：除能
		1：使能
	Bit 1 T1AE：TM1 比较器 A 匹配中断控制位
		0：除能
		1：使能
	Bit 0 T1PE：TM1 比较器 P 匹配中断控制位
		0：除能
		1：使能
	*/
	_mfi1 = 0x01;//T1AE=0,T1PE=1;
}

//RAM Init
void RAM_Init()
{	
	//RAM0 TO ZERO
	for(_mp0=0xff;_mp0>=0xa0;_mp0--)
	{
		 _iar0=0x00;
	}
	//RAM1 TO ZERO
	_bp=1;
	for(_mp1=0xff;_mp1>=0xa0;_mp1--)
	{
		 _iar1=0x00;
	}
	_bp=0;
}

//===============================================================
// User_Init
//===============================================================
//function:User_Init.
//input   :NULL.
//output  :NULL.
//description:用户初始化变量.
void User_Init(void)
{
	unsigned char i;
	
	/*INT Enbale*/
//	_mf0e = 1;
//	_mf1e = 1;
//	_t0ae = 1;
//	_t1pe = 1;
	_t0on = 1;//TM0 计数器 On/Off 控制位,=1 使能.
	_t1on = 0;//PWM禁止,初始值为LED常亮。
	_emi = 1;//总中断控制位,=1 使能.

	TimeSet_Init();
	Variable_Init();
	
	R_WorkMode = c_ModeInit;
	
	/*Flag*/
	flag0Byte = 0x00;
	flag1Byte = 0x00;
//	TimeFlag0Byte = 0x00;
	fg_LedByte = 0x00;
	display_data1 = 0x00;
	display_data2 = 0x00;
	display_data3 = 0x00;

	/*IO Setting*/
	P_HEATING   = 0;//关闭加热,=0 关闭, =1 打开加热.
	P_HEATING_C = 0;
	P_LED = 1;//开机LED 灭
	P_LED_C = 0;
	if(!LED_PWM_T1ON){
		P_LED = 0;
		LED_PWM_T1CP = 1;
		LED_PWM_T1ON = 1;
		PWMChange(C_PWM_PERIO_INIT,C_PWM_DUTY_INIT);
	}
	
	/*Variable*/
	R_intResAD_Value = 0;
	R_BatLevel = 0;
	R_BatLevelUp = 0;
	fg_BatLvlInitStart = 0;
	fg_BatDetePowerOn = 1;
	
	fg_PowerIn = 1;
	R_BatLevel = 1;
	for (i = 0; i <= 20; ++i)
	{
		Power_StatusDete();
		BatAD_Dete();//电压检测.
	}
}

//===================================================================
//function: TimeSet_Init
//input   :	NULL
//output  :	NULL
//description:初始化定时变量和标志.
//====================================================================
void TimeSet_Init(void)
{
	R_Time50msCount = 0;
	R_Time100msCount = 0;
	R_Time150msCount = 0;
	R_Time700msCount = 0;
	R_intTime1sCount = 0;
	R_Time2sCount = 0;
	R_intHeatingPWM2ms = C_1S;

	TimeFlag0Byte = 0x00;
}

//===================================================================
//function: Variable_Init
//input   :	NULL
//output  :	NULL
//description:初始化变量.
//====================================================================
void Variable_Init(void)
{
	//LED
	R_LedMode = C_LED_OFF;		  //LED 显示模式.
	R_LedDirFlag = 0; 		  //呼吸灯亮灭方向标志.
	R_LedDutyCycle = 0;		  //用于存放占空比.
	
	//Temperature
	R_intTempDisplayLevel = 0; 

	//Resistance AD Seting Temp value display.
	R_intResAD_Value = 0;
	R_intResAD_ValueBak = 0;
	R_intRESTempSet = 0;
	R_intRESTempSetCopy = 0; 
	R_UpdateTempSetCount = 0; 
	R_Low60Count = 0;
	R_ResADCount = 0;
	R_ModeChgCount = 0; 
	R_TimeResTempSetDisplay = 0; 

	//Battery AD 
	R_intBatADValue = 0;
	R_BatLevel_Count0 = 0;
	R_BatLevel_Count1 = 0;
	R_BatLevel_Count2 = 0;
	R_BatLevel_Count3 = 0;
	//R_BatLevel:实际电池电压等级,R_BatLevelUp:控制显示电池电压按顺序0~R_BatLevel.
	R_BatLevel = 0;
	R_BatLevelUp = 0;
	R_Time2Min_BTLow = 0;

	//NTC AD
	R_NoNTCCount = 0;
	R_intNTC_ADVal = 0;
	R_NTC_AD_Count = 0;
	R_intNTC_CurrentTemp = 0;

	R_PowerInCount = 0;
	R_DigitalTubeDisplayLoop = 0;

}

