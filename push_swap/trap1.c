/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trap1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:52:52 by apecci            #+#    #+#             */
/*   Updated: 2021/10/27 15:52:53 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushsw.h"

void	ft_rb(t_struct *s)
{
	int	i;
	int	j;
	int	tmp[MAX_STACK_LEN];

	i = 1;
	j = 0;
	while (j < s->lb)
	{
		tmp[j] = s->b[i];
		i++;
		j++;
	}
	tmp[s->lb - 1] = s->b[0];
	ft_intcpy(s->b, tmp, s->lb);
	write(1, "rb\n", 3);
}

void	ft_rrb(t_struct *s)
{
	int	i;
	int	j;
	int	tmp[MAX_STACK_LEN];

	i = 1;
	j = 0;
	while (i < s->lb)
	{
		tmp[i] = s->b[j];
		i++;
		j++;
	}
	tmp[0] = s->b[s->lb - 1];
	ft_intcpy(s->b, tmp, s->lb);
	write(1, "rrb\n", 4);
}

void	ft_rra(t_struct *s)
{
	int	i;
	int	j;
	int	tmp[MAX_STACK_LEN];

	i = 1;
	j = 0;
	while (i < s->la)
	{
		tmp[i] = s->a[j];
		i++;
		j++;
	}
	tmp[0] = s->a[s->la - 1];
	ft_intcpy(s->a, tmp, s->la);
	write(1, "rra\n", 4);
}

void	ft_rr(t_struct *s)
{
	ft_ra1(s);
	ft_rb1(s);
	write(1, "rr\n", 3);
}

void	ft_rrr(t_struct *s)
{
	ft_rra1(s);
	ft_rrb1(s);
	write(1, "rrr\n", 4);
}
