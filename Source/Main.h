/*~-1*/
/*~XSF_LANGUAGE: C/C++*/
/*~A:1*/
/*~+:Header*/
/*~T*/
/* SOURCE FILE    <Main.h>

 **************************************************************************
 *  PROJECT       <FlashLoader_AT644>
 *  MODULE        <Main>
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
 *  Rev 1.0   May 01 2021    CrZa
 *  Initial revision.
 *
 *************************************************************************/



/*~E:A1*/
/*~I:2*/
#ifndef _H_MAIN_
 
/*~T*/
#define _H_MAIN_

/*~A:3*/
/*~+:Types*/
/*~T*/

/*~E:A3*/
/*~A:4*/
/*~+:Constants*/
/*~T*/
/* number of pages to write (63kB), leaves 4 pages (1kB) for flashloader */
#define MA_ui16_PAGES_TO_WRITE  (uint16_t)252

/* size of a page in bytes */
#define MA_ui16_PAGE_SIZE       (uint16_t)256

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
/*~-1*/
#endif
/*~E:I2*/
