/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:52:24 by apecci            #+#    #+#             */
/*   Updated: 2022/03/14 15:52:25 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	init_sandro_shell(t_list **head,
							t_list **lsthead, char *in, char *p)
{
	while (1)
	{
		p = get_pro(*head);
		in_sig();
		in = readline(p);
		if (!in)
		{
			free(p);
			sandro_quit(head, lsthead);
		}
		free(p);
		if (!ft_strlen(in))
		{
			free(in);
			continue ;
		}
		add_history(in);
		in_scan(in, head, lsthead);
		if (!arg_reader(lsthead, 0, 0))
			ft_execute(head, lsthead);
		else
			sandro_cerror(head, "Syntax ", "Error", 2);
	}
}

static	void	sandroshell(void)
{
	int		fd;
	char	*str;

	fd = open("sandroshell.txt", O_RDONLY);
	str = NULL;
	if (fd < 0)
		return ;
	while (get_next_line(fd, &str) > 0)
	{
		printf("%s\n", str);
		free(str);
	}
	if (str)
		free(str);
	close(fd);
}

int	main(int argc, char **argv, char **envp)
{
	t_list	**head;
	t_list	**lsthead;

	if (argc && argv[1] && !envp)
		return (1);
	head = malloc(sizeof(t_list *));
	lsthead = malloc(sizeof(t_list *));
	if (!lsthead || !head)
		return (1);
	*head = NULL;
	*lsthead = NULL;
	sandroshell();
	init_env(head, envp);
	init_env2(head, "?", "0");
	init_sandro_shell(head, lsthead, NULL, NULL);
	return (0);
}
