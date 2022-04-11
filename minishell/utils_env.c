/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:38:40 by apecci            #+#    #+#             */
/*   Updated: 2022/04/04 15:45:31 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_env2(t_list **head, char *name, char *value)
{
	t_env	*ptr;
	t_list	*it;

	it = *head;
	while (it)
	{
		ptr = (t_env *)(it->content);
		if (!ft_strncmp(ptr->name, name, ft_strlen(name) + 1))
			break ;
		it = it->next;
	}
	if (it)
	{
		free(ptr->value);
		ptr->value = ft_calloc(ft_strlen(value) + 1, sizeof(char));
		ptr->value = ft_memcpy(ptr->value, value, ft_strlen(value));
	}
	else
		return (is_new_lst(head, name, value));
	if (ptr->value)
		return (0);
	else
		return (1);
}

static int	get_eq_len(char *str)
{
	int	i;

	i = 0;
	while (*str && *str != '=')
	{
		i++;
		str++;
	}
	return (i);
}

char	**split(char *str)
{
	char	**new;
	int		len;

	if (!str || !*str)
		return (NULL);
	len = get_eq_len(str);
	new = ft_calloc(2, sizeof(char *));
	if (!new)
		return (NULL);
	new[0] = calloc(len + 1, sizeof(char));
	if (!new[0])
		return (NULL);
	new[0] = ft_memcpy(new[0], str, len);
	len = ft_strlen(str) - 1 - len;
	if (len)
		new[1] = calloc(len + 1, sizeof(char));
	else
		new[1] = NULL;
	if (new[1])
		new[1] = ft_memcpy(new[1], str + ft_strlen(new[0]) + 1, len);
	return (new);
}

static int	lst_add(t_list **head, char *str)
{
	t_env	*content;
	char	**strr;

	content = malloc(sizeof(t_env));
	if (!head || !str || !content)
		return (1);
	strr = split(str);
	if (!strr)
		return (1);
	content->name = strr[0];
	content->value = strr[1];
	ft_lstadd_back(head, ft_lstnew(content));
	free(strr);
	return (0);
}

int	init_env(t_list **head, char **envp)
{
	int	err;
	int	i;

	err = 0;
	i = 0;
	while (!err && envp && envp[i])
	{
		err = lst_add(head, envp[i]);
		i++;
	}
	if (!envp || !i)
		err = -1;
	return (err);
}
