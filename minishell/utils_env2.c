/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:48:29 by apecci            #+#    #+#             */
/*   Updated: 2022/03/15 15:48:30 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_exp(char **m, int i)
{
	int	x;

	x = 0;
	while (m[i][x] && m[i][x] != '$' && m[i][x] != '"')
	{
		if (m[i][x] == '\'')
			return (0);
		x++;
	}
	return (1);
}

void	envexp(char **m, t_list **head)
{
	int		i;
	int		n;
	char	*str;

	i = 0;
	while (m[i])
	{
		if (is_exp(m, i))
		{
			n = 0;
			str = m[i];
			while (str && *str)
			{
				if (*str == '$')
					n++;
				str++;
			}
			while (n)
			{
				varexp(m, i, head);
				n--;
			}
		}
		i++;
	}
}

static int	ft_space(char c)
{
	if (((c >= 8) && (c <= 13)) || (c == 32))
		return (1);
	else
		return (0);
}

void	free_env(t_list **head, int flg)
{
	t_list	**crr;
	t_list	*next;
	int		i;

	i = 0;
	crr = head;
	while (*crr)
	{
		next = (*crr)->next;
		if (!flg)
			ft_lstdelone(*crr, &sandrolete);
		else
			ft_lstdelone(*crr, &comandelete);
		*crr = next;
		i++;
	}
	free(head);
}

int	ft_atoi(const char *nptr)
{
	int			sign;
	int			res;

	res = 0;
	sign = 1;
	while (ft_space(*nptr))
		nptr++;
	if ((*nptr == '-') || (*nptr == '+'))
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		res *= 10;
		res += (*nptr - 48);
		nptr++;
	}
	res *= sign;
	return (res);
}
