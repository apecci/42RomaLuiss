/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fd1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:35:37 by apecci            #+#    #+#             */
/*   Updated: 2022/03/16 15:35:38 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_fd(int fd, char *str)
{
	printf("Warning: wanted-> %s\n", str);
	close(fd);
	exit(errno);
}

void	stop_fd(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	eit(errno);
}
