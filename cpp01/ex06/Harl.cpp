#include "Harl.hpp"

/**
 * The Harl constructor initializes an array of command strings.
 */
Harl::Harl()
{
	this->commandList[0] = "DEBUG";
	this->commandList[1] = "INFO";
	this->commandList[2] = "WARNING";
	this->commandList[3] = "ERROR";
}

/**
 * The above code snippet is a destructor for a class named "Harl" in C++.
 */
Harl::~Harl()
{
}
// Privates
/**
 * The debug function outputs a debug message and calls the info function.
 */
void Harl::debug( void ){
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	Harl::info();
}

/**
 * The "info" function outputs a message about the cost of adding extra bacon and a
 * complaint about not enough bacon in a burger, and then calls the "warning"
 * function.
 */
void Harl::info( void ){
	std::cout << "[INFO]" << std::endl;
	std::cout <<"I cannot believe adding extra bacon costs more money."<< std::endl;
	std::cout <<"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	Harl::warning();
}

/**
 * The function "warning" prints a warning message followed by an error message.
 */
void Harl::warning( void ){
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month."<< std::endl;
	Harl::error();
}

/**
 * The function "error" prints an error message to the console.
 */
void Harl::error( void ){
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;

}
// Public

/* The `complain` function in the `Harl` class takes a `level` parameter of type
`std::string`. It compares the `level` parameter with the command list in the
`Harl` class. If a match is found, it calls the corresponding function using a
function pointer array `functions`. The function pointer array holds the
addresses of the `debug`, `info`, `warning`, and `error` member functions of the
`Harl` class. If no match is found, it prints the message "[ Probably
complaining about insignificant problems ]" to the console. */
void Harl::complain(std::string level){
	void    (Harl::*functions[4])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

	for (int i = 0 ; i < 4; i++){
		if (this->commandList[i].compare(level) == 0){
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

}
