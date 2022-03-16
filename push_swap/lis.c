/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:51:23 by apecci            #+#    #+#             */
/*   Updated: 2021/10/27 15:51:24 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushsw.h"

void	lis(t_struct *s)
{
	int	i;
	int	j;

	i = 0;
	ft_one(s);
	if (s->ac > 4)
		ft_maurizio_sarri(s);
	while (i < s->len)
	{
		j = i + 1;
		while (j < s->len)
		{
			if (s->a[i] < s->a[j] && s->lis[i] == s->lis[j])
			{
				s->lis[j] += 1;
				if (s->lis[j] > s->max)
				{
					s->max = s->lis[j];
					s->mass = s->a[j];
				}
			}
			j++;
		}
		i++;
	}
}

void	ft_init(t_struct *s)
{
	s->a = ft_calloc(sizeof(int), s->len);
	s->lis = ft_calloc(sizeof(int), s->len);
	s->b = ft_calloc(sizeof(int), s->len);
	s->pos = s->len * 2;
	s->la = s->len;
	s->max = 0;
}

void	parsing(t_struct *s, char **av)
{
	int		i;
	int		j;
	int		t;
	char	**appo;

	i = 1;
	t = 0;
	while (i < s->ac)
	{
		j = 0;
		appo = ft_split(av[i], ' ');
		while (appo[j++])
			t++;
		j = 0;
		while (appo[j])
		{
			free(appo[j]);
			j++;
		}
		free(appo);
		i++;
	}
	s->len = t;
}

void	ft_av_copy(t_struct *s, char **av)
{
	int		j;
	int		t;
	char	**appo;

	s->indicatore = 1;
	t = 0;
	while (s->indicatore < s->ac)
	{
		j = 0;
		appo = ft_split(av[s->indicatore], ' ');
		while (appo[j])
		{
			s->a[t] = ft_atoi(appo[j]);
			j++;
			t++;
		}
		j = 0;
		while (appo[j])
		{
			free(appo[j]);
			j++;
		}
		free(appo);
		s->indicatore++;
	}
}

void	three_numbers(t_struct *s)
{
	if (s->a[2] < s->a[1] && s->a[1] < s->a[0])
	{
		ft_ra(s);
		ft_sa(s);
	}
	else if (s->a[1] < s->a[0] && s->a[0] < s->a[2])
		ft_sa(s);
	else if (s->a[1] < s->a[2] && s->a[2] < s->a[0])
		ft_ra(s);
	else if (s->a[0] < s->a[2] && s->a[2] < s->a[1])
	{
		ft_rra(s);
		ft_sa(s);
	}
	else if (s->a[2] < s->a[0] && s->a[0] < s->a[1])
		ft_rra(s);
}
