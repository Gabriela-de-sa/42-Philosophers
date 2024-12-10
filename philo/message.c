/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:05:39 by gabriela          #+#    #+#             */
/*   Updated: 2024/12/05 17:51:19 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	ft_error(int n)
{
	if (n == 1)
		printf("only positive numbers!!");
	else if (n == 2)
		printf("invalid number of args!!");
	else if (n == 3)
		printf("invalid philosopher number!!");
	else if (n == 4)
		printf("eating limit must be > 0!!");
	else if (n == 5)
		printf("value greater than INT_MAX!!");
	else if (n == 6)
		printf("malloc error!!");
	return (1);
}

void	ft_print_message(pthread_mutex_t *mutex, t_act_dinner act_dinner, \
	t_philo *philo)
{
	long		logtime;
	t_dinner	*dinner;

	dinner = philo->dinner;
	if (philo->philo_full || ft_simulation_end(dinner))
		return ;
	logtime = 0;
	ft_act_mutex(LOCK, mutex);
	logtime = ft_time(dinner->start);
	if (act_dinner == FIRST_FORK && !ft_simulation_end(philo->dinner))
		printf("%ld %ld has taken a fork\n", logtime, philo->id);
	if ((act_dinner == SECOND_FORK && !ft_simulation_end(philo->dinner)))
		printf("%ld %ld has taken a fork\n", logtime, philo->id);
	else if (act_dinner == EAT && !ft_simulation_end(philo->dinner))
		printf("%ld %ld is eating\n", logtime, philo->id);
	else if (act_dinner == SLEEP && !ft_simulation_end(philo->dinner))
		printf("%ld %ld is sleeping\n", logtime, philo->id);
	else if (act_dinner == THINK && !ft_simulation_end(philo->dinner))
		printf("%ld %ld is thinking\n", logtime, philo->id);
	else if (act_dinner == DEAD)
		printf("%ld %ld died\n", logtime, philo->id);
	ft_act_mutex(UNLOCK, mutex);
}
