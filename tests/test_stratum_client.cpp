#include "../src/stratum_client.h"
#include <cassert>
#include <iostream>

void test_connect() {
    StratumClient client("localhost", 4444, "BONK:Wallet.Worker", "x");

    // Initial state
    assert(!client.isConnected());

    // Connect
    bool result = client.connect();

    // Final state
    assert(result == true);
    assert(client.isConnected() == true);

    std::cout << "test_connect passed!" << std::endl;
}
