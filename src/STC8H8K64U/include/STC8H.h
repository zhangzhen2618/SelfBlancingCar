#ifndef     __STC8H_H__
#define     __STC8H_H__

//包含本头文件后,不用另外再包含"REG51.H"

#include <compiler.h>

SFR(P0,          0x80);
	SBIT(P0_0,		0X80, 0);
	SBIT(P0_1,		0X80, 1);
	SBIT(P0_2,		0X80, 2);
	SBIT(P0_3,		0X80, 3);
	SBIT(P0_4,		0X80, 4);
	SBIT(P0_5,		0X80, 5);
	SBIT(P0_6,		0X80, 6);
	SBIT(P0_7,		0X80, 7);
SFR(SP,          0x81);
SFR(DPL,         0x82);
SFR(DPH,         0x83);
SFR(S4CON,       0x84);
SFR(S4BUF,       0x85);
SFR(PCON,        0x87);
SFR(TCON,        0x88);
	SBIT(TF1,		0X88, 7);
	SBIT(TR1,		0X88, 6);
	SBIT(TF0,		0X88, 5);
	SBIT(TR0,		0X88, 4);
	SBIT(IE1,		0X88, 3);
	SBIT(IT1,		0X88, 2);
	SBIT(IE0,		0X88, 1);
	SBIT(IT0,		0X88, 0);
SFR(TMOD,        0x89);
SFR(TL0,         0x8a);
SFR(TL1,         0x8b);
SFR(TH0,         0x8c);
SFR(TH1,         0x8d);
SFR(AUXR,        0x8e);
SFR(INTCLKO,     0x8f);
SFR(P1,          0x90);
	SBIT(P1_0,		0x90, 0);
	SBIT(P1_1,		0x90, 1);
	SBIT(P1_2,		0x90, 2);
	SBIT(P1_3,		0x90, 3);
	SBIT(P1_4,		0x90, 4);
	SBIT(P1_5,		0x90, 5);
	SBIT(P1_6,		0x90, 6);
	SBIT(P1_7,		0x90, 7);
SFR(P1M1,        0x91);
SFR(P1M0,        0x92);
SFR(P0M1,        0x93);
SFR(P0M0,        0x94);
SFR(P2M1,        0x95);
SFR(P2M0,        0x96);
SFR(SCON,        0x98);
	SBIT(SM0,		0x98, 7);
	SBIT(SM1,		0x98, 6);
	SBIT(SM2,		0x98, 5);
	SBIT(REN,		0x98, 4);
	SBIT(TB8,		0x98, 3);
	SBIT(RB8,		0x98, 2);
	SBIT(TI,		0x98, 1);
	SBIT(RI,		0x98, 0);
SFR(SBUF,        0x99);
SFR(S2CON,       0x9a);
SFR(S2BUF,       0x9b);
SFR(IRCBAND,     0x9d);
SFR(LIRTRIM,     0x9e);
SFR(IRTRIM,      0x9f);
SFR(P2,          0xa0);
	SBIT(P2_0,		0xa0, 0);
	SBIT(P2_1,		0xa0, 1);
	SBIT(P2_2,		0xa0, 2);
	SBIT(P2_3,		0xa0, 3);
	SBIT(P2_4,		0xa0, 4);
	SBIT(P2_5,		0xa0, 5);
	SBIT(P2_6,		0xa0, 6);
	SBIT(P2_7,		0xa0, 7);
SFR(P_SW1,       0xa2);
SFR(IE,          0xa8);
	SBIT(EA,		0xa8, 7);
	SBIT(ELVD,		0xa8, 6);
	SBIT(EADC,		0xa8, 5);
	SBIT(ES,		0xa8, 4);
	SBIT(ET1,		0xa8, 3);
	SBIT(EX1,		0xa8, 2);
	SBIT(ET0,		0xa8, 1);
	SBIT(EX0,		0xa8, 0);
SFR(SADDR,       0xa9);
SFR(WKTCL,       0xaa);
SFR(WKTCH,       0xab);
SFR(S3CON,       0xac);
SFR(S3BUF,       0xad);
SFR(TA,          0xae);
SFR(IE2,         0xaf);
SFR(P3,          0xb0);
	SBIT(P3_0,		0xb0, 0);
	SBIT(P3_1,		0xb0, 1);
	SBIT(P3_2,		0xb0, 2);
	SBIT(P3_3,		0xb0, 3);
	SBIT(P3_4,		0xb0, 4);
	SBIT(P3_5,		0xb0, 5);
	SBIT(P3_6,		0xb0, 6);
	SBIT(P3_7,		0xb0, 7);
SFR(P3M1,        0xb1);
SFR(P3M0,        0xb2);
SFR(P4M1,        0xb3);
SFR(P4M0,        0xb4);
SFR(IP2,         0xb5);
SFR(IP2H,        0xb6);
SFR(IPH,         0xb7);
SFR(IP,          0xb8);
	SBIT(PPCA,		0xb8, 7);
	SBIT(PLVD,		0xb8, 6);
	SBIT(PADC,		0xb8, 5);
	SBIT(PS,		0xb8, 4);
	SBIT(PT1,		0xb8, 3);
	SBIT(PX1,		0xb8, 2);
	SBIT(PT0,		0xb8, 1);
	SBIT(PX0,		0xb8, 0);
SFR(SADEN,       0xb9);
SFR(P_SW2,       0xba);
SFR(ADC_CONTR,   0xbc);
SFR(ADC_RES,     0xbd);
SFR(ADC_RESL,    0xbe);
SFR(P4,          0xc0);
	SBIT(P4_0,		0xc0, 0);
	SBIT(P4_1,		0xc0, 1);
	SBIT(P4_2,		0xc0, 2);
	SBIT(P4_3,		0xc0, 3);
	SBIT(P4_4,		0xc0, 4);
	SBIT(P4_5,		0xc0, 5);
	SBIT(P4_6,		0xc0, 6);
	SBIT(P4_7,		0xc0, 7);
SFR(WDT_CONTR,   0xc1);
SFR(IAP_DATA,    0xc2);
SFR(IAP_ADDRH,   0xc3);
SFR(IAP_ADDRL,   0xc4);
SFR(IAP_CMD,     0xc5);
SFR(IAP_TRIG,    0xc6);
SFR(IAP_CONTR,   0xc7);
SFR(P5,          0xc8);
	SBIT(P5_0,		0xc8, 0);
	SBIT(P5_1,		0xc8, 1);
	SBIT(P5_2,		0xc8, 2);
	SBIT(P5_3,		0xc8, 3);
	SBIT(P5_4,		0xc8, 4);
	SBIT(P5_5,		0xc8, 5);
	SBIT(P5_6,		0xc8, 6);
	SBIT(P5_7,		0xc8, 7);
