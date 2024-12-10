/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:37:06 by gabriela          #+#    #+#             */
/*   Updated: 2024/12/09 16:52:28 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

// escolha dos garfos, baseado na posicao do filo
void	ft_get_forks(t_philo *philo, t_fork *fork, t_dinner *dinner, int index)
{
	if (index % 2 == 0)
	{
		philo[index].first_fork = &fork[(index + 1) % dinner->number_philos];
		philo[index].second_fork = &fork[index];
	}
	else
	{
		philo[index].first_fork = &fork[index];
		philo[index].second_fork = &fork[(index + 1) % dinner->number_philos];
	}
	/*printf("\nPhilosopher %d:\n", index + 1); // Adiciona 1 para o número do filósofo
	printf("  First fork: ID %ld [Address: %p]\n", 
	       philo->first_fork->id_fork, (void *)philo->first_fork);
	printf("  Second fork: ID %ld [Address: %p]\n", 
	       philo->second_fork->id_fork, (void *)philo->second_fork);*/
	/*printf("Philo %ld: Fork esquerdo %p, Fork direito %p\n",
       philo[index].id, philo[index].first_fork, philo[index].second_fork);*/

}

// create array fork
int	ft_init_fork(t_dinner *dinner, t_fork *fork)
{
	int	i;

	i = 0;
	while (i < dinner->number_philos)
	{
		if (ft_act_mutex(INIT, &fork[i].fork) != 0)
			return (1);
		fork[i].id_fork = i;
		i++;
	}
	return (0);
}

// iniciar struct philo
int	ft_init_philo(t_dinner *dinner, t_philo *philo, t_fork *fork)
{
	int	i;

	i = 0;
	while (i < dinner->number_philos)
	{
		philo[i].id = i + 1;
		philo[i].count_meals = 0;
		philo[i].philo_full = false;
		philo[i].dinner = dinner;
		philo[i].fork = fork;
		if (ft_act_mutex(INIT, &philo[i].philo_mutex) != 0)
			return (1);
		ft_get_forks(philo, fork, dinner, i);
		i++;
	}
	return (0);
}

// iniciar struct dinner
int	ft_init(t_dinner *dinner, t_philo *philo, t_fork *fork, char **argv)
{
	dinner->philos = philo;
	dinner->forks = fork;
	dinner->number_philos = ft_atoi(argv[1]);
	dinner->time_die = ft_atoi(argv[2]);
	dinner->time_eat = ft_atoi(argv[3]);
	dinner->time_sleep = ft_atoi(argv[4]);
	dinner->stop = false;
	dinner->threads_ready = false;
	if (ft_act_mutex(INIT, &dinner->mutex_dinner) != 0)
		return (1);
	if (ft_act_mutex(INIT, &dinner->print_mutex) != 0)
		return (1);
	if (dinner->count_arg == 5)
		dinner->limit_meals = ft_atoi(argv[5]);
	else
		dinner->limit_meals = -1;
	if (ft_init_fork(dinner, fork) == 1)
		return (1);
	if (ft_init_philo(dinner, philo, fork) == 1)
		return (1);
	return (0);
}
