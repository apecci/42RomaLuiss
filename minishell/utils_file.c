/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:35:07 by apecci            #+#    #+#             */
/*   Updated: 2022/04/04 16:08:30 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*path_name(char *name, char *path)
{
	char	*fnd;

	fnd = ft_calloc(ft_strlen(path) + ft_strlen(name) + 2, sizeof(char));
	if (!fnd)
		return (NULL);
	ft_strlcat(fnd, path, ft_strlen(path) + 1);
	ft_strlcat(fnd, "/", ft_strlen(fnd) + 2);
	ft_strlcat(fnd, name, ft_strlen(fnd) + ft_strlen(name) + 1);
	return (fnd);
}

static int	check_file(char *name, int flg)
{
	struct stat	buf;

	if (flg)
		return (flg);
	if (name && !stat(name, &buf))
		return (1);
	if (name)
		free (name);
	return (0);
}

static char	*name_check(char *name)
{
	struct stat	buf;
	char		*back;

	if (!ft_strchr(name, '/'))
		return (NULL);
	if (stat(name, &buf) < 0)
		return (NULL);
	back = ft_calloc(ft_strlen(name) + 1, sizeof(char));
	if (!back)
		return (NULL);
	back = ft_memcpy(back, name, ft_strlen(name));
	return (back);
}

char	*file_exists(char *name, char *path, int i)
{
	char	**srch;
	char	*fnd;
	int		flg;

	flg = 0;
	if (!path || !name)
		return (NULL);
	fnd = name_check(name);
	if (fnd)
		return (fnd);
	srch = ft_split(path, ':');
	while (srch[i])
	{
		if (!flg && !ft_strchr(name, '/'))
			fnd = path_name(name, srch[i]);
		flg = check_file(fnd, flg);
		free(srch[i]);
		i++;
	}
	free(srch);
	if (flg)
		return (fnd);
	else
		return (NULL);
}
