#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{


	std::cout << "ScaveTrappe" << std::endl;
	ScavTrap	trap("Smough");
	
	trap.guardGate();
	std::cout << "HP : " << trap.getHP() << std::endl;
	std::cout << "EP : " << trap.getEP() << std::endl;
	std::cout << "AD : " << trap.getAD() << std::endl;
	trap.attack("Roberto Benigni");
	trap.takeDamage(100);
	trap.beRepaired(42);

	return (0);
}