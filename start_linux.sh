#!/bin/bash

echo "🚀 กำลังตั้งค่าและคอมไพล์ Kmining..."
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make

echo "✅ คอมไพล์เสร็จสิ้น กำลังเริ่มรัน Kmining..."
./miner_engine "$@"
