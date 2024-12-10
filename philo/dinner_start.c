/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:13:47 by gabriela          #+#    #+#             */
/*   Updated: 2024/12/10 13:33:42 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	ft_threads_end(t_dinner *dinner)
{
	int	i;

	i = 0;
	while (i < dinner->number_philos)
	{
		ft_act_thread(JOIN, &dinner->philos[i].threads, NULL, NULL);
		i++;
	}
}

void	*ft_dinner_philo(void *arg)
{
	t_philo		*philo;
	t_dinner	*dinner;

	philo = (t_philo *)arg;
	dinner = philo->dinner;
	ft_threads_ready(dinner);
	while (!ft_simulation_end(dinner))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

int	ft_dinner_start(t_dinner *dinner)
{
	int	i;

	dinner->start = ft_get_timestamp();
	i = 0;
	while (i < dinner->number_philos)
	{
		ft_set_long(&dinner->philos[i].philo_mutex, \
			&dinner->philos[i].last_meals, dinner->start);
		if (ft_act_thread(CREATE, &dinner->philos[i].threads, \
			ft_dinner_philo, &dinner->philos[i]) == 1)
			return (1);
		i++;
	}
	if (ft_act_thread(CREATE, &dinner->monitor, \
			ft_table, dinner))
		return (1);
	ft_set_bool(&dinner->mutex_dinner, &dinner->threads_ready, true);
	ft_act_thread(JOIN, &dinner->monitor, NULL, NULL);
	ft_threads_end(dinner);
	return (0);
}
