/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:48:21 by apecci            #+#    #+#             */
/*   Updated: 2022/03/15 17:48:23 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(const char *s)
{
	char	*string;
	size_t	length;
	size_t	i;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	string = (char *)malloc(length + 1);
	if (string == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		string[i] = s[i];
		i++;
	}
	string[length] = '\0';
	return (string);
}

int	ft_isalnum(int c)
{
	if (((c >= 48) && (c <= 57)) || ((c >= 65) && (c <= 90))
		|| ((c >= 97) && (c <= 122)))
		return (1);
	else
		return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	j;

	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (ret);
	i = 0;
	j = 0;
	while (s[i])
	{
		if ((i >= start) && (j < len))
		{
			ret[j] = s[i];
			j++;
		}
		i++;
	}
	ret[j] = '\0';
	return (ret);
}

static int	ft_checkchr(char c, char const *pool)
{
	int	i;

	i = 0;
	while (pool[i])
	{
		if (pool[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;
	int		j;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (ft_checkchr(s1[i], set))
		i++;
	while ((i != len) && (ft_checkchr(s1[len - 1], set)))
		len--;
	len = len - i;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	j = 0;
	while (j < len)
	{
		ptr[j] = s1[i + j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