SFR(P5M1,        0xc9);
SFR(P5M0,        0xca);
SFR(P6M1,        0xcb);
SFR(P6M0,        0xcc);
SFR(SPSTAT,      0xcd);
SFR(SPCTL,       0xce);
SFR(SPDAT,       0xcf);
SFR(PSW,         0xd0);
	SBIT(CY,		0xd0, 7);
	SBIT(AC,		0xd0, 6);
	SBIT(F0,		0xd0, 5);
	SBIT(RS1,		0xd0, 4);
	SBIT(RS0,		0xd0, 3);
	SBIT(OV,		0xd0, 2);
	SBIT(F1,		0xd0, 1);
	SBIT(P,		    0xd0, 0);
SFR(T4T3M,       0xd1);
SFR(T4H,         0xd2);
SFR(T4L,         0xd3);
SFR(T3H,         0xd4);
SFR(T3L,         0xd5);
SFR(T2H,         0xd6);
SFR(T2L,         0xd7);
SFR(USBCLK,      0xdc);
SFR(ADCCFG,      0xde);
SFR(IP3,         0xdf);
SFR(ACC,         0xe0);
SFR(P7M1,        0xe1);
SFR(P7M0,        0xe2);
SFR(DPS,         0xe3);
SFR(DPL1,        0xe4);
SFR(DPH1,        0xe5);
SFR(CMPCR1,      0xe6);
SFR(CMPCR2,      0xe7);
SFR(P6,          0xe8);
	SBIT(P6_0,		0xe8, 0);
	SBIT(P6_1,		0xe8, 1);
	SBIT(P6_2,		0xe8, 2);
	SBIT(P6_3,		0xe8, 3);
	SBIT(P6_4,		0xe8, 4);
	SBIT(P6_5,		0xe8, 5);
	SBIT(P6_6,		0xe8, 6);
	SBIT(P6_7,		0xe8, 7);
SFR(USBDAT,      0xec);
SFR(IP3H,        0xee);
SFR(AUXINTIF,    0xef);
SFR(B,           0xf0);
SFR(USBCON,      0xf4);
SFR(IAP_TPS,     0xf5);
SFR(P7,          0xf8);
	SBIT(P7_0,		0xf8, 0);
	SBIT(P7_1,		0xf8, 1);
	SBIT(P7_2,		0xf8, 2);
	SBIT(P7_3,		0xf8, 3);
	SBIT(P7_4,		0xf8, 4);
	SBIT(P7_5,		0xf8, 5);
	SBIT(P7_6,		0xf8, 6);
	SBIT(P7_7,		0xf8, 7);
SFR(USBADR,      0xfc);
SFR(RSTCFG,      0xff);

//如下特殊功能寄存器位于扩展RAM区域
//访问这些寄存器,需先将P_SW2的BIT7设置为1,才可正常读写

/////////////////////////////////////////////////
//FF00H-FFFFH
/////////////////////////////////////////////////



/////////////////////////////////////////////////
//FE00H-FEFFH
/////////////////////////////////////////////////

SFRX(CLKSEL,                  0xfe00);
SFRX(CLKDIV,                  0xfe01);
SFRX(HIRCCR,                  0xfe02);
SFRX(XOSCCR,                  0xfe03);
SFRX(IRC32KCR,                0xfe04);
SFRX(MCLKOCR,                 0xfe05);
SFRX(IRCDB,                   0xfe06);
SFRX(IRC48MCR,                0xfe07);
SFRX(X32KCR,                  0xfe08);

SFRX(P0PU,                    0xfe10);
SFRX(P1PU,                    0xfe11);
SFRX(P2PU,                    0xfe12);
SFRX(P3PU,                    0xfe13);
SFRX(P4PU,                    0xfe14);
SFRX(P5PU,                    0xfe15);
SFRX(P6PU,                    0xfe16);
SFRX(P7PU,                    0xfe17);
SFRX(P0NCS,                   0xfe18);
SFRX(P1NCS,                   0xfe19);
SFRX(P2NCS,                   0xfe1a);
SFRX(P3NCS,                   0xfe1b);
SFRX(P4NCS,                   0xfe1c);
SFRX(P5NCS,                   0xfe1d);
SFRX(P6NCS,                   0xfe1e);
SFRX(P7NCS,                   0xfe1f);
SFRX(P0SR,                    0xfe20);
SFRX(P1SR,                    0xfe21);
SFRX(P2SR,                    0xfe22);
SFRX(P3SR,                    0xfe23);
SFRX(P4SR,                    0xfe24);
SFRX(P5SR,                    0xfe25);
SFRX(P6SR,                    0xfe26);
SFRX(P7SR,                    0xfe27);
SFRX(P0DR,                    0xfe28);
SFRX(P1DR,                    0xfe29);
SFRX(P2DR,                    0xfe2a);
SFRX(P3DR,                    0xfe2b);
SFRX(P4DR,                    0xfe2c);
SFRX(P5DR,                    0xfe2d);
SFRX(P6DR,                    0xfe2e);
SFRX(P7DR,                    0xfe2f);
SFRX(P0IE,                    0xfe30);
SFRX(P1IE,                    0xfe31);
SFRX(P2IE,                    0xfe32);
SFRX(P3IE,                    0xfe33);
SFRX(P4IE,                    0xfe34);
SFRX(P5IE,                    0xfe35);
SFRX(P6IE,                    0xfe36);
SFRX(P7IE,                    0xfe37);

SFRX(LCMIFCFG,                0xfe50);
SFRX(LCMIFCFG2,               0xfe51);
SFRX(LCMIFCR,                 0xfe52);
SFRX(LCMIFSTA,                0xfe53);
SFRX(LCMIFDATL,               0xfe54);
SFRX(LCMIFDATH,               0xfe55);

