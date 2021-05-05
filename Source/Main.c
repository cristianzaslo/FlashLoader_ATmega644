/*~-1*/
/*~XSF_LANGUAGE: C/C++*/
/*~A:1*/
/*~+:Header*/
/*~T*/
/* SOURCE FILE     <Main.c>

 **************************************************************************
 *  PROJECT       <FlashLoader_AT644>
 *  MODULE        <Main>
 *  RESPONSIBLE   <Cristian Zaslo>
 **************************************************************************
 *  PURPOSE:      Program entry point
 *
 *
 **************************************************************************
 *  REMARKS:
 *  none
 *
 **************************************************************************
 *  CHANGE HISTORY:
 *  Log of all revisions so far:
 *
 *  Rev 1.0   May 01 2021    CrZa
 *  Initial revision.
 *
 *************************************************************************/



/*~E:A1*/
/*~A:2*/
/*~+:Includes*/
/*~T*/
#include <iom644.h>
#include "Global.h"
#include "Io.h"
#include "Uart.h"
#include "Fldr.h"
#include "Main.h"


/*~E:A2*/
/*~A:3*/
/*~+:Types*/
/*~T*/

/*~E:A3*/
/*~A:4*/
/*~+:Constants*/
/*~T*/
/* header value */
#define MA_ui8_HEADER  0x55

/*~T*/
/* header size */
#define MA_ui8_HEADER_SIZE (uint8_t)3

/*~T*/
/* positive acknowledge */
#define MA_ui8_POSITIVE_ACKN 0x55

/* negative acknowledge */
#define MA_ui8_NEGATIVE_ACKN 0xAA

