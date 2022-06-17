#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
Form("Presidential Pardon", 25, 5)
{
	this->setTarget("Bombolo");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
Form("Presidential Pardon", 25, 5)
{
	this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
{
	this->setTarget(copy.getTarget());
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& op)
{
	if (this == &op)
		return (*this);
	this->setTarget(op.getTarget());
	return (*this);
}

void	PresidentialPardonForm::Action() const
{
	std::cout << this->getTarget() << " has been officially pardoned by Zaphod Beeblebrox." << std::endl;
}