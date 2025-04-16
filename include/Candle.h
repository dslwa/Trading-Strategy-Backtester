#ifndef CANDLE_H
#define CANDLE_H

#include <string>

class Candle {
public:
    std::string timestamp;
    double open;
    double high;
    double low;
    double close;

    Candle() = default;

    Candle(const std::string& timestamp, double open, double high, double low, double close);
};

#endif