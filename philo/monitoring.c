/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:30:54 by gabriela          #+#    #+#             */
/*   Updated: 2024/11/14 18:31:27 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	ft_init_monitor(t_dinner *dinner, t_philo *philo, char **argv, int argc)
{
	dinner->philos = philo;
	dinner->count_arg = argc - 1;
	dinner->start = ft_get_timestamp();
	dinner->number_philos = ft_atoi(argv[1]);
	dinner->time_die = ft_atoi(argv[2]);
	dinner->time_eat = ft_atoi(argv[3]);
	dinner->time_sleep = ft_atoi(argv[4]);
	dinner->stop = 0;
	dinner->decrease_philo = dinner->number_philos;
	if (dinner->count_arg == 5)
		dinner->limit_meals = ft_atoi(argv[1]);
	else
		dinner->limit_meals = -1;
	printf("\niniciei o monitor\n");
}

int	ft_ignore_philo(t_dinner *dinner, int index)
{
	if (dinner->count_arg == 5)
	{
		printf("\nmonitor de count meals\n");
		if (dinner->philos[index].count_meals >= dinner->limit_meals)
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
		printf("%ld %i died\n", \
			current_time - dinner->start, dinner->philos[index].id);
		dinner->stop = 1;
		pthread_mutex_unlock(&dinner->mutex_dinner);
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
	while (!dinner->stop)
	{
		i = -1;
		while (++i <= dinner->number_philos - 1)
		{
			if (ft_check_died(dinner, i) == 1)
				break ;
			if (ft_ignore_philo(dinner, i) == 1)
			{
				i++;
				continue ;
			}
		}
		if (dinner->stop == 1)
			break ;
		if (dinner->decrease_philo <= 0)
			break ;
		usleep(1000);
	}
	return (NULL);
}

int	ft_monitoring(t_dinner *dinner)
{
	pthread_t	monitor;

	pthread_mutex_init(&dinner->mutex_dinner, NULL);
	if (pthread_create(&monitor, NULL, &ft_table, &dinner) != 0)
		return (1);
	if (pthread_join(monitor, NULL) != 0)
		return (1);
	return (0);
}
