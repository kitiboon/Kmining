#ifndef ALGOKAWPOW_H
#define ALGOKAWPOW_H

#include "IAlgorithm.h"

class AlgoKawPow : public IAlgorithm {
public:
    AlgoKawPow();
    ~AlgoKawPow() override;

    std::string getName() const override;
    void init() override;
    double hash() override;
    void cleanup() override;
};

#endif // ALGOKAWPOW_H
