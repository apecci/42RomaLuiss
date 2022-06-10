#include "Animal.hpp"

Animal::Animal() : type("Animal")
{}

Animal::Animal(const Animal& copy)
{
	*this = copy;
	return ;
}

Animal::~Animal()
{}

Animal&	Animal::operator = (const Animal &op)
{
	if (this == &op)
		return (*this);
	this->type = op.type;
	return (*this);
}

void	Animal::makeSound()	const
{
	std::cout << "The " << this->type << " goes << MARONN! >>" << std::endl;
}

std::string	Animal::getType()	const
{
	return (this->type);
}