#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

struct Data {
    Data(void);
    Data(std::string publicData, std::string privateData, int privateNumber);
    ~Data(void);
    Data(Data const &source);
    Data &operator=(Data const &source);

    std::string publicData;

    // Getters
    std::string getPrivateData(void) const;
    int         getPrivateNumber(void) const;
private:
    std::string _privateData;
    int         _privateNumber;
};

#endif
