/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:56:46 by gabriela          #+#    #+#             */
/*   Updated: 2024/12/10 13:33:24 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int argc, char **argv)
{
	t_dinner	*dinner;
	t_philo		*philo;
	t_fork		*fork;

	dinner = NULL;
	philo = NULL;
	fork = NULL;
	ft_page_philo();
	if (ft_validations(argc, argv) == 1)
		return (1);
	philo = malloc(ft_atoi(argv[1]) * sizeof(t_philo));
	fork = malloc(ft_atoi(argv[1]) * sizeof(t_fork));
	dinner = malloc(1 * sizeof(t_dinner));
	if (fork == NULL || philo == NULL || dinner == NULL)
		return (ft_error(6));
	dinner->count_arg = argc - 1;
	if (ft_init(dinner, philo, fork, argv) == 1)
		return (ft_clear_memory(dinner, philo, fork));
	if (ft_dinner_start(dinner) == 1)
		return (ft_clear_memory(dinner, philo, fork));
	ft_clear_memory(dinner, philo, fork);
}
