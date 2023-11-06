#include "Harl.hpp"

Harl::Harl()
{
	this->commandList[0] = "DEBUG";
	this->commandList[1] = "INFO";
	this->commandList[2] = "WARNING";
	this->commandList[3] = "ERROR";
}

Harl::~Harl()
{
}
// Privates
void Harl::debug( void ){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;

}

void Harl::info( void ){
	std::cout <<"I cannot believe adding extra bacon costs more money. ";
	std::cout <<"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ){
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started working here since last month."<< std::endl;

}

void Harl::error( void ){
	std::cout <<"This is unacceptable! I want to speak to the manager now." << std::endl;
}
// Public

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
