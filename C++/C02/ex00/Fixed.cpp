#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedValue = 0;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed& fix)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = fix;
	return ;
}

Fixed& Fixed::operator = (const Fixed& fix)
{	std::cout << "Assignation Operator called" << std::endl;
	if (this != &fix)
		this->fixedValue = fix.getRawBits();
	return(*this);
}


int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixedValue = raw;
	return ;
}