# Kmining

A custom cryptocurrency miner engine for NVIDIA GPUs.

## Prerequisites

- **CMake** (3.10 or higher)
- **C++ Compiler**:
  - Linux: GCC or Clang (C++17 support required)
  - Windows: Visual Studio 2019 or 2022 (with "Desktop development with C++" workload)

## Building the Project

The project uses CMake, which supports multiple platforms.

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

## Running the Miner

### Linux

```bash
./build/miner_engine
```

### Windows

```powershell
.\build\Release\miner_engine.exe
```

## Running Tests

### Linux

```bash
cd build
make run_tests
./run_tests
```

### Windows

```powershell
cd build
cmake --build . --target run_tests --config Release
.\Release\run_tests.exe
```

The tests verify the `StratumClient` connection logic and state management.
