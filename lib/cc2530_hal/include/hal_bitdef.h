#ifndef __HAL_BITDEF_H__
#define __HAL_BITDEF_H__

/*******************************************************************************
 * Interrupt Control Registers
 */

// IEN0 (0xA8) - Interrupt Enable 0 Register - bit accessible SFR register

// IEN1 (0xB8) - Interrupt Enable 1 Register - bit accessible SFR register

// IEN2 (0x9A) - Interrupt Enable 2 Register
#define IEN2_WDTIE                        0x20
#define IEN2_P1IE                         0x10
#define IEN2_UTX1IE                       0x08
#define IEN2_I2STXIE                      0x08
#define IEN2_UTX0IE                       0x04
#define IEN2_P2IE                         0x02
#define IEN2_USBIE                        0x02
#define IEN2_RFIE                         0x01


// TCON (0x88) - CPU Interrupt Flag 1 - bit accessible SFR register

// S0CON (0x98) - CPU Interrupt Flag 2 - bit accessible SFR register

// S1CON (0x9B) - CPU Interrupt Flag 3
#define S1CON_RFIF_1                      0x02
#define S1CON_RFIF_0                      0x01


// IRCON (0xC0) - CPU Interrupt Flag 4 - bit accessible SFR register

// IRCON2 (0xE8) - CPU Interrupt Flag 5 - bit accessible SFR register

// IP1 (0xB9) - Interrupt Priority 1
#define IP1_IPG5                          0x20
#define IP1_IPG4                          0x10
#define IP1_IPG3                          0x08
#define IP1_IPG2                          0x04
#define IP1_IPG1                          0x02
#define IP1_IPG0                          0x01

// IP0 (0xA9) - Interrupt Priority 0
#define IP0_IPG5                          0x20
#define IP0_IPG4                          0x10
#define IP0_IPG3                          0x08
#define IP0_IPG2                          0x04
#define IP0_IPG1                          0x02
#define IP0_IPG0                          0x01



/*******************************************************************************
 * Power Management and Clocks
 */

// PCON (0x87) - Power Mode Control
#define PCON_IDLE                         0x01


// SLEEP (0xBE) - Sleep Mode Control
#define SLEEP_OSC32K_CALDIS               0X80 // mark
#define SLEEP_MODE                        0X03

#define SLEEP_MODE_PM0                    0X00
#define SLEEP_MODE_PM1                    0X01
#define SLEEP_MODE_PM2                    0X02
#define SLEEP_MODE_PM3                    0X03

// SLEEPSTA (0X9D) - Sleep Mode Control Status
#define SLEEPSTA_OSC32K_CALDIS               0X80 // mark
#define SLEEPSTA_OSC32K_RST                  0X60
#define SLEEPSTA_CLK32K                      0X01

#define SLEEPSTA_RST_POR_BOD                 (0X00 << 3) 
#define SLEEPSTA_RST_EXT                     (0X01 << 3) 
#define SLEEPSTA_RST_WDT                     (0X02 << 3) 
 


// CLKCON (0xC6) - Clock Control
#define CLKCON_OSC32                      0x80  // bit mask, for the slow 32k clock oscillator
#define CLKCON_OSC                        0x40  // bit mask, for the system clock oscillator
#define CLKCON_TICKSPD                    0x38  // bit mask, for timer ticks output setting
#define CLKCON_TICKSPD0                   0x08  // bit mask, for timer ticks output setting
#define CLKCON_TICKSPD1                   0x10  // bit mask, for timer ticks output setting
#define CLKCON_TICKSPD2                   0x20  // bit mask, for timer ticks output setting
#define CLKCON_CLKSPD                     0x07  // bit mask, for the clock speed
#define CLKCON_CLKSPD0                    0x01  // bit mask, for the clock speed
#define CLKCON_CLKSPD1                    0x02  // bit mask, for the clock speed
#define CLKCON_CLKSPD2                    0x04  // bit mask, for the clock speed

#define TICKSPD_DIV_1                     (0x00 << 3)
#define TICKSPD_DIV_2                     (0x01 << 3)
#define TICKSPD_DIV_4                     (0x02 << 3)
#define TICKSPD_DIV_8                     (0x03 << 3)
#define TICKSPD_DIV_16                    (0x04 << 3)
#define TICKSPD_DIV_32                    (0x05 << 3)
#define TICKSPD_DIV_64                    (0x06 << 3)
#define TICKSPD_DIV_128                   (0x07 << 3)

#define CLKSPD_DIV_1                      (0x00)
#define CLKSPD_DIV_2                      (0x01)
#define CLKSPD_DIV_4                      (0x02)
#define CLKSPD_DIV_8                      (0x03)
#define CLKSPD_DIV_16                     (0x04)
#define CLKSPD_DIV_32                     (0x05)
#define CLKSPD_DIV_64                     (0x06)
#define CLKSPD_DIV_128                    (0x07)

