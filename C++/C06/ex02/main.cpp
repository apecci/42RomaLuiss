#include "Identify.hpp"

int main()
{
	Base*	base = generate();

	std::cout << " --- [ Identify from Pointer ] ---" << std::endl;
	pidentify(base);
	std::cout << std::endl << " --- [ Identify from Reference ] ---" << std::endl;
	ridentify(*base);

	return (0);
}