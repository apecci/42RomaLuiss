/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:08:00 by apecci            #+#    #+#             */
/*   Updated: 2022/01/21 15:08:01 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char *str)
{
	printf("%s\n", str);
	exit(-1);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long long	get_time(void)
{
	struct timeval	time;
	long long		time_mill;

	gettimeofday(&time, NULL);
	time_mill = (time.tv_sec) * 1000 + (time.tv_usec) / 1000;
	return (time_mill);
}

void	ft_philoprint(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->table->mutex_stampa);
	printf("%lld %d %s\n", (get_time() - philo->table->start), philo->p_id, str);
	pthread_mutex_unlock(&philo->table->mutex_stampa);
}
