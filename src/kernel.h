#ifndef KERNEL_H
#define KERNEL_H

// Wrapper functions for CUDA kernels to allow C++ code to interact with them
void initCudaDevice();

// Configuration for mining
struct MiningConfig {
    int gridSize;
    int blockSize;
    int unrollFactor;
};

void runMiningKernelMock();
void runMiningKernelMock(const MiningConfig& config);
void runBenchmarkMode(int durationSeconds);

#endif // KERNEL_H
