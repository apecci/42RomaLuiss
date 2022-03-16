/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_general.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:16:56 by apecci            #+#    #+#             */
/*   Updated: 2021/02/17 11:16:57 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		is_checkable(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
			|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void	ft_putnbr_fd(unsigned int n, int fd)
{
	unsigned int	nbr;

	if (n < 0)
	{
		nbr = (unsigned int)(-1 * n);
		write(1, &"-", 1);
	}
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	else
	{
		nbr = nbr + '0';
		write(1, &nbr, 1);
	}
}

int		ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}

int		ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}

int		is_number(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}
