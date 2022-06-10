#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), gatekeeper(false)
{
	setHP(100);
	setEP(50);
	setAD(20);

	std::cout << "ScavTrap " << getName() << " is hungry" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
{
	*this = copy;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << getName() << " was smashed by the chosen undead" << std::endl;
	return ;
}



void    ScavTrap::guardGate()
{
	gatekeeper = true;
	std::cout << "ScavTrap " << getName() << " has entered in Gate Keeper mode" << std::endl;
}
void	ScavTrap::attack(std::string const& target)
{
	std::cout << "ScavTrap " << getName() << " attacks with a gun" << target;
	std::cout << ", causing " << getAD() << " points of damage, that's a big damage!" << std::endl;
}