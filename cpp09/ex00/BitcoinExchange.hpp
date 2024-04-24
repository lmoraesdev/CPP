
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <queue>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>

class BitcoinExchange {

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &ref);
    BitcoinExchange &operator=(const BitcoinExchange &ref);

    void MakeExchange(char *argv);
    int ValidationCheck(std::string &line, std::queue<std::string> &str);
    bool CheckLeapYear(int year);
    bool CheckValidDate(int year, int month, int day);
    std::queue<std::string> Split(std::string input, char delimiter);
    std::string DoubleToString(double value);

private:
    std::map<std::string, double> standard;
    std::ifstream myfile;
    std::ifstream base;
    void MakeMap();
};

#endif
