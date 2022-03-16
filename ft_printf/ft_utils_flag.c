/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:16:20 by apecci            #+#    #+#             */
/*   Updated: 2021/02/17 11:16:21 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printabile	ft_find_width_string(t_printabile p, const char *s,
		int i, va_list list)
{
	int	res;
	int	j;

	j = p.j;
	res = 0;
	while (is_number(s[i + j]) == 1)
	{
		res *= 10;
		res += s[i + j] - '0';
		j++;
	}
	p.tipo = ft_find_tipo(s, (i + j));
	p.width = res;
	p = ft_find_precision_string(p, s, i, j);
	p.precision = ft_find_precision(s, (i + j), list);
	if (p.precision != -1)
		j += ft_ndigit(p.precision) + 1;
	p.j = j;
	return (p);
}

t_printabile	ft_find_width_param(t_printabile p, const char *s,
		int i, va_list list)
{
	int j;

	j = p.j;
	p.width = va_arg(list, int);
	p.tipo = ft_find_tipo(s, (i + j));
	j++;
	p.j = j;
	return (p);
}

t_printabile	ft_find_precision_support(t_printabile p, const char *s,
		int i, va_list list)
{
	p.precision = ft_find_precision(s, (i + p.j), list);
	p.tipo = ft_find_tipo(s, (i + p.j));
	p.j += 2;
	return (p);
}

t_printabile	ft_find_flags_support(t_printabile p, const char *s,
		int i, va_list list)
{
	if (s[i + p.j] == '-')
		p = ft_set_minus(p, s, i, p.j);
	else if (s[i + p.j] == '0')
		p = ft_set_zero(p);
	else if ((s[i + p.j] == '.') && (s[i + p.j + 1] == '*'))
		p = ft_find_precision_support(p, s, i, list);
	else if ((s[i + p.j] == '.') && (s[i + p.j + 1] != '*'))
	{
		p = ft_find_precision_string(p, s, i, p.j);
		return (p);
	}
	else if (is_number(s[i + p.j]) == 1 && s[i + p.j] != '0')
	{
		p = ft_find_width_string(p, s, i, list);
		return (p);
	}
	else if (s[i + p.j] == '*' && (is_checkable(s[i + p.j + 1])
				|| s[i + p.j + 1] == '.'))
	{
		p = ft_find_width_param(p, s, i, list);
		return (p);
	}
	p.j++;
	return (p);
}

t_printabile	ft_find_flags(t_printabile p, const char *s,
		int i, va_list list)
{
	i++;
	p.j = 0;
	while (s[i + p.j] != '%' && s[i + p.j] != '\0' &&
			s[i + p.j] != '\n' && (is_checkable(s[i + p.j]) == 0))
		p = ft_find_flags_support(p, s, i, list);
	if (p.width < -1)
	{
		p.minus = 1;
		p.width *= -1;
		p.zero = -1;
	}
	if ((is_checkable(p.tipo) == 1))
		p.zompa = p.j;
	else
		p.zompa = 0;
	return (p);
}
