/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <alessandro.pecci17@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:19:05 by apecci            #+#    #+#             */
/*   Updated: 2021/01/22 17:00:45 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_n(char *ret, char **line, int rd)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	while (ret[i])
	{
		if (ret[i] == '\n')
			break ;
		i++;
	}
	if (i < ft_strlen(ret))
	{
		*line = ft_strsub(ret, 0, i);
		tmp = ft_strsub(ret, i + 1, ft_strlen(ret));
		free(ret);
		ret = ft_strdup(tmp);
		free(tmp);
	}
	else if (rd == 0)
	{
		*line = ret;
		ret = NULL;
	}
	return (ret);
}

char	*ft_ctrl(char *ret, char *buf)
{
	char	*tmp;

	if (!ret)
		ret = ft_strdup(buf);
	else
	{
		tmp = ft_strjoin(ret, buf);
		free(ret);
		ret = ft_strdup(tmp);
		free(tmp);
	}
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			rd;
	static char	*ret[BUFFER_SIZE + 1];

	if (fd < 0)
		return (-1);
	while ((rd = read(fd, buf, BUFFER_SIZE)))
	{
		if (rd < 0)
			return (-1);
		buf[rd] = '\0';
		ret[fd] = ft_ctrl(ret[fd], buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (rd <= 0 && !ret[fd])
	{
		*line = ft_strdup("");
		return (rd);
	}
	ret[fd] = ft_get_n(ret[fd], line, rd);
	if (rd <= 0 && !ret[fd])
		return (rd);
	return (1);
}
