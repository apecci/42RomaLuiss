/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:21:42 by apecci            #+#    #+#             */
/*   Updated: 2022/03/16 15:21:43 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	create_tmp_fd(void)
{
	return (open("tmp_fd", O_WRONLY | O_CREAT | O_TRUNC, 0600));
}

static int	expand(char *str)
{
	int	f;

	while (*str)
	{
		f = 0;
		while ( *str && *str == '$')
		{
			f = 1;
			str++;
		}
		if (f && *str && (ft_isalnum(*str) || *str == '?'))
			return (1);
		if (*str)
			str++;
	}
	return (0);
}

static void	get_write_in(t_list **head, t_core *cnt, int tmp)
{
	char	*in;

	signal(SIGINT, stop_fd);
	while(head)
	{
		in = readline("> ");
		if (!in)
			exit_fd(tmp, cnt->inname);
		if (ft_strncmp(in, cnt->inname, ft_strlen(in) + 1))
		{
			while(expand(in))
				varexp(&in, 0, head);
			ft_putendl_fd(in, tmp);
		}
		else
		{
			close(tmp);
			free(in);
			break ;
		}
		free(in);
	}
	exit(0);
}

static void	resetin(void)
{
	int	tmp;

	tmp = open(".tmp_fd", O_RDONLY);
	unlink(".tmp_fd");
	dup2(tmp, STDIN_FILENO);
	close(tmp);
}

void	fd_in(t_list **head, t_core *cnt)
{
	int	tmp;
	int	pid;
	int	status;

	tmp = create_tmp_fd();
	cnt->fd = dup(STDIN_FILENO);
	if (tmp == -1)
		return ;
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
	{
		get_write_in(head, cnt, tmp);
		close(tmp);
	}
	waitpid(pid, &status, 0);
	sandro_error_print(head, NULL, 0);
	resetin();
	close(tmp);
}