#include	"EEPROM.h"

#define		_MCU_TYPE	0		//1: HT67F48X alike, 0: Standard MCU

////===============================================================
////void EEPROM_Read (void)
////===============================================================
uchar EEPROM_Read (unsigned char addr_data)
{
	unsigned char read_data;
	
	_eea = addr_data;
    
#if	_MCU_TYPE == 1    
	_mp1l = 0x40;
	_mp1h = 0x01;
#else    
	_mp1 = 0x40;
	_bp = 0x01;
#endif

	_iar1 |= 0b00000010;//RDEN=1
	_iar1 |= 0b00000001;//RD=1
    
	while (_iar1 & 0b00000001);
	{
		_clrwdt();
	}
	_iar1 &= 0b11111101;//rden=0x00;
	
#if	_MCU_TYPE == 1
	_mp1h = 0x00;
#else
	_bp = 0x00;
#endif

	read_data = _eed;
	
	return (read_data);
}

////===============================================================
////void EEPROM_Write (void)
////===============================================================
void EEPROM_Write (unsigned char addr_data,unsigned char data)
{
	_eea = addr_data;
 	_eed = data;
 	
#if	_MCU_TYPE == 1    
	_mp1l = 0x40;
	_mp1h = 0x01;
#else    
	_mp1 = 0x40;
	_bp = 0x01;
#endif

    _iar1|=0b00001000; //_wren=1;
    _iar1|=0b00000100; //_wr=1;
    
	while (_iar1&0b00000100);//while(_wr);
	{
		_clrwdt();
	}
    _iar1 &= 0b11111011;//_wr=0x00;
    
#if	_MCU_TYPE == 1
	_mp1h = 0x00;
#else
	_bp = 0x00;
#endif
}