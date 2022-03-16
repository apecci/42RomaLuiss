/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_checker2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:51:54 by apecci            #+#    #+#             */
/*   Updated: 2021/10/27 15:51:54 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushsw.h"

void	ft_sa_c(t_check *c)
{
	int	tmp;

	if (c->la < 2)
		return ;
	tmp = c->a[0];
	c->a[0] = c->a[1];
	c->a[1] = tmp;
}

void	ft_sb_c(t_check *c)
{
	int	tmp;

	if (c->lb < 2)
		return ;
	tmp = c->b[0];
	c->b[0] = c->b[1];
	c->b[1] = tmp;
}

void	ft_rrb_c(t_check *c)
{
	int	i;
	int	j;
	int	tmp[MAX_STACK_LEN];

	i = 1;
	j = 0;
	while (i < c->lb)
	{
		tmp[i] = c->b[j];
		i++;
		j++;
	}
	tmp[0] = c->b[c->lb - 1];
	ft_intcpy(c->b, tmp, c->lb);
}

void	ft_rra_c(t_check *c)
{
	int	i;
	int	j;
	int	tmp[MAX_STACK_LEN];

	i = 1;
	j = 0;
	while (i < c->la)
	{
		tmp[i] = c->a[j];
		i++;
		j++;
	}
	tmp[0] = c->a[c->la - 1];
	ft_intcpy(c->a, tmp, c->la);
}

void	ft_rr_c(t_check *c)
{
	ft_ra_c(c);
	ft_rb_c(c);
}
