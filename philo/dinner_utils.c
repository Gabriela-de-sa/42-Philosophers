/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:57:07 by gabriela          #+#    #+#             */
/*   Updated: 2024/12/10 12:01:28 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	ft_block_fork(t_philo *philo)
{
	t_dinner	*dinner;

	dinner = philo->dinner;
	ft_act_mutex(LOCK, &philo->first_fork->fork);
	ft_act_mutex(LOCK, &philo->second_fork->fork);
	ft_print_message(&dinner->print_mutex, FIRST_FORK, philo);
	ft_print_message(&dinner->print_mutex, SECOND_FORK, philo);
}

void	ft_unlock_fork(t_philo *philo)
{
	ft_act_mutex(UNLOCK, &philo->first_fork->fork);
	ft_act_mutex(UNLOCK, &philo->second_fork->fork);
}

void	ft_eat(t_philo *philo)
{
	long		time_total;
	t_dinner	*dinner;

	dinner = philo->dinner;
	ft_block_fork(philo);
	ft_set_long(&philo->philo_mutex, &philo->last_meals, ft_get_timestamp());
	time_total = ft_get_timestamp() + dinner->time_eat;
	ft_print_message(&dinner->print_mutex, EAT, philo);
	while (ft_get_timestamp() < time_total)
	{
		if (ft_simulation_end(dinner))
			break ;
		usleep(100);
	}
	ft_set_long(&philo->philo_mutex, &philo->count_meals, \
		philo->count_meals + 1);
	ft_unlock_fork(philo);
	if (philo->count_meals == dinner->limit_meals)
		ft_set_bool(&philo->philo_mutex, &philo->philo_full, true);
}


void	ft_sleep(t_philo *philo)
{
	long		time_total_sleep;
	t_dinner	*dinner;

	dinner = philo->dinner;
	ft_print_message(&dinner->print_mutex, SLEEP, philo);
	time_total_sleep = ft_get_timestamp() + dinner->time_sleep;
	while (ft_get_timestamp() < time_total_sleep)
	{
		if (ft_simulation_end(dinner))
			break ;
		usleep(100);
	}
}

void	ft_think(t_philo *philo)
{
	t_dinner	*dinner;

	dinner = philo->dinner;
	if (ft_simulation_end(dinner))
		return ;
	ft_print_message(&dinner->print_mutex, THINK, philo);
	usleep(1000);
}
