/*~-1*/
/*~XSF_LANGUAGE: C/C++*/
/*~A:1*/
/*~+:Header*/
/*~T*/
/* SOURCE FILE    <Fldr.h>

 **************************************************************************
 *  PROJECT       <FlashLoader_AT644>
 *  MODULE        <Fldr>
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
#ifndef _H_FLDR_
 
/*~T*/
#define _H_FLDR_

/*~A:3*/
/*~+:Types*/
/*~T*/

/*~E:A3*/
/*~A:4*/
/*~+:Constants*/
/*~T*/
/* page size, in words */
#define FL_ui8_PAGESIZE 128
/*~E:A4*/
/*~A:5*/
/*~+:Variables*/
/*~T*/
/* page to write */
extern __no_init uint8_t FL_aui8_FlashPage [FL_ui8_PAGESIZE];

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
/* erase page */
extern void FL_v_Erase_Page (uint8_t ui8_Page);

/* load page */
extern void FL_v_Load_Page (void);

/* write page */
extern void FL_v_Write_Page (uint8_t ui8_Page);

/*~E:A8*/
/*~T*/

/*~-1*/
#endif
/*~E:I2*/
