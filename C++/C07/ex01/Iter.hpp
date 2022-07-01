#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void    iter(T *arr, int len, void (*f)(T const & x))
{
    for (int i = 0; i < len; i++)
        f(arr[i]);
}

template <class myType>
void	swap(myType& a, myType& b)
{
	myType	c = a;
	a = b;
	b = c;
}

#endif