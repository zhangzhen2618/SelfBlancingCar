/**
 * @file hal_defs.h
 * @brief This file contains hardware abstraction layer definitions for the CC2530 microcontroller.
 */

#ifndef __HAL_DEFS_H__
#define __HAL_DEFS_H__

#include <stdint.h>
#include "hal_bitdef.h"
#include "cc2530.h"

/***********************************************************************************
* CONSTANTS AND DEFINES
*/

#ifndef TRUE
#define TRUE 1
#else
#warning "Macro TRUE already defined"
#endif

#ifndef FALSE
#define FALSE 0
#else
#warning "Macro FALSE already defined"
#endif

#ifndef NULL
#define NULL (void *)0
#else
#warning "Macro NULL already defined"
#endif

#ifndef SUCCESS
#define SUCCESS 0
#else
#warning "Macro SUCCESS already defined"
#endif

#ifndef FAILED
#define FAILED  1
#else
#warning "Macro FAILED already defined"
#endif

/***********************************************************************************
* MACROS
*/

#ifndef BV
#define BV(n)      (1 << (n))
#endif

#ifndef BM
#define BM(n)      (1 << (n))
#endif

#ifndef BF
#define BF(x,b,s)  (((x) & (b)) >> (s))
#endif

#ifndef MIN
#define MIN(n,m)   (((n) < (m)) ? (n) : (m))
#endif

#ifndef MAX
#define MAX(n,m)   (((n) < (m)) ? (m) : (n))
#endif

#ifndef ABS
#define ABS(n)     (((n) < 0) ? -(n) : (n))
#endif

/**
 * @brief Special Function Register (SFR) definitions for extended registers.
 * 
 * These macros define the addresses of the extended special function registers
 * for the CC2530 microcontroller.
 */
SFRX(X_U0DBUF, 0X70C1); ///< Extended SFR for UART0 data buffer
SFRX(X_U1DBUF, 0X70F9); ///< Extended SFR for UART1 data buffer

/**
 * @brief Bit mask definitions.
 * 
 * These macros define bit masks for individual bits in a byte.
 */
#define     BIT0                                0x01 ///< Bit mask for bit 0
#define     BIT1                                0x02 ///< Bit mask for bit 1
#define     BIT2                                0x04 ///< Bit mask for bit 2
#define     BIT3                                0x08 ///< Bit mask for bit 3
#define     BIT4                                0x10 ///< Bit mask for bit 4
#define     BIT5                                0x20 ///< Bit mask for bit 5
#define     BIT6                                0x40 ///< Bit mask for bit 6
#define     BIT7                                0x80 ///< Bit mask for bit 7

/**
 * @brief Macro for creating a single statement block.
 * 
 * This macro allows the creation of a single statement block that can be used
 * in places where a single statement is required, such as in an if statement
 * without braces.
 * 
 * @param x The statement to be executed.
 */
#define st(x)      do { x } while (__LINE__ == -1)

#endif // !__HAL_DEFS_H__