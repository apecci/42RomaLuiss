#include "ClapTrap.hpp"

int main()
{

	std::cout << "{ T1 - TERMINATOR }" << std::endl;
	ClapTrap	clap("T-800");

	clap.attack("Kyle Reese");
	clap.takeDamage(7);
	clap.beRepaired(39);

	clap.attack("Sarah Connor");
	clap.takeDamage(100);
	clap.beRepaired(42);

	return (0);
}