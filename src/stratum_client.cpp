#include "stratum_client.h"
#include <iostream>
#include <utility>

StratumClient::StratumClient(std::string host, int port)
    : host_(std::move(host)), port_(port), is_connected_(false) {}

bool StratumClient::connect() {
    std::cout << "Attempting to connect to stratum pool at " << host_ << ":" << port_ << "..." << std::endl;
    // Mock connection
    is_connected_ = true;
    std::cout << "Connected to stratum pool." << std::endl;
    return is_connected_;
}

void StratumClient::startListening() {
    if (!is_connected_) {
        std::cout << "Cannot start listening, not connected." << std::endl;
        return;
    }
    std::cout << "Listening for mining jobs (mocking stratum protocol)..." << std::endl;
}
