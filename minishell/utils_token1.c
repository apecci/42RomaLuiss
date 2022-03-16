/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:34:42 by apecci            #+#    #+#             */
/*   Updated: 2022/03/15 16:34:43 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*runner(char *str, char c)
{
	while (*str && *str != c)
		str++;
	if (*str)
		str++;
	return (str);
}

static char	*spacer(char *str)
{
	while (*str == 32 || (*str > 7 && *str < 14))
		str++;
	return (str);
}

static char	*cutter(char *start, char *end)
{
	int		len;
	char	*tkn;

	len = (int)(end - start);
	if (!len)
		return (NULL);
	tkn = ft_calloc(len + 1, sizeof(char));
	if (!tkn)
		return (NULL);
	tkn = ft_memcpy(tkn, start, len);
	return (tkn);
}

void	mfiller(char **m, char *start, char *end, int i)
{
	while (m && end && *end)
	{
		if (*end == 32)
		{
			m[i] = cutter(start, end);
			end = spacer(end);
			start = end;
			i++;
		}
		else if (*end == '"' || *end == '\'')
		{
			end = runner(end + 1, *end);
			m[i] = cutter(start, end);
			end = spacer(end);
			start = end;
			i++;
		}
		else if (*end)
			end++;
	}
	m[i] = cutter(start, end);
}
