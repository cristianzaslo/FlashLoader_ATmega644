***** Flashloader for ATMEAGA 644 microcontroller *****

Development toolchain:
---------------------
-> Compiler/Assembler:  IAR Atmel AVR v2.28A/WIN
-> Code editor:         X32 v3.0

Programming toolchain:
---------------------
-> target with ATMEGA 644 ucontroller
-> serial programmer to write the flashloader
-> RS232-TTL converter (e.g. http://picprojects.org.uk/projects/simpleSIO/ssio.htm)
-> Windows 7/10 environment
-> FlashTool_AT644 or a equivalent programming tool to write the main application

Installation:
------------
-> program the flashloader (flat644.hex) using a JATG interface or serial programmer (e.g. Atmel-ICE)
-> connect PD2 to GND; this step activates the flashloader upon reset 
-> connect PDO (RXD0), PD1 (TXD0) and GND pins to RS232-TTL converter
-> connect RS232-TTL converter to host PC
-> run FlashTool_AT644 application and select the *.hex file application to download
-> reset the the target; an 0x55 char will be sent by target and upon reception the download sequence is automatically started

Data exchange sequence diagram:
----------------------

TARGET (AVR)           HOST (PC)

                       Init
Reset
0x55           ->      Read
Read           <-      0x55, Cheksum_Low, Checksum_High  
0x55           ->      Read
Read           <-      Page_N (repeat with N=0..251)
N              ->      Read   (repeat with N=0..251)
Check prog          
0x55           ->      Read
Close                  Close 

Remark: in case of communication error or incorrect checksum an 0xAA char is sent to host and download sequence is aborted      


 