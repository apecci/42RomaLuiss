/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:24:43 by apecci            #+#    #+#             */
/*   Updated: 2022/05/12 16:24:44 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
			Weapon* weapon;
			std::string name;
			bool hasWeapon;
	public:
			HumanB(std::string name);
			~HumanB();

			void attack();
			void setWeapon(Weapon& type);
};

#endif
