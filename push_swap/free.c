/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:51:06 by apecci            #+#    #+#             */
/*   Updated: 2021/10/27 15:51:06 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushsw.h"

void	ft_free(t_struct *s)
{
	free(s->a);
	free(s->b);
	free(s->lis);
	if (s->len >= 6)
		free(s->sub);
}

void	ft_polka(t_struct *s)
{
	while (find_smallest(s) != 0)
	{
		if (find_smallest(s) < (s->la / 2))
			ft_ra(s);
		else
			ft_rra(s);
	}
}

void	ft_maurizio_sarri(t_struct *s)
{
	int	min;

	min = find_smallest(s);
	if (min < 30 || min > s->len - 50)
		ft_polka(s);
}

int	check_ascending_c(t_struct *s)
{
	int	i;

	i = 0;
	while (i < s->la - 1 && s->a[i] < s->a[i + 1])
		i++;
	if (i == s->la - 1)
		exit (0);
	else
		return (0);
}
