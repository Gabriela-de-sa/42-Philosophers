/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:56:46 by gabriela          #+#    #+#             */
/*   Updated: 2024/11/09 18:49:15 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_fork		*fork;
	int			n_philo;

	ft_page_philo();
	if (ft_validations(argc, argv) == 1)
		return (1);
	n_philo = ft_atoi(argv[1]);
	philo = malloc(n_philo * sizeof(t_philo));
	if (philo == NULL)
		return (1);
	fork = malloc(n_philo * sizeof(t_fork));
	if (fork == NULL)
		return (1);
	if (ft_create_fork(n_philo, fork) != 0)
		return (ft_clear_memory(philo, fork, n_philo));
	if (ft_create_thread(n_philo, philo, fork) != 0)
		return (ft_clear_memory(philo, fork, n_philo));
	if (ft_join(n_philo, philo) != 0)
		return (ft_clear_memory(philo, fork, n_philo));
	ft_clear_memory(philo, fork, n_philo);
}
