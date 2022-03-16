/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:51:47 by apecci            #+#    #+#             */
/*   Updated: 2021/10/27 15:51:48 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushsw.h"

void	ft_pb_c(t_check *c)
{
	int	i;
	int	tmp;
	int	index;

	i = 0;
	index = 0;
	tmp = 0;
	if (c->la <= 0)
		return ;
	tmp = c->a[0];
	ft_ra_c(c);
	c->la--;
	c->lb++;
	ft_rrb_c(c);
	c->b[0] = tmp;
}

void	ft_rb_c(t_check *c)
{
	int	i;
	int	j;
	int	tmp[MAX_STACK_LEN];

	i = 1;
	j = 0;
	while (j < c->lb)
	{
		tmp[j] = c->b[i];
		i++;
		j++;
	}
	tmp[c->lb - 1] = c->b[0];
	ft_intcpy(c->b, tmp, c->lb);
}

void	ft_pa_c(t_check *c)
{
	int	i;
	int	tmp;
	int	index;

	index = 0;
	i = 0;
	tmp = 0;
	if (c->lb <= 0)
		return ;
	tmp = c->b[0];
	ft_rb_c(c);
	c->lb--;
	c->la++;
	ft_rra_c(c);
	c->a[0] = tmp;
}

void	ft_ra_c(t_check *c)
{
	int	j;
	int	tmp;
	int	i;
	int	index;

	j = 0;
	index = 0;
	i = 1;
	tmp = c->a[0];
	while (j < c->la - 1)
	{
		c->a[j] = c->a[i];
		j++;
		i++;
	}
	c->a[c->la - 1] = tmp;
}

void	ft_ss_c(t_check *c)
{
	ft_sa_c(c);
	ft_sb_c(c);
}
