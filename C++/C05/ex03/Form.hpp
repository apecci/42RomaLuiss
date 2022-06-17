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
		std::string			target;
		
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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form is not signed!");
				}
		};

		Form();
		Form(const std::string name, int grade, int exec);
		Form(const Form& copy);
		virtual ~Form();
		Form& operator = (const Form& op);

		const std::string	getName() const;

		bool				getSignStatus() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		
		void				signature(const Bureaucrat& signee);
		void				execute(Bureaucrat const & executor) const;

		std::string				getTarget() const;
		void				setTarget(std::string target);
		virtual void		Action() const = 0;
};

std::ostream & operator<<(std::ostream & output, const Form & print);

#endif