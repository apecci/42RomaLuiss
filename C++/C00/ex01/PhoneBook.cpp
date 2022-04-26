/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:42:05 by apecci            #+#    #+#             */
/*   Updated: 2022/04/21 11:42:06 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	this->i = 0;
	return ;
}
PhoneBook::~PhoneBook(){
	return ;
}

void PhoneBook::addContact(){
	this->i %= 8;
	this->contacts[this->i].fillContact();
	this->i++;
	return ;
}

void PhoneBook::searchContact(){
	int			i = 0;
	std::string src;

	if (this->contacts[i].check() == false)
	{
		std::cout << "No estan Contactos ayayay!" << std::endl;
	}
	else
	{
		std::cout << "|    Index|First Name| Last Name|  NickName|" << std::endl;
		while (i < 8 && this->contacts[i].check() == true)
		{
			this->contacts[i].showSearchedContact(i);
			i++;
		}
		std::cout << "QUE QUIERES BUSCAR?" << std::endl;
		std::getline(std::cin, src);
		//if (src[0] > '0' && src[0] < '8')
			
	}
	return ;
}
