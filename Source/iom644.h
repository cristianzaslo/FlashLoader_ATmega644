/****************************************************************************
 **             - iom644.h -
 **
 **     This file declares the internal register addresses for ATmega644.
 **
 **     Used with iccAVR and aAVR.
 **
 **     Copyright Cristian Zaslo 2019. All rights reserved.
 **
 **     $Name: $
 **
 ***************************************************************************/

#include "iomacro.h"

#if TID_GUARD(3)
#error This file should only be compiled with iccavr or aavr whith processor option -v3
#endif /* TID_GUARD(3) */

/* Include the SFR part if this file has not been included before,
 * OR this file is included by the assembler (SFRs must be defined in
 * each assembler module). */
#if !defined(__IOM644_H) || defined(__IAR_SYSTEMS_ASM__)

#pragma language=extended

/*==========================*/
/* Predefined SFR Addresses */
/*==========================*/

/****************************************************************************
 * An example showing the SFR_B() macro call, 
 * the expanded result and usage of this result:
 *
 * SFR_B(AVR,   0x1F) Expands to:
 * __io union {
 *             unsigned char AVR;                 // The sfrb as 1 byte
 *             struct {                           // The sfrb as 8 bits
 *                     unsigned char AVR_Bit0:1,
 *                                   AVR_Bit1:1,
 *                                   AVR_Bit2:1,
 *                                   AVR_Bit3:1,
 *                                   AVR_Bit4:1,
 *                                   AVR_Bit5:1,
 *                                   AVR_Bit6:1,
 *                                   AVR_Bit7:1;
 *                    };
 *            } @ 0x1F;
 * Examples of how to use the expanded result:
 * AVR |= (1<<5);
 * or like this:
 * AVR_Bit5 = 1;
 ***************************************************************************/

SFR_B(PINA,   0x00) 
SFR_B(DDRA,   0x01) 
SFR_B(PORTA,  0x02) 
SFR_B(PINB,   0x03) 
SFR_B(DDRB,   0x04) 
SFR_B(PORTB,  0x05) 
SFR_B(PINC,   0x06) 
SFR_B(DDRC,   0x07) 
SFR_B(PORTC,  0x08) 
SFR_B(PIND,   0x09) 
SFR_B(DDRD,   0x0A) 
SFR_B(PORTD,  0x0B) 
SFR_B(TIFR0,  0x15) 
SFR_B(TIFR1,  0x16) 
SFR_B(TIFR2,  0x17) 
SFR_B(PCIFR,  0x1B) 
SFR_B(EIFR,   0x1C) 
SFR_B(EIMSK,  0x1D) 
SFR_B(GPIOR0, 0x1E) 
SFR_B(EECR,   0x1F) 
SFR_B(EEDR,   0x20) 
SFR_W(EEAR ,  0x21)
SFR_B(GTCCR,  0x23)
SFR_B(TCCR0A, 0x24)
SFR_B(TCCR0B, 0x25)
SFR_B(TCNT0,  0x26)
SFR_B(OCR0A,  0x27)
SFR_B(OCR0B,  0x28)
SFR_B(GPIOR1, 0x2A)
SFR_B(GPIOR2, 0x2B)
SFR_B(SPCR,   0x2C)
SFR_B(SPSR,   0x2D)
SFR_B(SPDR,   0x2E)
SFR_B(ACSR,   0x30)
SFR_B(OCDR,   0x31)
SFR_B(SMCR,   0x33)
SFR_B(MCUSR,  0x34)
SFR_B(MCUCR,  0x35)
SFR_B(SPMCSR, 0x37)
SFR_B(SPL,    0x3D)
SFR_B(SPH,    0x3E)
SFR_B(SREG,   0x3F)


/* Extended I/O space */
SFR_B_EXT(WDTCSR,   0x60)
SFR_B_EXT(CLKPR,    0x61)
SFR_B_EXT(PRR,      0x64)
SFR_B_EXT(OSCCAL,   0x66)
SFR_B_EXT(PCICR,    0x68)
SFR_B_EXT(EICRA,    0x69)
SFR_B_EXT(PCMSK0,   0x6B)
SFR_B_EXT(PCMSK1,   0x6C)
SFR_B_EXT(PCMSK2,   0x6D)
SFR_B_EXT(TIMSK0,   0x6E)
SFR_B_EXT(TIMSK1,   0x6F)
SFR_B_EXT(TIMSK2,   0x70)
SFR_B_EXT(PCMSK3,   0x73)
SFR_B_EXT(ADCL,     0x78)
SFR_B_EXT(ADCH,     0x79)
SFR_B_EXT(ADCSRA,   0x7A)
SFR_B_EXT(ADCSRB,   0x7B)
SFR_B_EXT(ADMUX,    0x7C)
SFR_B_EXT(DIDR0,    0x7E)
SFR_B_EXT(DIDR1,    0x7F)
SFR_B_EXT(TCCR1A,   0x80)
SFR_B_EXT(TCCR1B,   0x81)
SFR_B_EXT(TCCR1C,   0x82)
SFR_B_EXT(TCNT1L,   0x84)
SFR_B_EXT(TCNT1H,   0x85)
SFR_B_EXT(ICR1L,    0x86)
SFR_B_EXT(ICR1H,    0x87)
SFR_B_EXT(OCR1AL,   0x88)
SFR_B_EXT(OCR1AH,   0x89)
SFR_B_EXT(OCR1BL,   0x8A)
SFR_B_EXT(OCR1BH,   0x8B)
SFR_B_EXT(TCCR2A,   0xB0)
SFR_B_EXT(TCCR2B,   0xB1)
SFR_B_EXT(TCNT2,    0xB2)
SFR_B_EXT(OCR2A,    0xB3)
SFR_B_EXT(OCR2B,    0xB4)
SFR_B_EXT(ASSR,     0xB6)
SFR_B_EXT(TWBR,     0xB8)
SFR_B_EXT(TWSR,     0xB9)
SFR_B_EXT(TWAR,     0xBA)
SFR_B_EXT(TWDR,     0xBB)
SFR_B_EXT(TWCR,     0xBC)
SFR_B_EXT(TWAMR,    0xBD)
SFR_B_EXT(UCSR0A,   0xC0)
SFR_B_EXT(UCSR0B,   0xC1)
SFR_B_EXT(UCSR0C,   0xC2)
SFR_B_EXT(UBRR0L,   0xC4)
SFR_B_EXT(UBRR0H,   0xC5)
SFR_B_EXT(UDR0,     0xC6)



