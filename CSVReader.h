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
                
                // getline will fail when used with other than string types
                // std::getline(ss,tick_info.open,',');
                // std::getline(ss,tick_info.high,',');
                // std::getline(ss,tick_info.low,',');
                // std::getline(ss,tick_info.close,',');
                // std::getline(ss,tick_info.volume,',');
                // std::getline(ss,tick_info.ticker,',');

                std::string open_,close_,high_,low_,volume;

                try {
                    // load it into a str variable
                    std::getline(ss,open_,',');
                    std::getline(ss,high_,',');
                    std::getline(ss,low_,',');
                    std::getline(ss,close_,',');

                    // use the stod method to convert the string to a double for the struct type
                    tick_info.open = std::stod(open_);
                    tick_info.high = std::stod(high_);
                    tick_info.low = std::stod(low_);
                    tick_info.close = std::stod(close_);
                } catch (const std::invalid_argument& e) {
                    std::cerr<<"Invalid argument: "<<e.what()<<std::endl;
                } catch (const std::out_of_range& e) {
                    std::cerr<<"Value out of range: "<<e.what()<<std::endl;
                }

                std::getline(ss,tick_info.datetime,',');

                stock_data.push_back(tick_info);
            }
            file.close();
            return stock_data;
        }

};

#endif