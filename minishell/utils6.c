/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:01:42 by apecci            #+#    #+#             */
/*   Updated: 2022/03/16 16:01:43 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_getlen(long long n, int len)
{
	if (n < 0)
	{
		n *= -1;
		len = 1;
	}
	if (n < 10)
		len++;
	else
	{
		len++;
		len = ft_getlen((n / 10), len);
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	long long	x;
	char		*str;

	x = n;
	len = ft_getlen(x, 0);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (str);
	str[len] = 0;
	if (x < 0)
		x *= -1;
	while (len > 0)
	{
		str[len - 1] = 48 + (x % 10);
		x /= 10;
		len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	alen;
	size_t	blen;
	char	*ptr;

	alen = ft_strlen(s1) + 1;
	blen = ft_strlen(s2) + 1;
	ptr = malloc(sizeof(char) * (alen + blen + 1));
	if (!ptr)
		return (ptr);
	if (s1)
		ft_strlcpy(ptr, s1, alen);
	if (s2)
		ft_strlcat(ptr, s2, blen + alen + 1);
	return (ptr);
}

int	ft_isalpha(int c)
{
	if (((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)))
		return (1);
	else
		return (0);
}
