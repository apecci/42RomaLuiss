/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:38:48 by apecci            #+#    #+#             */
/*   Updated: 2022/01/21 16:38:50 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_table *table)
{
	if (table->philos)
		free(table->philos);
	if (table->mutex_fork)
		free(table->mutex_fork);
}

void	ft_close(t_table *table)
{
	int	i;

	i = 0;
	while (i++ < table->n_philo)
	{
		pthread_mutex_destroy(&table->mutex_fork[i]);
		pthread_detach(table->philos[i].t_id);
	}
	pthread_mutex_destroy(&table->mutex);
	pthread_mutex_destroy(&table->mutex_stampa);
	ft_free(table);
}
