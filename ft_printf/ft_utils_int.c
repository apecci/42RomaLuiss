/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:17:37 by apecci            #+#    #+#             */
/*   Updated: 2021/02/17 11:17:38 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printabile	ft_int_helper_1(t_printabile p, int num, char *support)
{
	if (num < 0)
		p = putstr_contatore(p, "-");
	while (p.precision > ft_strlen(support))
	{
		p = putstr_contatore(p, "0");
		p.precision--;
	}
	p = putstr_contatore(p, support);
	p.i++;
	return (p);
}

t_printabile	ft_int_helper_2(t_printabile p, int num, char *support)
{
	if (num < 0)
		p.width--;
	if (num < 0 && p.zero == 1)
		p = putstr_contatore(p, "-");
	while (p.width > ft_strlen(support) && p.minus == -1)
	{
		p = putstr_contatore(p, p.zero == -1 ? " " : "0");
		p.width--;
	}
	if (num < 0 && p.zero == -1)
		p = putstr_contatore(p, "-");
	p = putstr_contatore(p, support);
	while (p.width > ft_strlen(support) && p.minus == 1)
	{
		p = putstr_contatore(p, " ");
		p.width--;
	}
	p.i++;
	return (p);
}

t_printabile	ft_int_helper_3(t_printabile p, int num, char *support)
{
	int diff;

	num < 0 ? p.width-- : p.width * 1;
	diff = p.width - p.precision;
	if (ft_strlen(support) > p.precision)
		diff = p.width - ft_strlen(support);
	if (p.minus == -1)
		p = ft_print_until_diff(p, diff, " ");
	if (num < 0)
		p = putstr_contatore(p, "-");
	while (p.precision > ft_strlen(support))
	{
		p = putstr_contatore(p, "0");
		p.precision--;
	}
	p = putstr_contatore(p, support);
	while (diff > 0 && p.minus == 1)
	{
		p = putstr_contatore(p, " ");
		diff--;
	}
	p.i++;
	return (p);
}

t_printabile	ft_int_helper_4(t_printabile p)
{
	while (p.width-- > 0)
		p = putstr_contatore(p, " ");
	p.i += 2;
	return (p);
}

t_printabile	ft_int_handler(t_printabile p, va_list list)
{
	int		num;
	char	*support;

	num = va_arg(list, int);
	support = ft_itoa(num);
	if ((p.precision > 0) && p.width == -1)
		p = ft_int_helper_1(p, num, support);
	else if (p.precision < 0 && p.width != -1)
		p = ft_int_helper_2(p, num, support);
	else if (p.precision > 0 && p.width > 0)
		p = ft_int_helper_3(p, num, support);
	else if (p.precision == 0 && p.width == -1)
		p.i++;
	else if (p.precision == 0 && p.width != -1)
		p = ft_int_helper_4(p);
	else
	{
		if (num < 0)
			p = putstr_contatore(p, "-");
		p = putstr_contatore(p, support);
		p.zero == 1 ? p.i++ : p.i * 1;
		p.i++;
	}
	return (p);
}
