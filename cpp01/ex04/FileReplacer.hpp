#ifndef FILE_REPLACER_HPP
# define FILE_REPLACER_HPP

#include <iostream>
#include <fstream>
#include <string>

// Color codes
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

class FileReplacer
{
private:
	std::string _filename;
	std::string _search_string;
	std::string _replacement_string;
	std::ofstream _output_file;

	// Private methods
	void _replace(const std::string& line);
public:
	// Constructors and destructor
	FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2);
	~FileReplacer(void);
};

#endif
