/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:30:47 by apecci            #+#    #+#             */
/*   Updated: 2022/03/16 17:30:49 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    sandro_exit(t_list **env, t_list **ctt)
{
    int n;

    n = ft_atoi(envget(*env, "?"));
    if (env)
        free_env(env, 0);
    if (ctt)
        free_env(ctt, 1);
    exit(n);
}

void    exit_cmd(t_list **head, t_list **ctt, t_core *data)
{
    int i;
    int n;

    i = 0;
    n = 0;
    while (data->tkn[i])
    {
        if (ft_atoi(data->tkn[i]))
            n++;
        i++;
    }
    if (n > 1)
    {
        printf("exit: Too many Arguments!\n");
        sandro_error_print(head, NULL, 1);
        return ;
    }
    if (i > 1)
        sandro_error_print(head, NULL, ft_atoi(data->tkn[1]));
    sandro_exit(head, ctt);
}