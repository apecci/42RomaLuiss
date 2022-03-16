/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:52:40 by apecci            #+#    #+#             */
/*   Updated: 2021/10/27 15:52:41 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushsw.h"

static int	ft_spaces(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	long	nbr;
	long	sign;
	int		i;

	nbr = 0;
	sign = 1;
	i = 0;
	while ((str[i] != '\0') && ft_spaces(str[i]) == 1)
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] != '\0') && ('0' <= str[i]) && (str[i] <= '9'))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if ((nbr > 2147483647 && sign == 1) || (nbr > 2147483648 && sign == -1))
		{
			write(1, "Error\n", 6);
			exit (0);
		}
		i++;
	}
	return (sign * nbr);
}
