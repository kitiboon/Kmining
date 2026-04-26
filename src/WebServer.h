#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <string>

class WebServer {
public:
    WebServer(int port);
    ~WebServer();

    void start();
    void updateStats(const std::string& activeAlgo, double hashrate, const std::string& wallet);

private:
    int port_;
    std::string activeAlgo_;
    double currentHashrate_;
    std::string wallet_;
    // In a real implementation, we would have socket descriptors and a thread here
};

#endif // WEBSERVER_H