// CLKCONSTA (0X9E)
#define CLKCONSTA_OSC32                    0x80  // bit mask, for the slow 32k clock oscillator
#define CLKCONSTA_OSC                      0x40  // bit mask, for the system clock oscillator
#define CLKCONSTA_TICKSPD                  0x38  // bit mask, for timer ticks output setting
#define CLKCONSTA_TICKSPD0                 0x08  // bit mask, for timer ticks output setting
#define CLKCONSTA_TICKSPD1                 0x10  // bit mask, for timer ticks output setting
#define CLKCONSTA_TICKSPD2                 0x20  // bit mask, for timer ticks output setting
#define CLKCONSTA_CLKSPD                   0x07  // bit mask, for the clock speed
#define CLKCONSTA_CLKSPD0                  0x01  // bit mask, for the clock speed
#define CLKCONSTA_CLKSPD1                  0x02  // bit mask, for the clock speed
#define CLKCONSTA_CLKSPD2                  0x04  // bit mask, for the clock speed

/*******************************************************************************
 *  Flash Controller
 */

// FCTL (0xAE) - Flash Control
#define FCTL_BUSY                         0x80
#define FCTL_SWBSY                        0x40
#define FCTL_CONTRD                       0x10
#define FCTL_WRITE                        0x02
#define FCTL_ERASE                        0x01


// FWDATA (0xAF) - Flash Write Data

// FADDRH (0xAD) - Flash Address High Byte

// FADDRL (0xAC) - Flash Address Low Byte

// FWT (0xAB) - Flash Write Timing (Only bit 0-5 R/W)


/*******************************************************************************
 * I/O Ports
 */

// P0 (0x80) - Port 0 - bit accessible SFR register

// P1 (0x90) - Port 1 - bit accessible SFR register

// P2 (0xA0) - Port 2 - bit accessible SFR register

// PERCFG (0xF1) - Peripheral Control
#define PERCFG_T1CFG                      0x40
#define PERCFG_T3CFG                      0x20
#define PERCFG_T4CFG                      0x10
#define PERCFG_U1CFG                      0x02
#define PERCFG_U0CFG                      0x01



// ADCCFG (0xF2) - ADC input Configuration
#define ADCCFG_7                          0x80
#define ADCCFG_6                          0x40
#define ADCCFG_5                          0x20
#define ADCCFG_4                          0x10
#define ADCCFG_3                          0x08
#define ADCCFG_2                          0x04
#define ADCCFG_1                          0x02
#define ADCCFG_0                          0x01


// P0SEL (0xF3) - Port 0 Function Select (bit 7 not used)

// P1SEL (0xF4) - Port 1 Function Select

// P2SEL (0xF5) - Port 2 Function Select
#define P2SEL_PRI3P1                      0x40
#define P2SEL_PRI2P1                      0x20
#define P2SEL_PRI1P1                      0x10
#define P2SEL_PRI0P1                      0x08
#define P2SEL_SELP2_4                     0x04
#define P2SEL_SELP2_3                     0x02
#define P2SEL_SELP2_0                     0x01


// P0DIR (0xFD) - Port 0 Direction Select

// P1DIR (0xFE) - Port 1 Direction Select

// P2DIR (0xFF) - Port 2 Direction
#define P2DIR_PRIP0                       0xC0
#define P2DIR_0PRIP0                      0x40
#define P2DIR_1PRIP0                      0x80
#define P2DIR_DIRP2                       0x1F

#define P2DIR_PRIP0_0                     (0x00 << 6)
#define P2DIR_PRIP0_1                     (0x01 << 6)
#define P2DIR_PRIP0_2                     (0x02 << 6)
#define P2DIR_PRIP0_3                     (0x03 << 6)

#define P2DIR_DIRP2_4                     (0x10)
#define P2DIR_DIRP2_3                     (0x08)
#define P2DIR_DIRP2_2                     (0x04)
#define P2DIR_DIRP2_1                     (0x02)
#define P2DIR_DIRP2_0                     (0x01)



// P0INP (0x8F) - Port 0 Input Mode (bit 0 & 1 not used)

// P1INP (0xF6) - Port 1 Input Mode (bit 0 & 1 not used)

// P2INP (0xF7) - Port 2 Input Mode
#define P2INP_PDUP2                       0x80
#define P2INP_PDUP1                       0x40
#define P2INP_PDUP0                       0x20
#define P2INP_MDP2                        0x1F

#define P2INP_MDP2_0                      (0x01)
#define P2INP_MDP2_1                      (0x02)
#define P2INP_MDP2_2                      (0x04)
#define P2INP_MDP2_3                      (0x08)
#define P2INP_MDP2_4                      (0x10)



// P0IFG (0x89) - Port 0 Interrupt Status Flag

// P1IFG (0x8A) - Port 1 Interrupt Status Flag

// P2IFG (0x8B) - Port 2 Interrupt Status Flag (bit 7 - 5 not used)

// PICTL (0x8C) - Port Interrupt Control
#define PICTL_PADSC                       0x40
#define PICTL_P2IEN                       0x20
#define PICTL_P0IENH                      0x10
#define PICTL_P0IENL                      0x08
#define PICTL_P2ICON                      0x04
#define PICTL_P1ICON                      0x02
#define PICTL_P0ICON                      0x01


