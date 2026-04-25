#include <iostream>
#include <string>
#include "stratum_client.h"
#include "kernel.h"
#include "logger.h"

int main(int argc, char* argv[]) {
    g_logger.info("Starting Kmining Miner Engine...");

    bool isBenchmark = false;
    if (argc > 1) {
        std::string arg = argv[1];
        if (arg == "--benchmark") {
            isBenchmark = true;
        }
    }

    if (isBenchmark) {
        // Run benchmark mode for 10 seconds to test maximum hashrate
        runBenchmarkMode(10);
    } else {
        // Initialize CUDA (Mocked)
        initCudaDevice();

        // Initialize Stratum Client
        StratumClient client("us1.ethermine.org", 4444); // Example pool

        if (client.connect()) {
            client.startListening();

            // Simulate a continuous mining loop
            MiningConfig config = {4096, 128, 4}; // Normal operation config
            int loopCount = 0;

            while (loopCount < 3) { // Run 3 cycles for demonstration purposes
                client.receiveJobMock();
                runMiningKernelMock(config);
                client.submitShareMock();
                loopCount++;
            }
        } else {
            g_logger.error("Failed to connect to pool.");
            return 1;
        }
    }

    g_logger.info("Miner shutting down.");
    return 0;
}
