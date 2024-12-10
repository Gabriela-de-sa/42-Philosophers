/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:27:05 by gabriela          #+#    #+#             */
/*   Updated: 2024/12/04 11:54:04 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

// mudar o valor de uma variavel do tipo bool
void	ft_set_bool(pthread_mutex_t *mutex, bool *value, bool new)
{
	ft_act_mutex(LOCK, mutex);
	*value = new;
	ft_act_mutex(UNLOCK, mutex);
}

// mostrar o valor de uma variavel do tipo bool
bool	ft_get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool	var;

	ft_act_mutex(LOCK, mutex);
	var = *value;
	ft_act_mutex(UNLOCK, mutex);
	return (var);
}

// mudar o valor de uma variavel do tipo long
void	ft_set_long(pthread_mutex_t *mutex, long *value, long new)
{
	ft_act_mutex(LOCK, mutex);
	*value = new;
	ft_act_mutex(UNLOCK, mutex);
}

// mostrar o valor de uma variavel do tipo long
bool	ft_get_long(pthread_mutex_t *mutex, long *value)
{
	long	var;

	ft_act_mutex(LOCK, mutex);
	var = *value;
	ft_act_mutex(UNLOCK, mutex);
	return (var);
}
