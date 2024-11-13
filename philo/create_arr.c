/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:45:43 by gabriela          #+#    #+#             */
/*   Updated: 2024/11/13 17:54:02 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	ft_create_fork(int n_fork, t_fork *fork)
{
	int	i;

	i = 0;
	while (i < n_fork)
	{
		if (pthread_mutex_init(&fork[i].fork, NULL) != 0)
			return (1);
		fork[i].id_fork = i;
		i++;
	}
	return (0);
}

int	ft_create_thread(t_philo *philo, t_fork *fork, \
		char **argv, t_dinner *dinner)
{
	int	i;

	i = 0;
	while (i < dinner->number_philos)
	{
		philo[i].id = i + 1;
		philo[i].count_meals = 0;
		philo[i].last_meals = 0;
		philo[i].dinner = dinner;
		philo[i].fork = fork;
		philo[i].fork_right = &fork[i];
		philo[i].fork_left = &fork[(i + 1) % dinner->number_philos];
		if (philo->dinner->count_arg == 5)
			philo[i].limit_meals = ft_atoi(argv[5]);
		if (pthread_create(
				&philo[i].threads, NULL, &ft_dinner_philo, &philo[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_join(int size, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (pthread_join(philo[i].threads, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
