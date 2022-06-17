#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	founder("Virginia Raggi", 1);
	Bureaucrat	employee("Mario Draghi", 42);
	Form		form1("Vault visit request", 1, 1);
	Form		form2("Silvio Berlusconi's personal items withdrawal", 42, 10);
	Form		form3("Impossible-to-sign", 0, 1);

	std::cout << std::endl << "--- [ WELCOME TO INPS ] ---" << std::endl << std::endl;

	try
	{
		std::cout << form2 << std::endl;
		std::cout << employee << std::endl;
		employee.signForm(form2);
		std::cout << form2 << std::endl;

		std::cout << form1 << std::endl;
		employee.signForm(form1);
		std::cout << form1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << std::endl << "[ WARNING ] : " << e.what() << std::endl << std::endl;
	}
	std::cout << "[ " << employee.getName() << " calls a higher-graded Bureaucrat. ]" << std::endl << std::endl;
	try
	{
		// founder
		std::cout << founder << std::endl;
		founder.signForm(form1);
		std::cout << form1 << std::endl;

		std::cout << form3 << std::endl;
		founder.signForm(form3);
		std::cout << form3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << std::endl << "[ WARNING ] : " << e.what() << std::endl << std::endl;
	}

		std::cout << "--- [ THANK YOU FOR VISITING INPS ] ---" << std::endl << std::endl;


	return (0);
}