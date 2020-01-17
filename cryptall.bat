@echo=off

set inpfile=tests\sample_x86.exe
set outfile=tests\sample_x86.exe
set stubs=stubs

for /f "tokens=*" %%s in ('dir %stubs% /a:d /b') do (
python "programs\\cryptor.py"^
 --data-compress^
 --data-base64^
 --loader1-dir "%stubs%\%%s"^
 "%inpfile%"^
 "%outfile%.%%s"
)