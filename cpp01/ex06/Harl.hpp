#ifndef HARL_HPP
# define  HARL_HPP
# include <iostream>
# include <map>

class Harl
{
private:
	std::string commandList[4];
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
public:
	Harl();
	~Harl();
	void complain(std::string level);
};

#endif
