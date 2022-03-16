/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_flag_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:16:09 by apecci            #+#    #+#             */
/*   Updated: 2021/02/17 11:16:10 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			ft_find_tipo(const char *s, int i)
{
	i++;
	while (s[i] != '%' || s[i] != '\0')
	{
		if (is_checkable(s[i]) == 1)
			return (s[i]);
		i++;
	}
	return ('M');
}

int				ft_find_precision(const char *s, int k, va_list lista)
{
	int	res;

	if ((s[k] == '.') && (s[k + 1] == '*'))
	{
		res = va_arg(lista, int);
		if (res < -1)
			res = -1;
		return (res);
	}
	return (-1);
}

t_printabile	ft_find_precision_string(t_printabile p, const char *s,
		int i, int j)
{
	int	res;
	int	all_zeros;

	all_zeros = 1;
	j++;
	res = 0;
	p.tipo = ft_find_tipo(s, (i + j));
	while (is_number(s[i + j]) == 1)
	{
		if (s[i + j] != '0')
			all_zeros = 0;
		res *= 10;
		res += s[i + j] - '0';
		j++;
	}
	if (all_zeros == 1)
	{
		p.precision = 0;
		p.j = j + 1;
		return (p);
	}
	res == 0 ? p.precision = -1 : p.precision * 1;
	res != 0 ? p.precision = res : p.precision * 1;
	p.j = j;
	return (p);
}

t_printabile	ft_set_minus(t_printabile p, const char *s,
		int i, int j)
{
	p.minus = 1;
	p.j = j;
	p.tipo = ft_find_tipo(s, (i + j));
	return (p);
}

t_printabile	ft_set_zero(t_printabile p)
{
	p.zero = 1;
	return (p);
}
