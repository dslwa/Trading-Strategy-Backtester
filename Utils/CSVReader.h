#pragma once
#include <string>
#include <vector>
#include "../include/Candle.h"

class CSVReader {
public:
    static std::vector<Candle> loadCandles(const std::string& filename);
};