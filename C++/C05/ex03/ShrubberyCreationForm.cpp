#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
Form("Shrubbery Creation", 145, 137)
{
	this->setTarget("Groot");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
Form("Shrubbery Creation", 145, 137)
{
	this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
{
	this->setTarget(copy.getTarget());
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& op)
{
	if (this == &op)
		return (*this);
	this->setTarget(op.getTarget());
	return (*this);
}

void	ShrubberyCreationForm::Action() const
{
	std::ofstream	file;

	file.open((this->getTarget() + "_shrubbery").c_str(), std::ofstream::trunc);
	file << "LEBRON JAMES" << std::endl;
	file.close();

	std::cout << "File saved SUCCESSFULLY" << std::endl;
}