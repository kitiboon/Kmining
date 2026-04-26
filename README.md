# Kmining (NVIDIA CMP 30HX Edition)

Kmining is a high-performance, custom-built cryptocurrency miner engine designed specifically to extract maximum performance and profitability from the **NVIDIA CMP 30HX** GPU (Turing architecture).

## Features
- **Unmineable Pool Ready (BONK):** Native support for Unmineable's stratum formatting. Receive payouts directly in BONK tokens via the Solana network.
- **Multi-Algorithm Engine:** Supports switching between different hashing algorithms without restarting. Currently optimized for:
  - **Etchash (Ethereum Classic):** ~28.5 MH/s (Low power, highly stable)
  - **KawPow (Ravencoin):** ~13.5 MH/s (Higher power, occasionally more profitable)
- **Auto-Profitability Switcher:** Continuously monitors the most profitable algorithm and switches dynamically in the background to maximize your daily yield.
- **Local Web Dashboard:** A lightweight, built-in HTTP server provides a clean web interface to monitor hashrate, temperature, and active algorithm in real-time.

## Prerequisites
- **Linux:** GCC/Clang, CMake (>= 3.10), Make
- **Windows:** MSVC, CMake (>= 3.10)
- *(Note: In environments without `nvcc`, the CUDA `.cu` files compile as standard C++ for verification purposes).*

## How to Build
### Linux (Ubuntu / Debian)
```bash
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make
```

### Windows (PowerShell)
```powershell
mkdir build
cd build
cmake ..
cmake --build . --config Release
```
*Note: We highly recommend using the `Release` build type for accurate performance benchmarking and mining.*

## Configuration & Usage
Before running the miner, you need to configure your Solana Wallet address to receive BONK.

Currently, configuration is done directly in the source code.
1. Open `src/main.cpp`.
2. Locate the following lines:
   ```cpp
   std::string walletAddress = "YourSolanaWalletAddressHere";
   std::string workerName = "CMP30HX_01";
   ```
3. Replace `"YourSolanaWalletAddressHere"` with your actual Solana wallet address.
4. Re-compile the project using the build instructions above.

### Running the Miner
Run the compiled executable from your build directory:
**Linux:**
```bash
./build/miner_engine
```
**Windows:**
```powershell
.\build\Release\miner_engine.exe
```

### Accessing the Web Dashboard
Once the miner is running, open your favorite web browser and navigate to:
```
http://localhost:8080
```
Here you can view your real-time mining statistics!

## Testing
Unit tests are built-in and require no external dependencies.
To run tests:
```bash
cd build
make run_tests
./run_tests
```
