# Kmining

Kmining คือ Custom Cryptocurrency Miner Engine ที่เขียนด้วยภาษา C++ และ CUDA สำหรับ NVIDIA CMP 30HX GPU (Turing architecture) โดยเฉพาะ ตัวโปรแกรมรองรับ Multi-Algorithm, ระบบสลับการขุดอัตโนมัติตามความคุ้มค่า (Profitability Auto-Switching) และ Local Web Dashboard

## วิธีการใช้งานเบื้องต้น (How to Use)

### การคอมไพล์ (Build Instructions)
โปรแกรมนี้ใช้ CMake เป็น Build System และต้องการ C++17

**สำหรับ Linux:**
```bash
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make
```

**สำหรับ Windows 11 (ใช้ MSVC):**
```powershell
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

*หมายเหตุ: ในสภาวะแวดล้อมที่ไม่มี `nvcc` หรือ GPU สำหรับคอมไพล์ CUDA โค้ดจะถูกตั้งค่าให้คอมไพล์แบบ C++ จำลอง (Mocked) ไปก่อน*

### การรันโปรแกรม (Execution)
**บน Linux:**
```bash
./build/miner_engine
```

**บน Windows:**
```powershell
.\build\Release\miner_engine.exe
```

**Flags ที่รองรับ:**
- `--host` (ค่าเริ่มต้น: us1.ethermine.org)
- `--port` (ค่าเริ่มต้น: 4444)
- `--benchmark` (สำหรับรันจำลองทดสอบ Hashrate)
- `--help` (แสดงวิธีใช้)

โปรแกรมตั้งเป้าหมายไปที่พูล Unmineable สำหรับการรับผลตอบแทนเป็นเหรียญ BONK รูปแบบ username ของ stratum ต้องเป็น `BONK:WalletAddress.WorkerName`

### การทดสอบ (Testing)
โปรแกรมใช้ C++ Assertions มาตรฐานเพื่อหลีกเลี่ยงการใช้ Library ภายนอก (เนื่องจากข้อจำกัดเรื่องการเข้าถึงอินเทอร์เน็ตในการตั้งค่าระบบ)

**รันเทสต์บน Linux:**
```bash
cd build
make run_tests
./run_tests
```

**รันเทสต์บน Windows:**
```powershell
cmake --build . --target run_tests --config Release
.\build\Release\run_tests.exe
```