// P1IEN (0x8D) - Port 1 Interrupt Mask

// T1CNTH (0xE3) - Timer 1 Counter High

// T1CNTL (0xE2) - Timer 1 Counter Low

// T1CTL (0xE4) - Timer 1 Control and Status
#define T1CTL_CH2IF                       0x80 // Timer 1 channel 2 interrupt flag
#define T1CTL_CH1IF                       0x40 // Timer 1 channel 1 interrupt flag
#define T1CTL_CH0IF                       0x20 // Timer 1 channel 0 interrupt flag
#define T1CTL_OVFIF                       0x10 // Timer 1 counter overflow interrupt flag
#define T1CTL_DIV                         0x0C
#define T1CTL_DIV0                        0x04
#define T1CTL_DIV1                        0x08
#define T1CTL_MODE                        0x03
#define T1CTL_MODE0                       0x01
#define T1CTL_MODE1                       0x02

#define T1CTL_DIV_1                       (0x00 << 2) // Divide tick frequency by 1
#define T1CTL_DIV_8                       (0x01 << 2) // Divide tick frequency by 8
#define T1CTL_DIV_32                      (0x02 << 2) // Divide tick frequency by 32
#define T1CTL_DIV_128                     (0x03 << 2) // Divide tick frequency by 128

#define T1CTL_MODE_SUSPEND                (0x00)    // Operation is suspended (halt)
#define T1CTL_MODE_FREERUN                (0x01)    // Free Running mode
#define T1CTL_MODE_MODULO                 (0x02)    // Modulo
#define T1CTL_MODE_UPDOWN                 (0x03)    // Up/down


// T1CCTL0 (0xE5) - Timer 1 Channel 0 Capture/Compare Control
#define T1CCTL0_CPSEL                     0x80    // Timer 1 channel 0 capture select
#define T1CCTL0_IM                        0x40    // Channel 0 Interrupt mask
#define T1CCTL0_CMP                       0x38
#define T1CCTL0_CMP0                      0x08
#define T1CCTL0_CMP1                      0x10
#define T1CCTL0_CMP2                      0x20
#define T1CCTL0_MODE                      0x04    // Capture or compare mode
#define T1CCTL0_CAP                       0x03
#define T1CCTL0_CAP0                      0x01
#define T1CCTL0_CAP1                      0x02

#define T1C0_SET_ON_CMP                   (0x00 << 3)    // Clear output on compare-up set on 0
#define T1C0_CLR_ON_CMP                   (0x01 << 3)    // Set output on compare-up clear on 0
#define T1C0_TOG_ON_CMP                   (0x02 << 3)    // Toggle output on compare
#define T1C0_SET_CMP_UP_CLR_0             (0x03 << 3)    // Clear output on compare
#define T1C0_CLR_CMP_UP_SET_0             (0x04 << 3)    // Set output on compare

#define T1C0_NO_CAP                       (0x00)    // No capture
#define T1C0_RISE_EDGE                    (0x01)    // Capture on rising edge
#define T1C0_FALL_EDGE                    (0x02)    // Capture on falling edge
#define T1C0_BOTH_EDGE                    (0x03)    // Capture on both edges


// T1CC0H (0xDB) - Timer 1 Channel 0 Capture/Compare Value High

// T1CC0L (0xDA) - Timer 1 Channel 0 Capture/Compare Value Low

// T1CCTL1 (0xE6) - Timer 1 Channel 1 Capture/Compare Control
#define T1CCTL1_CPSEL                     0x80    // Timer 1 channel 1 capture select
#define T1CCTL1_IM                        0x40    // Channel 1 Interrupt mask
#define T1CCTL1_CMP                       0x38
#define T1CCTL1_CMP0                      0x08
#define T1CCTL1_CMP1                      0x10
#define T1CCTL1_CMP2                      0x20
#define T1CCTL1_MODE                      0x04    // Capture or compare mode
#define T1CCTL1_DSM_SPD                   0x04
#define T1CCTL1_CAP                       0x03
#define T1CCTL1_CAP0                      0x01
#define T1CCTL1_CAP1                      0x02

#define T1C1_SET_ON_CMP                   (0x00 << 3)  // Set output on compare
#define T1C1_CLR_ON_CMP                   (0x01 << 3)  // Clear output on compare
#define T1C1_TOG_ON_CMP                   (0x02 << 3)  // Toggle output on compare
#define T1C1_SET_CMP_UP_CLR_0             (0x03 << 3)  // Set output on compare-up clear on 0
#define T1C1_CLR_CMP_UP_SET_0             (0x04 << 3)  // Clear output on compare-up set on 0
#define T1C1_SET_C1_CLR_C0                (0x05 << 3)  // Set when equal to T1CC1, clear when equal to T1CC0
#define T1C1_CLR_C1_SET_C0                (0x06 << 3)  // Clear when equal to T1CC1, set when equal to T1CC0
#define T1C1_DSM_MODE                     (0x07 << 3)  // DSM mode

