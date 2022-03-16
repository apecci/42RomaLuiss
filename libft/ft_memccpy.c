/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <alessandro.pecci17@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:51:18 by apecci            #+#    #+#             */
/*   Updated: 2021/01/14 12:29:53 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_cicle(unsigned char *y, unsigned const char *z,
								unsigned char c1, size_t n)
{
	size_t				x;
	int					found;

	x = 0;
	found = 0;
	while (n > 0)
	{
		y[x] = z[x];
		x++;
		n--;
		if (c1 == z[x - 1])
		{
			found = 1;
			break ;
		}
	}
	if (found == 0)
	{
		return (NULL);
	}
	else
	{
		return (&y[x]);
	}
}

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*y;
	unsigned const char	*z;
	unsigned char		c1;

	y = dst;
	z = src;
	c1 = c;
	return (ft_cicle(y, z, c1, n));
}
