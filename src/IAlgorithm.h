#ifndef IALGORITHM_H
#define IALGORITHM_H

#include <string>

class IAlgorithm {
public:
    virtual ~IAlgorithm() = default;

    // Returns the name of the algorithm (e.g., "Etchash", "KawPow")
    virtual std::string getName() const = 0;

    // Performs the mining initialization/memory setup (e.g., DAG generation)
    virtual void init() = 0;

    // Runs a single mining iteration (mocked) and returns simulated hashrate
    virtual double hash() = 0;

    // Cleans up any resources
    virtual void cleanup() = 0;
};

#endif // IALGORITHM_H
