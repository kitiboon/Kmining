#ifndef STRATUM_CLIENT_H
#define STRATUM_CLIENT_H

#include <string>

class StratumClient {
public:
    StratumClient(std::string host, int port);
    bool connect();
    void startListening();

private:
    std::string host_;
    int port_;
    bool is_connected_;
};

#endif // STRATUM_CLIENT_H
