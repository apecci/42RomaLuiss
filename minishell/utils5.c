/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:01:13 by apecci            #+#    #+#             */
/*   Updated: 2022/03/16 15:01:14 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	sandro_error_print(t_list **head, char *str, int n)
{
	char	*name;

	if (str)
		perror(str);
	if (n < 0)
		n = EXIT_FAILURE;
	name = ft_itoa(n);
	init_env2(head, "?", name);
	free(name);
	return (n);
}

void	ft_putendl_fd(char *s, int fd)
{
	char	c;

	c = '\n';
	if (fd != 0)
	{
		write(fd, s, ft_strlen(s));
		write(fd, &c, 1);
	}	
}

void	sandro_cerror(t_list **head, char *s1, char *s2, int n)
{
	char	*str;

	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return ;
	ft_strlcat(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_putendl_fd(str, STDERR_FILENO);
	free(str);
	str = ft_itoa(n);
	init_env2(head, "?", str);
	free(str);
}