SFRX(RTCCR,                   0xfe60);
SFRX(RTCCFG,                  0xfe61);
SFRX(RTCIEN,                  0xfe62);
SFRX(RTCIF,                   0xfe63);
SFRX(ALAHOUR,                 0xfe64);
SFRX(ALAMIN,                  0xfe65);
SFRX(ALASEC,                  0xfe66);
SFRX(ALASSEC,                 0xfe67);
SFRX(INIYEAR,                 0xfe68);
SFRX(INIMONTH,                0xfe69);
SFRX(INIDAY,                  0xfe6a);
SFRX(INIHOUR,                 0xfe6b);
SFRX(INIMIN,                  0xfe6c);
SFRX(INISEC,                  0xfe6d);
SFRX(INISSEC,                 0xfe6e);
SFRX(YEAR,                    0xfe70);
SFRX(MONTH,                   0xfe71);
SFRX(DAY,                     0xfe72);
SFRX(HOUR,                    0xfe73);
SFRX(MIN,                     0xfe74);
SFRX(SEC,                     0xfe75);
SFRX(SSEC,                    0xfe76);

SFRX(I2CCFG,                  0xfe80);
SFRX(I2CMSCR,                 0xfe81);
SFRX(I2CMSST,                 0xfe82);
SFRX(I2CSLCR,                 0xfe83);
SFRX(I2CSLST,                 0xfe84);
SFRX(I2CSLADR,                0xfe85);
SFRX(I2CTXD,                  0xfe86);
SFRX(I2CRXD,                  0xfe87);
SFRX(I2CMSAUX,                0xfe88);

SFRX(SPFUNC,                  0xfe98);
SFRX(RSTFLAG,                 0xfe99);

SFRX(TM2PS,                   0xfea2);
SFRX(TM3PS,                   0xfea3);
SFRX(TM4PS,                   0xfea4);
SFRX(ADCTIM,                  0xfea8);
SFRX(T3T4PIN,                 0xfeac);
SFRX(ADCEXCFG,                0xfead);
SFRX(CMPEXCFG,                0xfeae);

SFRX(PWM1_ETRPS,              0xfeb0);
SFRX(PWM1_ENO,                0xfeb1);
SFRX(PWM1_PS,                 0xfeb2);
SFRX(PWM1_IOAUX,              0xfeb3);
SFRX(PWM2_ETRPS,              0xfeb4);
SFRX(PWM2_ENO,                0xfeb5);
SFRX(PWM2_PS,                 0xfeb6);
SFRX(PWM2_IOAUX,              0xfeb7);
SFRX(PWM1_CR1,                0xfec0);
SFRX(PWM1_CR2,                0xfec1);
SFRX(PWM1_SMCR,               0xfec2);
SFRX(PWM1_ETR,                0xfec3);
SFRX(PWM1_IER,                0xfec4);
SFRX(PWM1_SR1,                0xfec5);
SFRX(PWM1_SR2,                0xfec6);
SFRX(PWM1_EGR,                0xfec7);
SFRX(PWM1_CCMR1,              0xfec8);
SFRX(PWM1_CCMR2,              0xfec9);
SFRX(PWM1_CCMR3,              0xfeca);
SFRX(PWM1_CCMR4,              0xfecb);
SFRX(PWM1_CCER1,              0xfecc);
SFRX(PWM1_CCER2,              0xfecd);
SFR16LEX(PWM1_CNTR,               0xfece);
SFRX(PWM1_CNTRH,              0xfece);
SFRX(PWM1_CNTRL,              0xfecf);
SFR16LEX(PWM1_PSCR,               0xfed0);
SFRX(PWM1_PSCRH,              0xfed0);
SFRX(PWM1_PSCRL,              0xfed1);
SFR16LEX(PWM1_ARR,                0xfed2);
SFRX(PWM1_ARRH,               0xfed2);
SFRX(PWM1_ARRL,               0xfed3);
SFRX(PWM1_RCR,                0xfed4);
SFR16LEX(PWM1_CCR1,               0xfed5);
SFRX(PWM1_CCR1H,              0xfed5);
SFRX(PWM1_CCR1L,              0xfed6);
SFR16LEX(PWM1_CCR2,               0xfed7);
SFRX(PWM1_CCR2H,              0xfed7);
SFRX(PWM1_CCR2L,              0xfed8);
SFR16LEX(PWM1_CCR3,               0xfed9);
SFRX(PWM1_CCR3H,              0xfed9);
SFRX(PWM1_CCR3L,              0xfeda);
SFR16LEX(PWM1_CCR4,               0xfedb);
SFRX(PWM1_CCR4H,              0xfedb);
SFRX(PWM1_CCR4L,              0xfedc);
SFRX(PWM1_BKR,                0xfedd);
SFRX(PWM1_DTR,                0xfede);
SFRX(PWM1_OISR,               0xfedf);
SFRX(PWM2_CR1,                0xfee0);
SFRX(PWM2_CR2,                0xfee1);
SFRX(PWM2_SMCR,               0xfee2);
SFRX(PWM2_ETR,                0xfee3);
SFRX(PWM2_IER,                0xfee4);
SFRX(PWM2_SR1,                0xfee5);
SFRX(PWM2_SR2,                0xfee6);
SFRX(PWM2_EGR,                0xfee7);
SFRX(PWM2_CCMR1,              0xfee8);
SFRX(PWM2_CCMR2,              0xfee9);
SFRX(PWM2_CCMR3,              0xfeea);
SFRX(PWM2_CCMR4,              0xfeeb);
SFRX(PWM2_CCER1,              0xfeec);
SFRX(PWM2_CCER2,              0xfeed);
SFR16LEX(PWM2_CNTR,               0xfeee);
SFRX(PWM2_CNTRH,              0xfeee);
SFRX(PWM2_CNTRL,              0xfeef);
SFR16LEX(PWM2_PSCR,               0xfef0);
SFRX(PWM2_PSCRH,              0xfef0);
SFRX(PWM2_PSCRL,              0xfef1);
SFR16LEX(PWM2_ARR,                0xfef2);
SFRX(PWM2_ARRH,               0xfef2);
SFRX(PWM2_ARRL,               0xfef3);
SFRX(PWM2_RCR,                0xfef4);
SFR16LEX(PWM2_CCR1,               0xfef5);
SFRX(PWM2_CCR1H,              0xfef5);
SFRX(PWM2_CCR1L,              0xfef6);
SFR16LEX(PWM2_CCR2,               0xfef7);
SFRX(PWM2_CCR2H,              0xfef7);
SFRX(PWM2_CCR2L,              0xfef8);
SFR16LEX(PWM2_CCR3,               0xfef9);
SFRX(PWM2_CCR3H,              0xfef9);
SFRX(PWM2_CCR3L,              0xfefa);
SFR16LEX(PWM2_CCR4,               0xfefb);
SFRX(PWM2_CCR4H,              0xfefb);
SFRX(PWM2_CCR4L,              0xfefc);
SFRX(PWM2_BKR,                0xfefd);
SFRX(PWM2_DTR,                0xfefe);
SFRX(PWM2_OISR,               0xfeff);

