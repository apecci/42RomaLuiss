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

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <iostream>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	bool		init;
public:
	Contact(void);
	~Contact();
	void fillContact();
	void displaySearchMenu();
	void displayField(std::string str);
	void showSearchedContact(int i);
	bool check() const;
};

#endif