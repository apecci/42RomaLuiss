#include <iostream>
#include <iomanip>
#include "ScalarConversion.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
		return (1);
	
	ScalarConversion    sconv(av[1]);

	try
	{
		char	c = static_cast<char>(sconv);
		std::cout << "char: '" << c << "'" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "char: " << e.what() << std::endl;
	}

	try
	{
		int		i = static_cast<int>(sconv);
		std::cout << "int: " << i << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "int: " << e.what() << std::endl;
	}
	
	std::cout << std::setprecision(1) << std::fixed;

	try
	{
		float	f = static_cast<float>(sconv);
		std::cout << "float: " << f << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "float: " << e.what() << std::endl;
	}

	try
	{
		double	d = static_cast<double>(sconv);
		std::cout << "double: " << d << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "double: " << e.what() << std::endl;
	}
	
	return (0);
}