SFRX(PWMA_ETRPS,              0xfeb0);
SFRX(PWMA_ENO,                0xfeb1);
SFRX(PWMA_PS,                 0xfeb2);
SFRX(PWMA_IOAUX,              0xfeb3);
SFRX(PWMB_ETRPS,              0xfeb4);
SFRX(PWMB_ENO,                0xfeb5);
SFRX(PWMB_PS,                 0xfeb6);
SFRX(PWMB_IOAUX,              0xfeb7);
SFRX(PWMA_CR1,                0xfec0);
SFRX(PWMA_CR2,                0xfec1);
SFRX(PWMA_SMCR,               0xfec2);
SFRX(PWMA_ETR,                0xfec3);
SFRX(PWMA_IER,                0xfec4);
SFRX(PWMA_SR1,                0xfec5);
SFRX(PWMA_SR2,                0xfec6);
SFRX(PWMA_EGR,                0xfec7);
SFRX(PWMA_CCMR1,              0xfec8);
SFRX(PWMA_CCMR2,              0xfec9);
SFRX(PWMA_CCMR3,              0xfeca);
SFRX(PWMA_CCMR4,              0xfecb);
SFRX(PWMA_CCER1,              0xfecc);
SFRX(PWMA_CCER2,              0xfecd);
SFR16LEX(PWMA_CNTR,               0xfece);
SFRX(PWMA_CNTRH,              0xfece);
SFRX(PWMA_CNTRL,              0xfecf);
SFR16LEX(PWMA_PSCR,               0xfed0);
SFRX(PWMA_PSCRH,              0xfed0);
SFRX(PWMA_PSCRL,              0xfed1);
SFR16LEX(PWMA_ARR,                0xfed2);
SFRX(PWMA_ARRH,               0xfed2);
SFRX(PWMA_ARRL,               0xfed3);
SFRX(PWMA_RCR,                0xfed4);
SFR16LEX(PWMA_CCR1,               0xfed5);
SFRX(PWMA_CCR1H,              0xfed5);
SFRX(PWMA_CCR1L,              0xfed6);
SFR16LEX(PWMA_CCR2,               0xfed7);
SFRX(PWMA_CCR2H,              0xfed7);
SFRX(PWMA_CCR2L,              0xfed8);
SFR16LEX(PWMA_CCR3,               0xfed9);
SFRX(PWMA_CCR3H,              0xfed9);
SFRX(PWMA_CCR3L,              0xfeda);
SFR16LEX(PWMA_CCR4,               0xfedb);
SFRX(PWMA_CCR4H,              0xfedb);
SFRX(PWMA_CCR4L,              0xfedc);
SFRX(PWMA_BKR,                0xfedd);
SFRX(PWMA_DTR,                0xfede);
SFRX(PWMA_OISR,               0xfedf);
SFRX(PWMB_CR1,                0xfee0);
SFRX(PWMB_CR2,                0xfee1);
SFRX(PWMB_SMCR,               0xfee2);
SFRX(PWMB_ETR,                0xfee3);
SFRX(PWMB_IER,                0xfee4);
SFRX(PWMB_SR1,                0xfee5);
SFRX(PWMB_SR2,                0xfee6);
SFRX(PWMB_EGR,                0xfee7);
SFRX(PWMB_CCMR1,              0xfee8);
SFRX(PWMB_CCMR2,              0xfee9);
SFRX(PWMB_CCMR3,              0xfeea);
SFRX(PWMB_CCMR4,              0xfeeb);
SFRX(PWMB_CCER1,              0xfeec);
SFRX(PWMB_CCER2,              0xfeed);
SFR16LEX(PWMB_CNTR,               0xfeee);
SFRX(PWMB_CNTRH,              0xfeee);
SFRX(PWMB_CNTRL,              0xfeef);
SFR16LEX(PWMB_PSCR,               0xfef0);
SFRX(PWMB_PSCRH,              0xfef0);
SFRX(PWMB_PSCRL,              0xfef1);
SFR16LEX(PWMB_ARR,                0xfef2);
SFRX(PWMB_ARRH,               0xfef2);
SFRX(PWMB_ARRL,               0xfef3);
SFRX(PWMB_RCR,                0xfef4);
SFR16LEX(PWMB_CCR5,               0xfef5);
SFRX(PWMB_CCR5H,              0xfef5);
SFRX(PWMB_CCR5L,              0xfef6);
SFR16LEX(PWMB_CCR6,               0xfef7);
SFRX(PWMB_CCR6H,              0xfef7);
SFRX(PWMB_CCR6L,              0xfef8);
SFR16LEX(PWMB_CCR7,               0xfef9);
SFRX(PWMB_CCR7H,              0xfef9);
SFRX(PWMB_CCR7L,              0xfefa);
SFR16LEX(PWMB_CCR8,               0xfefb);
SFRX(PWMB_CCR8H,              0xfefb);
SFRX(PWMB_CCR8L,              0xfefc);
SFRX(PWMB_BKR,                0xfefd);
SFRX(PWMB_DTR,                0xfefe);
SFRX(PWMB_OISR,               0xfeff);

/////////////////////////////////////////////////
//FD00H-FDFFH
/////////////////////////////////////////////////

