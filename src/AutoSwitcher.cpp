#include "AutoSwitcher.h"
#include "logger.h"
#include <cstdlib> // For rand()

AutoSwitcher::AutoSwitcher() {}

void AutoSwitcher::addAlgorithm(std::shared_ptr<IAlgorithm> algo) {
    if (algo) {
        algorithms_.push_back(algo);
        // Set the first added algorithm as default
        if (!activeAlgorithm_) {
            activeAlgorithm_ = algo;
        }
    }
}

void AutoSwitcher::start() {
    g_logger.info("Starting Auto-Switcher...");
    if (activeAlgorithm_) {
        g_logger.info("Initial algorithm set to: " + activeAlgorithm_->getName());
        activeAlgorithm_->init();
    } else {
        g_logger.warn("No algorithms added to Auto-Switcher.");
    }
}

std::shared_ptr<IAlgorithm> AutoSwitcher::getActiveAlgorithm() const {
    return activeAlgorithm_;
}

void AutoSwitcher::checkAndSwitch() {
    if (algorithms_.size() <= 1) return;

    g_logger.info("AutoSwitcher: Checking profitability...");

    // Mock profitability check: randomly decide if we should switch for demonstration
    // In a real scenario, this would poll an API or calculate estimated yields
    bool shouldSwitch = (std::rand() % 10) > 7; // 20% chance to switch

    if (shouldSwitch) {
        // Find a different algorithm to switch to
        for (const auto& algo : algorithms_) {
            if (algo != activeAlgorithm_) {
                g_logger.info("AutoSwitcher: Found more profitable algorithm -> " + algo->getName());

                // Switch logic
                g_logger.info("Stopping current algorithm: " + activeAlgorithm_->getName());
                activeAlgorithm_->cleanup();

                activeAlgorithm_ = algo;
                g_logger.info("Switching to new algorithm: " + activeAlgorithm_->getName());
                activeAlgorithm_->init();
                break; // Just switch to the first different one for this mock
            }
        }
    } else {
         g_logger.info("AutoSwitcher: Current algorithm is still the most profitable.");
    }
}
