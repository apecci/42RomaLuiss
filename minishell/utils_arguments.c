/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:15:48 by apecci            #+#    #+#             */
/*   Updated: 2022/03/16 14:15:49 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_error(t_list **head)
{
	t_list	**crr;
	t_list	*next;

	crr = head;
	while (*crr)
	{
		next = (*crr)->next;
		ft_lstdelone(*crr, &delete_cmd);
		*crr = next;
	}
	*head = NULL;
	delete_first(head);
}

static void	sort_back(char **m, int tok)
{
	int i;
	int x;

	i = 0;
	while (i < tok)
	{
		if (!m[i])
		{
			x = i + 1;
			while (x < tok)
			{
				if (m[x])
				{
					m[i] = ft_strdup(m[x]);
					free(m[x]);
					m[x] = NULL;
					break ;
				}
				x++;
			}
		}
		i++;
	}
}

static int	get_tok(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	arg_reader(t_list **lsthead)
{
	t_list	*lst;
	t_core	*cnt;
	int		i;
	int		tok;

	tok = 0;
	lst = *lsthead;
	while (lst)
	{
		cnt = (t_core *)(lst->content);
		tok = get_tok(cnt->tkn);
		i = 0;
		while (i < tok && i >= 0)
		{
			i = checktokin(cnt, i);
			if (i >= 0)
				i = checktokout(cnt, i);
			i++;
		}
		sort_back(cnt->tkn, tok);
		if (i < 0)
		{
			check_error(lsthead);
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}
