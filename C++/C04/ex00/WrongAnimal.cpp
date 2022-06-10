#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wrong Animal")
{}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	*this = copy;
	return ;
}

WrongAnimal::~WrongAnimal()
{}

WrongAnimal&	WrongAnimal::operator = (const WrongAnimal &op)
{
	if (this == &op)
		return (*this);
	this->type = op.type;
	return (*this);
}

void	WrongAnimal::makeSound()	const
{
	std::cout << "The " << this->type << " goes << WRONG MARONN! >>" << std::endl;
}

std::string	WrongAnimal::getType()	const
{
	return (this->type);
}