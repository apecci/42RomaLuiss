#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
protected:
	std::string	name;
	int			hitPoints;
	int			energyPoints;
	int			attackDamage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& copy);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void			operator = (const ClapTrap &op);
	
	void			setHP(unsigned int hp);
	void			setEP(unsigned int hp);
	void			setAD(unsigned int hp);

	int				getHP() const;
	int				getEP() const;
	int				getAD() const;
	std::string		getName() const;
};

#endif