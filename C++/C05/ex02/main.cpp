#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	Bureaucrat				founder("Virginia Raggi", 1);
	Bureaucrat				employee("Mario Draghi", 50);
	ShrubberyCreationForm	shrubbery("Sergio");
	RobotomyRequestForm		robotomy("Rambo2");
	PresidentialPardonForm	pardon("Bombolo");

	std::cout << std::endl << "--- [ WELCOME TO INPS ] ---" << std::endl << std::endl;

	try
	{
		std::cout << shrubbery << std::endl;
		std::cout << employee << std::endl;
		employee.signForm(shrubbery);
		std::cout << shrubbery << std::endl;
		employee.executeForm(shrubbery);

		std::cout << std::endl << robotomy << std::endl;
		employee.signForm(robotomy);
		std::cout << robotomy << std::endl;
		employee.executeForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cout << std::endl << "[ WARNING ] : " << e.what() << std::endl << std::endl;
	}
	std::cout << std::endl << "[ " << employee.getName() << " calls a higher-graded Bureaucrat. ]" << std::endl << std::endl;
	try
	{
		std::cout << founder << std::endl;
		founder.executeForm(robotomy);
		founder.executeForm(robotomy);
		founder.executeForm(robotomy);

		std::cout << std::endl << pardon << std::endl;
		founder.signForm(pardon);
		std::cout << pardon << std::endl;
		founder.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cout << std::endl << std::endl << "[ WARNING ] : " << e.what() << std::endl << std::endl;
	}

		std::cout << std::endl << "--- [ THANK YOU FOR VISITING INPS ] ---" << std::endl << std::endl;


	return (0);
}