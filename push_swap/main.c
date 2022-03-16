/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:51:29 by apecci            #+#    #+#             */
/*   Updated: 2021/10/27 15:51:30 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushsw.h"

void	ranpapapam_volume_two(t_struct *s)
{
	if (s->len == 3)
	{
		three_numbers(s);
	}
	else if (s->len > 3 && s->len < 6)
	{
		algoritmo(s);
	}
}

int	index_max(t_struct *s)
{
	int	i;

	i = 0;
	while (s->a[i] != s->mass)
		i++;
	return (i);
}

void	ft_to_the_top(t_struct *s)
{
	int	index;

	index = index_max(s);
	if (index > s->la / 2)
	{
		while (s->a[s->la - 1] != s->mass)
			ft_rra(s);
	}
	else
	{
		while (s->a[s->la - 1] != s->mass)
			ft_ra(s);
	}
}

int	main(int ac, char **av)
{
	t_struct	s;
	t_count		count;
	int			index;

	s.ac = ac;
	parsing(&s, av);
	ft_init(&s);
	ft_av_copy(&s, av);
	ft_errors(ac, av, &s);
	if (s.len < 6)
		ranpapapam_volume_two(&s);
	else
	{
		lis(&s);
		ft_sub(&s);
		s.lb = 0;
		s.la = s.len;
		ft_push_sub_b(&s);
		while (s.lb > 0)
			ft_moves(&s, &count);
		index = index_max(&s);
		ft_to_the_top(&s);
	}
	ft_free(&s);
	return (0);
}
