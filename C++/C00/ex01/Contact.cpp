/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:53:37 by apecci            #+#    #+#             */
/*   Updated: 2022/04/27 11:53:38 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){
	return ;
}

Contact::~Contact(){
	return ;
}

void Contact::fillContact(){
	std::cout << "\x1b[34mGIMME YO FIRST NAME\x1b[0m" << std::endl;
	std::getline(std::cin, this->firstName, '\n');
	std::cout << "\x1b[34mGIMME YO LAST NAME\x1b[0m" << std::endl;
	std::getline(std::cin, this->lastName, '\n');
	std::cout << "\x1b[34mGIMME YO NICKNAME\x1b[0m" << std::endl;
	std::getline(std::cin, this->nickName, '\n');
	std::cout << "\x1b[34mGIMME YO PHONE NUMBER\x1b[0m" << std::endl;
	std::getline(std::cin, this->phoneNumber, '\n');
	std::cout << "\x1b[34mGIMME YO DARKEST SECRET\x1b[0m" << std::endl;
	std::getline(std::cin, this->darkestSecret, '\n');
	this->init = true;
	return ;
}

void Contact::displayContact(){
	std::cout << "\x1b[33mFirst Name     : \x1b[0m" << this->firstName << std::endl;
	std::cout << "\x1b[33mLast Name      : \x1b[0m" << this->lastName << std::endl;
	std::cout << "\x1b[33mNickName       : \x1b[0m" << this->nickName << std::endl;
	std::cout << "\x1b[33mPhone Number   : \x1b[0m" << this->phoneNumber << std::endl;
	std::cout << "\x1b[33mDarkest Secret : \x1b[0m" << this->darkestSecret << std::endl;
	return ;
}

void Contact::showSearchedContact(int i){
	std::cout << "|        " << i + 1 << "|";
	this->displayField(this->firstName);
	this->displayField(this->lastName);
	this->displayField(this->nickName);
	std::cout << std::endl;
	return ;
}

void Contact::displayField(std::string str){
	if (str.length() > 10)
		std::cout << std::setw(10) << str.substr(0, 9).append(".") << "|";
	else
		std::cout << std::right << std::setfill(' ') << std::setw(10) << str << "|";
	return ;
}

bool Contact::check() const{
	return (this->init);
}
