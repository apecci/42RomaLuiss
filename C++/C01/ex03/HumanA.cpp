/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:24:59 by apecci            #+#    #+#             */
/*   Updated: 2022/05/12 16:25:00 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& type) : weapon(type), name(name){
	std::cout << this->name << " join the fourth great ninja war";
	std::cout << " with a " << this->weapon.getType() << std::endl;
	return;
}

HumanA::~HumanA(){
	std::cout << this->name << " leaves the war suddenly" << std::endl;
	return;
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with " << this->weapon.getType() << std::endl;
	return ;
}
