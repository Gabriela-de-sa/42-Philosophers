/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:48:15 by gabriela          #+#    #+#             */
/*   Updated: 2024/11/09 18:37:55 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

// limpar memoria da struct

// destruir o mutex em um loop - primeiro fazer isso
void	ft_mutex_destroy(t_fork *fork, int n_philo)
{
	int	i;

	i = 0;
	while (i < n_philo)
	{
		pthread_mutex_destroy(&fork[i].fork);
		i++;
	}
}

int	ft_clear_memory(t_philo *philo, t_fork *fork, int n_philo)
{
	ft_mutex_destroy(fork, n_philo);
	free(philo);
	free(fork);
	return (0);
}
