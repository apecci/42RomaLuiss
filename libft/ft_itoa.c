/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <alessandro.pecci17@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:44:05 by apecci            #+#    #+#             */
/*   Updated: 2021/01/14 12:44:06 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ndigit(int n)
{
	int c;

	c = 0;
	if (n < 0)
	{
		n *= -1;
		c++;
	}
	while (n != 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int nb)
{
	char	*str;
	long	n;
	int		i;

	n = nb;
	i = ft_ndigit(n);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (str);
}
