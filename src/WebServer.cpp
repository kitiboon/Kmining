#include "WebServer.h"
#include "logger.h"

WebServer::WebServer(int port) : port_(port), currentHashrate_(0.0) {}

WebServer::~WebServer() {
    g_logger.info("WebServer shutting down.");
}

void WebServer::start() {
    g_logger.info("Starting lightweight Web Dashboard on http://localhost:" + std::to_string(port_));
    // Mocking server start
    g_logger.info("WebServer running (mocked).");
}

void WebServer::updateStats(const std::string& activeAlgo, double hashrate, const std::string& wallet) {
    activeAlgo_ = activeAlgo;
    currentHashrate_ = hashrate;
    wallet_ = wallet;

    // In a real implementation, this would update shared state that the HTTP server thread reads
    g_logger.debug("WebStats Updated -> Algo: " + activeAlgo_ +
                   " | Hashrate: " + std::to_string(currentHashrate_) + " MH/s" +
                   " | Wallet: " + wallet_);
}
