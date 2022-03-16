/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <alessandro.pecci17@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:48:19 by apecci            #+#    #+#             */
/*   Updated: 2021/01/13 15:50:38 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			x;
	unsigned char	*y;

	x = 0;
	y = s;
	while (n > 0)
	{
		y[x] = '\0';
		x++;
		n--;
	}
}
