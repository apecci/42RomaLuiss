#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class InvalidException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return ("Element can't be found inside container.");
		}
};

template <typename T>
typename	T::const_iterator   easyfind(T& container, int  target)
{
	typename T::const_iterator	i;

	i = std::find(container.begin(), container.end(), target);
	if (i == container.end())
		throw InvalidException();
	return (i);
}

#endif