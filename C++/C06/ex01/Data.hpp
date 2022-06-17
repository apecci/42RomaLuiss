#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

struct Data
{
	std::string	str;
	int			num;
};

uintptr_t	serialize(Data* p);
Data*	deserialize(uintptr_t raw);

#endif