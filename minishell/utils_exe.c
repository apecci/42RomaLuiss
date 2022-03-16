/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:52:35 by apecci            #+#    #+#             */
/*   Updated: 2022/03/16 14:52:36 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_builtin(t_core *data, t_list **head, t_list **lsthead)
{
	int	len;
	int	bui;

	len = ft_strlen(data->tkn[0]);
	bui = check_builtin(data, len);
	if (bui)
		return (builtin_exe(data, head, len, lsthead));
	else if (!bui && len)
		
}

int	ft_execute(t_list **head, t_list **lsthead)
{
	t_core	*cnt;
	int		err;

	err = 0;
	block_sig_cmd();
	if (!head || !lsthead)
		return (0);
	if (ft_lstsize(*lsthead) > 1)
		err = err | init_pipes(lsthead);
	while (*lsthead && err >= 0)
	{
		cnt = (t_core *)((*lsthead)->content);
		err = ft_redirect(head, cnt);
		if (!err)
			err = err | ft_builtin(cnt, head, lsthead);
		err = err | ft_close_redirect(cnt);
		delete_first(lsthead);
	}
	return (err);
}
