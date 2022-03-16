/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:43:23 by apecci            #+#    #+#             */
/*   Updated: 2022/03/16 14:43:24 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_cmd(void *lst)
{
	t_core	*cnt;
	int		i;

	i = 0;
	cnt = (t_core *)(lst);
	if (!cnt)
		return ;
	while (cnt->tkn[i])
	{
		free(cnt->tkn[i]);
		i++;
	}
	if (cnt->tkn)
		free(cnt->tkn);
	if (cnt->inname)
		free(cnt->inname);
	if (cnt->outname)
		free(cnt->outname);
	free(cnt);
}

void	delete_first(t_list **head)
{
	t_list	**crr;
	t_list	*next;

	crr = head;
	if (!*crr)
		return ;
	next = (*crr)->next;
	ft_lstdelone(*crr, delete_cmd);
	*crr = next;
	crr = &(*crr)->next;
}
