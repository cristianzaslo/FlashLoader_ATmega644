/*~-1*/
/*~XSF_LANGUAGE: C/C++*/
/*~A:1*/
/*~+:Header*/
/*~T*/
/* SOURCE FILE    <Io.h>

 **************************************************************************
 *  PROJECT       <FlashLoader_AT644>
 *  MODULE        <Io>
 *  RESPONSIBLE   <Cristian Zaslo>
 **************************************************************************
 *  PURPOSE:      Exported data and functions
 *
 *
 **************************************************************************
 *  REMARKS:
 *  ATMEGA 644 compliant
 *
 **************************************************************************
 *  CHANGE HISTORY:
 *  Log of all revisions so far:
 *
 *  Rev 1.0   Mar 01 2021    CrZa
 *  Initial revision.
 *
 *************************************************************************/



/*~E:A1*/
/*~I:2*/
#ifndef _H_IO_
 
/*~T*/
#define _H_IO_

/*~A:3*/
/*~+:Types*/
/*~T*/

/*~E:A3*/
/*~A:4*/
/*~+:Constants*/
/*~T*/
/* PIN levels */
#define HIGH (uint8_t)1
#define LOW  (uint8_t)0

/* PIN directions */
#define OUTPUT (uint8_t)1
#define INPUT  (uint8_t)0

/*~E:A4*/
/*~A:5*/
/*~+:Variables*/
/*~T*/

/*~E:A5*/
/*~A:6*/
/*~+:Macros*/
/*~T*/
/* set PIN latch */
#define IO_v_SET_PIN_LATCH(f_PIN, ui8_VAL)   (f_PIN = ui8_VAL)

/* get PIN latch */
#define IO_ui8_GET_PIN_LATCH(f_PIN)        ((uint8_t)f_PIN)

/* get PIN terminal */
#define IO_ui8_GET_PIN_TERMINAL(f_PIN)     ((uint8_t)f_PIN ## _TER)

/* set PIN direction */
#define IO_v_SET_PIN_DIR(f_PIN, ui8_DIR)   (f_PIN ## _DIR = ui8_DIR)

/* master pull up enable */
#define IO_v_PULL_UP_ENABLE (MCUCR_Bit4 = LOW)

/* master pull up disable */
#define IO_v_PULL_UP_DISABLE (MCUCR_Bit4 = HIGH)

/* set PIN pull-up */
#define IO_v_SET_PIN_PUL(f_PIN)   (IO_v_PULL_UP_ENABLE  , IO_v_SET_PIN_LATCH(f_PIN, HIGH) , (f_PIN ## _DIR = INPUT))

/* clear PIN pull-up */
#define IO_v_CLEAR_PIN_PUL(f_PIN) (IO_v_SET_PIN_LATCH (f_PIN, LOW), (f_PIN ## _DIR = INPUT))

/*~E:A6*/
/*~A:7*/
/*~+:Flags / Bit Masks*/
/*~T*/
/* PORT_A pin assignments */

/* latch */
#define IO_f_PORT_A_0           PORTA_Bit0
#define IO_f_PORT_A_1           PORTA_Bit1
#define IO_f_PORT_A_2           PORTA_Bit3
#define IO_f_PORT_A_3           PORTA_Bit2
#define IO_f_PORT_A_4           PORTA_Bit4
#define IO_f_PORT_A_5           PORTA_Bit5
#define IO_f_PORT_A_6           PORTA_Bit6
#define IO_f_PORT_A_7           PORTA_Bit7

/* direction */
#define IO_f_PORT_A_0_DIR       DDRA_Bit0
#define IO_f_PORT_A_1_DIR       DDRA_Bit1
#define IO_f_PORT_A_2_DIR       DDRA_Bit3
#define IO_f_PORT_A_3_DIR       DDRA_Bit2
#define IO_f_PORT_A_4_DIR       DDRA_Bit4
#define IO_f_PORT_A_5_DIR       DDRA_Bit5
#define IO_f_PORT_A_6_DIR       DDRA_Bit6
#define IO_f_PORT_A_7_DIR       DDRA_Bit7

/* terminal */
#define IO_f_PORT_A_0_TER       PINA_Bit0
#define IO_f_PORT_A_1_TER       PINA_Bit1
#define IO_f_PORT_A_2_TER       PINA_Bit3
#define IO_f_PORT_A_3_TER       PINA_Bit2
#define IO_f_PORT_A_4_TER       PINA_Bit4
#define IO_f_PORT_A_5_TER       PINA_Bit5
#define IO_f_PORT_A_6_TER       PINA_Bit6
#define IO_f_PORT_A_7_TER       PINA_Bit7


/*~T*/
/* PORT_B pin assignments */

/* latch */
#define IO_f_PORT_B_0              PORTB_Bit0
#define IO_f_PORT_B_1              PORTB_Bit1
#define IO_f_PORT_B_2              PORTB_Bit2
#define IO_f_PORT_B_3              PORTB_Bit3
#define IO_f_PORT_B_4              PORTB_Bit4
#define IO_f_PORT_B_5              PORTB_Bit5
#define IO_f_PORT_B_6              PORTB_Bit6
#define IO_f_PORT_B_7              PORTB_Bit7

