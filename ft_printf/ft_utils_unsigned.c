/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:18:22 by apecci            #+#    #+#             */
/*   Updated: 2021/02/17 11:18:24 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printabile	ft_unsigned_helper_4(t_printabile p, unsigned int num2)
{
	int			diff;

	diff = p.width - p.precision;
	if (ft_ndigit(num2) > p.precision)
		diff = p.width - ft_ndigit(num2);
	while (diff > 0 && p.minus == -1)
	{
		p = putstr_contatore(p, " ");
		diff--;
	}
	while (p.precision > ft_ndigit(num2))
	{
		p = putstr_contatore(p, "0");
		p.precision--;
	}
	num2 != 0 ? ft_putnbr_fd(num2, 1) : num2 * 1;
	p.contatore += ft_ndigit(num2);
	num2 == 0 ? p.contatore-- : p.contatore * 1;
	while (diff > 0 && p.minus == 1)
	{
		p = putstr_contatore(p, " ");
		diff--;
	}
	p.i++;
	return (p);
}

t_printabile	ft_unsigned_helper_1(t_printabile p, unsigned int support)
{
	int			len;

	len = ft_ndigit(support);
	support == 0 ? len += 1 : len * 1;
	while (p.width > len && p.minus == -1)
	{
		p = putstr_contatore(p, p.zero == -1 ? " " : "0");
		p.width--;
	}
	ft_putnbr_fd(support, 1);
	p.contatore += len;
	while (p.width > len && p.minus == 1)
	{
		p = putstr_contatore(p, p.zero == -1 ? " " : "0");
		p.width--;
	}
	return (p);
}

t_printabile	ft_precision_zero_handler(t_printabile p, unsigned int num2)
{
	num2 == 0 ? p.contatore-- : p.contatore * 1;
	if (p.width != -1)
	{
		while (p.width > 0 && p.width > num_of_digits(num2) && p.minus == -1)
		{
			p = putstr_contatore(p, " ");
			p.width--;
		}
		num2 != 0 ? ft_putnbr_fd(num2, 1) : num2 * 1;
		p.contatore += num_of_digits(num2);
		while (p.width > 0 && p.width > num_of_digits(num2) && p.minus == 1)
		{
			p = putstr_contatore(p, " ");
			p.width--;
		}
	}
	return (p);
}

t_printabile	ft_unsigned_helper_2(t_printabile p,
		long support_unsigned_num)
{
	while (p.precision > ft_ndigit(support_unsigned_num))
	{
		p = putstr_contatore(p, "0");
		p.precision--;
	}
	support_unsigned_num != 0 ?
		ft_putnbr_fd(support_unsigned_num, 1) : support_unsigned_num * 1;
	support_unsigned_num == 0 ? p.contatore-- : support_unsigned_num * 1;
	p.contatore += ft_ndigit(support_unsigned_num);
	return (p);
}

t_printabile	ft_unsigned(t_printabile p, va_list list)
{
	unsigned	int	num2;
	long			n;

	num2 = va_arg(list, unsigned int);
	n = (long)num2;
	if (p.width != -1 && p.precision < 0)
		p = ft_unsigned_helper_1(p, n);
	else if (p.width == -1 && p.precision > 0)
		p = ft_unsigned_helper_2(p, n);
	else if (p.width != -1 && p.precision > 0)
		p = ft_unsigned_helper_4(p, num2);
	else if (p.precision == 0)
		p = ft_precision_zero_handler(p, num2);
	else
	{
		p.precision != 0 ?
			ft_putnbr_fd(n, 1) : p.precision * 1;
		p.precision == 0 ? p.contatore-- : p.precision * 1;
		p.contatore += num_of_digits(n);
	}
	if ((n == 0 && p.precision != -1) ||
			(n == 0 && p.precision == -1 && p.width == -1))
		p.contatore++;
	p.i++;
	return (p);
}
