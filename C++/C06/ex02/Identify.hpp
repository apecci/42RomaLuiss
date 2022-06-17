#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void);
void	pidentify(Base* p);
void	ridentify(Base& p);//   You should never use a pointer inside this function.

#endif