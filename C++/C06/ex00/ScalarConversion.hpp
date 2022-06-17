#ifndef SCALARCONVERSION_HPP
# define SCALARCONVERSION_HPP


# include <iostream>
# include <cctype>
# include <exception>
# include <limits>
# include <cmath>

class ScalarConversion
{
private:
	ScalarConversion();
	bool		num;
	double		intValue;
public:
	class ImpossibleException : public std::exception
	{
		public:
			const char*	what() const throw();
	};
	class NotDisplayableException : public std::exception
	{
		public:
			const char*	what() const throw();
	};
	class InvalidException : public std::exception
	{
		public:
			const char*	what() const throw();
	};

	ScalarConversion(const char* av);
	ScalarConversion(const ScalarConversion& copy);
	virtual	~ScalarConversion();

	ScalarConversion&	operator = (const ScalarConversion& op);
	operator int() const;
	operator char() const;
	operator float() const;
	operator double() const;

	//std::string			getInput() const;//	DEBUG
};

#endif