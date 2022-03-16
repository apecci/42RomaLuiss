/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:51:00 by apecci            #+#    #+#             */
/*   Updated: 2021/10/27 15:51:01 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushsw.h"

int	ft_isdigit(char c)
{
	if ((c >= '0' && c <= '9' ) || (c == '-') || c == ' ')
		return (1);
	return (0);
}

int	integers(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				write (1, "Error\n", 6);
				exit (0);
			}
			else
				j++;
		}
		i++;
	}
	return (1);
}

void	double_search_c(t_check *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j <= c->la - 1)
	{
		i = j + 1;
		while (i <= c->la - 1)
		{
			if (c->a[j] == c->a[i])
			{
				write(1, "Error\n", 6);
				exit (0);
			}
			i++;
		}
		j++;
	}
}
