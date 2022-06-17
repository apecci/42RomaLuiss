#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat
{
	private:
		const std::string	name;
		int	grade;
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

		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		~Bureaucrat();
		Bureaucrat& operator = (const Bureaucrat& op);

		const std::string	getName() const;
		int 				getGrade() const;
		void				gradeIncrement();
		void				gradeDecrement();
};

std::ostream& operator << (std::ostream& output, const Bureaucrat& print);

#endif