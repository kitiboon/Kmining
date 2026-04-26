#include <iostream>

extern void test_connect();
extern void test_runMiningKernelMock();

int main() {
    std::cout << "Running tests..." << std::endl;
    test_connect();
    test_runMiningKernelMock();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