#define T1C1_NO_CAP                       (0x00)     // No capture
#define T1C1_RISE_EDGE                    (0x01)    // Capture on rising edge
#define T1C1_FALL_EDGE                    (0x02)    // Capture on falling edge
#define T1C1_BOTH_EDGE                    (0x03)    // Capture on both edges

#define DSM_IP_ON_OS_ON                   (0x00)    // Interpolator & output shaping enabled
#define DSM_IP_ON_OS_OFF                  (0x01)    // Interpolator enabled & output shaping disabled
#define DSM_IP_OFF_OS_ON                  (0x02)    // Interpolator disabled & output shaping enabled
#define DSM_IP_OFF_OS_OFF                 (0x03)    // Interpolator & output shaping disabled



// T1CC1H (0xDD) - Timer 1 Channel 1 Capture/Compare Value High

// T1CC1L (0xDC) - Timer 1 Channel 1 Capture/Compare Value Low

// T1CCTL2 (0xE7) - Timer 1 Channel 2 Capture/Compare Control
#define T1CCTL2_CPSEL                     0x80    // Timer 1 channel 2 capture select
#define T1CCTL2_IM                        0x40    // Channel 2 Interrupt mask
#define T1CCTL2_CMP                       0x38
#define T1CCTL2_CMP0                      0x08
#define T1CCTL2_CMP1                      0x10
#define T1CCTL2_CMP2                      0x20
#define T1CCTL2_MODE                      0x04    // Capture or compare mode
#define T1CCTL2_CAP                       0x03
#define T1CCTL2_CAP0                      0x01
#define T1CCTL2_CAP1                      0x02

#define T1C2_SET_ON_CMP                   (0x00 << 3)  // Set output on compare
#define T1C2_CLR_ON_CMP                   (0x01 << 3)  // Clear output on compare
#define T1C2_TOG_ON_CMP                   (0x02 << 3)  // Toggle output on compare
#define T1C2_SET_CMP_UP_CLR_0             (0x03 << 3)  // Set output on compare-up clear on 0
#define T1C2_CLR_CMP_UP_SET_0             (0x04 << 3)  // Clear output on compare-up set on 0
#define T1C2_SET_C2_CLR_C0                (0x05 << 3)  // Set when equal to T1CC2, clear when equal to T1CC0
#define T1C2_CLR_C2_SET_C0                (0x06 << 3)  // Clear when equal to T1CC2, set when equal to T1CC0

#define T1C2_NO_CAP                       (0x00)     // No capture
#define T1C2_RISE_EDGE                    (0x01)    // Capture on rising edge
#define T1C2_FALL_EDGE                    (0x02)    // Capture on falling edge
#define T1C2_BOTH_EDGE                    (0x03)    // Capture on both edges


// T1CC2H (0xDF) - Timer 1 Channel 2 Capture/Compare Value High

// T1CC2L (0xDE) - Timer 1 Channel 2 Capture/Compare Value Low

// T2CTL (0x9E) - Timer 2 Control
#define T2CTL_TEX                         0x40
#define T2CTL_INT                         0x10    // Enable Timer 2 interrupt
#define T2CTL_TIG                         0x04    // Tick generator mode
#define T2CTL_TIP                         0x03
#define T2CTL_TIP0                        0x01
#define T2CTL_TIP1                        0x02

#define T2CTL_TIP_64                      (0x00)
#define T2CTL_TIP_128                     (0x01)
#define T2CTL_TIP_256                     (0x02)
#define T2CTL_TIP_1024                    (0x03)


// T2CT (0x9C) - Timer 2 Count

// T2PR (0x9D) - Timer 2 Prescaler

// WORTIME0 (0xA5) - Sleep Timer Low Byte

// WORTIME1 (0xA6) - Sleep Timer High Byte

// WOREVT1 (0xA4) - Sleep Timer Event0 Timeout High

// WOREVT0 (0xA3) - Sleep Timer Event0 Timeout Low

// WORCTL (0xA2) - Sleep Timer Control
#define WORCTL_WOR_RESET                  0x04
#define WORCTL_WOR_RES                    0x03
#define WORCTL_WOR_RES0                   0x01
#define WORCTL_WOR_RES1                   0x02

#define WORCTL_WOR_RES_1                  (0x00)
#define WORCTL_WOR_RES_32                 (0x01)
#define WORCTL_WOR_RES_1024               (0x02)
#define WORCTL_WOR_RES_32768              (0x03)


// WORIRQ (0xA1) - Sleep Timer Interrupt Control
#define WORIRQ_EVENT0_MASK                0x10
#define WORIRQ_EVENT0_FLAG                0x01


// T3CNT (0xCA) - Timer 3 Counter

// T3CTL (0xCB) - Timer 3 Control
#define T3CTL_DIV                         0xE0
#define T3CTL_DIV0                        0x20
#define T3CTL_DIV1                        0x40
#define T3CTL_DIV2                        0x80
#define T3CTL_START                       0x10
#define T3CTL_OVFIM                       0x08
#define T3CTL_CLR                         0x04
#define T3CTL_MODE                        0x03
#define T3CTL_MODE0                       0x01
#define T3CTL_MODE1                       0x02

