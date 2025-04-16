#include "Backtester.h"
#include <iostream>
#include <iomanip>

Backtester::Backtester(const std::vector<Candle>& candles, Strategy* strategy, double initialCapital)
    : candles(candles), strategy(strategy), capital(initialCapital), positionSize(0.0), inPosition(false) {}


    void Backtester::printStats() const {
        int totalTrades = 0;
        int winningTrades = 0;
    
        for (size_t i = 1; i < trades.size(); i += 2) { // i = SELL, i-1 = BUY
            if (trades[i - 1].type == TradeType::BUY && trades[i].type == TradeType::SELL) {
                ++totalTrades;
                if (trades[i].price > trades[i - 1].price) {
                    ++winningTrades;
                }
            }
        }
    
        double winRate = totalTrades > 0 ? (double)winningTrades / totalTrades * 100.0 : 0.0;
    
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Liczba zakończonych transakcji: " << totalTrades << "\n";
        std::cout << "Liczba wygranych transakcji:    " << winningTrades << "\n";
        std::cout << "Win rate:                       " << winRate << " %\n";
    }

void Backtester::run() {
    for (size_t i = 0; i < candles.size(); ++i) {
        auto signal = strategy->generateSignal(candles, i);
        
        std::cout << "Index: " << i << ", Signal: ";
        if (signal == TradeSignal::BUY) {std::cout << "BUY";}
        else if (signal == TradeSignal::SELL){ std::cout << "SELL";}
        else {std::cout << "HOLD";}
        std::cout << ", Price: " << candles[i].close << std::endl;

        if (signal == TradeSignal::BUY && !inPosition) {
            positionSize = capital / candles[i].close;
            trades.push_back(Trade{candles[i].timestamp, TradeType::BUY, candles[i].close});
            inPosition = true;
        } else if (signal == TradeSignal::SELL && inPosition) {
            capital = positionSize * candles[i].close;
            trades.push_back(Trade{candles[i].timestamp, TradeType::SELL, candles[i].close});
            positionSize = 0.0;
            inPosition = false;
        }
    }

    if (inPosition && !candles.empty()) {
        capital = positionSize * candles.back().close;
    }
}

double Backtester::getFinalCapital() const {
    return capital;
}

const std::vector<Trade>& Backtester::getTrades() const {
    return trades;
}