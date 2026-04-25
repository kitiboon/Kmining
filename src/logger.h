#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <mutex>

class Logger {
public:
    Logger(const std::string& filename = "miner.log");
    ~Logger();

    void info(const std::string& message);
    void warn(const std::string& message);
    void error(const std::string& message);
    void debug(const std::string& message);

private:
    void log(const std::string& level, const std::string& message);
    std::string getCurrentTime();

    std::ofstream logFile_;
    std::mutex mutex_;
};

// Global logger instance declaration
extern Logger g_logger;

#endif // LOGGER_H
