@echo off
chcp 65001 >nul
setlocal EnableDelayedExpansion

:MENU
cls
echo ===============================================================================
echo                           Kmining Windows Control Panel
echo ===============================================================================
echo 1. Build Kmining (สร้างตัวรัน)
echo 2. Run Miner (เริ่มขุด)
echo 3. Run Benchmark (ทดสอบประสิทธิภาพ)
echo 4. Run Unit Tests (ทดสอบระบบ)
echo 5. Exit (ออก)
echo ===============================================================================
set /p choice="กรุณาเลือกเมนู (1-5): "

if "%choice%"=="1" goto BUILD
if "%choice%"=="2" goto RUN
if "%choice%"=="3" goto BENCHMARK
if "%choice%"=="4" goto TEST
if "%choice%"=="5" goto END

echo ไม่พบเมนูที่เลือก กรุณาลองใหม่...
timeout /t 2 >nul
goto MENU

:BUILD
echo.
echo กำลังตรวจสอบเครื่องมือที่จำเป็น...
where cmake >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] ไม่พบ CMake กรุณาติดตั้ง CMake ก่อนดำเนินการต่อ
    echo คุณสามารถติดตั้งผ่านคำสั่ง: winget install cmake
    pause
    goto MENU
)

echo 🚀 กำลังตั้งค่าและคอมไพล์ Kmining...
if not exist "build" mkdir build
cd build
cmake ..
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] การตั้งค่า CMake ล้มเหลว
    cd ..
    pause
    goto MENU
)
cmake --build . --config Release
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] การคอมไพล์ล้มเหลว
    cd ..
    pause
    goto MENU
)
cd ..
echo ✅ สร้าง Kmining สำเร็จ!
pause
goto MENU

:RUN
echo.
if not exist "build\Release\miner_engine.exe" (
    echo [ERROR] ไม่พบไฟล์ miner_engine.exe กรุณา Build ก่อน!
    pause
    goto MENU
)
echo เริ่มต้นขุด...
.\build\Release\miner_engine.exe
pause
goto MENU

:BENCHMARK
echo.
if not exist "build\Release\miner_engine.exe" (
    echo [ERROR] ไม่พบไฟล์ miner_engine.exe กรุณา Build ก่อน!
    pause
    goto MENU
)
echo เริ่มต้นทดสอบประสิทธิภาพ...
.\build\Release\miner_engine.exe --benchmark
pause
goto MENU

:TEST
echo.
if not exist "build\Release\run_tests.exe" (
    echo [ERROR] ไม่พบไฟล์ทดสอบระบบ (run_tests.exe) กำลังพยายามสร้าง...
    if not exist "build" mkdir build
    cd build
    cmake ..
    cmake --build . --target run_tests --config Release
    cd ..
)

if not exist "build\Release\run_tests.exe" (
    echo [ERROR] สร้างไฟล์ทดสอบไม่สำเร็จ กรุณาตรวจสอบโค้ด
    pause
    goto MENU
)

echo เริ่มรันระบบทดสอบ...
.\build\Release\run_tests.exe
pause
goto MENU

:END
exit /b 0