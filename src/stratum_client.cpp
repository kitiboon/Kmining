#include "stratum_client.h"
#include "logger.h"

StratumClient::StratumClient(std::string host, int port, std::string user, std::string pass)
    : host_(std::move(host)), port_(port), user_(std::move(user)), pass_(std::move(pass)), is_connected_(false) {}

bool StratumClient::connect() {
    g_logger.info("Attempting to connect to stratum pool at " + host_ + ":" + std::to_string(port_) + "...");
    if (!user_.empty()) {
        g_logger.info("Authenticating with user: " + user_);
    }
    // Mock connection
    is_connected_ = true;
    g_logger.info("Connected to stratum pool.");
    return is_connected_;
}

bool StratumClient::isConnected() const {
    return is_connected_;
}

void StratumClient::startListening() {
    if (!is_connected_) {
        g_logger.error("Cannot start listening, not connected.");
        return;
    }
    g_logger.info("Listening for mining jobs (mocking stratum protocol)...");
}

void StratumClient::receiveJobMock() {
    if (!is_connected_) return;
    g_logger.info("Stratum Client: Received new mining job.");
}

void StratumClient::submitShareMock() {
    if (!is_connected_) return;
    g_logger.info("Stratum Client: Valid share found! Submitting share...");
    g_logger.info("Stratum Client: Share accepted.");
}
