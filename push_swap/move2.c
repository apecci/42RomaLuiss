/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:52:13 by apecci            #+#    #+#             */
/*   Updated: 2021/10/27 15:52:14 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushsw.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*str;
	unsigned char		*d;
	size_t				i;

	i = 0;
	str = src;
	d = dest;
	if (d == str)
		return (dest);
	if (str > d)
	{
		while (i < n)
		{
			d[i] = str[i];
			i++;
		}
	}
	else
		while (n--)
			d[n] = str[n];
	return (dest);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*ret;

	ret = malloc(size);
	 if (!ret)
		return (NULL);
	ft_memmove(ret, ptr, size);
	free(ptr);
	ptr = NULL;
	return (ret);
}

void	ft_sa(t_struct *s)
{
	int	tmp;

	if (s->la < 2)
		return ;
	tmp = s->a[0];
	s->a[0] = s->a[1];
	s->a[1] = tmp;
	write(1, "sa\n", 3);
}

void	ft_sb(t_struct *s)
{
	int	tmp;

	if (s->lb < 2)
		return ;
	tmp = s->b[0];
	s->b[0] = s->b[1];
	s->b[1] = tmp;
	write(1, "sb\n", 3);
}
