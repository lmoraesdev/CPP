#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

// Color codes
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

class Zombie {
	private:
		std::string _name;
	public:
		// Constructors and destructors
		Zombie(std::string name);
		~Zombie(void);
		// Setters
		void setName(std::string name);
		// Getters
		std::string getName(void);
		// Member functions
		void announce(void);
};

Zombie*	newZombie(std::string name);
void 	randomChump(std::string name);

#endif
