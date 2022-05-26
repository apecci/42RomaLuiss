#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage  = 0;

	std::cout << std::endl << "[ I NEED YOUR CLOTHES, YOUR BOOTS AND YOUR MOTORBIKE! ]" << std::endl;
	std::cout << "ClapTrap " << name << " spawned in 1984 in Los Angeles, looking for Sarah Connor." << std::endl;
	return ;
}

ClapTrap::~ClapTrap()
{

	std::cout << std::endl << "[ I'LL BE BACK! ]" << std::endl;
	std::cout << "ClapTrap " << name << " was crashed with a hydraulic press." << std::endl;
	return ;
}

void	ClapTrap::attack(std::string const& target)
{
	std::cout << std::endl << "[ ASTA LA VISTA, BABY! ]" << std::endl;
	std::cout << "ClapTrap " << name << " attacks " << target;
	std::cout << ", causing " << attackDamage << " damage points!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << std::endl << "[ COME WITH ME IF YOU WANT TO LIVE! ]" << std::endl;
	std::cout << "ClapTrap " << name << " has been repaired." << std::endl;
	std::cout << "He has recovered " << amount << " damage points!" << std::endl;

	this->hitPoints += amount;

	std::cout << name << "'s total HPs are now " << hitPoints << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << std::endl << "[ I KNOW NOW WHY YOU CRY, BUT IT'S SOMETHING I CAN NEVER DO ]" << std::endl;
	std::cout << "ClapTrap " << name << " has been attacked! He gets " << amount << " damage points!" << std::endl;

	this->hitPoints -= amount;
	if (this->hitPoints <= 0)
	{
		this->hitPoints = 0;
		std::cout << "ClapTrap " << name << " got smashed." << std::endl;
	}
	std::cout << name << "'s total HPs are now " << hitPoints << std::endl;
}