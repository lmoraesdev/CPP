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
 * The debug function prints a statement about loving a specific type of burger.
 */
void Harl::debug( void ){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;

}

/**
 * The function "info" prints a complaint about not enough bacon in a burger.
 */
void Harl::info( void ){
	std::cout <<"I cannot believe adding extra bacon costs more money. ";
	std::cout <<"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

/**
 * The function "warning" prints a message about deserving extra bacon based on the
 * length of time someone has been coming.
 */
void Harl::warning( void ){
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started working here since last month."<< std::endl;

}

/**
 * The function "error" prints a message expressing dissatisfaction and a desire to
 * speak to the manager.
 */
void Harl::error( void ){
	std::cout <<"This is unacceptable! I want to speak to the manager now." << std::endl;
}
// Public

/* The `void Harl::complain(std::string level)` function is a member function of
the `Harl` class. It takes a string parameter `level` which represents the level
of complaint. */
void Harl::complain(std::string level){
	void    (Harl::*functions[4])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

	for (int i = 0 ; i < 4; i++){
		if (this->commandList[i].compare(level) == 0)
			(this->*functions[i])();
	}
}
