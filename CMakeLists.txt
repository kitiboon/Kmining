cmake_minimum_required(VERSION 3.10)
project(MinerEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# We are stubbing out CUDA compilation for the sandbox environment
# as nvcc is not available. We will compile .cu files as C++ for now
# just to verify the structure and syntax.
set_source_files_properties(src/kernel.cu PROPERTIES LANGUAGE CXX)
set_source_files_properties(src/kernel.cu PROPERTIES COMPILE_FLAGS "-x c++")

add_executable(miner_engine
    src/main.cpp
    src/stratum_client.cpp
    src/kernel.cu
    src/logger.cpp
    src/AlgoEtchash.cpp
    src/AlgoKawPow.cpp
    src/AutoSwitcher.cpp
    src/WebServer.cpp
)

add_executable(run_tests
    tests/test_main.cpp
    tests/test_stratum_client.cpp
    tests/test_kernel.cpp
    src/stratum_client.cpp
    src/kernel.cu
    src/logger.cpp
)
