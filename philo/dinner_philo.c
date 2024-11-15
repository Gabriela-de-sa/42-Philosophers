/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:13:15 by gabriela          #+#    #+#             */
/*   Updated: 2024/11/15 13:07:38 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

long	ft_get_timestamp(void)
{
	struct timeval	time;
	long			timestamp;

	gettimeofday(&time, NULL);
	timestamp = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (timestamp);
}

void	ft_sleep(t_philo *philo, long int log_time)
{
	log_time = ft_get_timestamp();
	printf("%ld %i is sleeping\n", log_time - philo->dinner->start, philo->id);
	usleep(philo->dinner->time_sleep * 1000);
}

void	ft_think(t_philo *philo, long int log_time)
{
	log_time = ft_get_timestamp();
	printf("%ld %i is thinking\n", log_time - philo->dinner->start, philo->id);
	usleep(1000);
}

void	ft_eat(t_philo *philo, long int log_time)
{
	pthread_mutex_lock(&philo->fork_left->fork);
	pthread_mutex_lock(&philo->fork_right->fork);
	log_time = ft_get_timestamp();
	usleep(philo->dinner->time_eat * 1000);
	printf("%ld %i has taken a fork\n", \
			log_time - philo->dinner->start, philo->id);
	printf("%ld %i is eating\n", log_time - philo->dinner->start, philo->id);
	philo->last_meals = log_time;
	if (philo->dinner->count_arg == 5)
		philo->count_meals++;
	pthread_mutex_unlock(&philo->fork_left->fork);
	pthread_mutex_unlock(&philo->fork_right->fork);
}

void	*ft_dinner_philo(void *arg)
{
	long int	log_time;
	t_philo		*philo;

	log_time = 0;
	philo = (t_philo *)arg;
	// usleep para dar tempo da thread de monitoramento ser criada
	usleep(2000);
	while (1)
	{
		if (philo->dinner->stop == 1 || philo->dinner->decrease_philo == 0)
			break ;
		ft_eat(philo, log_time);
		ft_sleep(philo, log_time);
		ft_think(philo, log_time);
	}
	return (NULL);
}
