/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:07:28 by apecci            #+#    #+#             */
/*   Updated: 2022/01/21 15:07:30 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	*ft_die(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	while (1)
	{
		if (philo->table->counter == philo->table->n_philo)
		{
			pthread_mutex_lock(&philo->table->mutex_stampa);
			printf("Philosopers ate %d times! gnam gnam\n",
				philo->table->eat_times);
			pthread_mutex_unlock(&philo->table->mutex);
		}
		if (get_time() - philo->table->start > philo->time_to_die)
		{
			ft_philoprint(philo, "s'è morto! rip");
			pthread_mutex_lock(&philo->table->mutex_stampa);
			pthread_mutex_unlock(&philo->table->mutex);
		}
		usleep(500);
	}
}

static	void	ft_eat(t_philo	*philo)
{
	pthread_mutex_lock(&philo->table->mutex_fork[philo->f_sx]);
	ft_philoprint(philo, "takes sx fork");
	pthread_mutex_lock(&philo->table->mutex_fork[philo->f_dx]);
	ft_philoprint(philo, "takes dx fork");
	philo->time_to_die = get_time() - philo->table->start + philo->time_to_die;
	ft_philoprint(philo, "is eating! gnam gnam");
	usleep(philo->table->t_to_eat * 1000);
	pthread_mutex_unlock(&philo->table->mutex_fork[philo->f_sx]);
	pthread_mutex_unlock(&philo->table->mutex_fork[philo->f_dx]);
	if (philo->table->eat_times != -1)
		philo->eat_times++;
}

static	void	*routine(void *philos)
{
	t_philo		*philo;
	pthread_t	thread_id;

	philo = (t_philo *)philos;
	pthread_create(&thread_id, NULL, ft_die, philos);
	while (1)
	{
		ft_eat(philo);
		if (philo->eat_times == philo->table->eat_times)
			philo->table->counter++;
		ft_philoprint(philo, "is sleeping! zZz");
		usleep(philo->table->t_to_sleep * 1000);
		ft_philoprint(philo, "is thinking! ...");
	}
}

void	ft_socratis(t_table *table)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&table->mutex);
	while (++i < table->n_philo)
	{
		if (pthread_create(&table->philos[i].t_id, NULL, routine,
				(void*)&table->philos[i]))
			ft_error("errore creazione thread :(");
		usleep(100);
	}
	pthread_mutex_lock(&table->mutex);
}
