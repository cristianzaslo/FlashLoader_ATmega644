SET COMPILER=C:\IARSystems\avr\bin\iccavr.exe
SET ASSEMBLER=C:\IARSystems\avr\bin\aavr.exe
SET LINKER=C:\IARSystems\avr\bin\xlink.exe
SET LINTER=C:\Lint\lint-nt.exe
SET SOURCE_FILES=D:\Projects\FlashLoader_AT644\Source\

SET LINKER_FILE=D:\Projects\FlashLoader_AT644\Link\lnkm644s.xcl
SET LINTER_FILE=D:\Projects\FlashLoader_AT644\Lint\iar_atmega16.lnt
SET INCLUDE_1=C:\IARSystems\avr\inc\
SET INCLUDE_2=D:\Projects\FlashLoader_AT644\Source\
SET OUT=D:\Projects\FlashLoader_AT644\Out\

SETLOCAL enabledelayedexpansion

DEL /Q %OUT%*.*

FOR %%F in (%SOURCE_FILES%*.c) DO %COMPILER% %%F -I%INCLUDE_1% -I%INCLUDE_2%  -lA %OUT% -lC %OUT% -o %OUT% -e -s3 --cpu=m16 --memory_model=small --eeprom_size=2048 --initializers_in_flash

FOR %%F in (%SOURCE_FILES%*.s90) DO %ASSEMBLER% %%F -I%INCLUDE_1% -I%INCLUDE_2% -L%OUT% -O%OUT% -v3 -u_enhancedCore


SET LINK_FILES=C:\IARSystems\avr\lib\dl3s-sf.r90
FOR %%F IN (%OUT%*.r90) DO SET LINK_FILES=!LINK_FILES! %%F

%LINKER% %LINK_FILES% -f %LINKER_FILE% -J2,sum -FINTEL-STANDARD -l %OUT%out.map -xs -o %OUT%flat644.hex

rem PAUSE 0

FOR %%F in (%SOURCE_FILES%*.c) do %LINTER% +v -u %LINTER_FILE% %%F > %OUT%%%~nF.lint

rem FOR %%F in (%SOURCE_FILES%*.c) do %LINTER% +v -u %LINTER_FILE% %%~nF > %OUT%%%~nF.lint

ENDLOCAL