SFRX(P0INTE,                  0xfd00);
SFRX(P1INTE,                  0xfd01);
SFRX(P2INTE,                  0xfd02);
SFRX(P3INTE,                  0xfd03);
SFRX(P4INTE,                  0xfd04);
SFRX(P5INTE,                  0xfd05);
SFRX(P6INTE,                  0xfd06);
SFRX(P7INTE,                  0xfd07);
SFRX(P0INTF,                  0xfd10);
SFRX(P1INTF,                  0xfd11);
SFRX(P2INTF,                  0xfd12);
SFRX(P3INTF,                  0xfd13);
SFRX(P4INTF,                  0xfd14);
SFRX(P5INTF,                  0xfd15);
SFRX(P6INTF,                  0xfd16);
SFRX(P7INTF,                  0xfd17);
SFRX(P0IM0,                   0xfd20);
SFRX(P1IM0,                   0xfd21);
SFRX(P2IM0,                   0xfd22);
SFRX(P3IM0,                   0xfd23);
SFRX(P4IM0,                   0xfd24);
SFRX(P5IM0,                   0xfd25);
SFRX(P6IM0,                   0xfd26);
SFRX(P7IM0,                   0xfd27);
SFRX(P0IM1,                   0xfd30);
SFRX(P1IM1,                   0xfd31);
SFRX(P2IM1,                   0xfd32);
SFRX(P3IM1,                   0xfd33);
SFRX(P4IM1,                   0xfd34);
SFRX(P5IM1,                   0xfd35);
SFRX(P6IM1,                   0xfd36);
SFRX(P7IM1,                   0xfd37);
SFRX(P0WKUE,                  0xfd40);
SFRX(P1WKUE,                  0xfd41);
SFRX(P2WKUE,                  0xfd42);
SFRX(P3WKUE,                  0xfd43);
SFRX(P4WKUE,                  0xfd44);
SFRX(P5WKUE,                  0xfd45);
SFRX(P6WKUE,                  0xfd46);
SFRX(P7WKUE,                  0xfd47);

SFRX(PIN_IP,                  0xfd60);
SFRX(PIN_IPH,                 0xfd61);

SFRX(CHIPID,                  0xfde0);

SFRX(CHIPID0,                 0xfde0);
SFRX(CHIPID1,                 0xfde1);
SFRX(CHIPID2,                 0xfde2);
SFRX(CHIPID3,                 0xfde3);
SFRX(CHIPID4,                 0xfde4);
SFRX(CHIPID5,                 0xfde5);
SFRX(CHIPID6,                 0xfde6);
SFRX(CHIPID7,                 0xfde7);
SFRX(CHIPID8,                 0xfde8);
SFRX(CHIPID9,                 0xfde9);
SFRX(CHIPID10,                0xfdea);
SFRX(CHIPID11,                0xfdeb);
SFRX(CHIPID12,                0xfdec);
SFRX(CHIPID13,                0xfded);
SFRX(CHIPID14,                0xfdee);
SFRX(CHIPID15,                0xfdef);
SFRX(CHIPID16,                0xfdf0);
SFRX(CHIPID17,                0xfdf1);
SFRX(CHIPID18,                0xfdf2);
SFRX(CHIPID19,                0xfdf3);
SFRX(CHIPID20,                0xfdf4);
SFRX(CHIPID21,                0xfdf5);
SFRX(CHIPID22,                0xfdf6);
SFRX(CHIPID23,                0xfdf7);
SFRX(CHIPID24,                0xfdf8);
SFRX(CHIPID25,                0xfdf9);
SFRX(CHIPID26,                0xfdfa);
SFRX(CHIPID27,                0xfdfb);
SFRX(CHIPID28,                0xfdfc);
SFRX(CHIPID29,                0xfdfd);
SFRX(CHIPID30,                0xfdfe);
SFRX(CHIPID31,                0xfdff);

/////////////////////////////////////////////////
//FC00H-FCFFH
/////////////////////////////////////////////////

SFRX(MD3,                     0xfcf0);
SFRX(MD2,                     0xfcf1);
SFRX(MD1,                     0xfcf2);
SFRX(MD0,                     0xfcf3);
SFRX(MD5,                     0xfcf4);
SFRX(MD4,                     0xfcf5);
SFRX(ARCON,                   0xfcf6);
SFRX(OPCON,                   0xfcf7);

/////////////////////////////////////////////////
//FB00H-FBFFH
/////////////////////////////////////////////////

SFRX(COMEN,                   0xfb00);
SFRX(SEGENL,                  0xfb01);
SFRX(SEGENH,                  0xfb02);
SFRX(LEDCTRL,                 0xfb03);
SFRX(LEDCKS,                  0xfb04);
SFRX(COM0_DA_L,               0xfb10);
SFRX(COM1_DA_L,               0xfb11);
SFRX(COM2_DA_L,               0xfb12);
SFRX(COM3_DA_L,               0xfb13);
SFRX(COM4_DA_L,               0xfb14);
SFRX(COM5_DA_L,               0xfb15);
SFRX(COM6_DA_L,               0xfb16);
SFRX(COM7_DA_L,               0xfb17);
SFRX(COM0_DA_H,               0xfb18);
SFRX(COM1_DA_H,               0xfb19);
SFRX(COM2_DA_H,               0xfb1a);
SFRX(COM3_DA_H,               0xfb1b);
SFRX(COM4_DA_H,               0xfb1c);
SFRX(COM5_DA_H,               0xfb1d);
SFRX(COM6_DA_H,               0xfb1e);
SFRX(COM7_DA_H,               0xfb1f);
SFRX(COM0_DC_L,               0xfb20);
SFRX(COM1_DC_L,               0xfb21);
SFRX(COM2_DC_L,               0xfb22);
SFRX(COM3_DC_L,               0xfb23);
SFRX(COM4_DC_L,               0xfb24);
SFRX(COM5_DC_L,               0xfb25);
SFRX(COM6_DC_L,               0xfb26);
SFRX(COM7_DC_L,               0xfb27);
SFRX(COM0_DC_H,               0xfb28);
SFRX(COM1_DC_H,               0xfb29);
SFRX(COM2_DC_H,               0xfb2a);
SFRX(COM3_DC_H,               0xfb2b);
SFRX(COM4_DC_H,               0xfb2c);
SFRX(COM5_DC_H,               0xfb2d);
SFRX(COM6_DC_H,               0xfb2e);
SFRX(COM7_DC_H,               0xfb2f);

