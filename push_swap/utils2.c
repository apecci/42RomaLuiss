/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:53:19 by apecci            #+#    #+#             */
/*   Updated: 2021/10/27 15:53:19 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushsw.h"

static int	ft_wcount(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	return (ft_strlen(src));
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	char	*start;
	char	**array;

	array = malloc((ft_wcount(s, c) + 1) * sizeof(char *));
	if (!s || !array)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			array[i] = malloc((s - start) + 1);
			if (!array[i])
				return (NULL);
			ft_strlcpy(array[i++], start, s - start + 1);
		}
		else
			s++;
	}
	array[i] = 0;
	return (array);
}
