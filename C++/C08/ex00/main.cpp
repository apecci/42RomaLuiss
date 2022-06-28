#include "EasyFind.hpp"

int main()
{
	std::vector<int>	vect;
	std::string			input;
	double				conv;

	for (int i = 0; i < 5; i++)
		vect.push_back(i + 1);

	std::cout << "Please enter a int value:" << std::endl;
	std::getline(std::cin, input, '\n');

	std::vector<int>::const_iterator	iter;

	conv = std::stod(input);
	std::cout << "Search Result: ";
	try
	{
		iter = easyfind(vect, (static_cast<int>(conv)));
		std::cout << "Element " << *iter << " was found inside container." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
