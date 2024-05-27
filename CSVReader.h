#ifndef CSVReeader
#define CSVReader

#include "StockData.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>


class CSVReader{
    public:
        std::string filename;
    
    private:
        CSVReader(const std::string& filename) : filename(filename) {}

        std::vector<StockData> file_reader(){
            std::vector<StockData> stock_data;
            std::ifstream file(filename);

            if (!file.is_open()){
                throw runtime_error("Error opening the file");
            }

            // ignore the headers 
            std::string line;
            std::getline(file,line)
            while(getline(file,line)){
                std::stringstream ss(line);
                StockData tick_info;

                std::getline(ss,date.tick_info,',');
                std::getline(ss,stockName.tick_info,',');
                std::getline(ss,datetime.tick_info,',');
                std::getline(ss,open.tick_info,',');
                std::getline(ss,high.tick_info,',');
                std::getline(ss,low.tick_info,',');
                std::getline(ss,close.tick_info,',');
                std::getline(ss,volume.tick_info,',');

                stock_data.push_back(tick_no);
            }
        }

}

#endif