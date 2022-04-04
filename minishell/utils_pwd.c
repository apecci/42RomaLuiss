/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:19:59 by apecci            #+#    #+#             */
/*   Updated: 2022/04/04 16:11:12 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_pwd(t_list **head)
{
	char	*str;

	str = envget(*head, "PWD");
	if (str)
		printf("%s\n", str);
	sandro_error_print(head, NULL, 0);
}
