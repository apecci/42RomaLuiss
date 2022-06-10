#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	bool    gatekeeper;

public:
	ScavTrap();
	ScavTrap(const ScavTrap& copy);
	ScavTrap(std::string name);
	~ScavTrap();

	void    guardGate();
	void	attack(std::string const& target);
	
};

#endif