#ifndef __IOM644_H
#define __IOM644_H


/* SFRs are local in assembler modules (so this file may need to be */
/* included in more than one module in the same source file), */
/* but #defines must only be made once per source file. */

/*==============================*/
/* Interrupt Vector Definitions */
/*==============================*/

/* NB! vectors are specified as byte addresses */

#define RESET_vect               (0x00) /* External Pin,Power-on Reset,Brown-out Reset,Watchdog Reset,and JTAG AVR Reset. See Datasheet.      */
#define INT0_vect                (0x04) /* External Interrupt Request 0 */
#define INT1_vect                (0x08) /* External Interrupt Request 1 */
#define INT2_vect                (0x0C) /* External Interrupt Request 2 */
#define PCINT0_vect              (0x10) /* Pin Change Interrupt Request 0 */
#define PCINT1_vect              (0x14) /* Pin Change Interrupt Request 1 */
#define PCINT2_vect              (0x18) /* Pin Change Interrupt Request 2 */
#define PCINT3_vect              (0x1C) /* Pin Change Interrupt Request 3 */
#define WDT_vect                 (0x20) /* Watchdog Time-out Interrupt */
#define TIMER2_COMPA_vect        (0x24) /* Timer/Counter2 Compare Match A */
#define TIMER2_COMPB_vect        (0x28) /* Timer/Counter2 Compare Match B */
#define TIMER2_OVF_vect          (0x2C) /* Timer/Counter2 Overflow */
#define TIMER1_CAPT_vect         (0x30) /* Timer/Counter1 Capture Event */
#define TIMER1_COMPA_vect        (0x34) /* Timer/Counter1 Compare Match A */
#define TIMER1_COMPB_vect        (0x38) /* Timer/Counter1 Compare Match B */
#define TIMER1_OVF_vect          (0x3C) /* Timer/Counter1 Overflow */
#define TIMER0_COMPA_vect        (0x40) /* Timer/Counter0 Compare Match A */
#define TIMER0_COMPB_vect        (0x44) /* Timer/Counter0 Compare Match B */
#define TIMER0_OVF_vect          (0x48) /* Timer/Counter0 Overflow */
#define SPI_STC_vect             (0x4C) /* SPI Serial Transfer Complete */
#define USART0_RX_vect           (0x50) /* USART0, Rx Complete */
#define USART0_UDRE_vect         (0x54) /* USART0 Data register Empty */
#define USART0_TX_vect           (0x58) /* USART0, Tx Complete */
#define ANALOG_COMP_vect         (0x5C) /* Analog Comparator */
#define ADC_vect                 (0x60) /* ADC Conversion Complete */
#define EE_READY_vect            (0x64) /* EEPROM Ready */
#define TWI_vect                 (0x68) /* 2-wire Serial Interface */
#define SPM_READY_vect           (0x6C) /* Store Program Memory Read */


#ifdef __IAR_SYSTEMS_ASM__   
#ifndef ENABLE_BIT_DEFINITIONS
#define  ENABLE_BIT_DEFINITIONS
#endif /* ENABLE_BIT_DEFINITIONS */
#endif /* __IAR_SYSTEMS_ASM__ */

#ifdef ENABLE_BIT_DEFINITIONS


/* Bit definitions for use with the IAR Assembler   
   The Register Bit names are represented by their bit number (0-7).
*/

 
/* Pointer definition */
#define    XL     r26
#define    XH     r27
#define    YL     r28
#define    YH     r29
#define    ZL     r30
#define    ZH     r31

/* Contants */
#define    RAMEND   0x10FF    /*Last On-Chip SRAM location*/
#define    XRAMEND  0xFFFF
#define    E2END    0x07FF
#define    FLASHEND 0xFFFF

#endif /* ENABLE_BIT_DEFINITIONS */ 
#endif /* __IOM644_H (define part) */

#pragma language=default

#endif /* __IOM644_H (SFR part) */
