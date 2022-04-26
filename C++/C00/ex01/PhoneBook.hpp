/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:30:55 by apecci            #+#    #+#             */
/*   Updated: 2022/04/20 14:30:56 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include <iomanip>
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int		i;
public:
	PhoneBook();
	~PhoneBook();

	void	addContact();
	void	searchContact();
};

#endif

