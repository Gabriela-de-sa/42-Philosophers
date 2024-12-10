/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:12:52 by gabriela          #+#    #+#             */
/*   Updated: 2024/12/10 13:13:34 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	ft_act_mutex(t_act act, pthread_mutex_t *mutex)
{
	int	status;

	status = 0;
	if (act == INIT)
		status = pthread_mutex_init(mutex, NULL);
	else if (act == LOCK)
		status = pthread_mutex_lock(mutex);
	else if (act == UNLOCK)
		status = pthread_mutex_unlock(mutex);
	else if (act == DESTROY)
		status = pthread_mutex_destroy(mutex);
	if (status == 1)
	{
		printf("Mutex error!!");
		return (1);
	}
	return (0);
}

int	ft_act_thread(t_act act, pthread_t *thread, \
	void *(*foo)(void *), void *data)
{
	int	status;

	status = 0;
	if (act == CREATE)
		status = pthread_create(thread, NULL, foo, data);
	else if (act == JOIN)
		status = pthread_join(*thread, NULL);
	else if (act == DETACH)
		status = pthread_detach(*thread);
	if (status == 1)
	{
		printf("Create thread error!!");
		return (1);
	}
	return (0);
}

void	ft_threads_ready(t_dinner *dinner)
{
	while (!ft_get_bool(&(dinner->mutex_dinner), &(dinner->threads_ready)))
		;
}

bool	ft_simulation_end(t_dinner *dinner)
{
	return (ft_get_bool(&dinner->mutex_dinner, &dinner->stop));
}
