#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		static const int	bits = 8;
		int					fixedValue;

	public:
		Fixed();
		Fixed(const Fixed& fix);
		Fixed& operator = (const Fixed& fix);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);
};

# endif