#define T3CTL_DIV_1                       (0x00 << 5)
#define T3CTL_DIV_2                       (0x01 << 5)
#define T3CTL_DIV_4                       (0x02 << 5)
#define T3CTL_DIV_8                       (0x03 << 5)
#define T3CTL_DIV_16                      (0x04 << 5)
#define T3CTL_DIV_32                      (0x05 << 5)
#define T3CTL_DIV_64                      (0x06 << 5)
#define T3CTL_DIV_128                     (0x07 << 5)

#define T3CTL_MODE_FREERUN                (0x00)
#define T3CTL_MODE_DOWN                   (0x01)
#define T3CTL_MODE_MODULO                 (0x02)
#define T3CTL_MODE_UPDOWN                 (0x03)



// T3CCTL0 (0xCC) - Timer 3 Channel 0 Compare Control
#define T3CCTL0_IM                        0x40
#define T3CCTL0_MODE                      0x04
#define T3CCTL0_CMP                       0x38
#define T3CCTL0_CMP0                      0x08
#define T3CCTL0_CMP1                      0x10
#define T3CCTL0_CMP2                      0x20

#define T3C0_SET_ON_CMP                   (0x00 << 3)  // Set output on compare
#define T3C0_CLR_ON_CMP                   (0x01 << 3)  // Clear output on compare
#define T3C0_TOG_ON_CMP                   (0x02 << 3)  // Toggle output on compare
#define T3C0_SET_CMP_UP_CLR_0             (0x03 << 3)  // Set output on compare-up clear on 0
#define T3C0_CLR_CMP_UP_SET_0             (0x04 << 3)  // Clear output on compare-up set on 0
#define T3C0_SET_CMP_CLR_255              (0x05 << 3)  // Set when equal to T3CC0, clear on 255
#define T3C0_CLR_CMP_SET_0                (0x06 << 3)  // Clear when equal to T3CC0, set on 0



// T3CC0 (0xCD) - Timer 3 Channel 0 Compare Value

// T3CCTL1 (0xCE) - Timer 3 Channel 1 Compare Control

#define T3CCTL1_IM                        0x40
#define T3CCTL1_MODE                      0x04
#define T3CCTL1_CMP                       0x38
#define T3CCTL1_CMP0                      0x08
#define T3CCTL1_CMP1                      0x10
#define T3CCTL1_CMP2                      0x20

#define T3C1_SET_ON_CMP                   (0x00 << 3)  // Set output on compare
#define T3C1_CLR_ON_CMP                   (0x01 << 3)  // Clear output on compare
#define T3C1_TOG_ON_CMP                   (0x02 << 3)  // Toggle output on compare
#define T3C1_SET_CMP_UP_CLR_0             (0x03 << 3)  // Set output on compare-up clear on 0
#define T3C1_CLR_CMP_UP_SET_0             (0x04 << 3)  // Clear output on compare-up set on 0
#define T3C1_SET_CMP_CLR_C0               (0x05 << 3)  // Set when equal to T3CC1, clear when equal to T3CC0
#define T3C1_CLR_CMP_SET_C0               (0x06 << 3)  // Clear when equal to T3CC1, set when equal to T3CC0


// T3CC1 (0xCF) - Timer 3 Channel 1 Compare Value

// T4CNT (0xEA) - Timer 4 Counter

// T4CTL (0xEB) - Timer 4 Control
#define T4CTL_DIV                         0xE0
#define T4CTL_DIV0                        0x20
#define T4CTL_DIV1                        0x40
#define T4CTL_DIV2                        0x80
#define T4CTL_START                       0x10
#define T4CTL_OVFIM                       0x08
#define T4CTL_CLR                         0x04
#define T4CTL_MODE                        0x03
#define T4CTL_MODE0                       0x01
#define T4CTL_MODE1                       0x02

#define T4CTL_MODE_FREERUN                (0x00)
#define T4CTL_MODE_DOWN                   (0x01)
#define T4CTL_MODE_MODULO                 (0x02)
#define T4CTL_MODE_UPDOWN                 (0x03)

#define T4CTL_DIV_1                       (0x00 << 5)
#define T4CTL_DIV_2                       (0x01 << 5)
#define T4CTL_DIV_4                       (0x02 << 5)
#define T4CTL_DIV_8                       (0x03 << 5)
#define T4CTL_DIV_16                      (0x04 << 5)
#define T4CTL_DIV_32                      (0x05 << 5)
#define T4CTL_DIV_64                      (0x06 << 5)
#define T4CTL_DIV_128                     (0x07 << 5)


// T4CCTL0 (0xEC) - Timer 4 Channel 0 Compare Control
#define T4CCTL0_IM                        0x40
#define T4CCTL0_CMP                       0x38
#define T4CCTL0_CMP0                      0x08
#define T4CCTL0_CMP1                      0x10
#define T4CCTL0_CMP2                      0x20
#define T4CCTL0_MODE                      0x04

