/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <alessandro.pecci17@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:56:23 by apecci            #+#    #+#             */
/*   Updated: 2021/01/12 11:02:10 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}
