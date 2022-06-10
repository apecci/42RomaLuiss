#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	std::cout << "--- [ Copy constructor test ] ---" << std::endl;
	Cat	i;
	Dog	f;

	Cat	j = i;
	Dog	g = f;

	std::cout << std::endl << "--- [  Ark test ] ---" << std::endl;
	Animal*	ark[4];
	for (int i = 0; i < 4; i++)
	{
		if (i % 2)
			ark[i] = new Dog;
		else
			ark[i] = new Cat;
	}
	for (int i = 0; i < 4; i++)
		ark[i]->makeSound();
	for (int i = 0; i < 4; i++)
		delete ark[i];
}