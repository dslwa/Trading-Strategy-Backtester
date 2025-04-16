#ifndef STRATEGY_H
#define STRATEGY_H

#include <vector>
#include "Candle.h"

enum class TradeSignal {
    BUY,
    SELL,
    HOLD
};

class Strategy {
public:
    virtual TradeSignal generateSignal(const std::vector<Candle>& candles, size_t index) = 0;
    virtual ~Strategy() = default;
};

#endif