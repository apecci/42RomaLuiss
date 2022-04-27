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
		std::cout << "\x1b[31mI'M EMPTY BABY!\x1b[0m" << std::endl;
	}
	else
	{
		std::cout << "|    \x1b[33mIndex\x1b[0m|\x1b[33mFirst Name\x1b[0m| \x1b[33mLast Name\x1b[0m|  \x1b[33mNickName\x1b[0m|" << std::endl;
		while (i < 8 && this->contacts[i].check() == true)
		{
			this->contacts[i].showSearchedContact(i);
			i++;
		}
		std::cout << "\x1b[32mWHAT CONTACT DO YOU WANNA SEE?\x1b[0m" << std::endl;
		std::getline(std::cin, src);
		if (src[0] > '0' && src[0] < '8' && !src[1])
		{
			i = atoi(src.c_str());
			if (i >= 1 && i <= 8)
				this->contacts[i - 1].displayContact();
		}
		else
			std::cout << "\x1b[31mWRONG INDEX, STAY FOCUS!!\x1b[0m" << std::endl;
	}
	return ;
}
