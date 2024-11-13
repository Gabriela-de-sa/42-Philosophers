/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:56:46 by gabriela          #+#    #+#             */
/*   Updated: 2024/11/13 17:52:13 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int argc, char **argv)
{
	t_dinner	*dinner;
	t_philo		*philo;
	t_fork		*fork;

	ft_page_philo();
	if (ft_validations(argc, argv) == 1)
		return (1);
	philo = malloc(ft_atoi(argv[1]) * sizeof(t_philo));
	fork = malloc(ft_atoi(argv[1]) * sizeof(t_fork));
	dinner = malloc(1 * sizeof(t_dinner));
	if (fork == NULL || philo == NULL || dinner == NULL)
		return (1);
	ft_init_monitor(dinner, argv, argc);
	if (ft_create_fork(dinner->number_philos, fork) != 0)
		return (ft_clear_memory(philo, fork, dinner, dinner->number_philos));
	if (ft_create_thread(philo, fork, argv, dinner) != 0)
		return (ft_clear_memory(philo, fork, dinner, dinner->number_philos));
	if (ft_monitoring(dinner) != 0)
		return (ft_clear_memory(philo, fork, dinner, dinner->number_philos));
	if (ft_join(dinner->number_philos, philo) != 0)
		return (ft_clear_memory(philo, fork, dinner, dinner->number_philos));
	ft_clear_memory(philo, fork, dinner, dinner->number_philos);
}