SFRX(TSCHEN1,                 0xfb40);
SFRX(TSCHEN2,                 0xfb41);
SFRX(TSCFG1,                  0xfb42);
SFRX(TSCFG2,                  0xfb43);
SFRX(TSWUTC,                  0xfb44);
SFRX(TSCTRL,                  0xfb45);
SFRX(TSSTA1,                  0xfb46);
SFRX(TSSTA2,                  0xfb47);
SFRX(TSRT,                    0xfb48);
SFR16LEX(TSDAT,                   0xfb49);
SFRX(TSDATH,                  0xfb49);
SFRX(TSDATL,                  0xfb4A);
SFR16LEX(TSTH00,                  0xfb50);
SFRX(TSTH00H,                 0xfb50);
SFRX(TSTH00L,                 0xfb51);
SFR16LEX(TSTH01,                  0xfb52);
SFRX(TSTH01H,                 0xfb52);
SFRX(TSTH01L,                 0xfb53);
SFR16LEX(TSTH02,                  0xfb54);
SFRX(TSTH02H,                 0xfb54);
SFRX(TSTH02L,                 0xfb55);
SFR16LEX(TSTH03,                  0xfb56);
SFRX(TSTH03H,                 0xfb56);
SFRX(TSTH03L,                 0xfb57);
SFR16LEX(TSTH04,                  0xfb58);
SFRX(TSTH04H,                 0xfb58);
SFRX(TSTH04L,                 0xfb59);
SFR16LEX(TSTH05,                  0xfb5a);
SFRX(TSTH05H,                 0xfb5a);
SFRX(TSTH05L,                 0xfb5b);
SFR16LEX(TSTH06,                  0xfb5c);
SFRX(TSTH06H,                 0xfb5c);
SFRX(TSTH06L,                 0xfb5d);
SFR16LEX(TSTH07,                  0xfb5e);
SFRX(TSTH07H,                 0xfb5e);
SFRX(TSTH07L,                 0xfb5f);
SFR16LEX(TSTH08,                  0xfb60);
SFRX(TSTH08H,                 0xfb60);
SFRX(TSTH08L,                 0xfb61);
SFR16LEX(TSTH09,                  0xfb62);
SFRX(TSTH09H,                 0xfb62);
SFRX(TSTH09L,                 0xfb63);
SFR16LEX(TSTH10,                  0xfb64);
SFRX(TSTH10H,                 0xfb64);
SFRX(TSTH10L,                 0xfb65);
SFR16LEX(TSTH11,                  0xfb66);
SFRX(TSTH11H,                 0xfb66);
SFRX(TSTH11L,                 0xfb67);
SFR16LEX(TSTH12,                  0xfb68);
SFRX(TSTH12H,                 0xfb68);
SFRX(TSTH12L,                 0xfb69);
SFR16LEX(TSTH13,                  0xfb6a);
SFRX(TSTH13H,                 0xfb6a);
SFRX(TSTH13L,                 0xfb6b);
SFR16LEX(TSTH14,                  0xfb6c);
SFRX(TSTH14H,                 0xfb6c);
SFRX(TSTH14L,                 0xfb6d);
SFR16LEX(TSTH15,                  0xfb6e);
SFRX(TSTH15H,                 0xfb6e);
SFRX(TSTH15L,                 0xfb6f);

SFRX(LCDCFG,                  0xfb80);
SFRX(LCDCFG2,                 0xfb81);
SFRX(DBLEN,                   0xfb82);
SFRX(COMLENL,                 0xfb83);
SFRX(COMLENM,                 0xfb84);
SFRX(COMLENH,                 0xfb85);
SFRX(BLINKRATE,               0xfb86);
SFRX(LCDCR,                   0xfb87);
SFRX(COMON,                   0xfb88);
SFRX(SEGON1,                  0xfb8a);
SFRX(SEGON2,                  0xfb8b);
SFRX(SEGON3,                  0xfb8c);
SFRX(SEGON4,                  0xfb8d);
SFRX(SEGON5,                  0xfb8e);
SFRX(C0SEGV0,                 0xfb90);
SFRX(C0SEGV1,                 0xfb91);
SFRX(C0SEGV2,                 0xfb92);
SFRX(C0SEGV3,                 0xfb93);
SFRX(C0SEGV4,                 0xfb94);
SFRX(C1SEGV0,                 0xfb98);
SFRX(C1SEGV1,                 0xfb99);
SFRX(C1SEGV2,                 0xfb9a);
SFRX(C1SEGV3,                 0xfb9b);
SFRX(C1SEGV4,                 0xfb9c);
SFRX(C2SEGV0,                 0xfba0);
SFRX(C2SEGV1,                 0xfba1);
SFRX(C2SEGV2,                 0xfba2);
SFRX(C2SEGV3,                 0xfba3);
SFRX(C2SEGV4,                 0xfba4);
SFRX(C3SEGV0,                 0xfba8);
SFRX(C3SEGV1,                 0xfba9);
SFRX(C3SEGV2,                 0xfbaa);
SFRX(C3SEGV3,                 0xfbab);
SFRX(C3SEGV4,                 0xfbac);

/////////////////////////////////////////////////
//FA00H-FAFFH
/////////////////////////////////////////////////

SFRX(DMA_M2M_CFG,             0xfa00);
SFRX(DMA_M2M_CR,              0xfa01);
SFRX(DMA_M2M_STA,             0xfa02);
SFRX(DMA_M2M_AMT,             0xfa03);
SFRX(DMA_M2M_DONE,            0xfa04);
SFRX(DMA_M2M_TXAH,            0xfa05);
SFRX(DMA_M2M_TXAL,            0xfa06);
SFRX(DMA_M2M_RXAH,            0xfa07);
SFRX(DMA_M2M_RXAL,            0xfa08);

SFRX(DMA_ADC_CFG,             0xfa10);
SFRX(DMA_ADC_CR,              0xfa11);
SFRX(DMA_ADC_STA,             0xfa12);
SFR16LEX(DMA_ADC_RXA,             0xfa17);
SFRX(DMA_ADC_RXAH,            0xfa17);
SFRX(DMA_ADC_RXAL,            0xfa18);
SFRX(DMA_ADC_CFG2,            0xfa19);
SFRX(DMA_ADC_CHSW0,           0xfa1a);
SFRX(DMA_ADC_CHSW1,           0xfa1b);

SFRX(DMA_SPI_CFG,             0xfa20);
SFRX(DMA_SPI_CR,              0xfa21);
SFRX(DMA_SPI_STA,             0xfa22);
SFRX(DMA_SPI_AMT,             0xfa23);
SFRX(DMA_SPI_DONE,            0xfa24);
SFR16LEX(DMA_SPI_TXA,             0xfa25);
SFRX(DMA_SPI_TXAH,            0xfa25);
SFRX(DMA_SPI_TXAL,            0xfa26);
SFR16LEX(DMA_SPI_RXA,             0xfa27);
SFRX(DMA_SPI_RXAH,            0xfa27);
SFRX(DMA_SPI_RXAL,            0xfa28);
SFRX(DMA_SPI_CFG2,            0xfa29);

