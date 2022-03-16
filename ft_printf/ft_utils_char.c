/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:15:56 by apecci            #+#    #+#             */
/*   Updated: 2021/02/17 11:15:58 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printabile	ft_putchar_simple(t_printabile p, const char *s)
{
	ft_putchar_fd(s[p.i], 1);
	p.contatore++;
	return (p);
}

t_printabile	ft_char(t_printabile p, va_list list)
{
	char	ret_c;

	ret_c = va_arg(list, int);
	p.width--;
	while (p.minus == -1 && p.width-- > 0)
		p = putstr_contatore(p, " ");
	ft_putchar_fd(ret_c, 1);
	while (p.minus == 1 && p.width-- > 0)
		p = putstr_contatore(p, " ");
	p.contatore++;
	p.i++;
	return (p);
}

t_printabile	ft_percent(t_printabile p)
{
	while (p.width > 1 && p.minus == -1)
	{
		p = putstr_contatore(p, p.zero == -1 ? " " : "0");
		p.width--;
	}
	p = putstr_contatore(p, "%");
	while (p.width > 1 && p.minus == 1)
	{
		p = putstr_contatore(p, " ");
		p.width--;
	}
	p.i++;
	return (p);
}
