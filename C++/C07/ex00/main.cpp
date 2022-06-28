#include "Whatever.hpp"

void testMain() 
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
	std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
	std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;
}

void	testSwap()
{
	int	a = 2;
	int	b = 4;
	
	std::cout << "[initial] a: " << a << " | [initial] b: " << b << std::endl;
	::swap(a, b);
	std::cout << "[swapped] a: " << a << " | [swapped] b: " << b << std::endl;


	std::string	str1 = "two";
	std::string	str2 = "forty";
	
	std::cout << "[initial] str1: " << str1 << " | [initial] str2: " << str2 << std::endl;
	::swap(str1, str2);
	std::cout << "[swapped] str1: " << str1 << " | [swapped] str2: " << str2 << std::endl;
}

void	testMin()
{
	std::cout << "Values to compare : 4, 2 | min : " << ::min(4, 2) << std::endl;
	std::cout << "Values to compare : true, false | min : " << std::boolalpha << ::min(true, false) << std::endl;
}

void	testMax()
{
	std::cout << "Values to compare : 4, 2 | max : " << ::max(4, 2) << std::endl;
	std::cout << "Values to compare : true, false | max : " << std::boolalpha << ::max(true, false) << std::endl;
}

int	checkInput(std::string input)
{
	if (input == "main")
		return (1);
	else if (input == "swap")
		return (2);
	else if (input == "min")
		return (3);
	else if (input == "max")
		return (4);
	else
		return (0);
}

int main()
{
	std::string	input;

	std::cout << "Please select an option:" << std::endl;
	std::cout << "<main> <swap> <min> <max>" << std::endl;
	std::getline(std::cin, input, '\n');// gets input value

	switch (checkInput(input))
	{
	case 1:
		testMain();
		return (0);
	case 2:
		testSwap();
		return (0);
	case 3:
		testMin();
		return (0);
	case 4:
		testMax();
		return (0);
	default:
		std::cout << "Error: Invalid input!" << std::endl;
		return (1);
	}
}