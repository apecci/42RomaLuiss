/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:41:55 by apecci            #+#    #+#             */
/*   Updated: 2022/04/21 11:41:56 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(){
	std::string	in;
	PhoneBook phoneBook;

	std::cout << "Bienvenido nel PhoneBookko, que quiere hacer?" << std::endl;
	std::cout << "ADD | SEARCH | EXIT" << std::endl;
	std::getline(std::cin, in, '\n');
	while (in != "EXIT"){
		if (in == "ADD")
			phoneBook.addContact();
		if (in == "SEARCH")
			phoneBook.searchContact();
		std::cout << "Ahora que quiere hacer?" << std::endl;
		std::cout << "ADD | SEARCH | EXIT" << std::endl;
		std::getline(std::cin, in, '\n');
	}
	std::cout << "ADIOS BANDOLERO!" << std::endl;
	return (0);
}
