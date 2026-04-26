#include <iostream>
#include <string>
#include <memory>
#include "stratum_client.h"
#include "kernel.h"
#include "logger.h"
#include "AlgoEtchash.h"
#include "AlgoKawPow.h"
#include "AutoSwitcher.h"
#include "WebServer.h"

int main(int argc, char* argv[]) {
    g_logger.info("Starting Kmining Miner Engine with Multi-Algo & Unmineable Support...");

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

        // Settings for Unmineable BONK payout
        std::string poolHost = "etchash.unmineable.com";
        int poolPort = 3333;
        std::string walletAddress = "YourSolanaWalletAddressHere";
        std::string workerName = "CMP30HX_01";
        std::string stratumUser = "BONK:" + walletAddress + "." + workerName;
        std::string stratumPass = "x";

        // Initialize Stratum Client
        StratumClient client(poolHost, poolPort, stratumUser, stratumPass);

        // Initialize Web Dashboard
        WebServer webServer(8080);
        webServer.start();

        // Initialize Auto-Switcher and Algorithms
        AutoSwitcher switcher;
        switcher.addAlgorithm(std::make_shared<AlgoEtchash>());
        switcher.addAlgorithm(std::make_shared<AlgoKawPow>());
        switcher.start();

        if (client.connect()) {
            client.startListening();

            int loopCount = 0;
            // Simulate a continuous mining loop (running 5 cycles for demo)
            while (loopCount < 5) {
                // Periodically check if we should switch algorithms for better profit
                switcher.checkAndSwitch();

                auto activeAlgo = switcher.getActiveAlgorithm();

                client.receiveJobMock();

                // Hash with the currently active algorithm
                double currentHashrate = activeAlgo->hash();

                // Update Dashboard stats
                webServer.updateStats(activeAlgo->getName(), currentHashrate, walletAddress);

                client.submitShareMock();
                loopCount++;
            }

            // Cleanup on exit
            if (switcher.getActiveAlgorithm()) {
                switcher.getActiveAlgorithm()->cleanup();
            }

        } else {
            g_logger.error("Failed to connect to pool.");
            return 1;
        }
    }

    g_logger.info("Miner shutting down.");
    return 0;
}
