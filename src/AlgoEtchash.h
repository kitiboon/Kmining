#ifndef ALGOETCHASH_H
#define ALGOETCHASH_H

#include "IAlgorithm.h"

class AlgoEtchash : public IAlgorithm {
public:
    AlgoEtchash();
    ~AlgoEtchash() override;

    std::string getName() const override;
    void init() override;
    double hash() override;
    void cleanup() override;
};

#endif // ALGOETCHASH_H
