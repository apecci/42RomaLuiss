#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage  = 3;

	std::cout << "ClapTrap " << name << " spawnato" << std::endl;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " distrutto" << std::endl;
	return ;
}

void	ClapTrap::attack(std::string const& target)
{
	std::cout << "ClapTrap " << name << " attacks " << target;
	std::cout << ", causing " << attackDamage << " damage points!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " has been repaired." << std::endl;
	std::cout << "He has recovered " << amount << " damage points!" << std::endl;

	this->hitPoints += amount;

	std::cout << name << "'s total HPs are now " << hitPoints << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " has been attacked! He gets " << amount << " damage points!" << std::endl;

	this->hitPoints -= amount;
	if (this->hitPoints <= 0)
	{
		this->hitPoints = 0;
		std::cout << "ClapTrap " << name << " got smashed." << std::endl;
	}
	std::cout << name << "'s total HPs are now " << hitPoints << std::endl;
}

void ClapTrap::operator = (const ClapTrap &op)
{
	if (this == &op)
		return ;
	name = op.getName();
	hitPoints = op.getHP();
	energyPoints = op.getEP();
	attackDamage = op.getAD();
}

void			ClapTrap::setHP(unsigned int hp)
{
	this->hitPoints = hp;
}

void			ClapTrap::setEP(unsigned int ep)
{
	this->energyPoints = ep;
}

void			ClapTrap::setAD(unsigned int ad)
{
	this->attackDamage = ad;
}

int				ClapTrap::getHP() const
{
	return (this->hitPoints);
}

int				ClapTrap::getEP() const
{
	return (this->energyPoints);
}

int				ClapTrap::getAD() const
{
	return (this->attackDamage);
}

std::string		ClapTrap::getName() const
{
	return (this->name);
}