#include "Form.hpp"

Form::Form() :
name("Blank paper"),
sign(false),
signGrade(150),
execGrade(150)
{}

Form::Form(const std::string name, int grade, int exec) :
name(name),
sign(false),
signGrade(grade),
execGrade(exec)
{}

Form::Form(const Form& copy) :
name(copy.getName()),
sign(false),
signGrade(copy.getSignGrade()),
execGrade(copy.getExecGrade())
{}

Form::~Form()
{}

Form& Form::operator = (const Form& op)
{
	if (this == &op)
		return (*this);
	this->sign = getSignStatus();
	return (*this);
}

const std::string	Form::getName() const
{
	return (this->name);
}

bool	Form::getSignStatus() const
{
	return (this->sign);
}

int	Form::getSignGrade() const
{
	return (this->signGrade);
}

int	Form::getExecGrade() const
{
	return (this->execGrade);
}

void	Form::signature(const Bureaucrat& signee)
{
	if (signee.getGrade() > signGrade)
		throw GradeTooLowException();
	else
		this->sign = true;
}

std::string	Form::getTarget() const
{
	return (this->target);
}

void	Form::setTarget(std::string target)
{
	this->target = target;
}

void	Form::execute(Bureaucrat const & executor) const
{
	if (this->sign == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->execGrade)
		throw GradeTooLowException();
	else
		Action();
}

std::ostream& operator << (std::ostream& output, const Form& print)
{
	output << "Form <" << print.getName() << "> is currently ";
	if (print.getSignStatus())
		output << "signed." << std::endl;
	else
		output << "not signed." << std::endl;
	if (print.getSignGrade() < 1)
		output << "No One has a grade high enough to sign form <" << print.getName() << ">." << std::endl;
	else if (print.getSignStatus() == false)
		output << "Form <" << print.getName() << "> can only be signed by grade " << print.getSignGrade() << " and executed by grade " << print.getExecGrade() << " Bureaucrats." << std::endl;
	return (output);
}