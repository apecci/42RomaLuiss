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

	std::cout << "\x1b[32mHI, I' M YOUR BRAND NEW PHONEBOOK, WHAT DO YOU WANT TO DO?\x1b[0m" << std::endl;
	std::cout << "\x1b[33mADD | SEARCH | EXIT\x1b[0m" << std::endl;
	std::getline(std::cin, in, '\n');
	while (in != "EXIT"){
		if (in == "ADD")
			phoneBook.addContact();
		else if (in == "SEARCH")
			phoneBook.searchContact();
		else
			std::cout << "\x1b[31mINVALID INPUT, STAY FOCUS!\x1b[0m";
		std::cout << "\x1b[32mLET'S GO AHEAD!\x1b[0m" << std::endl;
		std::cout << "\x1b[33mADD | SEARCH | EXIT\x1b[0m" << std::endl;
		std::getline(std::cin, in, '\n');
	}
	std::cout << "\x1b[36mGOOD BYE BABY!\x1b[0m" << std::endl;
	return (0);
}
