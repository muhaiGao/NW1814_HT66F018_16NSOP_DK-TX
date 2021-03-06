// HT66F018.h
//	This file contains the definition of registers for
//		Holtek HT66F018 microcontroller.
//	Generated by HTFileParse.dll.
//	[VERSION] 2.4, 4
// Do not modify manually.

#ifndef _HT66F018_H_
#define _HT66F018_H_

#ifndef __DISABLE_HGCC_BUILD_IN__
#include "build-in.h"
#endif

#define DEFINE_ISR(isr_name, vector) void __attribute((interrupt(vector))) isr_name(void)

#define DEFINE_SFR(sfr_type, sfr, addr) static volatile sfr_type sfr __attribute__ ((at(addr)))

typedef unsigned char __sfr_byte;

typedef struct {
	unsigned char __dmbp0 : 1;
	unsigned char : 7;
} __bp_bits;

typedef union {
	__bp_bits bits;
	__sfr_byte byte;
} __bp_type;

typedef struct {
	unsigned char __c : 1;
	unsigned char __ac : 1;
	unsigned char __z : 1;
	unsigned char __ov : 1;
	unsigned char __pdf : 1;
	unsigned char __to : 1;
	unsigned char : 2;
} __status_bits;

typedef union {
	__status_bits bits;
	__sfr_byte byte;
} __status_type;

typedef struct {
	unsigned char __hlclk : 1;
	unsigned char __idlen : 1;
	unsigned char __hto : 1;
	unsigned char __lto : 1;
	unsigned char __fsten : 1;
	unsigned char __cks0 : 1;
	unsigned char __cks1 : 1;
	unsigned char __cks2 : 1;
} __smod_bits;

typedef union {
	__smod_bits bits;
	__sfr_byte byte;
} __smod_type;

typedef struct {
	unsigned char __vlvd0 : 1;
	unsigned char __vlvd1 : 1;
	unsigned char __vlvd2 : 1;
	unsigned char : 1;
	unsigned char __lvden : 1;
	unsigned char __lvdo : 1;
	unsigned char : 2;
} __lvdc_bits;

typedef union {
	__lvdc_bits bits;
	__sfr_byte byte;
} __lvdc_type;

typedef struct {
	unsigned char __int0s0 : 1;
	unsigned char __int0s1 : 1;
	unsigned char __int1s0 : 1;
	unsigned char __int1s1 : 1;
	unsigned char : 4;
} __integ_bits;

typedef union {
	__integ_bits bits;
	__sfr_byte byte;
} __integ_type;

typedef struct {
	unsigned char __emi : 1;
	unsigned char __int0e : 1;
	unsigned char __cpe : 1;
	unsigned char __mf0e : 1;
	unsigned char __int0f : 1;
	unsigned char __cpf : 1;
	unsigned char __mf0f : 1;
	unsigned char : 1;
} __intc0_bits;

typedef union {
	__intc0_bits bits;
	__sfr_byte byte;
} __intc0_type;

typedef struct {
	unsigned char __mf1e : 1;
	unsigned char __mf2e : 1;
	unsigned char __ade : 1;
	unsigned char __tb0e : 1;
	unsigned char __mf1f : 1;
	unsigned char __mf2f : 1;
	unsigned char __adf : 1;
	unsigned char __tb0f : 1;
} __intc1_bits;

typedef union {
	__intc1_bits bits;
	__sfr_byte byte;
} __intc1_type;

typedef struct {
	unsigned char __tb1e : 1;
	unsigned char __int1e : 1;
	unsigned char : 2;
	unsigned char __tb1f : 1;
	unsigned char __int1f : 1;
	unsigned char : 2;
} __intc2_bits;

typedef union {
	__intc2_bits bits;
	__sfr_byte byte;
} __intc2_type;

typedef struct {
	unsigned char __t0pe : 1;
	unsigned char __t0ae : 1;
	unsigned char : 2;
	unsigned char __t0pf : 1;
	unsigned char __t0af : 1;
	unsigned char : 2;
} __mfi0_bits;

typedef union {
	__mfi0_bits bits;
	__sfr_byte byte;
} __mfi0_type;

typedef struct {
	unsigned char __t1pe : 1;
	unsigned char __t1ae : 1;
	unsigned char __t2pe : 1;
	unsigned char __t2ae : 1;
	unsigned char __t1pf : 1;
	unsigned char __t1af : 1;
	unsigned char __t2pf : 1;
	unsigned char __t2af : 1;
} __mfi1_bits;

typedef union {
	__mfi1_bits bits;
	__sfr_byte byte;
} __mfi1_type;

typedef struct {
	unsigned char __lve : 1;
	unsigned char __dee : 1;
	unsigned char : 2;
	unsigned char __lvf : 1;
	unsigned char __def : 1;
	unsigned char : 2;
} __mfi2_bits;

