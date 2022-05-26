#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		static const int	bits = 8;
		int					fixedValue;

	public:
		Fixed();
		Fixed(const Fixed& fix);

		Fixed(const int ival);
		Fixed(const float fval);
		
		Fixed& operator = (const Fixed& fix);

		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);
		
		float	toFloat() const;
		int		toInt() const;
};

std::ostream& operator<<(std::ostream& output, const Fixed& fix);

# endif