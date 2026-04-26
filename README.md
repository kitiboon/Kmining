# Kmining

A custom cryptocurrency miner engine for NVIDIA GPUs (optimized for CMP 30HX / Turing architecture).

## Prerequisites

- **CMake** (3.10 or higher)
- **C++ Compiler**:
  - Linux: GCC or Clang (C++17 support required)
  - Windows: Visual Studio 2019 or 2022 (with "Desktop development with C++" workload)

## 🛠 Building the Project

### Linux / macOS

```bash
mkdir -p build
cd build
cmake ..
make
```

### Windows 11 (PowerShell / Command Prompt)

```powershell
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

## 🚀 How to Run (Usage)

### 1. Running the Miner
The miner will attempt to connect to the default pool (`us1.ethermine.org:4444`) and start the hashing process.

**Linux:**
```bash
./build/miner_engine
```

**Windows:**
```powershell
.\build\Release\miner_engine.exe
```

### 2. Expected Output
When you run the miner, you should see:
- CUDA device initialization (mocked for CMP 30HX).
- Connection attempt to the stratum pool.
- Successful connection message.
- Mining kernel execution with mock hashrate (~30 MH/s).

## 🧪 How to Test

We have implemented unit tests to ensure the stability of the connection logic.

### 1. Running the Automated Tests

**Linux:**
```bash
cd build
make run_tests
./run_tests
```

**Windows:**
```powershell
cd build
cmake --build . --target run_tests --config Release
.\Release\run_tests.exe
```

### 2. What is being tested?
The `run_tests` executable verifies:
- `isConnected()` returns `false` before connection.
- `connect()` returns `true` upon successful handshake.
- `isConnected()` returns `true` after connection.

### 3. Manual Verification (Optional)
To verify the tests catch real bugs:
1. Open `src/stratum_client.cpp`.
2. Change `is_connected_ = true;` to `is_connected_ = false;` in the `connect()` method.
3. Re-build and run the tests.
4. You should see an **Assertion Failure**, proving the test is working correctly.
