/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:17:10 by apecci            #+#    #+#             */
/*   Updated: 2021/02/17 11:17:11 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printabile	ft_hex_handle_zero_support1(t_printabile p)
{
	if (p.width != -1 && p.precision < 0)
	{
		while (p.width > 1 && p.minus == 1)
		{
			p = putstr_contatore(p, p.zero == -1 ? " " : "0");
			p.width--;
		}
	}
	else if (p.precision > 0 && p.width == -1)
	{
		while (p.precision > 1)
		{
			p = putstr_contatore(p, "0");
			p.precision--;
		}
	}
	return (p);
}

t_printabile	ft_hex_handle_zero(t_printabile p)
{
	if (p.precision > 0 && p.width != -1)
	{
		p = ft_hex_helper_3(p, "0");
		p.i++;
		return (p);
	}
	else if (p.precision == 0 && p.width == -1)
	{
		p.i++;
		return (p);
	}
	else if (p.precision == 0 && p.width != -1)
		return (p = ft_hex_handle_zero_support_3(p));
	while (p.width > 1 && p.minus == -1 && p.precision < 0)
	{
		p = putstr_contatore(p, p.zero == -1 ? " " : "0");
		p.width--;
	}
	p = putstr_contatore(p, "0");
	p = ft_hex_handle_zero_support1(p);
	p.i++;
	return (p);
}

t_printabile	ft_hex_helper_1(t_printabile p, char *support)
{
	while (p.precision > ft_strlen(support))
	{
		p = putstr_contatore(p, "0");
		p.precision--;
	}
	if (p.tipo == 'X')
		p = putstr_contatore(p, support);
	else
		p = putstr_contatore(p, ft_str_to_lower(support));
	p.i++;
	return (p);
}

t_printabile	ft_hex_support1(t_printabile p, char *support)
{
	while (p.width > ft_strlen(support) && p.minus == -1)
	{
		p = putstr_contatore(p, p.zero == -1 ? " " : "0");
		p.width--;
	}
	if (p.tipo == 'X')
		p = putstr_contatore(p, support);
	else if (p.tipo == 'x')
		p = putstr_contatore(p, ft_str_to_lower(support));
	while (p.width > ft_strlen(support) && p.minus == 1)
	{
		p = putstr_contatore(p, p.zero == -1 ? " " : "0");
		p.width--;
	}
	p.i++;
	return (p);
}

t_printabile	ft_hex_handler(t_printabile p, va_list list)
{
	char			*support;
	unsigned int	un_support;

	un_support = va_arg(list, long long int);
	if (un_support == 0)
		return (p = ft_hex_handle_zero(p));
	support = hexadecimalconvert_long(un_support);
	if (p.precision > 0 && p.width == -1)
		p = ft_hex_helper_1(p, support);
	else if (p.precision < 0 && p.width != -1)
		return (p = ft_hex_support1(p, support));
	else if (p.precision > 0 && p.width != -1)
		p = ft_hex_helper_3(p, support);
	else
	{
		p.i++;
		if (p.tipo == 'X')
			p = putstr_contatore(p, support);
		else
			p = putstr_contatore(p, ft_str_to_lower(support));
	}
	return (p);
}
