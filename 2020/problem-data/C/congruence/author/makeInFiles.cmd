@ECHO OFF
set /a count=0
SETLOCAL enabledelayedexpansion
FOR /F "eol=; tokens=1,2,3 delims= " %%i IN (congruence_inp.txt) DO (
 set /a count+=1
 set No=0!count!
 makeTest %%i %%j %%k > tests\congruence.!No:~-2!.in
)
ECHO Done.