/* direction */
#define IO_f_PORT_B_0_DIR          DDRB_Bit0
#define IO_f_PORT_B_1_DIR          DDRB_Bit1
#define IO_f_PORT_B_2_DIR          DDRB_Bit2
#define IO_f_PORT_B_3_DIR          DDRB_Bit3
#define IO_f_PORT_B_4_DIR          DDRB_Bit4
#define IO_f_PORT_B_5_DIR          DDRB_Bit5
#define IO_f_PORT_B_6_DIR          DDRB_Bit6
#define IO_f_PORT_B_7_DIR          DDRB_Bit7

/* terminal */
#define IO_f_PORT_B_0_TER          PINB_Bit0
#define IO_f_PORT_B_1_TER          PINB_Bit1
#define IO_f_PORT_B_2_TER          PINB_Bit2
#define IO_f_PORT_B_3_TER          PINB_Bit3
#define IO_f_PORT_B_4_TER          PINB_Bit4
#define IO_f_PORT_B_5_TER          PINB_Bit5
#define IO_f_PORT_B_6_TER          PINB_Bit6
#define IO_f_PORT_B_7_TER          PINB_Bit7

/*~T*/
/* PORT_C pin assignments */

/* latch */
#define IO_f_PORT_C_0            PORTC_Bit0
#define IO_f_PORT_C_1            PORTC_Bit1
#define IO_f_PORT_C_2            PORTC_Bit2
#define IO_f_PORT_C_3            PORTC_Bit3
#define IO_f_PORT_C_4            PORTC_Bit4
#define IO_f_PORT_C_5            PORTC_Bit5
#define IO_f_PORT_C_6            PORTC_Bit6
#define IO_f_PORT_C_7            PORTC_Bit7

/* direction */
#define IO_f_PORT_C_0_DIR        DDRC_Bit0
#define IO_f_PORT_C_1_DIR        DDRC_Bit1
#define IO_f_PORT_C_2_DIR        DDRC_Bit2
#define IO_f_PORT_C_3_DIR        DDRC_Bit3
#define IO_f_PORT_C_4_DIR        DDRC_Bit4
#define IO_f_PORT_C_5_DIR        DDRC_Bit5
#define IO_f_PORT_C_6_DIR        DDRC_Bit6
#define IO_f_PORT_C_7_DIR        DDRC_Bit7

/* terminal */
#define IO_f_PORT_C_0_TER        PINC_Bit0
#define IO_f_PORT_C_1_TER        PINC_Bit1
#define IO_f_PORT_C_2_TER        PINC_Bit2
#define IO_f_PORT_C_3_TER        PINC_Bit3
#define IO_f_PORT_C_4_TER        PINC_Bit4
#define IO_f_PORT_C_5_TER        PINC_Bit5
#define IO_f_PORT_C_6_TER        PINC_Bit6
#define IO_f_PORT_C_7_TER        PINC_Bit7

/*~T*/
/* PORT_D pin assignments. To be reasigned based on the project needs */

/* latch */
#define IO_f_PORT_RX0           PORTD_Bit0
#define IO_f_PORT_TX0           PORTD_Bit1
#define IO_f_PORT_FLI           PORTD_Bit2
#define IO_f_PORT_TOG           PORTD_Bit3
#define IO_f_PORT_D_4           PORTD_Bit4
#define IO_f_PORT_D_5           PORTD_Bit5
#define IO_f_PORT_D_6           PORTD_Bit6
#define IO_f_PORT_D_7           PORTD_Bit7

/* direction */
#define IO_f_PORT_RX0_DIR       DDRD_Bit0
#define IO_f_PORT_TX0_DIR       DDRD_Bit1
#define IO_f_PORT_FLI_DIR       DDRD_Bit2
#define IO_f_PORT_TOG_DIR       DDRD_Bit3
#define IO_f_PORT_D_4_DIR       DDRD_Bit4
#define IO_f_PORT_D_5_DIR       DDRD_Bit5
#define IO_f_PORT_D_6_DIR       DDRD_Bit6
#define IO_f_PORT_D_7_DIR       DDRD_Bit7

/* terminal */
#define IO_f_PORT_RX0_TER       PIND_Bit0
#define IO_f_PORT_TX0_TER       PIND_Bit1
#define IO_f_PORT_FLI_TER       PIND_Bit2
#define IO_f_PORT_TOG_TER       PIND_Bit3
#define IO_f_PORT_D_4_TER       PIND_Bit4
#define IO_f_PORT_D_5_TER       PIND_Bit5
#define IO_f_PORT_D_6_TER       PIND_Bit6
#define IO_f_PORT_D_7_TER       PIND_Bit7

/*~E:A7*/
/*~A:8*/
/*~+:Function prototypes*/
/*~T*/
/* module initialization */
extern void IO_v_Init (void);
/*~E:A8*/
/*~T*/

/*~-1*/
#endif
/*~E:I2*/
