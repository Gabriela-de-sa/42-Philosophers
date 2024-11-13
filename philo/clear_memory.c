/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:48:15 by gabriela          #+#    #+#             */
/*   Updated: 2024/11/13 17:53:51 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

// destruir o mutex em um loop - primeiro fazer isso
void	ft_mutex_destroy_fork(t_fork *fork, t_dinner *dinner, int n_philo)
{
	int	i;

	i = 0;
	while (i < n_philo)
	{
		pthread_mutex_destroy(&fork[i].fork);
		i++;
	}
	pthread_mutex_destroy(&dinner->mutex_dinner);
}

int	ft_clear_memory(t_philo *philo, t_fork *fork, t_dinner *dinner, int n_philo)
{
	ft_mutex_destroy_fork(fork, dinner, n_philo);
	free(philo);
	free(fork);
	free(dinner);
	return (0);
}
