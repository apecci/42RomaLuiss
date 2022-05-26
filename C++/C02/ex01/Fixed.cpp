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
	return (this->fixedValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixedValue = raw;
	return ;
}

Fixed::Fixed(const int ival)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedValue = ival << this->bits;
	return ;
}

Fixed::Fixed(const float fval)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedValue = (int)(roundf(fval * (1 << this->bits)));
	return ;
}

float	Fixed::toFloat() const
{
	float	value;

	value = (float)this->fixedValue / (float)(1 << this->bits);
	return (value);
}

int		Fixed::toInt() const
{
	int	value;
	value = (int)(this->fixedValue >> this->bits);
	
	return(value);
}

std::ostream& operator<<(std::ostream& output, const Fixed& fix)
{
	output << fix.toFloat();
	return (output);
}