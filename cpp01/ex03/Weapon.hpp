#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

// Color codes
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

class Weapon {
private:
	std::string _type;

public:
	//default constructor
	Weapon();
	//parameter constructor
	Weapon(const std::string initialType);
	//destructor
	~Weapon();

	//setters
	void				setType(const std::string newType);

	//getters
	const std::string&	getType(void) const;
};

#endif
