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
