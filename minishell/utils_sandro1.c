/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sandro1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:09:30 by apecci            #+#    #+#             */
/*   Updated: 2022/03/15 16:09:31 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	copy_tkn(char **m, char **new, int i, int n)
{
	int	x;

	if (!new)
		return ;
	x = 0;
	while (x < n && m[i + x])
	{
		if (m[i + x][0] == '\"')
			new[x] = ft_strtrim(m[i + x], "\"");
		else
			new[x] = ft_strtrim(m[i + x], "\'");
		free(m[i + x]);
		x++;
	}
	new[x] = NULL;
}

static int	get_ntkn(char **m, int i)
{
	int	n;

	n = 0;
	while (m && m[i])
	{
		if (!ft_strncmp(m[i], "|\0", 2))
			break ;
		if (ft_strlen(m[i]))
			n++;
		i++;
	}
	return (n);
}

static void	init_cmdlst(char **m, t_list **lsthead)
{
	t_core	*cnt;
	int		i;
	int		n;

	i = 0;
	while (m && m[i])
	{
		n = get_ntkn(m, i);
		if (n)
		{
			cnt = ft_calloc(1, sizeof(t_core));
			if (!cnt)
				return ;
			cnt->tkn = ft_calloc(n + 1, sizeof(char *));
			copy_tkn(m, cnt->tkn, i, n);
			ft_lstadd_back(lsthead, ft_lstnew(cnt));
			i += n;
		}
		else
		{
			free(m[i]);
			i++;
		}
	}
}

static char	*sandrolizie(char *in)
{
	char	*hlp;

	hlp = ft_strtrim(in, " \t\r\n\v\f");
	if (!hlp)
		return (NULL);
	free(in);
	return (hlp);
}

void	in_scan(char *in, t_list **head, t_list **lsthead)
{
	char	**m;

	if (!in)
		return ;
	token_spacer(&in);
	in = sandrolizie(in);
	if (!ft_strlen(in))
	{
		free(in);
		return ;
	}
	m = token_cutter(in, head);
	if (m)
		init_cmdlst(m, lsthead);
	free(in);
	free(m);
}
