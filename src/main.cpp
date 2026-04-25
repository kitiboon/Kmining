#include <iostream>
#include <string>
#include "stratum_client.h"
#include "kernel.h"

void printUsage(const char* name) {
    std::cout << "Usage: " << name << " [options]\n"
              << "Options:\n"
              << "  --host <host>       Stratum pool host (default: us1.ethermine.org)\n"
              << "  --port <port>       Stratum pool port (default: 4444)\n"
              << "  --benchmark         Run a simulated test for maximum hashrate\n"
              << "  --help              Show this help message" << std::endl;
}

int main(int argc, char* argv[]) {
    std::string host = "us1.ethermine.org";
    int port = 4444;
    bool benchmark = false;

    try {
        for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];
            if (arg == "--host" && i + 1 < argc) {
                host = argv[++i];
            } else if (arg == "--port" && i + 1 < argc) {
                port = std::stoi(argv[++i]);
            } else if (arg == "--benchmark") {
                benchmark = true;
            } else if (arg == "--help") {
                printUsage(argv[0]);
                return 0;
            } else {
                std::cerr << "Unknown argument: " << arg << std::endl;
                printUsage(argv[0]);
                return 1;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error parsing arguments: " << e.what() << std::endl;
        printUsage(argv[0]);
        return 1;
    }

    if (benchmark) {
        std::cout << "Running benchmark..." << std::endl;
        initCudaDevice();
        runMiningKernelMock();
        return 0;
    }

    std::cout << "Starting Kmining Miner Engine..." << std::endl;

    // Initialize CUDA (Mocked)
    initCudaDevice();

    // Initialize Stratum Client
    StratumClient client(host, port);

    if (client.connect()) {
        client.startListening();

        // Start the hashing process (Mocked)
        runMiningKernelMock();
    } else {
        std::cerr << "Failed to connect to pool." << std::endl;
        return 1;
    }

    std::cout << "Miner shutting down." << std::endl;
    return 0;
}
