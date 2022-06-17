#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		Form*	makeShrubbery(std::string target);
		Form*	makeRobotomy(std::string target);
		Form*	makePardon(std::string target);
	public:
		Intern();
		Intern(const Intern& copy);
		~Intern();
		Intern& operator = (const Intern& op);

		Form*	makeForm(std::string fname, std::string target);
};

#endif