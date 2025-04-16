#include "CSVReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Candle> CSVReader::loadCandles(const std::string& filePath){
    std::vector<Candle> candles;
    std::ifstream file(filePath);
    if(!file.is_open()){
        std::cerr << "Error! cannot open file";
        return candles;
    }

    std::string line;
    bool firstLine = true;

    while(std::getline(file, line)){
        if(firstLine){
            firstLine = false;
            continue;
        }

        std::stringstream ss(line);
        std::string token;
        Candle candle;

        try {
            // timestamp
            std::getline(ss, token, ',');
            candle.timestamp = token;

            // open
            std::getline(ss, token, ',');
            candle.open = std::stod(token);

            // high
            std::getline(ss, token, ',');
            candle.high = std::stod(token);

            // low
            std::getline(ss, token, ',');
            candle.low = std::stod(token);

            // close
            std::getline(ss, token, ',');
            candle.close = std::stod(token);

            candles.push_back(candle);
        } catch (const std::exception& e) {
            std::cerr << "Error: " << line << "\n" << e.what() << std::endl;
        }
    }

    file.close();
    return candles;

}