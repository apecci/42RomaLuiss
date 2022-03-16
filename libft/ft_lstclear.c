/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <alessandro.pecci17@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:25:38 by apecci            #+#    #+#             */
/*   Updated: 2021/01/18 12:43:13 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*clr;

	if (!del || !*lst || !*lst)
		return ;
	while (lst && *lst)
	{
		clr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = clr;
	}
}