#define T4CCTL0_SET_ON_CMP                (0x00 << 3)
#define T4CCTL0_CLR_ON_CMP                (0x01 << 3)
#define T4CCTL0_TOG_ON_CMP                (0x02 << 3)
#define T4CCTL0_SET_CMP_UP_CLR_0          (0x03 << 3)
#define T4CCTL0_CLR_CMP_UP_SET_0          (0x04 << 3)
#define T4CCTL0_SET_CMP_CLR_255           (0x05 << 3)
#define T4CCTL0_CLR_CMP_SET_0             (0x06 << 3)


// T4CC0 (0xED) - Timer 4 Channel 0 Compare Value

// T4CCTL1 (0xEE) - Timer 4 Channel 1 Compare Control
#define T4CCTL1_IM                        0x40
#define T4CCTL1_CMP                       0x38
#define T4CCTL1_CMP0                      0x08
#define T4CCTL1_CMP1                      0x10
#define T4CCTL1_CMP2                      0x20
#define T4CCTL1_MODE                      0x04

#define T4CCTL1_SET_ON_CMP                (0x00 << 3)
#define T4CCTL1_CLR_ON_CMP                (0x01 << 3)
#define T4CCTL1_TOG_ON_CMP                (0x02 << 3)
#define T4CCTL1_SET_CMP_UP_CLR_0          (0x03 << 3)
#define T4CCTL1_CLR_CMP_UP_SET_0          (0x04 << 3)
#define T4CCTL1_SET_CMP_CLR_C0            (0x05 << 3)
#define T4CCTL1_CLR_CMP_SET_C0            (0x06 << 3)


// TIMIF (0xD8) - Timers 1/3/4 Interrupt Mask/Flag - bit accessible SFR register


/*******************************************************************************
 * ADC
 */

// ADCL (0xBA) - ADC Data Low (only bit 7-4 used)

// ADCH (0xBB) - ADC Data High

// ADCCON1 (0xB4) - ADC Control 1
#define ADCCON1_EOC                       0x80
#define ADCCON1_ST                        0x40
#define ADCCON1_STSEL                     0x30
#define ADCCON1_STSEL0                    0x10
#define ADCCON1_STSEL1                    0x20
#define ADCCON1_RCTRL                     0x0C
#define ADCCON1_RCTRL0                    0x04
#define ADCCON1_RCTRL1                    0x08

#define STSEL_P2_0                        (0x00 << 4)
#define STSEL_FULL_SPEED                  (0x01 << 4)
#define STSEL_T1C0_CMP_EVT                (0x02 << 4)
#define STSEL_ST                          (0x03 << 4)

#define ADCCON1_RCTRL_COMPL               (0x00 << 2)
#define ADCCON1_RCTRL_LFSR13              (0x01 << 2)



// ADCCON2 (0xB5) - ADC Control 2
#define ADCCON2_SREF                      0xC0
#define ADCCON2_SREF0                     0x40
#define ADCCON2_SREF1                     0x80
#define ADCCON2_SDIV                      0x30
#define ADCCON2_SDIV0                     0x10
#define ADCCON2_SDIV1                     0x20
#define ADCCON2_SCH                       0x0F
#define ADCCON2_SCH0                      0x01
#define ADCCON2_SCH1                      0x02
#define ADCCON2_SCH2                      0x04
#define ADCCON2_SCH3                      0x08

#define ADCCON2_SREF_1_25V                (0x00 << 6)
#define ADCCON2_SREF_P0_7                 (0x01 << 6)
#define ADCCON2_SREF_AVDD                 (0x02 << 6)
#define ADCCON2_SREF_P0_6_P0_7            (0x03 << 6)

#define ADCCON2_SDIV_64                   (0x00 << 4)
#define ADCCON2_SDIV_128                  (0x01 << 4)
#define ADCCON2_SDIV_256                  (0x02 << 4)
#define ADCCON2_SDIV_512                  (0x03 << 4)

#define ADCCON2_SCH_AIN0                  (0x00)
#define ADCCON2_SCH_AIN1                  (0x01)
#define ADCCON2_SCH_AIN2                  (0x02)
#define ADCCON2_SCH_AIN3                  (0x03)
#define ADCCON2_SCH_AIN4                  (0x04)
#define ADCCON2_SCH_AIN5                  (0x05)
#define ADCCON2_SCH_AIN6                  (0x06)
#define ADCCON2_SCH_AIN7                  (0x07)
#define ADCCON2_SCH_AIN0_1                (0x08)
#define ADCCON2_SCH_AIN2_3                (0x09)
#define ADCCON2_SCH_AIN4_5                (0x0A)
#define ADCCON2_SCH_AIN6_7                (0x0B)
#define ADCCON2_SCH_GND                   (0x0C)
#define ADCCON2_SCH_POSVOL                (0x0D)
#define ADCCON2_SCH_TEMPR                 (0x0E)
#define ADCCON2_SCH_VDD_3                 (0x0F)


