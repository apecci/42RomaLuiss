/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:29:19 by apecci            #+#    #+#             */
/*   Updated: 2022/01/17 16:29:21 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_philo {
	int				p_id;
	int				eat_times;
	int				time_to_die;
	int				f_sx;
	int				f_dx;
	struct s_table	*table;
	pthread_t		t_id;
}				t_philo;

typedef struct s_table {
	t_philo			*philos;
	pthread_mutex_t	mutex;
	pthread_mutex_t	mutex_stampa;
	pthread_mutex_t	*mutex_fork;
	int				n_philo;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				eat_times;
	long long		start;
	int				counter;
}			t_table;

//philo.c
void		ft_ciec(int argc, char **argv);

//utils
void		ft_error(char *str);
int			ft_isnum(char *str);
long long	get_time(void);
void		ft_philoprint(t_philo *philo, char *str);

//ft_atoi.c
int			ft_atoi(const char *str);

//init.c
void		ft_init(t_table *table, char **argv);

//routine.c
void		ft_socratis(t_table *table);

//close.c
void		ft_close(t_table *table);
void		ft_free(t_table *table);

#endif
