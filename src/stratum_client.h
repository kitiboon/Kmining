#ifndef STRATUM_CLIENT_H
#define STRATUM_CLIENT_H

#include <string>

class StratumClient {
public:
    StratumClient(std::string host, int port, std::string user = "", std::string pass = "");
    bool connect();
    bool isConnected() const;
    void startListening();
    void receiveJobMock();
    void submitShareMock();

private:
    std::string host_;
    int port_;
    std::string user_;
    std::string pass_;
    bool is_connected_;
};

#endif // STRATUM_CLIENT_H
