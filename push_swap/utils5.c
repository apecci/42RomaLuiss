/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:53:34 by apecci            #+#    #+#             */
/*   Updated: 2021/10/27 15:53:35 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushsw.h"

void	ft_ra1(t_struct *s)
{
	int	j;
	int	tmp;
	int	i;
	int	index;

	j = 0;
	i = 1;
	index = 0;
	tmp = s->a[0];
	while (j < s->la - 1)
	{
		s->a[j] = s->a[i];
		j++;
		i++;
	}
	s->a[s->la - 1] = tmp;
}

void	ft_rb1(t_struct *s)
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
}

void	ft_rrb1(t_struct *s)
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
}

void	ft_rra1(t_struct *s)
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
}
