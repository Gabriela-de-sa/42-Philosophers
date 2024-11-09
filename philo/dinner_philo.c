/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:13:15 by gabriela          #+#    #+#             */
/*   Updated: 2024/11/09 18:49:28 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

// function test
void	*ft_dinner_philo(void *p_index)
{
	t_philo	*philo;

	philo = (t_philo *)p_index;
	printf("index philo: %i\n", philo->id);
	return (NULL);
}