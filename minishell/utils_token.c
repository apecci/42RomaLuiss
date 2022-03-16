/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:11:44 by apecci            #+#    #+#             */
/*   Updated: 2022/03/15 16:11:45 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**token_cutter(char *str, t_list **head)
{
	char	**m;

	m = ft_calloc(ft_strlen(str) + 1, sizeof(char *));
	if (!m)
		return (NULL);
	mfiller(m, str, str, 0);
	envexp(m, head);
	return (m);
}

static	char	*new_line(char *line, char *crr, int op_size, int offset)
{
	char	**hlp;
	char	*new;

	hlp = ft_calloc(6, sizeof(char *));
	if (!hlp)
		return (NULL);
	hlp[0] = ft_substr(line, 0, offset);
	hlp[1] = ft_substr(crr, 0, op_size);
	hlp[2] = strdup(crr + op_size);
	hlp[3] = ft_strjoin(hlp[0], " ");
	hlp[4] = ft_strjoin(hlp[3], hlp[1]);
	hlp[5] = ft_strjoin(hlp[4], " ");
	new = ft_strjoin(hlp[5], hlp[2]);
	free(hlp[0]);
	free(hlp[1]);
	free(hlp[2]);
	free(hlp[3]);
	free(hlp[4]);
	free(hlp[5]);
	free(hlp);
	return (new);
}

static	int	is_operator(char *str)
{
	if (!(ft_strncmp(str, "|", 1)))
	{
		if (ft_isalnum(*(str + 1)))
			return (1);
	}
	if (!(ft_strncmp(str, ">>", 2)) || !(ft_strncmp(str, "<<", 2)))
	{
		if (ft_isalnum(*(str + 2)))
			return (1);
	}
	if (!(ft_strncmp(str, ">", 1)) || !(ft_strncmp(str, "<", 1)))
	{
		if (ft_isalnum(*(str) + 1))
			return (1);
	}
	return (0);
}

static	char	*space_ins(char **line, char *crr, char *linein)
{
	char	*new;
	int		op_size;
	int		offset;

	if (crr != linein)
		if (*(crr -1) == '>' || *(crr - 1) == '<')
			return (crr++);
	if (*crr == *(crr + 1))
		op_size = 2;
	else
		op_size = 1;
	offset = crr - *line;
	new = new_line(*line, crr, op_size, offset);
	free(*line);
	*line = new;
	return (new + offset + op_size + 1);
}

void	token_spacer(char **line)
{
	char	*crr;
	char	*linein;
	char	is_quote;

	crr = *line;
	linein = *line;
	while (crr && *crr)
	{
		if ((*crr == '\'' && ft_strchr(crr + 1, '\''))
			|| ((*crr == '"' && ft_strchr(crr + 1, '"'))))
		{
			is_quote = *crr;
			crr++;
			while (*crr != is_quote)
				crr++;
		}
		if (is_operator(crr))
			crr = space_ins(line, crr, linein);
		crr++;
	}
}
