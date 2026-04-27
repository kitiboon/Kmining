@echo off
echo 🚀 กำลังตั้งค่าและคอมไพล์ Kmining...
mkdir build 2>nul
cd build
cmake ..
cmake --build . --config Release

echo ✅ คอมไพล์เสร็จสิ้น กำลังเริ่มรัน Kmining...
.\Release\miner_engine.exe %*
