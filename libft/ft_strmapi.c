/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <alessandro.pecci17@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:47:06 by apecci            #+#    #+#             */
/*   Updated: 2021/01/14 17:47:08 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		str_len;
	char	*to_return;
	char	support;

	str_len = ft_strlen(s);
	i = 0;
	if (!(to_return = (char *)malloc(sizeof(char) * str_len + 1)))
		return (NULL);
	while (s[i])
	{
		support = f(i, s[i]);
		to_return[i] = support;
		i++;
	}
	to_return[i] = '\0';
	return (to_return);
}