typedef union {
	__mfi2_bits bits;
	__sfr_byte byte;
} __mfi2_type;

typedef struct {
	unsigned char __pa0 : 1;
	unsigned char __pa1 : 1;
	unsigned char __pa2 : 1;
	unsigned char __pa3 : 1;
	unsigned char __pa4 : 1;
	unsigned char __pa5 : 1;
	unsigned char __pa6 : 1;
	unsigned char __pa7 : 1;
} __pa_bits;

typedef union {
	__pa_bits bits;
	__sfr_byte byte;
} __pa_type;

typedef struct {
	unsigned char __pac0 : 1;
	unsigned char __pac1 : 1;
	unsigned char __pac2 : 1;
	unsigned char __pac3 : 1;
	unsigned char __pac4 : 1;
	unsigned char __pac5 : 1;
	unsigned char __pac6 : 1;
	unsigned char __pac7 : 1;
} __pac_bits;

typedef union {
	__pac_bits bits;
	__sfr_byte byte;
} __pac_type;

typedef struct {
	unsigned char __papu0 : 1;
	unsigned char __papu1 : 1;
	unsigned char __papu2 : 1;
	unsigned char __papu3 : 1;
	unsigned char __papu4 : 1;
	unsigned char __papu5 : 1;
	unsigned char __papu6 : 1;
	unsigned char __papu7 : 1;
} __papu_bits;

typedef union {
	__papu_bits bits;
	__sfr_byte byte;
} __papu_type;

typedef struct {
	unsigned char __pawu0 : 1;
	unsigned char __pawu1 : 1;
	unsigned char __pawu2 : 1;
	unsigned char __pawu3 : 1;
	unsigned char __pawu4 : 1;
	unsigned char __pawu5 : 1;
	unsigned char __pawu6 : 1;
	unsigned char __pawu7 : 1;
} __pawu_bits;

typedef union {
	__pawu_bits bits;
	__sfr_byte byte;
} __pawu_type;

typedef struct {
	unsigned char __t0cp : 1;
	unsigned char __t1cp : 1;
	unsigned char __t2cp : 1;
	unsigned char : 4;
	unsigned char __clop : 1;
} __tmpc_bits;

typedef union {
	__tmpc_bits bits;
	__sfr_byte byte;
} __tmpc_type;

typedef struct {
	unsigned char __ws0 : 1;
	unsigned char __ws1 : 1;
	unsigned char __ws2 : 1;
	unsigned char __we0 : 1;
	unsigned char __we1 : 1;
	unsigned char __we2 : 1;
	unsigned char __we3 : 1;
	unsigned char __we4 : 1;
} __wdtc_bits;

typedef union {
	__wdtc_bits bits;
	__sfr_byte byte;
} __wdtc_type;

typedef struct {
	unsigned char __tb00 : 1;
	unsigned char __tb01 : 1;
	unsigned char __tb02 : 1;
	unsigned char __lxtlp : 1;
	unsigned char __tb10 : 1;
	unsigned char __tb11 : 1;
	unsigned char __tbck : 1;
	unsigned char __tbon : 1;
} __tbc_bits;

typedef union {
	__tbc_bits bits;
	__sfr_byte byte;
} __tbc_type;

typedef struct {
	unsigned char __wrf : 1;
	unsigned char __lrf : 1;
	unsigned char __lvrf : 1;
	unsigned char : 4;
	unsigned char __fsyson : 1;
} __ctrl_bits;

typedef union {
	__ctrl_bits bits;
	__sfr_byte byte;
} __ctrl_type;

typedef struct {
	unsigned char __lvs0 : 1;
	unsigned char __lvs1 : 1;
	unsigned char __lvs2 : 1;
	unsigned char __lvs3 : 1;
	unsigned char __lvs4 : 1;
	unsigned char __lvs5 : 1;
	unsigned char __lvs6 : 1;
	unsigned char __lvs7 : 1;
} __lvrc_bits;

typedef union {
	__lvrc_bits bits;
	__sfr_byte byte;
} __lvrc_type;

typedef struct {
	unsigned char __acs0 : 1;
	unsigned char __acs1 : 1;
	unsigned char __acs2 : 1;
	unsigned char : 1;
	unsigned char __adrfs : 1;
	unsigned char __adoff : 1;
	unsigned char __eocb : 1;
	unsigned char __start : 1;
} __adcr0_bits;

typedef union {
	__adcr0_bits bits;
	__sfr_byte byte;
} __adcr0_type;

