/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <alessandro.pecci17@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:21:54 by apecci            #+#    #+#             */
/*   Updated: 2021/01/14 13:30:51 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		len_s1;
	char		*res;
	int			i;

	i = 0;
	len_s1 = ft_strlen(s1);
	if (NULL == (res = malloc(sizeof(char) * len_s1 + 1)))
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
