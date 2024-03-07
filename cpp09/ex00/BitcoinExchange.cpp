#include "BitcoinExchange.hpp"

// constructor
BitcoinExchange::BitcoinExchange() {
    std::cout << std::setw(15) << "[BitcoinExchange] "<< "create!!!" << std::endl;
    this->base.open("data.csv");
    if (this->base.is_open())
        MakeMap();
    else{
        std::cout << "ERROR: Cannot open file" << std::endl;
        exit(1);
    }
}

// destructor
BitcoinExchange::~BitcoinExchange() {
    std::cout << std::setw(15) << "[BitcoinExchange] " << "delete!!" << std::endl;
    this->base.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref) {
    *this = ref;
    std::cout << std::setw(15) << "[BitcoinExchange] " << "copy!!" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref) {
    std::cout << std::setw(15) << "[BitcoinExchange] " << "operator=!!" << std::endl;
    this->standard = ref.standard;
    return (*this);
}

bool BitcoinExchange::CheckLeapYear(int year) {
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

bool BitcoinExchange::CheckValidDate(int year, int month, int day) {
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30)
            return false;
    } else if (month == 2) {
        if (this->CheckLeapYear(year) && day > 29)
            return false;
        if (!(this->CheckLeapYear(year)) && day > 28)
            return false;
    }
    return true;
}

std::queue<std::string> BitcoinExchange::Split(std::string input, char delimiter) {
    std::queue<std::string> result;
    std::stringstream ss(input);
    std::string tmp;

    while (getline(ss, tmp, delimiter))
        result.push(tmp);
    return result;
}

std::string BitcoinExchange::DoubleToString(double value) {
    std::ostringstream o;
    if (!(o << value))
        return "";
    return o.str();
}

void BitcoinExchange::MakeMap() {
    std::string key;
    std::cout << "=========Make Map=========" << std::endl;
    while (getline(this->base, key, ',')) {
        if (key == "date") {
            getline(this->base, key);
            continue;
        }
        std::string val;
        getline(this->base, val);
        this->standard[key] = atof(val.c_str());
    }
}

int BitcoinExchange::ValidationCheck(
    std::string &line_,
    std::queue<std::string> &_strs) {
    std::queue<std::string> string_s;
    std::queue<std::string> datetime_str;
    double check;
    int i = 0;
    int pipe_cnt = 0;
    int hipen_cnt = 0;
    int dot_cnt = 0;
    int sp_cnt = 0;

    while (line_[i]) {
        if (pipe_cnt == 0 && line_[i] == '-')
            hipen_cnt++;
        else if (line_[i] == '|')
            pipe_cnt++;
        else if ((line_[i] < 48 || line_[i] > 57) && line_[i] != 32 &&
                 line_[i] != 46 && line_[i] != 45)
        {
            std::cout << "Error: bad input => " << line_ << std::endl;
            return 0;
        } else if (line_[i] == 32)
            sp_cnt++;
        else if (line_[i] == 46) {
            dot_cnt++;
            if (pipe_cnt == 0)
            {
                std::cout << "Error: bad input => " << line_ << std::endl;
                return 0;
            }
        } else if (pipe_cnt && line_[i] == '-')
        {
            std::cout << "Error: not a positive number." << std::endl;
            return 0;
        }
        i++;
    }
    if (pipe_cnt != 1 || hipen_cnt != 2 || sp_cnt != 2 || dot_cnt > 1){
        std::cout << "Error: bad input => " << line_ << std::endl;
        return 0;
    }

    string_s = this->Split(line_, '|');
    int datetime_len = string_s.front().size();
    if (string_s.size() != 2 || string_s.front()[datetime_len - 1] != ' ' ||
        string_s.back()[0] != ' ') {
        std::cout << "Error: bad input => " << line_ << std::endl;
        return 0;
    }
    string_s.front().erase(datetime_len - 1, 1);
    datetime_len = string_s.front().size();
    string_s.back().erase(0, 1);
    datetime_str = this->Split(string_s.front(), '-');

    if (datetime_str.size() != 3 ||
        (string_s.back().size() == 1 &&
         dot_cnt == 1))
    {
        std::cout << "Error: bad input => " << line_ << std::endl;
        return 0;
    }

    int t1 = atoi(datetime_str.front().c_str());
    datetime_str.pop();
    int t2 = atoi(datetime_str.front().c_str());
    datetime_str.pop();
    int t3 = atoi(datetime_str.front().c_str());
    datetime_str.pop();

    if (this->CheckValidDate(t1, t2, t3) == false)
    {
        std::cout << "Error: bad input => " << line_ << std::endl;
        return 0;
    }
    std::cout.precision(19);
    check = atof(string_s.back().c_str());
    if (check > 1000.0)
    {
        std::cout << "Error: too large a number." << std::endl;
        return 0;
    }
    if (check < 0.0) {
        std::cout << "Error: not a positive number." << std::endl;
        return 0;
    }
    std::cout.precision(7);
    _strs.push(string_s.front());
    _strs.push(string_s.back());
    return 1;
}

void BitcoinExchange::MakeExchange(char *_argv) {
    bool flag = false;
    std::string line;
    std::map<std::string, double>::iterator it;
    float _val;

    this->myfile.open(_argv);
    if (this->myfile.is_open()) {
        std::cout << std::string(80, '-') << std::endl;
        std::cout << "File Opened: the conversion has begun ..." << std::endl << std::endl;

        while (getline(this->myfile, line)) {
            std::queue<std::string> _strs;
            if (line == "date | value") {
                if (flag == true) {
                    std::cout << "Error: bad input => " << line << std::endl;
                }
                flag = true;
                continue;
            }
            flag = true;
            if (this->ValidationCheck(line, _strs) == 0)
                continue;
            if (_strs.front() < (this->standard).begin()->first) {
                std::cout << "Error: No Standard Data. => " << _strs.front() << std::endl;
                continue;
            }
            it = (this->standard).lower_bound(_strs.front());
            _val = atof(_strs.back().c_str());
            if ((this->standard).find(_strs.front()) != (this->standard).end()) {
                std::cout << _strs.front() << " => " << _strs.back() << " = " << (it->second) * _val << std::endl;
            }
            else {
                if (_strs.front() > (this->standard).rbegin()->first)
                    std::cout << "Error: No Standard Data. Future data. => " << _strs.front() << std::endl;
                else
                    std::cout << _strs.front() << " => " << _strs.back() << " = " << ((--it)->second) * _val << std::endl;
            }
        }
        this->myfile.close();
        std::cout << std::string(80, '-') << std::endl;
    }
    else {
        std::cout << "ERROR: file does not opened." << std::endl;
    }
}
