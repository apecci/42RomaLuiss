#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "Wrong Cat";
}

WrongCat::~WrongCat()
{}

WrongCat::WrongCat(const WrongCat& copy)
{
	*this = copy;
	return ;
}

WrongCat& WrongCat::operator = (const WrongCat& op)
{
	if (this == &op)
		return (*this);
	this->type = op.type;
	return (*this);
}

void	WrongCat::makeSound()	const
{
	std::cout << "The " << this->type << " goes << WREOOOOOOOWNG! >>" << std::endl;
}