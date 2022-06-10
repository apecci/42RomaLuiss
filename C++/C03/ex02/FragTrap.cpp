#include "FragTrap.hpp"


FragTrap::FragTrap()
{}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    setHP(100);
	setEP(100);
	setAD(30);

	std::cout << "FragTrap " << getName() << " join the battle" << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap& copy)
{
    *this = copy;
    return ;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << getName() << " has been destroyed" << std::endl;
	return ;
}

void FragTrap::highFivesGuys()
{
    std::cout << std::endl << "FragTrap " << getName() << " says : ";
    std::cout << "<< I LIKE HIGH FIVES >>" << std::endl;
}