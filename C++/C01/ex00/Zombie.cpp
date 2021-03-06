/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:42:47 by apecci            #+#    #+#             */
/*   Updated: 2022/04/28 12:42:49 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->name = name;
	return;
}

Zombie::~Zombie(){
	std::cout << this->name + "Destroyed!" << std::endl;
	return;
}

void Zombie::announce(void) const{
	std::cout << this->name + ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}

std::string Zombie::getNome(void) const{
	return this->name;
}
