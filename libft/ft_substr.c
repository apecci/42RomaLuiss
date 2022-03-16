/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <alessandro.pecci17@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:16:53 by apecci            #+#    #+#             */
/*   Updated: 2021/01/19 10:11:25 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*final;
	size_t			x;
	size_t			y;

	x = 0;
	y = 0;
	if (!(final = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s[x])
	{
		if (x >= start && y < len)
		{
			final[y] = s[x];
			y++;
		}
		x++;
	}
	final[y] = '\0';
	return (final);
}
