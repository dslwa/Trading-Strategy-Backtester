#include "SMACrossoverStrategy.h"
#include "SMAIndicator.h"

SMACrossoverStrategy::SMACrossoverStrategy(size_t shortPeriod, size_t longPeriod)
    : shortPeriod(shortPeriod), longPeriod(longPeriod) {}

TradeSignal SMACrossoverStrategy::generateSignal(const std::vector<Candle>& candles, size_t index) {
    if (index < longPeriod) return TradeSignal::HOLD;

    double shortSMA = SMAIndicator::calculate(candles, index, shortPeriod);
    double longSMA = SMAIndicator::calculate(candles, index, longPeriod);

    double prevShortSMA = SMAIndicator::calculate(candles, index - 1, shortPeriod);
    double prevLongSMA = SMAIndicator::calculate(candles, index - 1, longPeriod);

    if (prevShortSMA < prevLongSMA && shortSMA > longSMA) {
        return TradeSignal::BUY;
    } else if (prevShortSMA > prevLongSMA && shortSMA < longSMA) {
        return TradeSignal::SELL;
    }

    return TradeSignal::HOLD;
}