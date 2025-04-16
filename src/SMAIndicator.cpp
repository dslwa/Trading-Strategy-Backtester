#include "SMAIndicator.h"

double SMAIndicator::calculate(const std::vector<Candle>& candles, size_t index, size_t period) {
    if (index + 1 < period) return 0.0;

    double sum = 0.0;
    for (size_t i = index + 1 - period; i <= index; ++i) {
        sum += candles[i].close;
    }
    return sum / period;
}