/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:18:53 by apecci            #+#    #+#             */
/*   Updated: 2022/04/04 16:07:33 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	has_equal(char *str)
{
	if (str && (ft_strlen(str) < 3 || !ft_isalpha(*str)))
		return (0);
	while (str && *str)
	{
		if (!ft_isalnum(*str) && *str != '=')
			return (0);
		if (*str == '=')
			return (1);
		str++;
	}
	return (0);
}

static void	export_print(t_list **head)
{
	t_env	**ptr;
	int		i;

	i = 0;
	ptr = sort_env(head);
	while (ptr && ptr[i])
	{
		printf("Declare -x");
		printf("%s=\"", ptr[i]->name);
		if (envget(*head, ptr[i]->name))
			printf("%s\"\n", envget(*head, ptr[i]->name));
		else
			printf("\"\n");
		i++;
	}
	free(ptr);
}

static char	*trimmer(char *old)
{
	char	*new;

	if (old[0] == '\"')
		new = ft_strtrim(old, "\"");
	else if (old[0] == '\'')
		new = ft_strtrim(old, "\'");
	else
		return (old);
	free(old);
	return (new);
}

static void	export_error(t_list **head, char *tkn)
{
	char	*front;

	front = ft_calloc(9 + ft_strlen(tkn) + 1, sizeof(char));
	if (!front)
		return ;
	ft_strlcpy(front, "export: \'", 10);
	ft_strlcat(front, tkn, 9 + ft_strlen(tkn) + 1);
	sandro_cerror(head, front, "\' is not a valid identifier!", 1);
	free(front);
}

void	builtin_export(t_list **head, t_core *data)
{
	char	**new;
	int		i;

	i = 1;
	sandro_error_print(head, NULL, 0);
	while (ft_strlen(data->tkn[i]))
	{
		if (has_equal(data->tkn[i]))
		{
			new = split(data->tkn[i]);
			if (new[0] && new[1])
			{
				new[1] = trimmer(new[1]);
				init_env2(head, new[0], new[1]);
				free(new[0]);
				free(new[1]);
				free(new);
			}
		}
		else
			export_error(head, data->tkn[1]);
		i++;
	}
	if (i == 1)
		export_print(head);
}
