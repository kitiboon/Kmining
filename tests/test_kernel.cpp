#include "../src/kernel.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>

void test_runMiningKernelMock() {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    runMiningKernelMock();

    std::cout.rdbuf(old);

    std::string output = buffer.str();
    assert(output.find("Running mining kernel on GPU (mock)...") != std::string::npos);
    assert(output.find("Hashing... (mock hashrate ~30 MH/s)") != std::string::npos);

    std::cout << "test_runMiningKernelMock passed!" << std::endl;
}
