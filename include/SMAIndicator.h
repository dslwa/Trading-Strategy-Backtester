#ifndef SMA_INDICATOR_H
#define SMA_INDICATOR_H

#include <vector>
#include "Candle.h"

class SMAIndicator {
public:
    static double calculate(const std::vector<Candle>& candles, size_t index, size_t period);
};

#endif