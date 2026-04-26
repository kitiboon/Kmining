#ifndef AUTOSWITCHER_H
#define AUTOSWITCHER_H

#include "IAlgorithm.h"
#include <memory>
#include <vector>

class AutoSwitcher {
public:
    AutoSwitcher();

    // Add supported algorithms
    void addAlgorithm(std::shared_ptr<IAlgorithm> algo);

    // Starts the switching logic
    void start();

    // Gets the currently active algorithm
    std::shared_ptr<IAlgorithm> getActiveAlgorithm() const;

    // Checks for profitability and switches if necessary
    void checkAndSwitch();

private:
    std::vector<std::shared_ptr<IAlgorithm>> algorithms_;
    std::shared_ptr<IAlgorithm> activeAlgorithm_;
};

#endif // AUTOSWITCHER_H
