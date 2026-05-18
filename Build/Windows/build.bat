@echo off
setlocal

cmake -B build -G Ninja
if %errorlevel% neq 0 exit /b %errorlevel%

cmake --build build
if %errorlevel% neq 0 exit /b %errorlevel%

endlocal
