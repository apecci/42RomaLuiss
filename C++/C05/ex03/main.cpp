#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	Bureaucrat				founder("Virginia Raggi", 1);
	Bureaucrat				employee("Mario Draghi", 50);
	Intern					intern;
	Form*					form;

	std::cout << std::endl << "--- [ WELCOME TO INPS ] ---" << std::endl << std::endl;

	try
	{
		//employee
		form = intern.makeForm("Shrubbery Creation", "Marco");
		std::cout << employee << std::endl;
		employee.signForm(*form);
		std::cout << *form << std::endl;
		employee.executeForm(*form);

		delete form;

		form = intern.makeForm("Robotomy Request", "Salvatore");
		employee.signForm(*form);
		std::cout << *form << std::endl;
		employee.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cout << std::endl << "[ WARNING ] : " << e.what() << std::endl << std::endl;
	}
	std::cout << std::endl << "[ " << employee.getName() << " calls a higher-graded Bureaucrat. ]" << std::endl << std::endl;
	try
	{
		std::cout << founder << std::endl;
		founder.executeForm(*form);
		founder.executeForm(*form);
		founder.executeForm(*form);

		delete form;

		form = intern.makeForm("Presidential Pardon", "Bambi");
		founder.signForm(*form);
		std::cout << *form << std::endl;
		founder.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cout << std::endl << std::endl << "[ WARNING ] : " << e.what() << std::endl << std::endl;
	}

		std::cout << std::endl << "--- [ THANK YOU FOR VISITING INPS ] ---" << std::endl << std::endl;

	delete form;
	return (0);
}