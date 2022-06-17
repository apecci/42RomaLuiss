#include "Data.hpp"

uintptr_t	serialize(Data* p)
{
	uintptr_t	intp;

	intp = reinterpret_cast<uintptr_t>(p);
	return (intp);
}

Data*	deserialize(uintptr_t raw)
{
	Data*	p;
	p = reinterpret_cast<Data*>(raw);
	return (p);
}