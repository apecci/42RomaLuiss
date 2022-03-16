/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:02:37 by apecci            #+#    #+#             */
/*   Updated: 2022/03/16 15:02:38 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	init_pipe(int i, int *fd, int size)
{
	if (1 < size -1)
	{
		if (pipe(fd + i * 2) == -1)
			return (2);
	}
	return (0);
}

int	init_pipes(t_list ** lsthead)
{
	int		size;
	int		i;
	int		*fd;
	t_core	*cnt;
	t_list	*run;

	size = ft_lstsize(*lsthead);
	fd = ft_calloc((size - 1) * 2, sizeof(int));
	if (!fd)
		return (1);
	i = 0;
	run = *lsthead;
	while (i < size)
	{
		cnt = (t_core *)(run ->content);
		cnt->pipe = size - 1;
		cnt->pipen = i;
		cnt->fdpipe = fd;
		if (init_pipe(i, fd, size))
			return (2);
		i++;
		run = run->next;
	}
	return (0);
}

int	check_builtin(t_core *data, int len)
{
	if (!len)
		return (0);
	else if (len > 3 && !strncmp(data->tkn[0], "exit", len))
		return (1);
	else if (len > 1 && !strncmp(data->tkn[0], "cd", len))
		return (1);
	else if (len > 2 && !strncmp(data->tkn[0], "env", len))
		return (1);
	else if (len > 2 && !strncmp(data->tkn[0], "pwd", len))
		return (1);
	else if (len > 3 && !strncmp(data->tkn[0], "echo", len))
		return (1);
	else if (len > 5 && !strncmp(data->tkn[0], "export", len))
		return (1);
	else if (len > 4 && !strncmp(data->tkn[0], "unset", len))
		return (1);
	return (0);
}

void	close_pipe(t_core *data)
{
	int	in;

	if (data->pipe < 1)
		return ;
	in = data->pipen * 2;
	if (!data->pipen)
		close(data->fdpipe[1]);
	else if (data->pipen > 0 && data->pipen != data->pipe)
	{
		close(data->fdpipe[in + 1]);
		close(data->fdpipe[in - 2]);
	}
	else if (data->pipen == data-> pipe)
	{
		close (data->fdpipe[in - 2]);
		free(data->fdpipe);
	}
}

void	close_pipes(t_core *data)
{
	int	in;
	int	i;

	if (data->pipe < 1)
		return ;
	in = data->pipe * 2 + 1;
	i = 0;
	while (i <= in)
	{
		close(data->fdpipe[i]);
		i++;
	}
}