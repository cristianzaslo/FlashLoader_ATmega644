/*~-1*/
/*~XSF_LANGUAGE: C/C++*/
/*~A:1*/
/*~+:Header*/
/*~T*/
/* SOURCE FILE    <Uart.h>

 **************************************************************************
 *  PROJECT       <FlashLoader_AT644>
 *  MODULE        <Uart>
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
#ifndef _H_UART_
 
/*~T*/
#define _H_UART_

/*~A:3*/
/*~+:Types*/
/*~T*/

/*~E:A3*/
/*~A:4*/
/*~+:Constants*/
/*~A:5*/
/*~+:Baudrate*/
/*~K*/
/*~+:-------   Configuration 8Mz clock frequency, single speed   -----*/
/*~T*/
#define  UA_ui16_002400_BPS    (uint16_t)207
#define  UA_ui16_004800_BPS    (uint16_t)103
#define  UA_ui16_009600_BPS    (uint16_t)51
#define  UA_ui16_014400_BPS    (uint16_t)34
#define  UA_ui16_019200_BPS    (uint16_t)25
#define  UA_ui16_028800_BPS    (uint16_t)16
#define  UA_ui16_038400_BPS    (uint16_t)12
#define  UA_ui16_057600_BPS    (uint16_t)8
#define  UA_ui16_076800_BPS    (uint16_t)6
#define  UA_ui16_115200_BPS    (uint16_t)3
#define  UA_ui16_230400_BPS    (uint16_t)1
#define  UA_ui16_250000_BPS    (uint16_t)1
#define  UA_ui16_500000_BPS    (uint16_t)0

/*~E:A5*/
/*~A:6*/
/*~+:Operation Mode*/
/*~T*/
#define UA_ui8_ASYNCHRONOUS    (uint8_t)0x00
#define UA_ui8_SYNCHRONOUS     (uint8_t)0x40
#define UA_ui8_MASTER_SPI      (uint8_t)0xC0

/*~E:A6*/
/*~A:7*/
/*~+:Parity Mode*/
/*~T*/
#define UA_ui8_NO_PARITY    (uint8_t)0x00
#define UA_ui8_EVEN_PARITY  (uint8_t)0x20
#define UA_ui8_ODD_PARITY   (uint8_t)0x30

/*~E:A7*/
/*~A:8*/
/*~+:Stop bits*/
/*~T*/
#define UA_ui8_ONE_STOP    (uint8_t)0x00
#define UA_ui8_TWO_STOP    (uint8_t)0x08

/*~E:A8*/
/*~A:9*/
/*~+:Char size*/
/*~T*/
#define UA_ui8_FIVE_BITS     (uint8_t)0x00
#define UA_ui8_SIX_BITS      (uint8_t)0x02
#define UA_ui8_SEVEN_BITS    (uint8_t)0x04
#define UA_ui8_EIGHT_BITS    (uint8_t)0x06
#define UA_ui8_NINE_BITS     (uint8_t)0x0E

/*~E:A9*/
/*~A:10*/
/*~+:Clock polarity*/
/*~T*/
#define UA_ui8_POLARITY_LOW     (uint8_t)0x00
#define UA_ui8_POLARITY_HIGH    (uint8_t)0x01

/*~E:A10*/
/*~A:11*/
/*~+:Rx errors*/
/*~T*/
#define UA_ui8_NOERROR     (uint8_t)0x00
#define UA_ui8_FRAMING     (uint8_t)0x10
#define UA_ui8_OVERRUN     (uint8_t)0x08
#define UA_ui8_PARITY      (uint8_t)0x04
#define UA_ui8_FR_OV       (uint8_t)(UA_ui8_FRAMING + UA_ui8_OVERRUN)
#define UA_ui8_FR_PA       (uint8_t)(UA_ui8_FRAMING + UA_ui8_PARITY)
#define UA_ui8_OV_PA       (uint8_t)(UA_ui8_OVERRUN + UA_ui8_PARITY)
#define UA_ui8_FR_OV_PA    (uint8_t)(UA_ui8_FRAMING + UA_ui8_OVERRUN + UA_ui8_PARITY)

/*~E:A11*/
/*~T*/

/*~E:A4*/
/*~A:12*/
/*~+:Variables*/
/*~T*/

/*~E:A12*/
/*~A:13*/
/*~+:Macros*/
/*~T*/

/*~E:A13*/
/*~A:14*/
/*~+:Flags / Bit Masks*/
/*~T*/

/*~E:A14*/
/*~A:15*/
/*~+:Function prototypes*/
/*~T*/
/* set communication baudrate */
extern void UA_v_SetBaudrate (const uint16_t ui16_BaudRate);

/* set frame format */
/* clock polarity must be LOW for asynchronous mode */
extern void UA_v_SetFrameFormat (const uint8_t ui8_Mode, const uint8_t ui8_Parity, const uint8_t ui8_StopBits, const uint8_t ui8_CharSize, const uint8_t ui8_ClockPolarity);

/* enable Rx */
extern void UA_v_Enable_Rx (void);

/* disable Rx */
extern void UA_v_Disable_Rx (void);

/* enable Tx */
extern void UA_v_Enable_Tx (void);

/* disable Tx */
extern void UA_v_Disable_Tx (void);

/* enable Tx completed interrupt */
extern void UA_v_Enable_Interrupt_Tx_Complete (void);

/* disable Tx completed interrupt */
extern void UA_v_Disable_Interrupt_Tx_Complete (void);

/* enable Tx buffer empty interrupt */
extern void UA_v_Enable_Interrupt_Tx_Empty (void);

/* disable Tx buffer empty interrupt */
extern void UA_v_Disable_Interrupt_Tx_Empty (void);

/* enable Rx completed interrupt */
extern void UA_v_Enable_Interrupt_Rx (void);

/* disable Rx completed interrupt */
extern void UA_v_Disable_Interrupt_Rx (void);

/* Rx completed status flag */
extern bool_t UA_f_Rx_Complete (void);

/* Tx completed status flag */
extern bool_t UA_f_Tx_Complete (void);

/* clear Tx completed status flag */
extern void UA_v_Clear_Tx_Complete (void);

/* Tx buffer empty status flag */
extern bool_t UA_f_Tx_Empty (void);

/* MPC mode: slaves wait to be addressed */
extern void UA_v_MPC_WaitAddress (void);

/* MPC mode: slaves wait for data */
extern void UA_v_MPC_WaitData (void);

/* send char: 5 to 9 bits length */
extern void UA_v_SendChar (const uint16_t ui16_Char);

/* get Rx errors; must be called before UA_vGetChar function */
extern uint8_t UA_ui8_GetErrors (void);

/* get char: 5 to 9 bits length */
extern uint16_t UA_ui16_GetChar (void);

/*~K*/
/*~+:-----   USER DEFINED FUNCTIONS   -----*/
/*~T*/
/* initialization */
extern void UA_v_Init (void);
/*~E:A15*/
/*~-1*/
#endif
/*~E:I2*/
