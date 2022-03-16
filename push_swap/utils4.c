/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:53:28 by apecci            #+#    #+#             */
/*   Updated: 2021/10/27 15:53:29 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushsw.h"

char	*ft_strjoin(char *s1, char *s2, t_struct *s)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1 || !s2 || !str)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	s->mov++;
	return (str);
}

void	ft_push_sub_b(t_struct *s)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	j = 0;
	l = s->la;
	while (i < l)
	{
		if (s->sub[i] == 1)
			ft_ra(s);
		else
			ft_pb(s);
		i++;
	}
}

void	ft_push_sub_a(t_struct *s)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	j = 0;
	l = s->la;
	while (i < l)
	{
		if (s->sub[i] == 0)
			ft_ra(s);
		else
		{
			ft_pb(s);
		}
		i++;
	}
}

int	ft_isdigit(char c)
{
	if ((c >= '0' && c <= '9' ) || (c == '-') || c == ' ')
		return (1);
	return (0);
}
