#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{

	FragTrap	frag("Mario Draghi");

	std::cout << "HP : " << frag.getHP() << std::endl;
	std::cout << "EP : " << frag.getEP() << std::endl;
	std::cout << "AD : " << frag.getAD() << std::endl;
	frag.highFivesGuys();
	frag.attack("il papato");
	frag.takeDamage(300);
	frag.beRepaired(242);

	return (0);
}