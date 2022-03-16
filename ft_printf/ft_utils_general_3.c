/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_general_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:16:46 by apecci            #+#    #+#             */
/*   Updated: 2021/02/17 11:16:47 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printabile		ft_initialize(t_printabile p)
{
	p.tipo = 'H';
	p.zompa = 0;
	p.width = -1;
	p.precision = -1;
	p.zero = -1;
	p.minus = -1;
	p.j = 0;
	return (p);
}

size_t				hexlenght_long(size_t n)
{
	size_t			k;
	size_t			j;

	k = n;
	j = 0;
	while (k != 0)
	{
		j++;
		k = k / 16;
	}
	return (j);
}

char				*hexadecimalconvert_long(size_t n)
{
	size_t			k;
	size_t			g;
	size_t			j;
	char			*res;

	j = hexlenght_long(n);
	if (NULL == (res = malloc(sizeof(char) * j + 1)))
		return (NULL);
	k = n;
	res[j] = '\0';
	j -= 1;
	while (k != 0)
	{
		g = k % 16;
		if (g < 10)
			res[j--] = 48 + g;
		else
			res[j--] = 55 + g;
		k = k / 16;
	}
	return (res);
}

int					num_of_digits(long long n)
{
	long long	k;
	int			j;

	k = n;
	j = 0;
	while (k != 0)
	{
		j++;
		k = k / 10;
	}
	return (j);
}
