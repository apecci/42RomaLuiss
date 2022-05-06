/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:00:02 by apecci            #+#    #+#             */
/*   Updated: 2022/05/06 12:00:03 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie Resurrected!" << std::endl;
	return ;
}

Zombie::~Zombie()
{
	std::cout << "Zombie Destroyed!" << std::endl;
	return ;
}

std::string	Zombie::getName()	const{
	return (this->name);
}

void		Zombie::setName(std::string name){
	this->name = name;
	return ;
}

void	Zombie::announce() const{
	std::cout << this->name << ": WRYYYYYYYYYYYYYY" << std::endl;
	return ;
}
