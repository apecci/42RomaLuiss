/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <alessandro.pecci17@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:58:18 by apecci            #+#    #+#             */
/*   Updated: 2021/01/13 16:01:27 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			x;
	unsigned char	*y;

	x = 0;
	y = str;
	while (n > 0)
	{
		y[x] = c;
		x++;
		n--;
	}
	return (str);
}
