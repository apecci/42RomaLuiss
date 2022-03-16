/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:51:17 by apecci            #+#    #+#             */
/*   Updated: 2021/10/27 15:51:18 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushsw.h"

int	get_next_line(char **line)
{
	char	buffer[1024 * 1024];
	int		res;
	int		i;

	i = 0;
	res = 0;
	if (!line)
		return (-1);
	while (res >= 0)
	{
		res = read(0, &buffer[i], 1);
		if (buffer[i] == '\n' || res == 0)
		{
			buffer[i] = 0;
			*line = ft_strdup(buffer);
			if (!*line)
				return (-1);
			if (res == 0)
				return (0);
			else
				return (1);
		}
		i++;
	}
	return (-1);
}
