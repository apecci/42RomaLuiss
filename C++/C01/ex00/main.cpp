/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:42:31 by apecci            #+#    #+#             */
/*   Updated: 2022/04/28 12:42:33 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
	Zombie zombie("Mario Draghi");
	zombie.announce();

	randomChump("Lino Banfi");

	Zombie *dio = newZombie("Dio Brando");
	dio->announce();
	delete dio;

	return 0;
}
