/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:42:02 by apecci            #+#    #+#             */
/*   Updated: 2022/03/15 15:42:03 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	display_pro(int i)
{
	i++;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	in_sig(void)
{
	signal(SIGINT, display_pro);
	signal(SIGQUIT, SIG_IGN);
}

static void	display_block_sig_cmd(int sig)
{
	sig++;
	write(1, "\n", 1);
}

static void	quit_pro(int sig)
{
	sig++;
	printf("Exit from Process...\n");
}

void	block_sig_cmd(void)
{
	signal(SIGINT, display_block_sig_cmd);
	signal(SIGQUIT, quit_pro);
}
