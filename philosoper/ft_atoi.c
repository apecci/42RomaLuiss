/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:08:08 by apecci            #+#    #+#             */
/*   Updated: 2022/01/21 15:08:10 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	ft_isspace(char c)
{
	if (c == '\n' || c == '\r' || c == '\f' || c == '\t' || c == '\v'
		|| c == ' ')
		return (1);
	return (0);
}

static	int	is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

static	int	is_char_int(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static	int	get_result(const char *str, long res, int s)
{
	while (is_char_int(*str))
	{
		res = res * 10 + (*str - '0');
		if (s == -1 && res > 2147483648)
			return (0);
		if (s == 1 && res > 2147483647)
			return (-1);
		str++;
	}
	return ((int)(res * s));
}

int	ft_atoi(const char *str)
{
	int		s;
	long	res;

	s = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	while (is_sign(*str))
	{
		if (*(str++) == '-')
			s = -1;
		break ;
	}
	return (get_result(str, res, s));
}
