#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal*	wrongmeta = new WrongAnimal();
	const WrongAnimal*	k = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	wrongmeta->makeSound();
	k->makeSound();
	
		delete meta;
	delete i;
	delete j;
	
	std::cout << std::endl << k->getType() << " " << std::endl;
	wrongmeta->makeSound();
	k->makeSound();
	delete wrongmeta;
	delete k;
}