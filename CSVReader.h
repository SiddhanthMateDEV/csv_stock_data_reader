#ifndef CSVREADER_H
#define CSVREADER_H

#include "StockData.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>


class CSVReader{
    private:
        std::string filename;
    public:
        CSVReader(const std::string& filename) : filename(filename) {}

        std::vector<StockData> file_reader() {
            std::vector<StockData> stock_data;
            std::ifstream file(filename);

            if (!file.is_open()){
                throw std::runtime_error("Error opening the file");
            }

            // ignore the headers 
            std::string line;
            std::getline(file,line);

            while (std::getline(file,line)) {
                std::stringstream ss(line);
                StockData tick_info;

                std::getline(ss,tick_info.date,',');
                std::getline(ss,tick_info.time,',');
                std::getline(ss,tick_info.open,',');
                std::getline(ss,tick_info.high,',');
                std::getline(ss,tick_info.low,',');
                std::getline(ss,tick_info.close,',');
                std::getline(ss,tick_info.volume,',');
                std::getline(ss,tick_info.ticker,',');
                std::getline(ss,tick_info.datetime,',');

                stock_data.push_back(tick_info);
            }

            file.close();
            return stock_data;
        }

};

#endif