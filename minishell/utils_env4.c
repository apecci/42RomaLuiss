/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:23:36 by apecci            #+#    #+#             */
/*   Updated: 2022/03/15 17:23:37 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_env_n(t_list **head)
{
	int		i;
	t_list	*ptr;

	ptr = *head;
	i = 0;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

char	*envget(t_list *head, char *str)
{
	t_env	*value;

	if (!head || !str)
		return (NULL);
	while (head)
	{
		value = (t_env *)(head->content);
		if (!strncmp(value->name, str, ft_strlen(str) + 1))
			return (value->value);
		head = head->next;
	}
	return (NULL);
}

char	env_export(t_list **head)
{
	t_env	*cnt;
	t_list	*lst;
	char	**arr;
	char	*help;
	int		i;

	i = 0;
	arr = ft_calloc(get_env_n(head) + 1,sizeof(char *));
	if (!arr)
		return (NULL);
	lst = *head;
	while (lst)
	{
		cnt = (t_env *)(lst->content);
		help = ft_strjoin(cnt->name, "=");
		arr[i] = ft_strjoin(help, cnt->value);
		lst = lst->next;
		i++;
		free(help);
	}
	arr[i] = NULL;
	return (arr);
}

int	builtin_env(t_list **lst)
{
	t_env	*ptr;
	t_list	*head;

	if (!lst)
		return (1);
	head = *lst;
	while (head)
	{
		ptr = (t_env *)(head->content);
		printf("%s=", ptr->name);
		if (ptr->value)
			printf("%s\n", ptr->value);
		else
			printf("\n");
		head = head->next;
	}
	sandro_error_print(lst, NULL, 0);
	return (0);
}