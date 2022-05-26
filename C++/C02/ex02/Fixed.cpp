#include "Fixed.hpp"

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	this->fixedValue = 0;
	return ;
}

Fixed::~Fixed()
{
	return ;
}

Fixed::Fixed(const Fixed& fix)
{
	*this = fix;
	return ;
}

Fixed& Fixed::operator = (const Fixed& fix)
{	
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
	this->fixedValue = ival << this->bits;
	return ;
}

Fixed::Fixed(const float fval)
{
	this->fixedValue = (round(fval * (1 << this->bits)));
	return ;
}

float	Fixed::toFloat() const
{
	float	value;

	value = ((float)this->fixedValue / (1 << this->bits));
	return (value);
}

int		Fixed::toInt() const
{
	int	value;
	value = (int)(this->fixedValue >> this->bits);
	
	return(value);
}

std::ostream& operator << (std::ostream& output, const Fixed& fix)
{
	output << fix.toFloat();
	return (output);
}

bool	Fixed::operator > (const Fixed& fix) const
{
	return (this->fixedValue > fix.getRawBits());
}

bool	Fixed::operator < (const Fixed& fix) const
{
	return (this->fixedValue < fix.getRawBits());
}

bool	Fixed::operator >= (const Fixed& fix) const
{
	return (this->fixedValue >= fix.getRawBits());
}

bool	Fixed::operator <= (const Fixed& fix) const
{
	return (this->fixedValue <= fix.getRawBits());
}

bool	Fixed::operator == (const Fixed& fix) const
{
	return (this->fixedValue == fix.getRawBits());
}

bool	Fixed::operator != (const Fixed& fix) const
{
	return (this->fixedValue != fix.getRawBits());
}

Fixed	Fixed::operator + (const Fixed& fix) const
{
	Fixed	op;
	op.setRawBits(this->fixedValue + fix.getRawBits());
	return (op);
}

Fixed	Fixed::operator - (const Fixed& fix) const
{
	Fixed	op;
	op.setRawBits(this->fixedValue - fix.getRawBits());
	return (op);
}

Fixed	Fixed::operator * (const Fixed& fix) const
{
	Fixed	op;
	op.setRawBits((this->fixedValue * fix.getRawBits()) >> this->bits);
	return (op);
}

Fixed	Fixed::operator / (const Fixed& fix) const
{
	Fixed	op;
	op.setRawBits((this->fixedValue << this->bits) / fix.getRawBits());
	return (op);
}

Fixed	Fixed::operator ++ ()
{
	this->fixedValue++;
	return (*this);
}

Fixed	Fixed::operator ++ (int)
{
	Fixed	res(*this);
	operator ++ ();
	return (res);
}

Fixed	Fixed::operator -- ()
{
	this->fixedValue--;
	return (*this);
}

Fixed	Fixed::operator -- (int)
{
	Fixed	res(*this);
	operator -- ();
	return (res);
}


const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.operator<(b))
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}