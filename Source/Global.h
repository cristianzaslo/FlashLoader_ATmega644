/*~-1*/
/*~XSF_LANGUAGE: C/C++*/
/*~A:1*/
/*~+:Header*/
/*~T*/
/* SOURCE FILE    <Global.h>

 **************************************************************************
 *  PROJECT       <FlashLoader_AT644>
 *  MODULE        <Global>
 *  RESPONSIBLE   <Cristian Zaslo>
 **************************************************************************
 *  PURPOSE:      Exported data and functions
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
 *  Rev 1.0   Mar 01 2021    CrZa
 *  Initial revision.
 *
 *************************************************************************/



/*~E:A1*/
/*~I:2*/
#ifndef _H_GLOBAL_
 
/*~T*/
#define _H_GLOBAL_

/*~A:3*/
/*~+:Types*/
/*~T*/
/* fundamental types */
typedef unsigned char        bool_t;
typedef char                 char_t;
typedef unsigned char       uint8_t;
typedef signed char         sint8_t;
typedef unsigned short int uint16_t;
typedef signed short int   sint16_t;
typedef unsigned long int  uint32_t;
typedef signed long int    sint32_t;

/*~E:A3*/
/*~A:4*/
/*~+:Constants*/
/*~T*/
/* fundamental constants */
#define FALSE (uint8_t)0
#define TRUE  (uint8_t)1

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
/* bit masks */
#define BIT_0  (uint8_t)0x0001
#define BIT_1  (uint8_t)0x0002
#define BIT_2  (uint8_t)0x0004
#define BIT_3  (uint8_t)0x0008
#define BIT_4  (uint8_t)0x0010
#define BIT_5  (uint8_t)0x0020
#define BIT_6  (uint8_t)0x0040
#define BIT_7  (uint8_t)0x0080

#define BIT_8  (uint16_t)0x0100
#define BIT_9  (uint16_t)0x0200
#define BIT_10 (uint16_t)0x0400
#define BIT_11 (uint16_t)0x0800

/*~E:A7*/
/*~A:8*/
/*~+:Function prototypes*/
/*~T*/
/* module initialization */
extern void GL_v_Init (void);
/*~E:A8*/
/*~T*/

/*~-1*/
#endif
/*~E:I2*/
