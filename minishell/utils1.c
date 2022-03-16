/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:17:13 by apecci            #+#    #+#             */
/*   Updated: 2022/03/14 16:17:14 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	gnl_strlen(const char *s, int flag)
{
	size_t	i;

	i = 0;
	if (flag <= 0)
	{
		while (s[i] != '\0')
			i++;
	}
	else
		while (s[i] != '\0' && s[i] != '\n')
			i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	char	*bck;

	bck = (char *)s;
	while (*bck)
	{
		if (*bck == (char)c)
			return (bck);
		bck++;
	}
	if (!(*bck) && !c)
		return (bck);
	else
		return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	l;
	size_t	i;
	size_t	len;

	l = 0;
	i = 0;
	len = ft_strlen(dst);
	if (dstsize == 0 || (len > dstsize - 1))
		return (ft_strlen(src) + dstsize);
	l = len;
	while (((len + i) < (dstsize - 1)) && (src[i]))
	{
		dst[l] = src[i];
		l++;
		i++;
	}
	dst[l] = '\0';
	if (len >= dstsize)
		len = dstsize;
	return (len + ft_strlen(src));
}