// ADCCON3 (0xB6) - ADC Control 3
#define ADCCON3_EREF                      0xC0
#define ADCCON3_EREF0                     0x40
#define ADCCON3_EREF1                     0x80
#define ADCCON3_EDIV                      0x30
#define ADCCON3_EDIV0                     0x10
#define ADCCON3_EDIV1                     0x20
#define ADCCON2_ECH                       0x0F
#define ADCCON2_ECH0                      0x01
#define ADCCON2_ECH1                      0x02
#define ADCCON2_ECH2                      0x04
#define ADCCON2_ECH3                      0x08

#define ADCCON3_EREF_1_25V                (0x00 << 6)
#define ADCCON3_EREF_P0_7                 (0x01 << 6)
#define ADCCON3_EREF_AVDD                 (0x02 << 6)
#define ADCCON3_EREF_P0_6_P0_7            (0x03 << 6)

#define ADCCON3_EDIV_64                   (0x00 << 4)
#define ADCCON3_EDIV_128                  (0x01 << 4)
#define ADCCON3_EDIV_256                  (0x02 << 4)
#define ADCCON3_EDIV_512                  (0x03 << 4)

#define ADCCON3_ECH_AIN0                  (0x00)
#define ADCCON3_ECH_AIN1                  (0x01)
#define ADCCON3_ECH_AIN2                  (0x02)
#define ADCCON3_ECH_AIN3                  (0x03)
#define ADCCON3_ECH_AIN4                  (0x04)
#define ADCCON3_ECH_AIN5                  (0x05)
#define ADCCON3_ECH_AIN6                  (0x06)
#define ADCCON3_ECH_AIN7                  (0x07)
#define ADCCON3_ECH_AIN0_1                (0x08)
#define ADCCON3_ECH_AIN2_3                (0x09)
#define ADCCON3_ECH_AIN4_5                (0x0A)
#define ADCCON3_ECH_AIN6_7                (0x0B)
#define ADCCON3_ECH_GND                   (0x0C)
#define ADCCON3_ECH_POSVOL                (0x0D)
#define ADCCON3_ECH_TEMPR                 (0x0E)
#define ADCCON3_ECH_VDD_3                 (0x0F)



/*******************************************************************************
 * Random Number Generator
 */

// RNDL (0xBC) - Random Number Generator Data Low Byte

// RNDH (0xBD) - Random Number Generator Data High Byte


/*******************************************************************************
 * AES
 */

// ENCCS (0xB3) - Encryption Control and Status
#define ENCCS_MODE                        0x70
#define ENCCS_MODE0                       0x10
#define ENCCS_MODE1                       0x20
#define ENCCS_MODE2                       0x40
#define ENCCS_RDY                         0x08
#define ENCCS_CMD                         0x06
#define ENCCS_CMD0                        0x02
#define ENCCS_CMD1                        0x04
#define ENCCS_ST                          0x01

#define ENCCS_MODE_CBC                    (0x00 << 4)
#define ENCCS_MODE_CFB                    (0x01 << 4)
#define ENCCS_MODE_OFB                    (0x02 << 4)
#define ENCCS_MODE_CTR                    (0x03 << 4)
#define ENCCS_MODE_ECB                    (0x04 << 4)
#define ENCCS_MODE_CBCMAC                 (0x05 << 4)

#define ENCCS_CMD_ENC                     (0x00 << 1)
#define ENCCS_CMD_DEC                     (0x01 << 1)
#define ENCCS_CMD_LDKEY                   (0x02 << 1)
#define ENCCS_CMD_LDIV                    (0x03 << 1)


// ENCDI (0xB1) - Encryption Input Data

// ENCDO (0xB2) - Encryption Output Data


/*******************************************************************************
 * Watchdog Timer
 */

// WDCTL (0xC9) - Watchdog Timer Control
#define WDCTL_CLR                         0xF0
#define WDCTL_CLR0                        0x10
#define WDCTL_CLR1                        0x20
#define WDCTL_CLR2                        0x40
#define WDCTL_CLR3                        0x80
#define WDCTL_EN                          0x08
#define WDCTL_MODE                        0x04
#define WDCTL_INT                         0x03
#define WDCTL_INT0                        0x01
#define WDCTL_INT1                        0x02


#define WDCTL_INT_SEC_1                   (0x00)
#define WDCTL_INT1_MSEC_250               (0x01)
#define WDCTL_INT2_MSEC_15                (0x02)
#define WDCTL_INT3_MSEC_2                 (0x03)



/*******************************************************************************
 * USART
 */

// U0CSR (0x86) - USART 0 Control and Status

#define U0CSR_MODE                        0x80
#define U0CSR_RE                          0x40
#define U0CSR_SLAVE                       0x20
#define U0CSR_FE                          0x10
#define U0CSR_ERR                         0x08
#define U0CSR_RX_BYTE                     0x04
#define U0CSR_TX_BYTE                     0x02
#define U0CSR_ACTIVE                      0x01


