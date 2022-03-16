/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <alessandro.pecci17@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:08:33 by apecci            #+#    #+#             */
/*   Updated: 2021/01/15 12:34:27 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*res;
	int		i;
	int		j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (NULL == (res = (char *)malloc(sizeof(char) * (len_s1 + len_s2))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		j++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
