/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:50:29 by apecci            #+#    #+#             */
/*   Updated: 2021/10/27 15:50:30 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushsw.h"

void	ft_init_c(t_check *c)
{
	c->a = ft_calloc(sizeof(int), c->la);
	c->b = ft_calloc(sizeof(int), c->la);
	c->lb = 0;
}

void	parsing_c(t_check *c, char **av)
{
	int		i;
	int		j;
	char	**appo;

	i = 1;
	c->la = 0;
	while (i < c->ac)
	{
		j = 0;
		appo = ft_split(av[i], ' ');
		while (appo[j])
		{
			j++;
			c->la++;
		}
		j = 0;
		while (appo[j])
		{
			free(appo[j]);
			j++;
		}
		free(appo);
		i++;
	}
}

void	ft_av_copy_c(t_check *c, char **av)
{
	int		i;
	int		j;
	int		t;
	char	**appo;

	i = 1;
	t = 0;
	while (i < c->ac)
	{
		j = 0;
		appo = ft_split(av[i], ' ');
		while (appo[j])
		{
			c->a[t++] = ft_atoi(appo[j]);
			j++;
		}
		j = 0;
		while (appo[j])
		{
			free(appo[j]);
			j++;
		}
		free(appo);
		i++;
	}
}

int	check_ascending(t_check *c)
{
	int	i;

	i = 0;
	while (i < c->la - 1 && c->a[i] < c->a[i + 1])
		i++;
	if (i == c->la - 1)
	{
		write(1, "OK\n", 3);
		return (1);
	}
	else
	{
		write(1, "KO\n", 3);
		return (0);
	}
}