/*~T*/
/* program states */
#define MA_ui8_INIT           0
#define MA_ui8_READ_HEADER    1
#define MA_ui8_READ_PAGE      2
#define MA_ui8_WRITE_PAGE     3
#define MA_ui8_CHECK_PRG      4
#define MA_ui8_END           10

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
/*~+:int main (void)*/
/*~F:10*/
int main (void)
/*~-1*/
{
   /*~T*/
   /* state */
   uint8_t ui8_State;

   /* byte counter */
   uint8_t ui8_ByteCounter;

   /* page counter */
   uint8_t ui8_PageCounter;

   /* expected checksum */
   uint16_t ui16_EChecksum;

   /* calculated checksum */
   uint16_t ui16_CChecksum;

   /*~T*/
   /* init global */
   GL_v_Init ();

   /* init IOs */
   IO_v_Init ();

   /*~I:11*/
   /* check three times on low level on FLI pin */
   if (!IO_ui8_GET_PIN_TERMINAL (IO_f_PORT_FLI) && !IO_ui8_GET_PIN_TERMINAL (IO_f_PORT_FLI) && !IO_ui8_GET_PIN_TERMINAL (IO_f_PORT_FLI))
   /*~-1*/
   {
      /*~T*/
      /* FLI input is low, go to FL section */
   /*~-1*/
   }
   /*~O:I11*/
   /*~-2*/
   else
   {
      /*~T*/
      /* FLI input is high, jump to application */
      asm("JMP 0x0000\n");

   /*~-1*/
   }
   /*~E:I11*/
   /*~T*/
   /* init state */
   ui8_State = MA_ui8_INIT;
   /*~U:12*/
   /*~-2*/
   do
   {
      /*~C:13*/
      /* selection on state */
      switch (ui8_State)
      /*~-1*/
      {
         /*~A:14*/
         /*~+:Init*/
         /*~F:15*/
         /* init */
         case MA_ui8_INIT:
         /*~-1*/
         {
            /*~T*/
            /* disable interrupts */
            asm("CLI\n");

            /* init UART */
            UA_v_Init ();

            /* send char */
            UA_v_SendChar (MA_ui8_HEADER);

            /* init page counter */
            ui8_PageCounter = 0;

            /* change state */
            ui8_State = MA_ui8_READ_HEADER;

            /*~T*/
            /* break */
            break;
         /*~-1*/
         }
         /*~E:F15*/
         /*~E:A14*/
         /*~A:16*/
         /*~+:Read header*/
         /*~F:17*/
         /* read header */
         case MA_ui8_READ_HEADER:
         /*~-1*/
         {
            /*~T*/
            /* init counter */
            ui8_ByteCounter = 0;
            /*~U:18*/
            /*~-2*/
            do
            {
               /*~U:19*/
               /*~-2*/
               do
               {
                  /*~T*/
                  /* wait for Rx buffer full */
               /*~-1*/
               }
               /*~O:U19*/
               while (!UA_f_Rx_Complete ()); /* loop */
               /*~E:U19*/
               /*~T*/
               /* store byte into buffer */
               FL_aui8_FlashPage [ui8_ByteCounter] = (uint8_t)UA_ui16_GetChar ();

            /*~-1*/
            }
            /*~O:U18*/
            while (ui8_ByteCounter++ < (uint8_t)(MA_ui8_HEADER_SIZE - 1));/* loop */
            /*~E:U18*/
            /*~I:20*/
            /* Rx error or wrong identification ? */
            if (UA_ui8_GetErrors () || (FL_aui8_FlashPage [0] != MA_ui8_HEADER))
            /*~-1*/
            {
               /*~T*/
               /* send feedback */
               UA_v_SendChar (MA_ui8_NEGATIVE_ACKN);

               /* change state */
               ui8_State = MA_ui8_END;

            /*~-1*/
            }
            /*~O:I20*/
            /*~-2*/
            else
            {
               /*~T*/
               /* store expected checksum */
               ui16_EChecksum = (uint16_t)FL_aui8_FlashPage [1];
               ui16_EChecksum += ((uint16_t)FL_aui8_FlashPage [2] << 8);

               /* send feedback */
               UA_v_SendChar (MA_ui8_HEADER);

               /* change state */
               ui8_State = MA_ui8_READ_PAGE;

            /*~-1*/
            }
            /*~E:I20*/
            /*~T*/
            /* break */
            break;
         /*~-1*/
         }
         /*~E:F17*/
         /*~E:A16*/
         /*~A:21*/
         /*~+:Read page*/
         /*~F:22*/
         /* read page */
         case MA_ui8_READ_PAGE:
         /*~-1*/
         {
            /*~T*/
            /* init counter */
            ui8_ByteCounter = 0;
            /*~U:23*/
            /*~-2*/
            do
            {
               /*~U:24*/
               /*~-2*/
               do
               {
                  /*~T*/
                  /* wait for Rx buffer full */
               /*~-1*/
               }
               /*~O:U24*/
               while (!UA_f_Rx_Complete ()); /* loop */
               /*~E:U24*/
               /*~T*/
               /* store byte into buffer */
               FL_aui8_FlashPage [ui8_ByteCounter] = (uint8_t)UA_ui16_GetChar ();

            /*~-1*/
            }
            /*~O:U23*/
            while (ui8_ByteCounter++ < (uint8_t)(MA_ui16_PAGE_SIZE - 1));/* loop */
            /*~E:U23*/
            /*~I:25*/
            /* Rx error or wrong identification ? */
            if (UA_ui8_GetErrors ())
            /*~-1*/
            {
               /*~T*/
               /* send feedback */
               UA_v_SendChar (MA_ui8_NEGATIVE_ACKN);

               /* change state */
               ui8_State = MA_ui8_END;

            /*~-1*/
            }
            /*~O:I25*/
            /*~-2*/
            else
            {
               /*~T*/
               /* change state */
               ui8_State = MA_ui8_WRITE_PAGE;

            /*~-1*/
            }
            /*~E:I25*/
            /*~T*/
            /* break */
            break;
         /*~-1*/
         }
         /*~E:F22*/
         /*~E:A21*/
         /*~A:26*/
         /*~+:Write page*/
         /*~F:27*/
         /* write page */
         case MA_ui8_WRITE_PAGE:
         /*~-1*/
         {
            /*~T*/
            /* erase page */
            FL_v_Erase_Page (ui8_PageCounter);

            /* load page */
            FL_v_Load_Page ();

            /* write page */
            FL_v_Write_Page (ui8_PageCounter);

            /* send feedback */
            UA_v_SendChar (ui8_PageCounter);

            /*~I:28*/
            /* all pages done ? */
            if (ui8_PageCounter++ == (uint8_t)(MA_ui16_PAGES_TO_WRITE - 1))
            /*~-1*/
            {
               /*~T*/
               /* change state */
               ui8_State = MA_ui8_CHECK_PRG;

            /*~-1*/
            }
            /*~O:I28*/
            /*~-2*/
            else
            {
               /*~T*/
               /* change state */
               ui8_State = MA_ui8_READ_PAGE;

            /*~-1*/
            }
            /*~E:I28*/
            /*~T*/
            /* break */
            break;
         /*~-1*/
         }
         /*~E:F27*/
         /*~E:A26*/
         /*~A:29*/
         /*~+:Check programming*/
         /*~F:30*/
         /* check programming */
         case MA_ui8_CHECK_PRG:
         /*~-1*/
         {
            /*~T*/
            /* init calculated checksum */
            ui16_CChecksum = 0;

            /* init page counter */
            ui8_PageCounter = 0;

            /*~U:31*/
            /*~-2*/
            do
            {
               /*~T*/
               /* init counter */
               ui8_ByteCounter = 0;

               /*~U:32*/
               /*~-2*/
               do
               {
                  /*~T*/
                  /* update calculated checksum */
                  ui16_CChecksum += *(__flash  uint8_t *)(((uint16_t)ui8_PageCounter << 8) + ui8_ByteCounter); 
               /*~-1*/
               }
               /*~O:U32*/
               while (ui8_ByteCounter++ < (uint8_t)(MA_ui16_PAGE_SIZE - 1)); /* loop */
               /*~E:U32*/
            /*~-1*/
            }
            /*~O:U31*/
            while (ui8_PageCounter++ < (uint8_t)(MA_ui16_PAGES_TO_WRITE - 1)); /* loop */
            /*~E:U31*/
            /*~I:33*/
            /* calculated and expected are the same ? */
            if (ui16_CChecksum == ui16_EChecksum)
            /*~-1*/
            {
               /*~T*/
               /* send feedback */
               UA_v_SendChar (MA_ui8_POSITIVE_ACKN);

            /*~-1*/
            }
            /*~O:I33*/
            /*~-2*/
            else
            {
               /*~T*/
               /* send feedback */
               UA_v_SendChar (MA_ui8_NEGATIVE_ACKN);

            /*~-1*/
            }
            /*~E:I33*/
            /*~T*/
            /* change state */
            ui8_State = MA_ui8_END;

            /*~T*/
            /* break */
            break;
         /*~-1*/
         }
         /*~E:F30*/
         /*~E:A29*/
         /*~O:C13*/
         /*~-2*/
         default:
         {
            /*~T*/
            /* MA_ui8_END */
            /* flash sequence complete */

         /*~-1*/
         }
      /*~-1*/
      }
      /*~E:C13*/
   /*~-1*/
   }
   /*~O:U12*/
   while (TRUE); /* endless loop */
   /*~E:U12*/
/*~-1*/
}
/*~E:F10*/
/*~E:A9*/
