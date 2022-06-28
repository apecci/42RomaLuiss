#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <class Array, class Function>
void    iter(Array* arr, size_t size, Function* foo)
{
    for (size_t i = 0; i < size; i++)
        foo(arr[i]);
}

template <class myType>
void	swap(myType& a, myType& b)
{
	myType	c = a;
	a = b;
	b = c;
}

#endif