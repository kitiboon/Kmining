@echo off
setlocal EnableDelayedExpansion

:MENU
cls
echo ===============================================================================
echo                           Kmining Windows Control Panel
echo ===============================================================================
echo 1. Build Kmining
echo 2. Run Miner
echo 3. Run Benchmark
echo 4. Run Unit Tests
echo 5. Exit
echo ===============================================================================
set /p choice="Please select an option (1-5): "

if "%choice%"=="1" goto BUILD
if "%choice%"=="2" goto RUN
if "%choice%"=="3" goto BENCHMARK
if "%choice%"=="4" goto TEST
if "%choice%"=="5" goto END

echo Invalid choice. Please try again...
timeout /t 2 >nul
goto MENU

:BUILD
echo.
echo Checking for required tools...
where cmake >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] CMake not found. Please install CMake before continuing.
    echo You can install it via: winget install cmake
    pause
    goto MENU
)

echo Setting up and compiling Kmining...
if not exist "build" mkdir build
cd build
cmake ..
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] CMake configuration failed.
    cd ..
    pause
    goto MENU
)
cmake --build . --config Release
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] Compilation failed.
    cd ..
    pause
    goto MENU
)
cd ..
echo Kmining built successfully!
pause
goto MENU

:RUN
echo.
if not exist "build\Release\miner_engine.exe" (
    echo [ERROR] miner_engine.exe not found. Please build first!
    pause
    goto MENU
)
echo Starting miner...
.\build\Release\miner_engine.exe
pause
goto MENU

:BENCHMARK
echo.
if not exist "build\Release\miner_engine.exe" (
    echo [ERROR] miner_engine.exe not found. Please build first!
    pause
    goto MENU
)
echo Starting benchmark...
.\build\Release\miner_engine.exe --benchmark
pause
goto MENU

:TEST
echo.
if not exist "build\Release\run_tests.exe" (
    echo [WARNING] run_tests.exe not found. Attempting to build...
    if not exist "build" mkdir build
    cd build
    cmake ..
    cmake --build . --target run_tests --config Release
    cd ..
)

if not exist "build\Release\run_tests.exe" (
    echo [ERROR] Failed to build tests.
    pause
    goto MENU
)

echo Running test suite...
.\build\Release\run_tests.exe
pause
goto MENU

:END
exit /b 0