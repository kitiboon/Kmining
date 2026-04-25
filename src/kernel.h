#ifndef KERNEL_H
#define KERNEL_H

// Wrapper functions for CUDA kernels to allow C++ code to interact with them
void initCudaDevice();
void runMiningKernelMock();

#endif // KERNEL_H
