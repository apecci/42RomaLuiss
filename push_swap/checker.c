/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:50:50 by apecci            #+#    #+#             */
/*   Updated: 2021/10/27 15:50:51 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushsw.h"

int	are_command(t_check *c, char *line)
{
	if (line[0] == 'p' && line[1] == 'a' && !line[2])
		ft_pa_c(c);
	else if (line[0] == 's' && line[1] == 'a' && line[2] == '\0')
		ft_sa_c(c);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\0')
		ft_ra_c(c);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a' && !line[3])
		ft_rra_c(c);
	else if (line[0] == 'p' && line[1] == 'b' && !line[2])
		ft_pb_c(c);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\0')
		ft_sb_c(c);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\0')
		ft_rb_c(c);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b' && !line[3])
		ft_rrb_c(c);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r' && !line[3])
		ft_rrr_c(c);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\0')
		ft_rr_c(c);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\0')
		ft_ss_c(c);
	else
		return (0);
	return (1);
}

void	you_make_me_make_moves(t_check *c, char *line)
{
	while (get_next_line(&line) > 0)
	{
		if (!(are_command(c, line)))
		{
			write(1, "Error\n", 6);
			exit (0);
		}
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
}

int	main(int ac, char **av)
{
	t_check		c;
	int			x;
	char		*line;

	x = 0;
	c.ac = ac;
	line = NULL;
	if (ac == 1)
		exit (0);
	integers(ac, av);
	parsing_c(&c, av);
	ft_init_c(&c);
	ft_av_copy_c(&c, av);
	double_search_c(&c);
	you_make_me_make_moves(&c, line);
	check_ascending(&c);
	free(c.a);
	free(c.b);
}
