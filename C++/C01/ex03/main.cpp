/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:25:53 by apecci            #+#    #+#             */
/*   Updated: 2022/05/12 16:25:54 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(){
	{
		Weapon club = Weapon("spiked club");

		HumanA bob("bob", club);
		bob.attack();
		club.setType("mitramortale");
		bob.attack();
	}

	{
		Weapon club = Weapon("spiked club");
		HumanB jim("jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("kunai matto fracico");
		jim.attack();
	}
	return (0);
}