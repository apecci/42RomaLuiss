/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:52:46 by apecci            #+#    #+#             */
/*   Updated: 2021/10/27 15:52:47 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushsw.h"

void	runpapapam(int j, int i, t_struct *s)
{
	if (j < s->la / 2)
		while (j-- > 0)
			ft_ra(s);
	else
		while (s->la != j++)
			ft_rra(s);
	if (i < s->lb / 2)
		while (i-- > 0)
			ft_rb(s);
	else
		while (i++ != s->lb)
			ft_rrb(s);
	ft_pa(s);
	ft_max(s);
}

void	ft_moves(t_struct *s, t_count *count)
{
	int	i;
	int	usless;

	i = ft_best_moves(s, count);
	usless = ft_count_moves(s, i, count);
	if (s->x < s->la / 2 && i < s->lb / 2)
	{
		while (i > 0 && s->x > 0)
		{
			ft_rr(s);
			i--;
			s->x--;
		}
	}
	else if (s->x >= s->la / 2 && i >= s->lb / 2)
	{
		while (i != s->lb && s->x != s->la)
		{
			ft_rrr(s);
			s->x++;
			i++;
		}
	}
	runpapapam (s->x, i, s);
}
