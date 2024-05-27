#ifndef STOCKDATA_H
#define STOCKDATA_H

#include <string>

struct StockData{
    std::string date;
    std::string time;
    double open;
    double high;
    double low;
    double close;
    long int volume;
    std::string ticker;
    std::string datetime;
};

#endif

//STOCKDATA_H
