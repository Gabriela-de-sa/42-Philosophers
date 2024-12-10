/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:59:52 by gabriela          #+#    #+#             */
/*   Updated: 2024/12/10 14:14:29 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	ft_check_table(t_philo *philo, t_dinner *dinner)
{
	int		i;
	long	eating_enough;

	i = 0;
	eating_enough = 0;
	while (i < dinner->number_philos && !ft_simulation_end(dinner))
	{
		// checa se o philo comeu suficiente
		if (ft_get_bool(&philo[i].philo_mutex, &philo[i].philo_full) == true)
			eating_enough++;
		// checa se o philo morreu - nao funciona
		if (ft_get_timestamp() - \
			ft_get_long(&philo[i].philo_mutex, &philo[i].last_meals) \
			>= dinner->time_die)
		{
			ft_print_message(&dinner->print_mutex, DEAD, philo);
			ft_set_bool(&dinner->mutex_dinner, &dinner->stop, true);
			break ;
		}
		i++;
	}
	if (eating_enough == dinner->number_philos)
		ft_set_bool(&dinner->mutex_dinner, &dinner->stop, true);
}

void	*ft_table(void *arg)
{
	t_philo		*philo;
	t_dinner	*dinner;

	dinner = (t_dinner *)arg;
	philo = dinner->philos;
	// verifica se todas as threads estao prontas
	ft_threads_ready(dinner);
	while (!ft_simulation_end(dinner))
	{
		ft_check_table(philo, dinner);
		usleep(100);
	}
	return (NULL);
}
