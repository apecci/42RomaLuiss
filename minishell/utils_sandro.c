/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sandro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:31:35 by apecci            #+#    #+#             */
/*   Updated: 2022/03/15 15:31:38 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	comandelete(void *lst)
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

void	sandrolete(void *lst)
{
	t_env	*cnt;

	cnt = (t_env *)(lst);
	if (cnt->name)
		free(cnt->name);
	if (cnt->value)
		free(cnt->value);
	free(cnt);
}

void	sandro_quit(t_list **env, t_list **c)
{
	int	n;

	n = ft_atoi(envget(*env, "?"));
	if (env)
		free_env(env, 0);
	if (c)
		free_env(c, 1);
	exit(n);
}

char	*get_pro(t_list *head)
{
	char	*pro;
	char	*name;
	char	*dir;

	name = envget(head, "LOGNAME");
	dir = envget(head, "PWD");
	pro = calloc(ft_strlen(name) + ft_strlen(dir) + 16, sizeof(char));
	ft_strlcat(pro, name, ft_strlen(name) + 1);
	ft_strlcat(pro, ":", ft_strlen(pro) + 9);
	ft_strlcat(pro, dir, ft_strlen(pro) + ft_strlen(dir) + 1);
	ft_strlcat(pro, " ", ft_strlen(pro) + 8);
	return (pro);
}
