/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:17:51 by apecci            #+#    #+#             */
/*   Updated: 2022/04/04 15:44:47 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	flg_check(char *s)
{
	if (!s || *s != '-')
		return (0);
	s++;
	while (*s)
	{
		if (*s != 'n')
			return (0);
		s++;
	}
	return (1);
}

static void	echo_print(char *s, int flg)
{
	if (!flg)
		write(STDOUT_FILENO, s, ft_strlen(s));
	else
	{
		write(STDOUT_FILENO, " ", 1);
		write(STDOUT_FILENO, s, ft_strlen(s));
	}
}

void	builtin_echo(t_list **head, t_core *data)
{
	int	i;
	int	flg;

	i = 1;
	flg = 0;
	while (flg_check(data->tkn[i]))
	{
		flg++;
		i++;
	}
	while (data->tkn[i])
	{
		if (ft_strlen(data->tkn[i]) != 0)
		{
			if ((!flg && i > 1) || (flg && i > flg * 1))
				echo_print(data->tkn[i], 1);
			else
				echo_print(data->tkn[i], 0);
		}
		i++;
	}
	if (!flg)
		printf("\n");
	sandro_error_print(head, NULL, 0);
}