typedef struct {
	unsigned char __adck0 : 1;
	unsigned char __adck1 : 1;
	unsigned char __adck2 : 1;
	unsigned char : 1;
	unsigned char __vrefs : 1;
	unsigned char : 1;
	unsigned char __vbgen : 1;
	unsigned char __acs4 : 1;
} __adcr1_bits;

typedef union {
	__adcr1_bits bits;
	__sfr_byte byte;
} __adcr1_type;

typedef struct {
	unsigned char __ace0 : 1;
	unsigned char __ace1 : 1;
	unsigned char __ace2 : 1;
	unsigned char __ace3 : 1;
	unsigned char __ace4 : 1;
	unsigned char __ace5 : 1;
	unsigned char __ace6 : 1;
	unsigned char __ace7 : 1;
} __acerl_bits;

typedef union {
	__acerl_bits bits;
	__sfr_byte byte;
} __acerl_type;

typedef struct {
	unsigned char __pb0 : 1;
	unsigned char __pb1 : 1;
	unsigned char __pb2 : 1;
	unsigned char __pb3 : 1;
	unsigned char __pb4 : 1;
	unsigned char __pb5 : 1;
	unsigned char __pb6 : 1;
	unsigned char : 1;
} __pb_bits;

typedef union {
	__pb_bits bits;
	__sfr_byte byte;
} __pb_type;

typedef struct {
	unsigned char __pbc0 : 1;
	unsigned char __pbc1 : 1;
	unsigned char __pbc2 : 1;
	unsigned char __pbc3 : 1;
	unsigned char __pbc4 : 1;
	unsigned char __pbc5 : 1;
	unsigned char __pbc6 : 1;
	unsigned char : 1;
} __pbc_bits;

typedef union {
	__pbc_bits bits;
	__sfr_byte byte;
} __pbc_type;

typedef struct {
	unsigned char __pbpu0 : 1;
	unsigned char __pbpu1 : 1;
	unsigned char __pbpu2 : 1;
	unsigned char __pbpu3 : 1;
	unsigned char __pbpu4 : 1;
	unsigned char __pbpu5 : 1;
	unsigned char __pbpu6 : 1;
	unsigned char : 1;
} __pbpu_bits;

typedef union {
	__pbpu_bits bits;
	__sfr_byte byte;
} __pbpu_type;

typedef struct {
	unsigned char : 3;
	unsigned char __t2on : 1;
	unsigned char __t2ck0 : 1;
	unsigned char __t2ck1 : 1;
	unsigned char __t2ck2 : 1;
	unsigned char __t2pau : 1;
} __tm2c0_bits;

typedef union {
	__tm2c0_bits bits;
	__sfr_byte byte;
} __tm2c0_type;

typedef struct {
	unsigned char __t2cclr : 1;
	unsigned char __t2dpx : 1;
	unsigned char __t2pol : 1;
	unsigned char __t2oc : 1;
	unsigned char __t2io0 : 1;
	unsigned char __t2io1 : 1;
	unsigned char __t2m0 : 1;
	unsigned char __t2m1 : 1;
} __tm2c1_bits;

typedef union {
	__tm2c1_bits bits;
	__sfr_byte byte;
} __tm2c1_type;

typedef struct {
	unsigned char __t2rp0 : 1;
	unsigned char __t2rp1 : 1;
	unsigned char __t2rp2 : 1;
	unsigned char __t2rp3 : 1;
	unsigned char __t2rp4 : 1;
	unsigned char __t2rp5 : 1;
	unsigned char __t2rp6 : 1;
	unsigned char __t2rp7 : 1;
} __tm2rp_bits;

typedef union {
	__tm2rp_bits bits;
	__sfr_byte byte;
} __tm2rp_type;

typedef struct {
	unsigned char : 3;
	unsigned char __t0on : 1;
	unsigned char __t0ck0 : 1;
	unsigned char __t0ck1 : 1;
	unsigned char __t0ck2 : 1;
	unsigned char __t0pau : 1;
} __tm0c0_bits;

typedef union {
	__tm0c0_bits bits;
	__sfr_byte byte;
} __tm0c0_type;

typedef struct {
	unsigned char __t0cclr : 1;
	unsigned char __t0dpx : 1;
	unsigned char __t0pol : 1;
	unsigned char __t0oc : 1;
	unsigned char __t0io0 : 1;
	unsigned char __t0io1 : 1;
	unsigned char __t0m0 : 1;
	unsigned char __t0m1 : 1;
} __tm0c1_bits;

typedef union {
	__tm0c1_bits bits;
	__sfr_byte byte;
} __tm0c1_type;

typedef struct {
	unsigned char __t0rp0 : 1;
	unsigned char __t0rp1 : 1;
	unsigned char __t0rp2 : 1;
	unsigned char __t0rp3 : 1;
	unsigned char __t0rp4 : 1;
	unsigned char __t0rp5 : 1;
	unsigned char __t0rp6 : 1;
	unsigned char __t0rp7 : 1;
} __tm0rp_bits;

