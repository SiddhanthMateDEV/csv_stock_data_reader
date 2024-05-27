#ifndef STOCKDATA_H
#define STOCKDATA_H

#include <string>

struct StockData{
    std::string stockName;
    std::string dateTime;
    double open;
    double high;
    double low;
    double close;
    long int volume;
};

#endif

//STOCKDATA_H
