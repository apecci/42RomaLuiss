/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:00:20 by apecci            #+#    #+#             */
/*   Updated: 2022/05/06 12:00:21 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int i, std::string name){
		Zombie*		horde = new Zombie[i];
	std::string	nameZ[] = {"Dio Brando", "Mario Draghi", "Lino Banfi", "Jhon Cena", "Socrate tutto matto", "Carletto principe dei mostri"};
	int			x = 0;
	horde[0].setName(name);
	while (++x < i)
		horde[x].setName(nameZ[x - 1]);
	return(horde);
}
