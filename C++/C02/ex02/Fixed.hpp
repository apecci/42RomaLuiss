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

		bool	operator > (const Fixed& fix) const;
		bool	operator < (const Fixed& fix) const;
		bool	operator >= (const Fixed& fix) const;
		bool	operator <= (const Fixed& fix) const;
		bool	operator == (const Fixed& fix) const;
		bool	operator != (const Fixed& fix) const;

		Fixed	operator + (const Fixed& fix) const;
		Fixed	operator - (const Fixed& fix) const;
		Fixed	operator * (const Fixed& fix) const;
		Fixed	operator / (const Fixed& fix) const;

		Fixed	operator ++ ();
		Fixed	operator ++ (int);
		Fixed	operator -- ();
		Fixed	operator -- (int);

		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);
		
		float	toFloat() const;
		int		toInt() const;

		const static Fixed& min(const Fixed& a, const Fixed& b);
		const static Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& output, const Fixed& fix);

# endif