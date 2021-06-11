/*~-1*/
/*~XSF_LANGUAGE: C/C++*/
/*~A:1*/
/*~+:Header*/
/*~T*/
/* SOURCE FILE    <Io.c>

 **************************************************************************
 *  PROJECT       <FlashLoader_AT644>
 *  MODULE        <Io>
 *  RESPONSIBLE   <Cristian Zaslo>
 **************************************************************************
 *  PURPOSE:      IO driver
 *
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
/* included files */
#include <iom644.h>
#include "Global.h"
#include "Io.h"    
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
/*~K*/
/*~+:-----   SPECIFIC USER DEFINED FUNCTIONS   -----*/
/*~A:9*/
/*~+:void IO_v_Init (void)*/
/*~F:10*/
/* module initialization */
void IO_v_Init (void)
/*~-1*/
{
   /*~T*/
   /* configure FLI pin */
   IO_v_SET_PIN_DIR (IO_f_PORT_FLI, INPUT);
   IO_v_SET_PIN_PUL (IO_f_PORT_FLI);
/*~-1*/
}
/*~E:F10*/
/*~E:A9*/
