#ifndef TRADE_H
#define TRADE_H

#include <string>

enum class TradeType {
    BUY,
    SELL
};

struct Trade {
    std::string timestamp;
    TradeType type;
    double price;
};

#endif