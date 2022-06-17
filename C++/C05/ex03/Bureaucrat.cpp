#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Sailor Moon"), grade(150)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& op)
{
	if (this == &op)
		return (*this);
	this->grade = op.grade;
	return (*this);
}

std::ostream& operator << (std::ostream& output, const Bureaucrat& print)
{
	output << "< My name is " << print.getName() << ". I am Bureaucrat n." << print.getGrade() << " of the INPS. >" << std::endl;
	return (output);
}

const std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::gradeIncrement()
{
	std::cout << " Promotion attempt for " << this->getName() << "." << std::endl;
	if (this->grade <= 1)
		throw GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::gradeDecrement()
{
	std::cout << " Demotion attempt for " << this->getName() << "." << std::endl;
	if (this->grade >= 150)
		throw GradeTooLowException();
	this->grade++;
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.signature(*this);
		std::cout << "Bureaucrat " << this->getName() << " signs <" << form.getName() << "> form." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "<" << form.getName() << "> form cannot be signed by Bureaucrat " << this->getName() << ". " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const Form& form)
{
	try
	{
		std::cout << this->name << " tries to execute <" << form.getName() << ">." << std::endl;
		form.execute(*this);
	}
	catch(std::exception & e)
	{
		std::cerr << this->name << " cannot execute <" << form.getName() << ">. " << e.what() << std::endl;
	}
}