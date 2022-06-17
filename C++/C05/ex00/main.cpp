#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	founder("Virginia Raggi", 1);
	Bureaucrat	griphook;

	try
	{
		std::cout << griphook << std::endl;
		griphook.gradeIncrement();
		std::cout << griphook << std::endl;
		griphook.gradeDecrement();
		std::cout << griphook << std::endl;
		griphook.gradeDecrement();
		std::cout << griphook << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << std::endl << "[ WARNING ] : " << e.what() << std::endl << std::endl;
	}
	try
	{
		std::cout << founder << std::endl;
		founder.gradeDecrement();
		std::cout << founder << std::endl;
		founder.gradeIncrement();
		std::cout << founder << std::endl;
		founder.gradeIncrement();
		std::cout << founder << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << std::endl << "[ WARNING ] : " << e.what() << std::endl << std::endl;
	}

	

	return (0);
}