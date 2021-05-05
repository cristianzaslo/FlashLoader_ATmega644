/*~-1*/
/*~XSF_LANGUAGE: C/C++*/
/*~A:1*/
/*~+:Header*/
/*~T*/
/* SOURCE FILE    <Uart.c>

 **************************************************************************
 *  PROJECT       <FlashLoader_AT644>
 *  MODULE        <Uart>
 *  RESPONSIBLE   <Cristian Zaslo>
 **************************************************************************
 *  PURPOSE:      UART driver
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
/*~A:2*/
/*~+:Includes*/
/*~T*/
#include <iom644.h>
#include "Global.h"
#include "Uart.h"

/*~E:A2*/
/*~A:3*/
/*~+:Types*/
/*~T*/

/*~E:A3*/
/*~A:4*/
/*~+:Constants*/
/*~T*/

/*~E:A4*/
/*~A:5*/
/*~+:Variables*/
/*~T*/

/*~E:A5*/
/*~A:6*/
/*~+:Macros*/
/*~T*/

/*~E:A6*/
/*~A:7*/
/*~+:Flags / Bit Masks*/
/*~T*/

/*~E:A7*/
/*~A:8*/
/*~+:Function prototypes*/
/*~T*/

/*~E:A8*/
/*~A:9*/
/*~+:void UA_v_SetBaudrate (const uint16_t ui16_BaudRate)*/
/*~F:10*/
void UA_v_SetBaudrate (const uint16_t ui16_BaudRate)
/*~-1*/
{
   /*~T*/
   /* set low speed mode */
   UCSR0A_Bit1 = FALSE;

   /* set baudrate, clear bits 12-15 of UBRR */
   UBRR0L = (uint8_t)ui16_BaudRate;
   UBRR0H = (uint8_t)(ui16_BaudRate >> 8) & (uint8_t)0x0F;

/*~-1*/
}
/*~E:F10*/
/*~E:A9*/
/*~A:11*/
/*~+:void UA_v_SetFrameFormat (const uint8_t ui8_Mode, const uint8_t ui8_Parity, const uint8_t ui8_StopBits, const uint8_t ui8_CharSize, const uint8_t ui8_ClockPolarity)*/
/*~F:12*/
void UA_v_SetFrameFormat (const uint8_t ui8_Mode, const uint8_t ui8_Parity, const uint8_t ui8_StopBits, const uint8_t ui8_CharSize, const uint8_t ui8_ClockPolarity)
/*~-1*/
{
   /*~T*/
   /* temporary */
   uint8_t ui8_Temp;
   /*~T*/
   /* set USART operation mode, parity, stop bits, char size, clock polarity */
   ui8_Temp  = ui8_Mode | ui8_Parity | ui8_StopBits | (ui8_CharSize & (uint8_t)0x06) | ui8_ClockPolarity;

   /* copy value to UCSRC register */
   UCSR0C = ui8_Temp;

   /*~I:13*/
   /* char size is 9 bits ?*/
   if (ui8_CharSize & 0x08)
   /*~-1*/
   {
      /*~T*/
      /* set UCSZ2 */
      UCSR0B_Bit2 = TRUE;
   /*~-1*/
   }
   /*~O:I13*/
   /*~-2*/
   else
   {
      /*~T*/
      /* clear UCSZ2 */
      UCSR0B_Bit2 = FALSE;
   /*~-1*/
   }
   /*~E:I13*/
/*~-1*/
}
/*~E:F12*/
/*~E:A11*/
/*~A:14*/
/*~+:void UA_v_Enable_Rx (void)*/
/*~F:15*/
void UA_v_Enable_Rx (void)
/*~-1*/
{
   /*~T*/
   /* enable receiver */
   UCSR0B_Bit4 = TRUE;

/*~-1*/
}
/*~E:F15*/
/*~E:A14*/
/*~A:16*/
/*~+:void UA_v_Disable_Rx (void)*/
/*~F:17*/
void UA_v_Disable_Rx (void)
/*~-1*/
{
   /*~T*/
   /* disable receiver */
   UCSR0B_Bit4 = FALSE;

/*~-1*/
}
/*~E:F17*/
/*~E:A16*/
/*~A:18*/
/*~+:void UA_v_Enable_Tx (void)*/
/*~F:19*/
void UA_v_Enable_Tx (void)
/*~-1*/
{
   /*~T*/
   /* enable transmitter */
   UCSR0B_Bit3 = TRUE;

/*~-1*/
}
/*~E:F19*/
/*~E:A18*/
/*~A:20*/
/*~+:void UA_v_Disable_Tx (void)*/
/*~F:21*/
void UA_v_Disable_Tx (void)
/*~-1*/
{
   /*~T*/
   /* disable transmitter */
   UCSR0B_Bit3 = FALSE;

/*~-1*/
}
/*~E:F21*/
/*~E:A20*/
/*~A:22*/
/*~+:void UA_v_Enable_Interrupt_Tx_Complete (void)*/
/*~F:23*/
void UA_v_Enable_Interrupt_Tx_Complete (void)
/*~-1*/
{
   /*~T*/
   /* enable Tx complete interrupt */
   UCSR0B_Bit6 = TRUE;

/*~-1*/
}
/*~E:F23*/
/*~E:A22*/
/*~A:24*/
/*~+:void UA_v_Disable_Interrupt_Tx_Complete (void)*/
/*~F:25*/
void UA_v_Disable_Interrupt_Tx_Complete (void)
/*~-1*/
{
   /*~T*/
   /* disable Tx complete interrupt */
   UCSR0B_Bit6 = FALSE;

/*~-1*/
}
/*~E:F25*/
/*~E:A24*/
/*~A:26*/
/*~+:void UA_v_Enable_Interrupt_Tx_Empty (void)*/
/*~F:27*/
void UA_v_Enable_Interrupt_Tx_Empty (void)
/*~-1*/
{
   /*~T*/
   /* enable transmit buffer empty interrupt */
   UCSR0B_Bit5 = TRUE;

/*~-1*/
}
/*~E:F27*/
/*~E:A26*/
/*~A:28*/
/*~+:void UA_v_Disable_Interrupt_Tx_Empty (void)*/
/*~F:29*/
void UA_v_Disable_Interrupt_Tx_Empty (void)
/*~-1*/
{
   /*~T*/
   /* disable transmit buffer empty interrupt */
   UCSR0B_Bit5 = FALSE;

/*~-1*/
}
/*~E:F29*/
/*~E:A28*/
/*~A:30*/
/*~+:void UA_v_Enable_Interrupt_Rx (void)*/
/*~F:31*/
void UA_v_Enable_Interrupt_Rx (void)
/*~-1*/
{
   /*~T*/
   /* enable Rx complete interrupt */
   UCSR0B_Bit7 = TRUE;

/*~-1*/
}
/*~E:F31*/
/*~E:A30*/
/*~A:32*/
/*~+:void UA_v_Disable_Interrupt_Rx (void)*/
/*~F:33*/
void UA_v_Disable_Interrupt_Rx (void)
/*~-1*/
{
   /*~T*/
   /* disable Rx complete interrupt */
   UCSR0B_Bit7 = FALSE;

/*~-1*/
}
/*~E:F33*/
/*~E:A32*/
/*~A:34*/
/*~+:bool_t UA_f_Rx_Complete (void)*/
/*~F:35*/
bool_t UA_f_Rx_Complete (void)
/*~-1*/
{
   /*~T*/
   /* return receive complete status */
   return (bool_t)UCSR0A_Bit7;
/*~-1*/
}
/*~E:F35*/
/*~E:A34*/
/*~A:36*/
/*~+:bool_t UA_f_Tx_Complete (void)*/
/*~F:37*/
bool_t UA_f_Tx_Complete (void)
/*~-1*/
{
   /*~T*/
   /* return transmit complete status */
   return (bool_t)UCSR0A_Bit6;
/*~-1*/
}
/*~E:F37*/
/*~E:A36*/
/*~A:38*/
/*~+:void UA_v_Clear_Tx_Complete (void)*/
/*~F:39*/
void UA_v_Clear_Tx_Complete (void)
/*~-1*/
{
   /*~T*/
   /* clear transmit complete status bit */
   UCSR0A_Bit6 = FALSE;
/*~-1*/
}
/*~E:F39*/
/*~E:A38*/
/*~A:40*/
/*~+:bool_t UA_f_Tx_Empty (void)*/
/*~F:41*/
bool_t UA_f_Tx_Empty (void)
/*~-1*/
{
   /*~T*/
   /* return transmit buffer empty status */
   return (bool_t)UCSR0A_Bit5;
/*~-1*/
}
/*~E:F41*/
/*~E:A40*/
/*~A:42*/
/*~+:void UA_v_MPC_WaitAddress (void)*/
/*~F:43*/
void UA_v_MPC_WaitAddress (void)
/*~-1*/
{
   /*~T*/
   /* enable addressing */
   UCSR0A_Bit0 = TRUE;

/*~-1*/
}
/*~E:F43*/
/*~E:A42*/
/*~A:44*/
/*~+:void UA_v_MPC_WaitData (void)*/
/*~F:45*/
void UA_v_MPC_WaitData (void)
/*~-1*/
{
   /*~T*/
   /* wait for data byte */
   UCSR0A_Bit0 = FALSE;

/*~-1*/
}
/*~E:F45*/
/*~E:A44*/
/*~A:46*/
/*~+:void UA_v_SendChar (const uint16_t ui16_Char)*/
/*~F:47*/
void UA_v_SendChar (const uint16_t ui16_Char)
/*~-1*/
{
   /*~I:48*/
   /* char size is 9 bit ? */
   if (UCSR0B_Bit2)
   /*~-1*/
   {
      /*~I:49*/
      /* must the 9th bit set ?*/
      if (ui16_Char & (uint16_t)0x0100)
      /*~-1*/
      {
         /*~T*/
         /* set 9th bit */
         UCSR0B_Bit0 = TRUE;
      /*~-1*/
      }
      /*~O:I49*/
      /*~-2*/
      else
      {
         /*~T*/
         /* clear 9th bit */
         UCSR0B_Bit0 = FALSE;
      /*~-1*/
      }
      /*~E:I49*/
   /*~-1*/
   }
   /*~O:I48*/
   /*~-2*/
   else
   {
      /*~T*/
      /* 8 bit or less char size */
   /*~-1*/
   }
   /*~E:I48*/
   /*~T*/
   /* send first 8 bits */
   UDR0 = (uint8_t)ui16_Char;

   /*~T*/

/*~-1*/
}
/*~E:F47*/
/*~E:A46*/
/*~A:50*/
/*~+:uint8_t UA_ui8_GetErrors (void)*/
/*~F:51*/
uint8_t UA_ui8_GetErrors (void)
/*~-1*/
{
   /*~T*/
   /* return Rx error status */
   return (UCSR0A & (uint8_t)0x1C);
/*~-1*/
}
/*~E:F51*/
/*~E:A50*/
/*~A:52*/
/*~+:uint16_t UA_ui16_GetChar (void)*/
/*~F:53*/
uint16_t UA_ui16_GetChar (void)
/*~-1*/
{
   /*~T*/
   /* receive char, clear all bits at initialization */
   uint16_t ui16_Result = 0;
   /*~I:54*/
   /* char size is 9 bit ? */
   if (UCSR0B_Bit2)
   /*~-1*/
   {
      /*~I:55*/
      /* is the 9th bit set ?*/
      if (UCSR0B_Bit1)
      /*~-1*/
      {
         /*~T*/
         /* set 9th bit in result */
         ui16_Result = (uint16_t)0x100;
      /*~-1*/
      }
      /*~O:I55*/
      /*~-2*/
      else
      {
         /*~T*/
         /* 9th bit in result is cleared */

      /*~-1*/
      }
      /*~E:I55*/
   /*~-1*/
   }
   /*~O:I54*/
   /*~-2*/
   else
   {
      /*~T*/
      /* less than 9 bit char size */
   /*~-1*/
   }
   /*~E:I54*/
   /*~T*/
   /* add first 8 bits to the result */
   ui16_Result |= (uint16_t)UDR0;

   /* return received char */
   return ui16_Result;

/*~-1*/
}
/*~E:F53*/
/*~E:A52*/
/*~K*/
/*~+:-----   SPECIFIC USER DEFINED FUNCTIONS   -----*/
/*~A:56*/
/*~+:void UA_v_Init (void)*/
/*~F:57*/
void UA_v_Init (void)
/*~-1*/
{
   /*~K*/
   /*~+:-----   PLACE USER INITIALISATION CODE   -----*/
   /*~T*/
   /* baudrate 9.6k */
   UA_v_SetBaudrate (UA_ui16_009600_BPS);

   /* set frame format */
   UA_v_SetFrameFormat (UA_ui8_ASYNCHRONOUS, UA_ui8_NO_PARITY, UA_ui8_ONE_STOP, UA_ui8_EIGHT_BITS, UA_ui8_POLARITY_LOW);

   /* enable Tx */
   UA_v_Enable_Tx ();

   /* enable Rx */
   UA_v_Enable_Rx ();

   /* disable interrupt Tx */
   UA_v_Disable_Interrupt_Tx_Complete ();

   /* disable interrupt Tx buffer empty */
   UA_v_Disable_Interrupt_Tx_Empty ();

   /* disable interrupt Rx complete */
   UA_v_Disable_Interrupt_Rx ();

   /* clear Tx complete interrupt flag */
   UA_v_Clear_Tx_Complete ();

/*~-1*/
}
/*~E:F57*/
/*~E:A56*/
