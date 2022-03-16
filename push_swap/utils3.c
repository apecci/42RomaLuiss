/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:53:24 by apecci            #+#    #+#             */
/*   Updated: 2021/10/27 15:53:25 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushsw.h"

void	ft_intcpy(int *stack, int *tmp, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		stack[i] = tmp[i];
		i++;
	}
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
	{
		*p = '\0';
		p++;
	}
}

void	*ft_calloc(size_t count, int size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	ft_one(t_struct *s)
{
	int	i;

	i = 0;
	while (i < s->len)
	{
		s->lis[i] = 1;
		i++;
	}
}

void	ft_sub(t_struct *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s->lis[i] != s->max)
		i++;
	s->sub = ft_calloc(sizeof(int), s->len);
	while (i >= 0)
	{
		if (s->lis[i] == s->max - j)
		{
			s->sub[i] = 1;
			j++;
		}
		i--;
	}
}