SFRX(DMA_UR1T_CFG,            0xfa30);
SFRX(DMA_UR1T_CR,             0xfa31);
SFRX(DMA_UR1T_STA,            0xfa32);
SFRX(DMA_UR1T_AMT,            0xfa33);
SFRX(DMA_UR1T_DONE,           0xfa34);
SFR16LEX(DMA_UR1T_TXA,            0xfa35);
SFRX(DMA_UR1T_TXAH,           0xfa35);
SFRX(DMA_UR1T_TXAL,           0xfa36);
SFRX(DMA_UR1R_CFG,            0xfa38);
SFRX(DMA_UR1R_CR,             0xfa39);
SFRX(DMA_UR1R_STA,            0xfa3a);
SFRX(DMA_UR1R_AMT,            0xfa3b);
SFRX(DMA_UR1R_DONE,           0xfa3c);
SFR16LEX(DMA_UR1R_RXA,            0xfa3d);
SFRX(DMA_UR1R_RXAH,           0xfa3d);
SFRX(DMA_UR1R_RXAL,           0xfa3e);

SFRX(DMA_UR2T_CFG,            0xfa40);
SFRX(DMA_UR2T_CR,             0xfa41);
SFRX(DMA_UR2T_STA,            0xfa42);
SFRX(DMA_UR2T_AMT,            0xfa43);
SFRX(DMA_UR2T_DONE,           0xfa44);
SFR16LEX(DMA_UR2T_TXA,            0xfa45);
SFRX(DMA_UR2T_TXAH,           0xfa45);
SFRX(DMA_UR2T_TXAL,           0xfa46);
SFRX(DMA_UR2R_CFG,            0xfa48);
SFRX(DMA_UR2R_CR,             0xfa49);
SFRX(DMA_UR2R_STA,            0xfa4a);
SFRX(DMA_UR2R_AMT,            0xfa4b);
SFRX(DMA_UR2R_DONE,           0xfa4c);
SFR16LEX(DMA_UR2R_RXA,            0xfa4d);
SFRX(DMA_UR2R_RXAH,           0xfa4d);
SFRX(DMA_UR2R_RXAL,           0xfa4e);

SFRX(DMA_UR3T_CFG,            0xfa50);
SFRX(DMA_UR3T_CR,             0xfa51);
SFRX(DMA_UR3T_STA,            0xfa52);
SFRX(DMA_UR3T_AMT,            0xfa53);
SFRX(DMA_UR3T_DONE,           0xfa54);
SFR16LEX(DMA_UR3T_TXA,            0xfa55);
SFRX(DMA_UR3T_TXAH,           0xfa55);
SFRX(DMA_UR3T_TXAL,           0xfa56);
SFRX(DMA_UR3R_CFG,            0xfa58);
SFRX(DMA_UR3R_CR,             0xfa59);
SFRX(DMA_UR3R_STA,            0xfa5a);
SFRX(DMA_UR3R_AMT,            0xfa5b);
SFRX(DMA_UR3R_DONE,           0xfa5c);
SFR16LEX(DMA_UR3R_RXA,            0xfa5d);
SFRX(DMA_UR3R_RXAH,           0xfa5d);
SFRX(DMA_UR3R_RXAL,           0xfa5e);

SFRX(DMA_UR4T_CFG,            0xfa60);
SFRX(DMA_UR4T_CR,             0xfa61);
SFRX(DMA_UR4T_STA,            0xfa62);
SFRX(DMA_UR4T_AMT,            0xfa63);
SFRX(DMA_UR4T_DONE,           0xfa64);
SFR16LEX(DMA_UR4T_TXA,            0xfa65);
SFRX(DMA_UR4T_TXAH,           0xfa65);
SFRX(DMA_UR4T_TXAL,           0xfa66);
SFRX(DMA_UR4R_CFG,            0xfa68);
SFRX(DMA_UR4R_CR,             0xfa69);
SFRX(DMA_UR4R_STA,            0xfa6a);
SFRX(DMA_UR4R_AMT,            0xfa6b);
SFRX(DMA_UR4R_DONE,           0xfa6c);
SFR16LEX(DMA_UR4R_RXA,            0xfa6d);
SFRX(DMA_UR4R_RXAH,           0xfa6d);
SFRX(DMA_UR4R_RXAL,           0xfa6e);

SFRX(DMA_LCM_CFG,             0xfa70);
SFRX(DMA_LCM_CR,              0xfa71);
SFRX(DMA_LCM_STA,             0xfa72);
SFRX(DMA_LCM_AMT,             0xfa73);
SFRX(DMA_LCM_DONE,            0xfa74);
SFR16LEX(DMA_LCM_TXA,             0xfa75);
SFRX(DMA_LCM_TXAH,            0xfa75);
SFRX(DMA_LCM_TXAL,            0xfa76);
SFR16LEX(DMA_LCM_RXA,             0xfa77);
SFRX(DMA_LCM_RXAH,            0xfa77);
SFRX(DMA_LCM_RXAL,            0xfa78);

/////////////////////////////////////////////////
//USB Control Regiter
/////////////////////////////////////////////////

//SFR(USBCLK,      0xdc);
//SFR(USBDAT,      0xec);
//SFR(USBCON,      0xf4);
//SFR(USBADR,      0xfc);

//使用方法:
//      char dat;
//
//      READ_USB(CSR0, dat);        //读USB寄存器
//      WRITE_USB(FADDR, 0x00);     //写USB寄存器

#define     READ_USB(reg, dat)          \
            {                           \
                while (USBADR & 0x80);  \
                USBADR = (reg) | 0x80;  \
                while (USBADR & 0x80);  \
                (dat) = USBDAT;         \
            }

#define     WRITE_USB(reg, dat)         \
            {                           \
                while (USBADR & 0x80);  \
                USBADR = (reg) & 0x7f;  \
                USBDAT = (dat);         \
            }

