/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:48:15 by gabriela          #+#    #+#             */
/*   Updated: 2024/11/28 14:20:31 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

// destruir o mutex em um loop - primeiro fazer isso
void	ft_mutex_destroy_fork(t_fork *fork, t_dinner *dinner)
{
	int	i;

	i = 0;
	while (i < dinner->number_philos)
	{
		ft_act_mutex(DESTROY, &fork[i].fork);
		i++;
	}
}

void	ft_mutex_destroy_philo(t_philo *philo, t_dinner *dinner)
{
	int	i;

	i = 0;
	while (i < dinner->number_philos)
	{
		ft_act_mutex(DESTROY, &philo[i].philo_mutex);
		i++;
	}
}

int	ft_clear_memory(t_dinner *dinner, t_philo *philo, t_fork *fork)
{
	ft_mutex_destroy_fork(fork, dinner);
	ft_mutex_destroy_philo(philo, dinner);
	ft_act_mutex(DESTROY, &dinner->mutex_dinner);
	ft_act_mutex(DESTROY, &dinner->print_mutex);
	if (philo != NULL)
		free(philo);
	if (fork != NULL)
		free(fork);
	if (dinner != NULL)
		free(dinner);
	return (0);
}
