/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_general_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:16:33 by apecci            #+#    #+#             */
/*   Updated: 2021/02/17 11:16:35 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putchar_fd(int c, int fd)
{
	write(fd, &c, 1);
}

int				ft_strlen(char *s)
{
	int			len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int				ft_ndigit(int n)
{
	int			c;

	c = 0;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

char			*ft_itoa(int nb)
{
	char		*str;
	long		n;
	int			i;

	n = nb;
	i = ft_ndigit(n);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (str);
}
