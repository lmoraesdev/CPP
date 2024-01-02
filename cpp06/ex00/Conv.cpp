#include "Conv.hpp"

Conv::Conv(std::string input){
	this->input = input;
}

Conv::Conv(const Conv &ref){
	*this = static_cast<Conv>(ref);
}

Conv::~Conv() {}

Conv		&Conv::operator=(Conv const &ref){
	if (this != &ref)
		*this = ref;
	return *this;
}


void Conv::parse(){
	this->special();
	this->validate();
	this->toFloat();
	this->toInt();
	this->toChar();
	this->toDouble();
	this->print();
}

void Conv::special(){
	int i = 0;
	if(this->input[i] == '-' || this->input[i] == '+')
			i++;
	if (!this->input.compare(i, 3, "inf")){
		this->printInf();
	} else if (this->input == "nan" || this->input == "nanf"){
		this->printNan();
	}
}

void Conv::printInf(){
	if (this->input == "inff" || this->input == "+inff" || this->input == "inf" || this->input == "+inf"){
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "inff" << std::endl;
		std::cout << "double: " <<  "inf"<< std::endl;
	} else if (this->input == "-inff"  || this->input == "-inf" ){
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " <<  "-inf"<< std::endl;
	} else {
		std::cerr << "invalid convertion" << std::endl;
	}
	this->~Conv();
	std::exit(0);
}

void Conv::printNan(){
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "nanf" << std::endl;
	std::cout << "double: " <<  "nan"<< std::endl;
	this->~Conv();
	std::exit(0);
}

void Conv::validate(){
	int i = 0;

	if((this->input[i] >= '0' && this->input[i] <= '9') || this->input[i] == '-' || this->input[i] == '+')
	{
		if(this->input[i] == '-' || this->input[i] == '+')
			i++;
		while(std::isdigit(this->input[i]))
			i++;
		if (this->input[i] == '\0'){
			this->toInt();
		} else if (this->input[i] == '.'){
			i++;
			if (this->input[i] == '\0'){
				std::cerr << "invalid convertion" << std::endl;
				this->~Conv();
				std::exit(0);
			}
			while (std::isdigit(this->input[i]))
				i++;
			if (this->input[i] == 'f' && this->input[i + 1] == '\0'){
				this->toFloat();
			} else if (this->input[i] == '\0') {
				this->toDouble();
			} else {
				std::cerr << "invalid convertion" << std::endl;
				this->~Conv();
				std::exit(0);
			}
		} else {
			std::cerr << "invalid convertion" << std::endl;
			this->~Conv();
			std::exit(0);
		}
	} else if (std::isalpha(this->input[i])) {
		if (this->input.length() > 1){
			std::cerr << "invalid convertion" << std::endl;
			this->~Conv();
			std::exit(0);
		}
		this->toChar();
	}
}

void Conv::toFloat(){
	std::stringstream holder(this->input.c_str());

	holder >> this->_float;
	this->_int = static_cast<int>(this->_float);
	this->_double = static_cast<double>(this->_float);
	this->_char = static_cast<char>(this->_float);
}

void Conv::toInt(){
	std::stringstream holder(this->input.c_str());

	holder >> this->_int;
	this->_float = static_cast<float>(this->_int);
	this->_double = static_cast<double>(this->_int);
	this->_char = static_cast<char>(this->_int);
}

void Conv::toChar(){
	std::stringstream holder(this->input.c_str());

	holder >> this->_char;
	this->_float = static_cast<float>(this->_char);
	this->_double = static_cast<double>(this->_char);
	this->_int = static_cast<int>(this->_char);
}

void Conv::toDouble(){
	std::stringstream holder(this->input.c_str());

	holder >> this->_double;
	this->_float = static_cast<float>(this->_double);
	this->_char = static_cast<char>(this->_double);
	this->_int = static_cast<int>(this->_double);
}

void Conv::print(){
	std::cout << "char: " ;
	if (std::isprint(this->_char))
		std ::cout << this->_char << std::endl;
	else
		std ::cout << "Not displayable" << std::endl;

	std::cout << "int: " << this->_int << std::endl;

	std::cout << "float: " << this->_float ;
	if (this->input.find('.') == static_cast<size_t>(-1))
		std::cout << ".0" ;
	std::cout << "f" << std::endl;

	std::cout << "double: " << this->_double ;
	if (this->input.find('.') == static_cast<size_t>(-1))
		std::cout << ".0" ;
	std::cout << std::endl;
}
