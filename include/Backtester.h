#ifndef BACKTESTER_H
#define BACKTESTER_H

#include <vector>
#include "Candle.h"
#include "Trade.h"
#include "Strategy.h"

class Backtester {
public:
    Backtester(const std::vector<Candle>& candles, Strategy* strategy, double initialCapital = 10000.0);

    void run();
    double getFinalCapital() const;
    const std::vector<Trade>& getTrades() const;
    void printStats() const;

private:
    std::vector<Candle> candles;
    std::vector<Trade> trades;
    Strategy* strategy;
    double capital;
    double positionSize;
    bool inPosition;
};

#endif