#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
}

Dog::~Dog()
{}

Dog::Dog(const Dog& copy)
{
	*this = copy;
	return ;
}

Dog&	Dog::operator = (const Dog &op)
{
	if (this == &op)
		return (*this);
	this->type = op.type;
	return (*this);
}

void	Dog::makeSound()	const
{
	std::cout << "The " << this->type << " goes << WOOOOOF! >>" << std::endl;
}