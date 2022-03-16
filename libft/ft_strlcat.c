/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <alessandro.pecci17@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:03:03 by apecci            #+#    #+#             */
/*   Updated: 2021/01/13 17:11:33 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s1;
	size_t	s2;
	size_t	x;
	size_t	y;

	s1 = ft_strlen(dst);
	s2 = ft_strlen(src);
	x = s1;
	y = 0;
	if (s1 < dstsize - 1 && dstsize > 0)
	{
		while (src[y] != '\0' && (s1 + y) < (dstsize - 1))
		{
			dst[x] = src[y];
			x++;
			y++;
		}
		dst[x] = '\0';
	}
	if (s1 >= dstsize)
		s1 = dstsize;
	return (s1 + s2);
}