typedef union {
	__tm0rp_bits bits;
	__sfr_byte byte;
} __tm0rp_type;

typedef struct {
	unsigned char : 3;
	unsigned char __t1on : 1;
	unsigned char __t1ck0 : 1;
	unsigned char __t1ck1 : 1;
	unsigned char __t1ck2 : 1;
	unsigned char __t1pau : 1;
} __tm1c0_bits;

typedef union {
	__tm1c0_bits bits;
	__sfr_byte byte;
} __tm1c0_type;

typedef struct {
	unsigned char __t1cclr : 1;
	unsigned char __t1capts : 1;
	unsigned char __t1pol : 1;
	unsigned char __t1oc : 1;
	unsigned char __t1io0 : 1;
	unsigned char __t1io1 : 1;
	unsigned char __t1m0 : 1;
	unsigned char __t1m1 : 1;
} __tm1c1_bits;

typedef union {
	__tm1c1_bits bits;
	__sfr_byte byte;
} __tm1c1_type;

typedef struct {
	unsigned char __chyen : 1;
	unsigned char : 2;
	unsigned char __cos : 1;
	unsigned char __cout : 1;
	unsigned char __cpol : 1;
	unsigned char __cen : 1;
	unsigned char __csel : 1;
} __cpc_bits;

typedef union {
	__cpc_bits bits;
	__sfr_byte byte;
} __cpc_type;

typedef struct {
	unsigned char __pc0 : 1;
	unsigned char __pc1 : 1;
	unsigned char __pc2 : 1;
	unsigned char : 5;
} __pc_bits;

typedef union {
	__pc_bits bits;
	__sfr_byte byte;
} __pc_type;

typedef struct {
	unsigned char __pcc0 : 1;
	unsigned char __pcc1 : 1;
	unsigned char __pcc2 : 1;
	unsigned char : 5;
} __pcc_bits;

typedef union {
	__pcc_bits bits;
	__sfr_byte byte;
} __pcc_type;

typedef struct {
	unsigned char __pcpu0 : 1;
	unsigned char __pcpu1 : 1;
	unsigned char __pcpu2 : 1;
	unsigned char : 5;
} __pcpu_bits;

typedef union {
	__pcpu_bits bits;
	__sfr_byte byte;
} __pcpu_type;

typedef struct {
	unsigned char __rd : 1;
	unsigned char __rden : 1;
	unsigned char __wr : 1;
	unsigned char __wren : 1;
	unsigned char : 4;
} __eec_bits;

typedef union {
	__eec_bits bits;
	__sfr_byte byte;
} __eec_type;


