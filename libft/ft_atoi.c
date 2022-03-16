/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <alessandro.pecci17@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 08:49:07 by apecci            #+#    #+#             */
/*   Updated: 2021/01/12 09:10:30 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	seg;
	int	ret;

	i = 0;
	seg = 1;
	ret = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			seg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret *= 10;
		ret += str[i] - '0';
		i++;
	}
	return (ret * seg);
}
