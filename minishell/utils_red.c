/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_red.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:10:56 by apecci            #+#    #+#             */
/*   Updated: 2022/03/16 15:10:57 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	inhandler(t_list **head, t_core *cnt)
{
	int	fd;

	fd = open(cnt->inname, O_RDONLY, 0644);
	if (fd = -1)
	{
		sandro_error_print(head, cnt->inname, -1);
		return (1);
	}
	cnt->fdin = dup(STDERR_FILENO);
	if (dup2(fd, STDIN_FILENO) == -1)
		sandro_error_print(head, "dup2", -1);
	if (cnt->fdin == -1)
	{
		sandro_error_print(head, "dup", -1);
		return (2);
	}
	return (0);
}

static int	outhandler(t_list **head, t_core *cnt)
{
	int	fd;

	fd = 0;
	if (cnt->redout == 1)
		fd = open(cnt->outname, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	else if (cnt->appout == 1)
		fd = open(cnt->outname, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
	{
		sandro_error_print(head, cnt->outname, -1);
		return (1);
	}
	cnt->fdout = dup(STDERR_FILENO);
	if (dup2(fd, STDOUT_FILENO) == -1)
		sandro_error_print(head, "dup2", -1);
	if (cnt->fdout == -1)
	{
		sandro_error_print(head, "dup", -1);
		return (2);
	}
	return (0);
}

int	ft_redirect(t_list **head, t_core *cnt)
{
	int	err;

	err = 0;
	if (cnt->redin)
		err = inhandler(head, cnt);
	if (!err && cnt->appin)
		fd_in(head, cnt);
	if (!err && (cnt->redout || cnt->appout))
		err = err | outhandler(head, cnt);
	return (err);
}

int	ft_close_redirect(t_core *cnt)
{
	int	err;

	err =0;
	if (cnt->fdin > 0)
	{
		err = dup2(cnt->fdin, STDIN_FILENO);
		close(cnt->fdin);
	}
	if (cnt->fdout > 0)
	{
		err = err | dup2(cnt->fdout, STDOUT_FILENO);
		close(cnt->fdout);
	}
	if (cnt->fd > 0)
	{
		err = err | dup2(cnt->fd, STDIN_FILENO);
		close(cnt->fd);
	}
	return (err);
}
