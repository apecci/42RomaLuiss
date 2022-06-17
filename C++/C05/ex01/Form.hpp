#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				sign;
		const int			signGrade;
		const int			execGrade;
		
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade is too high.");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade is too low.");
				}
		};

		Form();
		Form(const std::string name, int grade, int exec);
		Form(const Form& copy);
		~Form();
		Form& operator = (const Form& op);

		const std::string	getName() const;
		bool				getSignStatus() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		void				signature(const Bureaucrat& signee);
};

std::ostream & operator<<(std::ostream & output, const Form & print);

#endif