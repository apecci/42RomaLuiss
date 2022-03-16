/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:18:02 by apecci            #+#    #+#             */
/*   Updated: 2021/02/17 11:18:04 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printabile	putstr_contatore(t_printabile p, char *support)
{
	int	to_ret;

	to_ret = 0;
	while (support[to_ret])
	{
		ft_putchar_fd(support[to_ret], 1);
		p.contatore++;
		to_ret++;
	}
	return (p);
}

char			*ft_str_to_lower(char *support)
{
	int	i;

	i = 0;
	while (support[i])
	{
		support[i] = ft_tolower(support[i]);
		i++;
	}
	return (support);
}

t_printabile	ft_print_support_until_prec(t_printabile p, char *support)
{
	int	k;

	k = 0;
	while (k < p.precision && support[k] != '\0')
	{
		ft_putchar_fd(support[k], 1);
		p.contatore++;
		k++;
	}
	return (p);
}

t_printabile	ft_print_width_till_num_of_spaces(t_printabile p,
		int num_of_spaces)
{
	while (p.width > num_of_spaces)
	{
		p = putstr_contatore(p, " ");
		p.width--;
	}
	return (p);
}

t_printabile	ft_print_until_diff(t_printabile p, int diff, char *to_print)
{
	while (diff > 0)
	{
		p = putstr_contatore(p, to_print);
		diff--;
	}
	return (p);
}