DEFINE_SFR(__sfr_byte, __mp0, 0x01);
DEFINE_SFR(__sfr_byte, __mp1, 0x03);
DEFINE_SFR(__bp_type, __bp, 0x04);
DEFINE_SFR(__sfr_byte, __acc, 0x05);
DEFINE_SFR(__sfr_byte, __pcl, 0x06);
DEFINE_SFR(__sfr_byte, __tblp, 0x07);
DEFINE_SFR(__sfr_byte, __tblh, 0x08);
DEFINE_SFR(__sfr_byte, __tbhp, 0x09);
DEFINE_SFR(__status_type, __status, 0x0a);
DEFINE_SFR(__smod_type, __smod, 0x0b);
DEFINE_SFR(__lvdc_type, __lvdc, 0x0c);
DEFINE_SFR(__integ_type, __integ, 0x0d);
DEFINE_SFR(__intc0_type, __intc0, 0x0e);
DEFINE_SFR(__intc1_type, __intc1, 0x0f);
DEFINE_SFR(__intc2_type, __intc2, 0x10);
DEFINE_SFR(__mfi0_type, __mfi0, 0x11);
DEFINE_SFR(__mfi1_type, __mfi1, 0x12);
DEFINE_SFR(__mfi2_type, __mfi2, 0x13);
DEFINE_SFR(__pa_type, __pa, 0x14);
DEFINE_SFR(__pac_type, __pac, 0x15);
DEFINE_SFR(__papu_type, __papu, 0x16);
DEFINE_SFR(__pawu_type, __pawu, 0x17);
DEFINE_SFR(__tmpc_type, __tmpc, 0x19);
DEFINE_SFR(__wdtc_type, __wdtc, 0x1a);
DEFINE_SFR(__tbc_type, __tbc, 0x1b);
DEFINE_SFR(__ctrl_type, __ctrl, 0x1c);
DEFINE_SFR(__lvrc_type, __lvrc, 0x1d);
DEFINE_SFR(__sfr_byte, __eea, 0x1e);
DEFINE_SFR(__sfr_byte, __eed, 0x1f);
DEFINE_SFR(__sfr_byte, __adrl, 0x20);
DEFINE_SFR(__sfr_byte, __adrh, 0x21);
DEFINE_SFR(__adcr0_type, __adcr0, 0x22);
DEFINE_SFR(__adcr1_type, __adcr1, 0x23);
DEFINE_SFR(__acerl_type, __acerl, 0x24);
DEFINE_SFR(__pb_type, __pb, 0x25);
DEFINE_SFR(__pbc_type, __pbc, 0x26);
DEFINE_SFR(__pbpu_type, __pbpu, 0x27);
DEFINE_SFR(__tm2c0_type, __tm2c0, 0x28);
DEFINE_SFR(__tm2c1_type, __tm2c1, 0x29);
DEFINE_SFR(__sfr_byte, __tm2dl, 0x2a);
DEFINE_SFR(__sfr_byte, __tm2dh, 0x2b);
DEFINE_SFR(__sfr_byte, __tm2al, 0x2c);
DEFINE_SFR(__sfr_byte, __tm2ah, 0x2d);
DEFINE_SFR(__tm2rp_type, __tm2rp, 0x2e);
DEFINE_SFR(__tm0c0_type, __tm0c0, 0x2f);
DEFINE_SFR(__tm0c1_type, __tm0c1, 0x30);
DEFINE_SFR(__sfr_byte, __tm0dl, 0x31);
DEFINE_SFR(__sfr_byte, __tm0dh, 0x32);
DEFINE_SFR(__sfr_byte, __tm0al, 0x33);
DEFINE_SFR(__sfr_byte, __tm0ah, 0x34);
DEFINE_SFR(__tm0rp_type, __tm0rp, 0x35);
DEFINE_SFR(__tm1c0_type, __tm1c0, 0x36);
DEFINE_SFR(__tm1c1_type, __tm1c1, 0x37);
DEFINE_SFR(__sfr_byte, __tm1dl, 0x38);
DEFINE_SFR(__sfr_byte, __tm1dh, 0x39);
DEFINE_SFR(__sfr_byte, __tm1al, 0x3a);
DEFINE_SFR(__sfr_byte, __tm1ah, 0x3b);
DEFINE_SFR(__sfr_byte, __tm1rpl, 0x3c);
DEFINE_SFR(__sfr_byte, __tm1rph, 0x3d);
DEFINE_SFR(__cpc_type, __cpc, 0x3e);
DEFINE_SFR(__pc_type, __pc, 0x40);
DEFINE_SFR(__pcc_type, __pcc, 0x41);
DEFINE_SFR(__pcpu_type, __pcpu, 0x42);
DEFINE_SFR(__eec_type, __eec, 0x140);
DEFINE_SFR(__sfr_byte, __iar0, 0x00);
DEFINE_SFR(__sfr_byte, __iar1, 0x02);

#define _iar0     __iar0
#define _iar1     __iar1
#define _mp0      __mp0
#define _mp1      __mp1
#define _bp       __bp.byte
#define _acc      __acc
#define _pcl      __pcl
#define _tblp     __tblp
#define _tblh     __tblh
#define _tbhp     __tbhp
#define _status   __status.byte
#define _smod     __smod.byte
#define _lvdc     __lvdc.byte
#define _integ    __integ.byte
#define _intc0    __intc0.byte
#define _intc1    __intc1.byte
#define _intc2    __intc2.byte
#define _mfi0     __mfi0.byte
#define _mfi1     __mfi1.byte
#define _mfi2     __mfi2.byte
#define _pa       __pa.byte
#define _pac      __pac.byte
#define _papu     __papu.byte
#define _pawu     __pawu.byte
#define _tmpc     __tmpc.byte
#define _wdtc     __wdtc.byte
#define _tbc      __tbc.byte
#define _ctrl     __ctrl.byte
#define _lvrc     __lvrc.byte
#define _eea      __eea
#define _eed      __eed
#define _adrl     __adrl
#define _adrh     __adrh
#define _adcr0    __adcr0.byte
#define _adcr1    __adcr1.byte
#define _acerl    __acerl.byte
#define _pb       __pb.byte
#define _pbc      __pbc.byte
#define _pbpu     __pbpu.byte
#define _tm2c0    __tm2c0.byte
#define _tm2c1    __tm2c1.byte
#define _tm2dl    __tm2dl
#define _tm2dh    __tm2dh
#define _tm2al    __tm2al
#define _tm2ah    __tm2ah
#define _tm2rp    __tm2rp.byte
#define _tm0c0    __tm0c0.byte
#define _tm0c1    __tm0c1.byte
#define _tm0dl    __tm0dl
#define _tm0dh    __tm0dh
#define _tm0al    __tm0al
#define _tm0ah    __tm0ah
#define _tm0rp    __tm0rp.byte
#define _tm1c0    __tm1c0.byte
#define _tm1c1    __tm1c1.byte
#define _tm1dl    __tm1dl
#define _tm1dh    __tm1dh
#define _tm1al    __tm1al
#define _tm1ah    __tm1ah
#define _tm1rpl   __tm1rpl
#define _tm1rph   __tm1rph
#define _cpc      __cpc.byte
#define _pc       __pc.byte
#define _pcc      __pcc.byte
#define _pcpu     __pcpu.byte
#define _eec      __eec.byte

