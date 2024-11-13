/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:30:54 by gabriela          #+#    #+#             */
/*   Updated: 2024/11/13 16:33:04 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	ft_init_monitor(t_dinner *dinner, char **argv, int argc)
{
	dinner->count_arg = argc - 1;
	dinner->start = ft_get_timestamp();
	dinner->number_philos = ft_atoi(argv[1]);
	dinner->time_die = ft_atoi(argv[2]);
	dinner->time_eat = ft_atoi(argv[3]);
	dinner->time_sleep = ft_atoi(argv[4]);
	dinner->stop = 0;
	dinner->decrease_philo = dinner->number_philos;
	printf("iniciei o monitor");
}

int	ft_ignore_philo(t_dinner *dinner, int index)
{
	if (dinner->count_arg == 5)
	{
		printf("monitor de count meals");
		if (dinner->philos[index].count_meals >= dinner->philos->limit_meals)
		{
			pthread_mutex_lock(&dinner->mutex_dinner);
			dinner->decrease_philo--;
			pthread_mutex_unlock(&dinner->mutex_dinner);
			return (1);
		}
	}
	return (0);
}

int	ft_check_died(t_dinner *dinner, int index)
{
	long	time_alive;
	long	current_time;

	pthread_mutex_lock(&dinner->mutex_dinner);
	current_time = ft_get_timestamp();
	time_alive = current_time - dinner->philos[index].last_meals;
	if (time_alive >= dinner->time_die)
	{
		printf("entrei dentro do if time_alive >= dinner->time_die stop");
		dinner->stop = 1;
		return (1);
	}
	pthread_mutex_unlock(&dinner->mutex_dinner);
	return (0);
}

void	*ft_table(void *arg)
{
	t_dinner	*dinner;
	int			i;

	dinner = (t_dinner *)arg;
	i = 0;
	while (!dinner->stop)
	{
		i = 0;
		printf("table checando");
		while (i <= dinner->number_philos - 1)
		{
			if (ft_check_died(dinner, i) == 1)
				break ;
			if (ft_ignore_philo(dinner, i) == 1)
			{
				i++;
				continue ;
			}
			i++;
		}
		if (dinner->stop == 1)
			break ;
		if (dinner->decrease_philo == 0)
			break ;
	}
	return (NULL);
}

int	ft_monitoring(t_dinner *dinner)
{
	pthread_t	monitor;

	printf("monitor");
	pthread_mutex_init(&dinner->mutex_dinner, NULL);
	if (pthread_create(&monitor, NULL, &ft_table, &dinner) != 0)
		return (1);
	if (pthread_join(monitor, NULL) != 0)
		return (1);
	return (0);
}
