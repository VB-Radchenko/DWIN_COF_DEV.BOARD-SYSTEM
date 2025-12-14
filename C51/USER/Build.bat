cd ..\OBJ
srec_cat.exe T5L51.hex -Intel -o T5L51.bin -Binary 
echo.
copy "T5L51.bin" ..\..\GUI\DWIN_SET
copy "T5L51.bin" J:\DWIN_SET