/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:23:25 by apecci            #+#    #+#             */
/*   Updated: 2022/03/16 14:23:26 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	settokin(t_core *cnt, int i, int flg)
{
	if (!cnt->tkn[i + 1])
		return (-666);
	if (flg)
		cnt->appin = 1;
	else
		cnt->redin = 1;
	if (!cnt->inname)
		cnt->inname = ft_strdup(cnt->tkn[i + 1]);
	free(cnt->tkn[i]);
	free(cnt->tkn[i + 1]);
	cnt->tkn[i] = NULL;
	cnt->tkn[i + 1] = NULL;
	return (i);
}

int	checktokin(t_core *cnt, int i)
{
	if (!cnt->tkn[i])
		return (i);
	if (!ft_strncmp(cnt->tkn[i], "<<", 3))
	{
		i = settokin(cnt, i, 1);
		return (i + 1);
	}
	else if (!ft_strncmp(cnt->tkn[i], "<", 2))
	{
		i = settokin(cnt, i, 0);
		return (i + 1);
	}
	return (i);
}

static int	settokout(t_core *cnt, int i, int flg)
{
	if (!cnt->tkn[i + 1])
		return (0);
	if (flg)
		cnt->appout = 1;
	else
		cnt->redout = 1;
	if (cnt->outname)
		free(cnt->outname);
	cnt->outname = ft_strdup(cnt->tkn[i + 1]);
	free(cnt->tkn[i]);
	free(cnt->tkn[i + 1]);
	cnt->tkn[i] = NULL;
	cnt->tkn[i + 1] = NULL;
	return (i);
}

int	checktokout(t_core *cnt, int i)
{
	if (!cnt->tkn[i])
		return (i);
	if (!ft_strncmp(cnt->tkn[i], ">>", 3))
	{
		i = settokout(cnt, i, 1);
		return (i + 1);
	}
	else if (!ft_strncmp(cnt->tkn[i], ">", 2))
	{
		i = settokout(cnt, i, 0);
		return (i + 1);
	}
	return (i);
}
