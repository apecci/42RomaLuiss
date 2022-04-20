/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:33:38 by apecci            #+#    #+#             */
/*   Updated: 2022/04/20 14:33:39 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
public:
	Contact(void);
	Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string dk, int i);
	~Contact();
	int i;
};

class PhoneBook
{
private:
	/* data */
public:
	Contact contacts[8];

	PhoneBook(/* args */);
	~PhoneBook();
	void getPrompt();
	void add();
	void search();
	void exit();
	void displayContacts();
};

#endif