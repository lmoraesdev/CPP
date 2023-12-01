#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++){
		this->inv[i] = 0;
	}
	std::cout << "MateriaSource constructor called " << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &ref)
{
	*this = ref;
	std::cout << "MateriaSource contructor by copy" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++){
		if (this->inv[i])
			delete this->inv[i];
	}
	std::cout << "Destructor of MateriaSource " << " called" <<std::endl;
}

MateriaSource		&MateriaSource::operator=(MateriaSource const &ref)
{
	std::cout << "Assignation with operator= called" <<std::endl;
	if (this != &ref)
	{
		*this = ref;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m){
	for (int i = 0; i < 4; i++){
		if (this->inv[i] == 0){
			this->inv[i] = m;
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++){
		if (this->inv[i] && this->inv[i]->getType() == type){
			return (this->inv[i]->clone());
		}
	}
	return (0);
}
