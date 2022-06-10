#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "brain was created." << std::endl;
}

Brain::~Brain()
{
	std::cout << "brain was destroyed." << std::endl;
}

Brain::Brain(const Brain& copy)
{
	*this = copy;
}

Brain&	Brain::operator = (const Brain& op)
{
	if (this == &op)
		return (*this);
	for (size_t i = 0; i < this->ideas->size(); i++)
		this->ideas[i] = op.ideas[i];
	return (*this);
}

std::string*	Brain::getIdeas()
{
	return (this->ideas);
}