/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:13:33 by apecci            #+#    #+#             */
/*   Updated: 2022/03/14 16:13:36 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_and_free(char **line, char **ptr, int err)
{
	if (!*line)
		*line = ft_calloc(1, sizeof(char));
	if (err == 0)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (0);
}

static int	ft_do_copy(char **line, char *ptr, int len)
{
	char	*hlp;

	if (!*line)
	{
		*line = ft_calloc(len + 1, sizeof(char));
		if (!*line)
			return (-1);
		ft_strlcat(*line, ptr, len + 1);
	}
	else
	{
		hlp = ft_calloc(len + 1, sizeof(char));
		if (!hlp)
			return (-1);
		ft_strlcat(hlp, *line, len + 1);
		ft_strlcat(hlp, ptr, len + 1);
		free(*line);
		*line = hlp;
	}
	return (1);
}

static int	ft_handle_cr(char **line, char *ptr)
{
	int		len;
	int		i;

	len = gnl_strlen(ptr, 1);
	if (!*line)
		i = ft_do_copy(line, ptr, len);
	else
		i = ft_do_copy(line, ptr, gnl_strlen(*line, 0) + len);
	if (i < 0)
		return (i);
	len++;
	i = 0;
	while (ptr[len + i])
	{
		ptr[i] = ptr[len + i];
		i++;
	}
	ft_bzero((ptr + i), len);
	return (1);
}

static int	ft_copy_content(char **line, char *ptr)
{
	int	err;
	int	len;

	len = gnl_strlen(ptr, 0);
	if (!*line)
		err = ft_do_copy(line, ptr, len);
	else
		err = ft_do_copy(line, ptr, len + gnl_strlen(*line, 0));
	if (err > 0)
		ft_bzero(ptr, len);
	return (err);
}

int	get_next_line(int fd, char **line)
{
	int			err;
	static char	*buffer[1024];

	err = 1;
	if (read(fd, NULL, 0) < 0 || !line)
		return (-1);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(32 + 1, sizeof(char));
	if (!buffer[fd])
		return (-1);
	if (*line)
		*line = NULL;
	if (gnl_strlen(buffer[fd], 0) == 0)
		err = read(fd, buffer[fd], 32);
	while (err > 0 && !(ft_strchr(buffer[fd], '\n')))
	{
		err = ft_copy_content(line, buffer[fd]);
		if (err > 0)
			err = read(fd, buffer[fd], 32);
	}
	if (err > 0)
		err = ft_handle_cr(line, buffer[fd]);
	ft_check_and_free(line, &buffer[fd], err);
	return (err);
}
