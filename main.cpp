#include "CSVReader.h"
#include "Backtester.h"
#include "SMACrossoverStrategy.h"

#include <iostream>

int main() {
    auto candles = CSVReader::loadCandles("Data/EURUSD.csv");

    SMACrossoverStrategy strategy(20, 10);
    Backtester backtester(candles, &strategy);
    backtester.run();

    std::cout << "Końcowy kapitał: " << backtester.getFinalCapital() << "\n";
    backtester.printStats();
    
    return 0;
}