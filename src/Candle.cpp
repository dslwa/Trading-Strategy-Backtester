#include "Candle.h"

Candle::Candle(const std::string& timestamp, double open, double high, double low, double close)
    : timestamp(timestamp), open(open), high(high), low(low), close(close) {}