/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:01:32 by apecci            #+#    #+#             */
/*   Updated: 2022/03/15 17:01:33 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*exper(char *old, char *ins, int in, int exit)
{
	char	*new;
	int		len;

	len = ft_strlen(old);
	if (ins)
		len += ft_strlen(ins);
	else
	{
		new = ft_calloc(len + 1, sizeof(char));
		ft_strlcpy(new, old, in);
		ft_strlcat(new, old + in + exit + 1, len);
		return (new);
	}
	new = ft_calloc(len + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, old, in + 1);
	ft_strlcat(new, ins, ft_strlen(new) + ft_strlen(ins) + 1);
	ft_strlcat(new, old + in + exit + 1, len);
	return (new);
}

static int	expinexit(char *str)
{
	int	n;

	n = 0;
	if (*str && *str == '?')
		return (1);
	while (*str && ft_isalnum(*str))
	{
		str++;
		n++;
	}
	return (n);
}

static int	mono_doll(char *str)
{
	if (ft_strlen(str) < 2)
		return (1);
	if (*str == '$' && *(str + 1) == '?')
		return (0);
	if (*str == '$' && ft_isalnum(*(str + 1)))
		return (0);
	return (1);
}

static int	expin(char *str)
{
	int	n;

	n = 0;
	while (*str && *(str + 1) && mono_doll(str))
	{
		str++;
		n++;
	}
	return (n);
}

void	varexp(char **m, int i, t_list **head)
{
	int		in;
	int		exit;
	char	*var;
	char	*new;
	char	*tmp;

	in = expin(m[i]);
	exit = expinexit(m[i] + in + 1);
	var = ft_substr(m[i], in + 1, exit);
	if (!ft_strlen(var))
	{
		free(var);
		return ;
	}
	tmp = envget(*head, var);
	if (!tmp)
		tmp = "";
	new = exper(m[i], tmp, in, exit);
	free(var);
	free(m[i]);
	m[i] = new;
}
