/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:52:07 by apecci            #+#    #+#             */
/*   Updated: 2021/10/27 15:52:08 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushsw.h"

void	ft_pb(t_struct *s)
{
	int	i;
	int	tmp;
	int	index;

	i = 0;
	index = 0;
	tmp = 0;
	if (s->la <= 0)
		return ;
	tmp = s->a[0];
	ft_ra1(s);
	s->la--;
	s->lb++;
	ft_rrb1(s);
	s->b[0] = tmp;
	write(1, "pb\n", 3);
}

void	ft_pa(t_struct *s)
{
	int	i;
	int	tmp;
	int	index;

	index = 0;
	i = 0;
	tmp = 0;
	if (s->lb <= 0)
		return ;
	tmp = s->b[0];
	ft_rb1(s);
	s->lb--;
	s->la++;
	ft_rra1(s);
	s->a[0] = tmp;
	write(1, "pa\n", 3);
}

void	ft_ra(t_struct *s)
{
	int	j;
	int	tmp;
	int	i;
	int	index;

	j = 0;
	index = 0;
	i = 1;
	tmp = s->a[0];
	while (j < s->la - 1)
	{
		s->a[j] = s->a[i];
		j++;
		i++;
	}
	s->a[s->la - 1] = tmp;
	write(1, "ra\n", 3);
}
