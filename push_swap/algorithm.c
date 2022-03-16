/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:50:13 by apecci            #+#    #+#             */
/*   Updated: 2021/10/27 15:50:15 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushsw.h"

void	ft_max(t_struct *s)
{
	int	i;
	int	max;

	i = 0;
	max = -2147483647;
	while (i < s->la)
	{
		if (s->a[i] > max)
		{
			max = s->a[i];
		}
		i++;
	}
	s->mass = max;
}

void	ft_intimoves(t_count *count)
{
	count->j = 0;
	count->index = 0;
	count->max = 2147483647;
}

void	ft_ciclo1(t_count *count, t_struct *s, int pos)
{
	if (s->b[pos] < s->a[count->j] && s->a[count->j] < count->max)
	{
		count->max = s->a[count->j];
		count->index = count->j;
	}
	count->j++;
}

int	ft_count_moves(t_struct *s, int pos, t_count *count)
{
	ft_intimoves(count);
	ft_max(s);
	while (count->j < s->la)
		ft_ciclo1(count, s, pos);
	while (count->j > s->la)
	{
		if (s->b[pos] < s->a[count->j] && s->a[count->j] < count->max)
		{
			count->max = s->a[count->j];
			count->index = count->j;
		}
		count->j--;
	}
	count->j = 0;
	if (s->b[pos] > s->mass)
	{
		while (s->a[count->j] != s->mass)
			count->j++;
		count->index = count->j + 1;
	}
	s->x = count->index;
	if (count->index <= s->la / 2)
		return (count->index);
	else
		return (s->la - count->index);
}

int	ft_best_moves(t_struct *s, t_count *count)
{
	int	i;
	int	m;
	int	p;

	p = 0;
	m = 0;
	i = 0;
	s->pos = 100000;
	while (i < s->lb)
	{
		if (i < s->lb / 2)
			m = ft_count_moves(s, i, count) + i + 1;
		else
			m = ft_count_moves(s, i, count) + s->lb - i + 1;
		if (m < s->pos)
		{
			s->pos = m;
			p = i;
		}
		i++;
	}
	return (p);
}
