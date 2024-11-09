/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:45:43 by gabriela          #+#    #+#             */
/*   Updated: 2024/11/09 18:46:44 by gabriela         ###   ########.fr       */
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

int	ft_create_thread(int n_philo, t_philo *philo, t_fork *fork)
{
	int	i;

	i = 0;
	while (i < n_philo)
	{
		philo[i].id = i + 1;
		philo[i].fork_right = &fork[i];
		philo[i].fork_left = &fork[(i + 1) % n_philo];
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
