/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:59:52 by apecci            #+#    #+#             */
/*   Updated: 2022/05/06 11:59:54 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
	Zombie	*horde;
	int		nbZombies = 7;
	int		i = 0;
	
	horde = zombieHorde(nbZombies, "Sailor Moon");
	while (i < nbZombies)
	{
		horde[i].announce();
		i++;
	}
	delete [] horde;
	return (0);
}
