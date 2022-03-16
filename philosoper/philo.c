/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:29:04 by apecci            #+#    #+#             */
/*   Updated: 2022/01/17 16:29:06 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_ciec(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
		ft_error("Invalid number of Arguments");
	while (argv[++i])
	{
		if (ft_isnum(argv[i]) && ft_atoi(argv[i]) <= 0)
			ft_error("Invalid Arguments");
	}
	if (ft_atoi(argv[1]) < 1)
		ft_error("we need more Philos to work!");
}

int	main(int argc, char **argv)
{
	t_table	table;

	ft_ciec(argc, argv);
	ft_init(&table, argv);
	ft_socratis(&table);
	ft_close(&table);
	return (1);
}
