#include "Span.hpp"

const char*	Span::ExceededSpaceException::what() const throw()
{
	return ("Container is full.");
}

const char*	Span::NotEnoughElemsException::what() const throw()
{
	return ("Not enough Elements.");
}

Span::Span() :
size(0)
{}

Span::Span(unsigned int N) :
size(N)
{}

Span::Span(const Span& copy)
{
	*this = copy;
}

Span::~Span()
{}

Span&	Span::operator = (const Span& op)
{
	if (this == &op)
		return (*this);
	this->vect.clear();
	this->size = op.size;
	this->vect = op.vect;
	return (*this);
}

void	Span::addNumber(const int& n)
{
	if (vect.size() == this->size)
		throw (ExceededSpaceException());
	vect.push_back(n);
}

unsigned int	Span::shortestSpan()
{
	std::vector<int>::iterator	iter;
	int					tmp;
	int					ret;

	if (this->vect.size() < 2)
		throw (NotEnoughElemsException());

	std::sort(vect.begin(), vect.end());
	iter = vect.begin();
	ret = std::abs(*(iter + 1) - *iter);
	for (iter += 2; iter < vect.end(); iter++)
	{
		tmp = std::abs(*iter - *(iter - 1));
		if (tmp < ret)
			ret = tmp;
	}
	return (ret);
}

unsigned int	Span::longestSpan()
{
	if (this->vect.size() < 2)
		throw (NotEnoughElemsException());
	return (std::abs(*std::max_element(vect.begin(), vect.end()) - *std::min_element(vect.begin(), vect.end())));
}