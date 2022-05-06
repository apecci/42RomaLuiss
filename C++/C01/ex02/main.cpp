/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:16:26 by apecci            #+#    #+#             */
/*   Updated: 2022/05/06 12:16:27 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string 	brain = "HI THIS IS BRAIN";
	std::string*	stringPTR = &brain;
	std::string&	stringREF = brain;

	std::cout << "BRAIN's Address		: " << &brain << std::endl;
	std::cout << "stringPTR's address	: " << stringPTR << std::endl;
	std::cout << "stringREF's address	: " << &stringREF << std::endl;
	std::cout << "stringVAL	: " << brain << std::endl;
	std::cout << "stringPTR	: " << *stringPTR << std::endl;
	std::cout << "stringREF	: " << stringREF << std::endl;
	return (0);
}
