/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:00:34 by apecci            #+#    #+#             */
/*   Updated: 2022/03/16 17:00:35 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	to_fork(t_core *data, int len)
{
	if (!data->pipe)
		return (0);
	if (len > 2 && !ft_strncmp(data->tkn[0], "env", len))
		return (1);
	else if (len > 2 && !ft_strncmp(data->tkn[0], "pwd", len))
		return (1);
	else if (len > 3 && !ft_strncmp(data->tkn[0], "echo", len))
		return (1);
	else if (len > 5 && !ft_strncmp(data->tkn[0], "export", len))
	{
		if (ft_strlen(data->tkn[1]))
			return (0);
		else
			return (1);
	}
	return (0);
}

static int	builtin_run(t_core *data, t_list **head, int len, t_list **cnt)
{
	if (len > 3 && !data->pipe && !ft_strncmp(data->tkn[0], "exit", len))
		exit_cmd(head, cnt, data);
	else if (len > 1 && !ft_strncmp(data->tkn[0], "cd", len))
		builtin_cd(head, data);
	else if (len > 2 && !ft_strncmp(data->tkn[0], "env", len))
		builtin_env(head);
	else if (len > 2 && !ft_strncmp(data->tkn[0], "pwd", len))
		builtin_pwd(head);
	else if (len > 3 && !ft_strncmp(data->tkn[0], "echo", len))
		builtin_echo(head, data);
	else if (len > 5 && !ft_strncmp(data->tkn[0], "export", len))
		builtin_export(head, data);
	else if (len > 4 && !ft_strncmp(data->tkn[0], "unset", len))
		builtin_unset(head, data);
	return (0);
}

static void	builtin_pipe(t_core *data)
{
	int	in;

	data->pin = dup(STDIN_FILENO);
	data->pout = dup(STDOUT_FILENO);
	in = data->pipen * 2;
	if (data->pipen != data->pipe)
		dup2(data->fdpipe[in + 1], STDOUT_FILENO);
	if (data->pipen > 0)
		dup2(data->fdpipe[in - 2], STDIN_FILENO);
}

static void	pipe_destroyer(t_core *data)
{
	dup2(data->pin, STDIN_FILENO);
	dup2(data->pout, STDOUT_FILENO);
	close(data->pin);
	close(data->pout);
}

int	builtin_exe(t_core *data, t_list **head, int len, t_list **lsthead)
{
	int	err;

	err = 0;
	if (!to_fork(data, len))
		err = builtin_run(data, head, len, lsthead);
	else
	{
		builtin_pipe(data);
		err = builtin_run(data, head, len ,lsthead);
		pipe_destroyer(data);
	}
	close_pipe(data);
	return (err);
}