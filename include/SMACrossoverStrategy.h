#ifndef SMA_CROSSOVER_STRATEGY_H
#define SMA_CROSSOVER_STRATEGY_H

#include "Strategy.h"

class SMACrossoverStrategy : public Strategy {
public:
    SMACrossoverStrategy(size_t shortPeriod, size_t longPeriod);

    TradeSignal generateSignal(const std::vector<Candle>& candles, size_t index) override;

private:
    size_t shortPeriod;
    size_t longPeriod;
};

#endif