/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:32:25 by apecci            #+#    #+#             */
/*   Updated: 2022/03/14 16:32:27 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_new_lst(t_list **head, char *name, char *value)
{
	t_env	*cntn;

	cntn = malloc(sizeof(t_env));
	if (!head || !name || !value || !cntn)
		return (1);
	cntn->name = ft_calloc(ft_strlen(name) + 1, sizeof(char));
	cntn->value = ft_calloc(ft_strlen(value) + 1, sizeof(char));
	if (!cntn->name || !cntn->value)
		return (1);
	cntn->name = ft_memcpy(cntn->name, name, ft_strlen(name));
	cntn->value = ft_memcpy(cntn->value, value, ft_strlen(value));
	ft_lstadd_back(head, ft_lstnew(cntn));
	return (0);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (head == NULL)
		return (NULL);
	head->content = content;
	(*head).next = NULL;
	return (head);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*add;

	if (lst && new)
	{
		if (*lst)
		{
			add = ft_lstlast(*lst);
			add->next = new;
			new->next = NULL;
		}
		else
		{
			*lst = new;
			new->next = NULL;
		}
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*tgt;
	char			*ptr;

	tgt = (char *)dest;
	ptr = (char *)src;
	i = 0;
	while (i < n)
	{
		tgt[i] = ptr[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
