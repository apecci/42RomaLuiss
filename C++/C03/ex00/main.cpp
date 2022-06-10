#include "ClapTrap.hpp"

int main()
{
	ClapTrap	clap("Roberto Saviano tutto matto");

	clap.attack("Sailor Moon");
	clap.takeDamage(7);
	clap.beRepaired(39);

	clap.attack("Roberto Benigni");
	clap.takeDamage(100);
	clap.beRepaired(42);

	return (0);
}