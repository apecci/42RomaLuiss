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
	output << "My name is " << print.getName() << ". I am Bureaucrat n." << print.getGrade() << " of the INPS.";
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