#define     USBBASE                 0
#define     FADDR                   (USBBASE + 0)
#define     UPDATE                  0x80
#define     POWER                   (USBBASE + 1)
#define     ISOUD                   0x80
#define     USBRST                  0x08
#define     USBRSU                  0x04
#define     USBSUS                  0x02
#define     ENSUS                   0x01
#define     INTRIN1                 (USBBASE + 2)
#define     EP5INIF                 0x20
#define     EP4INIF                 0x10
#define     EP3INIF                 0x08
#define     EP2INIF                 0x04
#define     EP1INIF                 0x02
#define     EP0IF                   0x01
#define     INTROUT1                (USBBASE + 4)
#define     EP5OUTIF                0x20
#define     EP4OUTIF                0x10
#define     EP3OUTIF                0x08
#define     EP2OUTIF                0x04
#define     EP1OUTIF                0x02
#define     INTRUSB                 (USBBASE + 6)
#define     SOFIF                   0x08
#define     RSTIF                   0x04
#define     RSUIF                   0x02
#define     SUSIF                   0x01
#define     INTRIN1E                (USBBASE + 7)
#define     EP5INIE                 0x20
#define     EP4INIE                 0x10
#define     EP3INIE                 0x08
#define     EP2INIE                 0x04
#define     EP1INIE                 0x02
#define     EP0IE                   0x01
#define     INTROUT1E               (USBBASE + 9)
#define     EP5OUTIE                0x20
#define     EP4OUTIE                0x10
#define     EP3OUTIE                0x08
#define     EP2OUTIE                0x04
#define     EP1OUTIE                0x02
#define     INTRUSBE                (USBBASE + 11)
#define     SOFIE                   0x08
#define     RSTIE                   0x04
#define     RSUIE                   0x02
#define     SUSIE                   0x01
#define     FRAME1                  (USBBASE + 12)
#define     FRAME2                  (USBBASE + 13)
#define     INDEX                   (USBBASE + 14)
#define     INMAXP                  (USBBASE + 16)
#define     CSR0                    (USBBASE + 17)
#define     SSUEND                  0x80
#define     SOPRDY                  0x40
#define     SDSTL                   0x20
#define     SUEND                   0x10
#define     DATEND                  0x08
#define     STSTL                   0x04
#define     IPRDY                   0x02
#define     OPRDY                   0x01
#define     INCSR1                  (USBBASE + 17)
#define     INCLRDT                 0x40
#define     INSTSTL                 0x20
#define     INSDSTL                 0x10
#define     INFLUSH                 0x08
#define     INUNDRUN                0x04
#define     INFIFONE                0x02
#define     INIPRDY                 0x01
#define     INCSR2                  (USBBASE + 18)
#define     INAUTOSET               0x80
#define     INISO                   0x40
#define     INMODEIN                0x20
#define     INMODEOUT               0x00
#define     INENDMA                 0x10
#define     INFCDT                  0x08
#define     OUTMAXP                 (USBBASE + 19)
#define     OUTCSR1                 (USBBASE + 20)
#define     OUTCLRDT                0x80
#define     OUTSTSTL                0x40
#define     OUTSDSTL                0x20
#define     OUTFLUSH                0x10
#define     OUTDATERR               0x08
#define     OUTOVRRUN               0x04
#define     OUTFIFOFUL              0x02
#define     OUTOPRDY                0x01
#define     OUTCSR2                 (USBBASE + 21)
#define     OUTAUTOCLR              0x80
#define     OUTISO                  0x40
#define     OUTENDMA                0x20
#define     OUTDMAMD                0x10
#define     COUNT0                  (USBBASE + 22)
#define     OUTCOUNT1               (USBBASE + 22)
#define     OUTCOUNT2               (USBBASE + 23)
#define     FIFO0                   (USBBASE + 32)
#define     FIFO1                   (USBBASE + 33)
#define     FIFO2                   (USBBASE + 34)
#define     FIFO3                   (USBBASE + 35)
#define     FIFO4                   (USBBASE + 36)
#define     FIFO5                   (USBBASE + 37)
#define     UTRKCTL                 (USBBASE + 48)
#define     UTRKSTS                 (USBBASE + 49)

/////////////////////////////////////////////////
//Interrupt Vector
/////////////////////////////////////////////////

#define     INT0_VECTOR             0       //0003H
#define     TMR0_VECTOR             1       //000BH
#define     INT1_VECTOR             2       //0013H
#define     TMR1_VECTOR             3       //001BH
#define     UART1_VECTOR            4       //0023H
#define     ADC_VECTOR              5       //002BH
#define     LVD_VECTOR              6       //0033H
#define     UART2_VECTOR            8       //0043H
#define     SPI_VECTOR              9       //004BH
#define     INT2_VECTOR             10      //0053H
#define     INT3_VECTOR             11      //005BH
#define     TMR2_VECTOR             12      //0063H
#define     USER_VECTOR             13      //006BH
#define     INT4_VECTOR             16      //0083H
#define     UART3_VECTOR            17      //008BH
#define     UART4_VECTOR            18      //0093H
#define     TMR3_VECTOR             19      //009BH
#define     TMR4_VECTOR             20      //00A3H
#define     CMP_VECTOR              21      //00ABH
#define     I2C_VECTOR              24      //00C3H
#define     USB_VECTOR              25      //00CBH
#define     PWMA_VECTOR             26      //00D3H
#define     PWMB_VECTOR             27      //00DBH

#define     TKSU_VECTOR             35      //011BH
#define     RTC_VECTOR              36      //0123H
#define     P0INT_VECTOR            37      //012BH
#define     P1INT_VECTOR            38      //0133H
#define     P2INT_VECTOR            39      //013BH
#define     P3INT_VECTOR            40      //0143H
#define     P4INT_VECTOR            41      //014BH
#define     P5INT_VECTOR            42      //0153H
#define     P6INT_VECTOR            43      //015BH
#define     P7INT_VECTOR            44      //0163H
#define     DMA_M2M_VECTOR          47      //017BH
#define     DMA_ADC_VECTOR          48      //0183H
#define     DMA_SPI_VECTOR          49      //018BH
#define     DMA_UR1T_VECTOR         50      //0193H
#define     DMA_UR1R_VECTOR         51      //019BH
#define     DMA_UR2T_VECTOR         52      //01A3H
#define     DMA_UR2R_VECTOR         53      //01ABH
#define     DMA_UR3T_VECTOR         54      //01B3H
#define     DMA_UR3R_VECTOR         55      //01BBH
#define     DMA_UR4T_VECTOR         56      //01C3H
#define     DMA_UR4R_VECTOR         57      //01CBH
#define     DMA_LCM_VECTOR          58      //01D3H
#define     LCM_VECTOR              59      //01DBH

/////////////////////////////////////////////////
#define	EAXSFR()		P_SW2 |= 0x80		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展SFR(XSFR) */
#define	EAXRAM()		P_SW2 &= ~0x80		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展RAM(XRAM) */


/////////////////////////////////////////////////

#endif

