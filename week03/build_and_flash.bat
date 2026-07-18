@echo off
setlocal

echo STEP 1: CLEANING BUILD DIRECTORY

if exist build (
    echo Deleting existing build folder...
    rmdir /s /q build

    if errorlevel 1 (
        echo Failed to delete build folder!
        pause
        exit /b 1
    )
)

echo.
echo STEP 2: CONFIGURING PROJECT WITH CMAKE

cmake -B build -G Ninja

if errorlevel 1 (
    echo Configuration failed!
    pause
    exit /b 1
)

echo.
echo STEP 3: COMPILING FIRMWARE WITH NINJA

ninja -C build

if errorlevel 1 (
    echo Build failed!
    pause
    exit /b 1
)

if not exist build\app_firmware.bin (
    echo Firmware file was not generated!
    pause
    exit /b 1
)

echo.
echo STEP 4: FLASHING FIRMWARE TO TARGET MCU

STM32_Programmer_CLI -c port=SWD -w build\app_firmware.bin 0x08000000 -v -rst

if errorlevel 1 (
    echo Flashing failed!
    pause
    exit /b 1
)

echo.
echo BUILD AND FLASH COMPLETED SUCCESSFULLY!
pause
exit /b 0