// U0UCR (0xC4) - USART 0 UART Control
#define U0UCR_FLUSH                       0x80
#define U0UCR_FLOW                        0x40
#define U0UCR_D9                          0x20
#define U0UCR_BIT9                        0x10
#define U0UCR_PARITY                      0x08
#define U0UCR_SPB                         0x04
#define U0UCR_STOP                        0x02
#define U0UCR_START                       0x01


// U0GCR (0xC5) - USART 0 Generic Control
#define U0GCR_CPOL                        0x80
#define U0GCR_CPHA                        0x40
#define U0GCR_ORDER                       0x20
#define U0GCR_BAUD_E                      0x1F
#define U0GCR_BAUD_E0                     0x01
#define U0GCR_BAUD_E1                     0x02
#define U0GCR_BAUD_E2                     0x04
#define U0GCR_BAUD_E3                     0x08
#define U0GCR_BAUD_E4                     0x10


// U0DBUF (0xC1) - USART 0 Receive/Transmit Data Buffer

// U0BAUD (0xC2) - USART 0 Baud Rate Control

// U1CSR (0xF8) - USART 1 Control and Status - bit accessible SFR register
#define U1CSR_MODE                        0x80
#define U1CSR_RE                          0x40
#define U1CSR_SLAVE                       0x20
#define U1CSR_FE                          0x10
#define U1CSR_ERR                         0x08
#define U1CSR_RX_BYTE                     0x04
#define U1CSR_TX_BYTE                     0x02
#define U1CSR_ACTIVE                      0x01


// U1UCR (0xFB) - USART 1 UART Control
#define U1UCR_FLUSH                       0x80
#define U1UCR_FLOW                        0x40
#define U1UCR_D9                          0x20
#define U1UCR_BIT9                        0x10
#define U1UCR_PARITY                      0x08
#define U1UCR_SPB                         0x04
#define U1UCR_STOP                        0x02
#define U1UCR_START                       0x01


// U1GCR (0xFC) - USART 1 Generic Control
#define U1GCR_CPOL                        0x80
#define U1GCR_CPHA                        0x40
#define U1GCR_ORDER                       0x20
#define U1GCR_BAUD_E                      0x1F
#define U1GCR_BAUD_E0                     0x01
#define U1GCR_BAUD_E1                     0x02
#define U1GCR_BAUD_E2                     0x04
#define U1GCR_BAUD_E3                     0x08
#define U1GCR_BAUD_E4                     0x10


// U1DBUF (0xF9) - USART 1 Receive/Transmit Data Buffer

// U1BAUD (0xFA) - USART 1 Baud Rate Control


/*******************************************************************************
 * I2S
 */

// 0xDF40: I2SCFG0 - I2S Configuration Register 0
#define I2SCFG0_TXIEN                     0x80
#define I2SCFG0_RXIEN                     0x40
#define I2SCFG0_ULAWE                     0x20
#define I2SCFG0_ULAWC                     0x10
#define I2SCFG0_TXMONO                    0x08
#define I2SCFG0_RXMONO                    0x04
#define I2SCFG0_MASTER                    0x02
#define I2SCFG0_ENAB                      0x01


// 0xDF41: I2SCFG1 - I2S Configuration Register 1
#define I2SCFG1_WORDS                     0xF8
#define I2SCFG1_WORDS0                    0x08
#define I2SCFG1_WORDS1                    0x10
#define I2SCFG1_WORDS2                    0x20
#define I2SCFG1_WORDS3                    0x40
#define I2SCFG1_WORDS4                    0x80
#define I2SCFG1_TRIGNUM                   0x06
#define I2SCFG1_TRIGNUM0                  0x02
#define I2SCFG1_TRIGNUM1                  0x04
#define I2SCFG1_IOLOC                     0x01

#define I2SCFG1_TRIGNUM_NO_TRIG           (0x00 << 1)
#define I2SCFG1_TRIGNUM_USB_SOF           (0x01 << 1)
#define I2SCFG1_TRIGNUM_IOC_1             (0x02 << 1)
#define I2SCFG1_TRIGNUM_T1_CH0            (0x03 << 1)



// 0xDF42: I2SDATL - I2S Data Low Byte

// 0xDF43: I2SDATH - I2S Data High Byte

// 0xDF44: I2SWCNT - I2S Word Count Register

// 0xDF45: I2SSTAT - I2S Status Register
#define I2SSTAT_TXUNF                     0x80
#define I2SSTAT_RXOVF                     0x40
#define I2SSTAT_TXLR                      0x20
#define I2SSTAT_RXLR                      0x10
#define I2SSTAT_TXIRQ                     0x08
#define I2SSTAT_RXIRQ                     0x04
#define I2SSTAT_WCNT                      0x03
#define I2SSTAT_WCNT0                     0x01
#define I2SSTAT_WCNT1                     0x02

#define I2SSTAT_WCNT_10BIT                (0x02)
#define I2SSTAT_WCNT_9BIT                 (0x01)
#define I2SSTAT_WCNT_9_10BIT              (0x02)


#endif // !