#define _dmbp0    __bp.bits.__dmbp0
#define _c        __status.bits.__c
#define _ac       __status.bits.__ac
#define _z        __status.bits.__z
#define _ov       __status.bits.__ov
#define _pdf      __status.bits.__pdf
#define _to       __status.bits.__to
#define _hlclk    __smod.bits.__hlclk
#define _idlen    __smod.bits.__idlen
#define _hto      __smod.bits.__hto
#define _lto      __smod.bits.__lto
#define _fsten    __smod.bits.__fsten
#define _cks0     __smod.bits.__cks0
#define _cks1     __smod.bits.__cks1
#define _cks2     __smod.bits.__cks2
#define _vlvd0    __lvdc.bits.__vlvd0
#define _vlvd1    __lvdc.bits.__vlvd1
#define _vlvd2    __lvdc.bits.__vlvd2
#define _lvden    __lvdc.bits.__lvden
#define _lvdo     __lvdc.bits.__lvdo
#define _int0s0   __integ.bits.__int0s0
#define _int0s1   __integ.bits.__int0s1
#define _int1s0   __integ.bits.__int1s0
#define _int1s1   __integ.bits.__int1s1
#define _emi      __intc0.bits.__emi
#define _int0e    __intc0.bits.__int0e
#define _cpe      __intc0.bits.__cpe
#define _mf0e     __intc0.bits.__mf0e
#define _int0f    __intc0.bits.__int0f
#define _cpf      __intc0.bits.__cpf
#define _mf0f     __intc0.bits.__mf0f
#define _mf1e     __intc1.bits.__mf1e
#define _mf2e     __intc1.bits.__mf2e
#define _ade      __intc1.bits.__ade
#define _tb0e     __intc1.bits.__tb0e
#define _mf1f     __intc1.bits.__mf1f
#define _mf2f     __intc1.bits.__mf2f
#define _adf      __intc1.bits.__adf
#define _tb0f     __intc1.bits.__tb0f
#define _tb1e     __intc2.bits.__tb1e
#define _int1e    __intc2.bits.__int1e
#define _tb1f     __intc2.bits.__tb1f
#define _int1f    __intc2.bits.__int1f
#define _t0pe     __mfi0.bits.__t0pe
#define _t0ae     __mfi0.bits.__t0ae
#define _t0pf     __mfi0.bits.__t0pf
#define _t0af     __mfi0.bits.__t0af
#define _t1pe     __mfi1.bits.__t1pe
#define _t1ae     __mfi1.bits.__t1ae
#define _t2pe     __mfi1.bits.__t2pe
#define _t2ae     __mfi1.bits.__t2ae
#define _t1pf     __mfi1.bits.__t1pf
#define _t1af     __mfi1.bits.__t1af
#define _t2pf     __mfi1.bits.__t2pf
#define _t2af     __mfi1.bits.__t2af
#define _lve      __mfi2.bits.__lve
#define _dee      __mfi2.bits.__dee
#define _lvf      __mfi2.bits.__lvf
#define _def      __mfi2.bits.__def
#define _pa0      __pa.bits.__pa0
#define _pa1      __pa.bits.__pa1
#define _pa2      __pa.bits.__pa2
#define _pa3      __pa.bits.__pa3
#define _pa4      __pa.bits.__pa4
#define _pa5      __pa.bits.__pa5
#define _pa6      __pa.bits.__pa6
#define _pa7      __pa.bits.__pa7
#define _pac0     __pac.bits.__pac0
#define _pac1     __pac.bits.__pac1
#define _pac2     __pac.bits.__pac2
#define _pac3     __pac.bits.__pac3
#define _pac4     __pac.bits.__pac4
#define _pac5     __pac.bits.__pac5
#define _pac6     __pac.bits.__pac6
#define _pac7     __pac.bits.__pac7
#define _papu0    __papu.bits.__papu0
#define _papu1    __papu.bits.__papu1
#define _papu2    __papu.bits.__papu2
#define _papu3    __papu.bits.__papu3
#define _papu4    __papu.bits.__papu4
#define _papu5    __papu.bits.__papu5
#define _papu6    __papu.bits.__papu6
#define _papu7    __papu.bits.__papu7
#define _pawu0    __pawu.bits.__pawu0
#define _pawu1    __pawu.bits.__pawu1
#define _pawu2    __pawu.bits.__pawu2
#define _pawu3    __pawu.bits.__pawu3
#define _pawu4    __pawu.bits.__pawu4
#define _pawu5    __pawu.bits.__pawu5
#define _pawu6    __pawu.bits.__pawu6
#define _pawu7    __pawu.bits.__pawu7
#define _t0cp     __tmpc.bits.__t0cp
#define _t1cp     __tmpc.bits.__t1cp
#define _t2cp     __tmpc.bits.__t2cp
#define _clop     __tmpc.bits.__clop
#define _ws0      __wdtc.bits.__ws0
#define _ws1      __wdtc.bits.__ws1
#define _ws2      __wdtc.bits.__ws2
#define _we0      __wdtc.bits.__we0
#define _we1      __wdtc.bits.__we1
#define _we2      __wdtc.bits.__we2
#define _we3      __wdtc.bits.__we3
#define _we4      __wdtc.bits.__we4
#define _tb00     __tbc.bits.__tb00
#define _tb01     __tbc.bits.__tb01
#define _tb02     __tbc.bits.__tb02
#define _lxtlp    __tbc.bits.__lxtlp
#define _tb10     __tbc.bits.__tb10
#define _tb11     __tbc.bits.__tb11
#define _tbck     __tbc.bits.__tbck
#define _tbon     __tbc.bits.__tbon
#define _wrf      __ctrl.bits.__wrf
#define _lrf      __ctrl.bits.__lrf
#define _lvrf     __ctrl.bits.__lvrf
#define _fsyson   __ctrl.bits.__fsyson
#define _lvs0     __lvrc.bits.__lvs0
#define _lvs1     __lvrc.bits.__lvs1
#define _lvs2     __lvrc.bits.__lvs2
#define _lvs3     __lvrc.bits.__lvs3
#define _lvs4     __lvrc.bits.__lvs4
#define _lvs5     __lvrc.bits.__lvs5
#define _lvs6     __lvrc.bits.__lvs6
#define _lvs7     __lvrc.bits.__lvs7
#define _acs0     __adcr0.bits.__acs0
#define _acs1     __adcr0.bits.__acs1
#define _acs2     __adcr0.bits.__acs2
#define _adrfs    __adcr0.bits.__adrfs
#define _adoff    __adcr0.bits.__adoff
#define _eocb     __adcr0.bits.__eocb
#define _start    __adcr0.bits.__start
#define _adck0    __adcr1.bits.__adck0
#define _adck1    __adcr1.bits.__adck1
#define _adck2    __adcr1.bits.__adck2
#define _vrefs    __adcr1.bits.__vrefs
#define _vbgen    __adcr1.bits.__vbgen
#define _acs4     __adcr1.bits.__acs4
#define _ace0     __acerl.bits.__ace0
#define _ace1     __acerl.bits.__ace1
#define _ace2     __acerl.bits.__ace2
#define _ace3     __acerl.bits.__ace3
#define _ace4     __acerl.bits.__ace4
#define _ace5     __acerl.bits.__ace5
#define _ace6     __acerl.bits.__ace6
#define _ace7     __acerl.bits.__ace7
#define _pb0      __pb.bits.__pb0
#define _pb1      __pb.bits.__pb1
#define _pb2      __pb.bits.__pb2
#define _pb3      __pb.bits.__pb3
#define _pb4      __pb.bits.__pb4
#define _pb5      __pb.bits.__pb5
#define _pb6      __pb.bits.__pb6
#define _pbc0     __pbc.bits.__pbc0
#define _pbc1     __pbc.bits.__pbc1
#define _pbc2     __pbc.bits.__pbc2
#define _pbc3     __pbc.bits.__pbc3
#define _pbc4     __pbc.bits.__pbc4
#define _pbc5     __pbc.bits.__pbc5
#define _pbc6     __pbc.bits.__pbc6
#define _pbpu0    __pbpu.bits.__pbpu0
#define _pbpu1    __pbpu.bits.__pbpu1
#define _pbpu2    __pbpu.bits.__pbpu2
#define _pbpu3    __pbpu.bits.__pbpu3
#define _pbpu4    __pbpu.bits.__pbpu4
#define _pbpu5    __pbpu.bits.__pbpu5
#define _pbpu6    __pbpu.bits.__pbpu6
#define _t2on     __tm2c0.bits.__t2on
#define _t2ck0    __tm2c0.bits.__t2ck0
#define _t2ck1    __tm2c0.bits.__t2ck1
#define _t2ck2    __tm2c0.bits.__t2ck2
#define _t2pau    __tm2c0.bits.__t2pau
#define _t2cclr   __tm2c1.bits.__t2cclr
#define _t2dpx    __tm2c1.bits.__t2dpx
#define _t2pol    __tm2c1.bits.__t2pol
#define _t2oc     __tm2c1.bits.__t2oc
#define _t2io0    __tm2c1.bits.__t2io0
#define _t2io1    __tm2c1.bits.__t2io1
#define _t2m0     __tm2c1.bits.__t2m0
#define _t2m1     __tm2c1.bits.__t2m1
#define _t2rp0    __tm2rp.bits.__t2rp0
#define _t2rp1    __tm2rp.bits.__t2rp1
#define _t2rp2    __tm2rp.bits.__t2rp2
#define _t2rp3    __tm2rp.bits.__t2rp3
#define _t2rp4    __tm2rp.bits.__t2rp4
#define _t2rp5    __tm2rp.bits.__t2rp5
#define _t2rp6    __tm2rp.bits.__t2rp6
#define _t2rp7    __tm2rp.bits.__t2rp7
#define _t0on     __tm0c0.bits.__t0on
#define _t0ck0    __tm0c0.bits.__t0ck0
#define _t0ck1    __tm0c0.bits.__t0ck1
#define _t0ck2    __tm0c0.bits.__t0ck2
#define _t0pau    __tm0c0.bits.__t0pau
#define _t0cclr   __tm0c1.bits.__t0cclr
#define _t0dpx    __tm0c1.bits.__t0dpx
#define _t0pol    __tm0c1.bits.__t0pol
#define _t0oc     __tm0c1.bits.__t0oc
#define _t0io0    __tm0c1.bits.__t0io0
#define _t0io1    __tm0c1.bits.__t0io1
#define _t0m0     __tm0c1.bits.__t0m0
#define _t0m1     __tm0c1.bits.__t0m1
#define _t0rp0    __tm0rp.bits.__t0rp0
#define _t0rp1    __tm0rp.bits.__t0rp1
#define _t0rp2    __tm0rp.bits.__t0rp2
#define _t0rp3    __tm0rp.bits.__t0rp3
#define _t0rp4    __tm0rp.bits.__t0rp4
#define _t0rp5    __tm0rp.bits.__t0rp5
#define _t0rp6    __tm0rp.bits.__t0rp6
#define _t0rp7    __tm0rp.bits.__t0rp7
#define _t1on     __tm1c0.bits.__t1on
#define _t1ck0    __tm1c0.bits.__t1ck0
#define _t1ck1    __tm1c0.bits.__t1ck1
#define _t1ck2    __tm1c0.bits.__t1ck2
#define _t1pau    __tm1c0.bits.__t1pau
#define _t1cclr   __tm1c1.bits.__t1cclr
#define _t1capts  __tm1c1.bits.__t1capts
#define _t1pol    __tm1c1.bits.__t1pol
#define _t1oc     __tm1c1.bits.__t1oc
#define _t1io0    __tm1c1.bits.__t1io0
#define _t1io1    __tm1c1.bits.__t1io1
#define _t1m0     __tm1c1.bits.__t1m0
#define _t1m1     __tm1c1.bits.__t1m1
#define _chyen    __cpc.bits.__chyen
#define _cos      __cpc.bits.__cos
#define _cout     __cpc.bits.__cout
#define _cpol     __cpc.bits.__cpol
#define _cen      __cpc.bits.__cen
#define _csel     __cpc.bits.__csel
#define _pc0      __pc.bits.__pc0
#define _pc1      __pc.bits.__pc1
#define _pc2      __pc.bits.__pc2
#define _pcc0     __pcc.bits.__pcc0
#define _pcc1     __pcc.bits.__pcc1
#define _pcc2     __pcc.bits.__pcc2
#define _pcpu0    __pcpu.bits.__pcpu0
#define _pcpu1    __pcpu.bits.__pcpu1
#define _pcpu2    __pcpu.bits.__pcpu2

#define ___mkstr(x)                #x
#define __EEPROM_DATA(a, b, c, d, e, f, g, h) \
                         asm("eeprom_data .section 'eeprom'"); \
                         asm("db\t" ___mkstr(a));        \
                         asm("db\t" ___mkstr(b));        \
                         asm("db\t" ___mkstr(c));        \
                         asm("db\t" ___mkstr(d));        \
                         asm("db\t" ___mkstr(e));        \
                         asm("db\t" ___mkstr(f));        \
                         asm("db\t" ___mkstr(g));        \
                         asm("db\t" ___mkstr(h));        

#endif // _HT66F018_H_
