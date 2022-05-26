/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:26:02 by apecci            #+#    #+#             */
/*   Updated: 2022/05/12 16:26:03 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type){
	return ;
}

Weapon::~Weapon(){
	return;
}

const std::string& Weapon::getType(){
	return(this->type);
}

void Weapon::setType(std::string type){
	this->type = type;
	return;
}

