/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:52:34 by apecci            #+#    #+#             */
/*   Updated: 2021/10/27 15:52:35 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushsw.h"

void	algoritmo(t_struct *s)
{
	s->la = s->len;
	while (s->la > 3)
	{
		while (find_smallest(s) != 0)
		{
			if (find_smallest(s) < (s->la / 2))
				ft_ra(s);
			else
				ft_rra(s);
		}
		ft_pb(s);
	}
	three_numbers(s);
	while (s->lb != 0)
		ft_pa(s);
}

int	find_smallest(t_struct *s)
{
	int	i;
	int	index;
	int	min;

	index = 0;
	min = s->a[0];
	i = 0;
	while (i < s->la)
	{
		if (s->a[i] < min)
		{
			min = s->a[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	double_search(t_struct *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j <= s->la - 1)
	{
		i = j + 1;
		while (i <= s->la - 1)
		{
			if (s->a[j] == s->a[i])
			{
				write(1, "Error\n", 6);
				exit (0);
			}
			i++;
		}
		j++;
	}
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

void	ft_errors(int ac, char **av, t_struct *s)
{
	if (ac == 1)
	{
		exit (0);
	}
	integers(ac, av);
	double_search(s);
	check_ascending_c(s);
}
