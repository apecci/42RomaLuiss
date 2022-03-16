/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:07:40 by apecci            #+#    #+#             */
/*   Updated: 2022/01/21 15:07:41 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	ft_philos(t_table *table)
{
	int	i;

	i = -1;
	table->philos = (t_philo *)malloc(sizeof(t_philo) * table->n_philo);
	if (!table->philos)
		ft_error("mallocamiento brutto brutto!");
	while (++i < table->n_philo)
	{
		table->philos[i].table = table;
		table->philos[i].p_id = i + 1;
		table->philos[i].eat_times = 0;
		table->philos[i].time_to_die = table->t_to_die;
		table->philos[i].f_dx = (i + 1) % (table->n_philo);
		table->philos[i].f_sx = i;
	}
}

static	void	ft_mutex_fork(t_table *table)
{
	int	i;

	i = -1;
	table->mutex_fork = (pthread_mutex_t *)malloc
		(sizeof(pthread_mutex_t) * table->n_philo);
	if (!table->mutex_fork)
		ft_error("Mallocamiento brutto brutto!");
	while (++i < table->n_philo)
	{
		if (pthread_mutex_init(&table->mutex_fork[i], NULL))
			ft_error("Mutexamiento brutto brutto!");
	}
}

static	void	ft_mutex(t_table *table)
{
	if (pthread_mutex_init(&table->mutex, NULL))
		ft_error("Mutexamiento brutto brutto!");
	if (pthread_mutex_init(&table->mutex_stampa, NULL))
		ft_error("Mutexamiento brutto brutto!");
}

static	void	ft_init_table(t_table *table, char **argv)
{
	table->n_philo = ft_atoi(argv[1]);
	table->t_to_die = ft_atoi(argv[2]);
	table->t_to_eat = ft_atoi(argv[3]);
	table->t_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->eat_times = ft_atoi(argv[5]);
	else
		table->eat_times = -1;
	table->start = get_time();
	table->counter = 0;
}

void	ft_init(t_table *table, char **argv)
{
	ft_init_table(table, argv);
	ft_philos(table);
	ft_mutex_fork(table);
	ft_mutex(table);
}
