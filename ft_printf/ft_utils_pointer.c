/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:17:49 by apecci            #+#    #+#             */
/*   Updated: 2021/02/17 11:17:50 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printabile	ft_pointer_handler_null_argument(t_printabile p)
{
	if (p.width != -1 && p.width > 2)
	{
		p.precision != 0 ? p.width-- : p.width * 1;
		if (p.minus == -1)
			p = ft_print_width_till_num_of_spaces(p, 2);
		p = putstr_contatore(p, "0x");
		if (p.precision != 0)
			p = putstr_contatore(p, "0");
		if (p.minus == 1)
			p = ft_print_width_till_num_of_spaces(p, 2);
	}
	else
	{
		p = putstr_contatore(p, "0x");
		if (p.precision != 0)
			p = putstr_contatore(p, "0");
	}
	p.i++;
	return (p);
}

t_printabile	ft_pointer_handle_multiple_flags(t_printabile p, char *support)
{
	int			diff;

	diff = p.width - p.precision;
	if ((ft_strlen(support) + 2) > p.precision)
		diff = p.width - (ft_strlen(support) + 2);
	while (diff > 0 && p.minus == -1)
	{
		p = putstr_contatore(p, " ");
		diff--;
	}
	p = putstr_contatore(p, "0x");
	while (p.precision > (ft_strlen(support) + 2))
	{
		p = putstr_contatore(p, "0");
		p.precision--;
	}
	p = putstr_contatore(p, ft_str_to_lower(support));
	while (diff > 0 && p.minus == 1)
	{
		p = putstr_contatore(p, " ");
		diff--;
	}
	return (p);
}

t_printabile	ft_pointer(t_printabile p, va_list list)
{
	size_t		num2;
	char		*support;

	if (!(num2 = (size_t)va_arg(list, void *)))
		return (p = ft_pointer_handler_null_argument(p));
	support = hexadecimalconvert_long(num2);
	if (p.width != -1 && p.precision < 0)
	{
		if (p.minus == -1)
			p = ft_print_width_till_num_of_spaces(p, (ft_strlen(support) + 2));
		p = putstr_contatore(p, "0x");
		p = putstr_contatore(p, ft_str_to_lower(support));
		if (p.minus == 1)
			p = ft_print_width_till_num_of_spaces(p, (ft_strlen(support) + 2));
	}
	else if (p.width != -1 && p.precision > 0)
		p = ft_pointer_handle_multiple_flags(p, support);
	else
	{
		p = putstr_contatore(p, "0x");
		p = putstr_contatore(p, ft_str_to_lower(support));
	}
	p.i++;
	free(support);
	return (p);
}
