#include "Identify.hpp"

Base*	generate(void)
{
	srand(time(0));
	int random = rand() % 3;
	
	switch (random)
	{
	case 0:
		return (new A);
		//break;
	
	case 1:
		return (new B);
		//break;
	
	default:
		return (new C);
		//break;
	}
}

void	pidentify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	ridentify(Base& p)
{
	pidentify(&p);
}
