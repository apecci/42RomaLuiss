/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:00:29 by apecci            #+#    #+#             */
/*   Updated: 2022/05/06 12:00:30 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string name;
public:
	Zombie();
	~Zombie();

	void	announce(void) const;
	std::string getName() const;
	void setName(std::string name);
};

Zombie* zombieHorde(int i, std::string name);
#endif
