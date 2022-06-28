#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <iostream>
# include <algorithm>
# include <vector>
# include <cmath>
# include <limits>

class Span
{
	private:
		Span();
		unsigned int		size;
		std::vector<int>	vect;

	public:

		class ExceededSpaceException : public std::exception
		{
			public:
				const char*	what() const throw();
		};

		class NotEnoughElemsException : public std::exception
		{
			public:
				const char*	what() const throw();
		};

		Span(unsigned int N);
		Span(const Span& copy);
		virtual ~Span();

		Span&	operator = (const Span& op);

		void	addNumber(const int& n);

		template <typename iter>
		void	addNumber(iter first, iter last)
		{
			for (iter begin = first; begin != last; begin++)
				addNumber(*begin);
		};
		
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
};

#endif