/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <alessandro.pecci17@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:54:01 by apecci            #+#    #+#             */
/*   Updated: 2021/01/13 15:56:35 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				x;
	unsigned char		*y;
	unsigned const char	*z;

	x = 0;
	y = dest;
	z = src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		y[x] = z[x];
		x++;
		n--;
	}
	return (dest);
}
