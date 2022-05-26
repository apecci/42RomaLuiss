/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:25:13 by apecci            #+#    #+#             */
/*   Updated: 2022/05/12 16:25:16 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name){
	this->name = name;
	this->hasWeapon = false;

	std::cout << this->name << " join the fourth great ninja war" << std::endl;
	return;
}

HumanB::~HumanB(){
	std::cout << this->name << " leaves the war suddenly" << std::endl;
	return;
}

void HumanB::attack(){
	if (this->hasWeapon)
		std::cout << this->name << " attacks with " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " don t have a weapon, use his fists " << std::endl;
	return;
}

void HumanB::setWeapon(Weapon& type){
	srand(time(0));
	this->hasWeapon = rand() %2;
	this->weapon = &type;
}