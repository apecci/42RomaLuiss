/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:52:35 by apecci            #+#    #+#             */
/*   Updated: 2022/03/16 14:52:36 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	is_path(t_list **head)
{
	char	*path;

	path = envget(*head, "PATH");
	if (path)
		return (path);
	else
		return ("./");
}

static void	prog_runner(t_list **head, t_core *data)
{
	char	*name;
	int		status;
	pid_t	pid;

	pid = 0;
	status = 0;
	name = NULL;
	name = file_exists(data->tkn[0], is_path(head), 0);
	if (name)
	{
		pid = fork();
		if (!pid)
			
	}
}

static int	ft_builtin(t_core *data, t_list **head, t_list **lsthead)
{
	int	len;
	int	bui;

	len = ft_strlen(data->tkn[0]);
	bui = check_builtin(data, len);
	if (bui)
		return (builtin_exe(data, head, len, lsthead));
	else if (!bui && len)
		prog_runner(head, data);
	return (0);
}

int	ft_execute(t_list **head, t_list **lsthead)
{
	t_core	*cnt;
	int		err;

	err = 0;
	block_sig_cmd();
	if (!head || !lsthead)
		return (0);
	if (ft_lstsize(*lsthead) > 1)
		err = err | init_pipes(lsthead);
	while (*lsthead && err >= 0)
	{
		cnt = (t_core *)((*lsthead)->content);
		err = ft_redirect(head, cnt);
		if (!err)
			err = err | ft_builtin(cnt, head, lsthead);
		err = err | ft_close_redirect(cnt);
		delete_first(lsthead);
	}
	return (err);
}
