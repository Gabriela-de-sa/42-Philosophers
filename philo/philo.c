/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:56:31 by gde-sa            #+#    #+#             */
/*   Updated: 2024/07/11 02:04:42 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (ft_check_args(argc, argv) == 1)
	{
		printf("erro");
		return (1);
	}
	printf("ok");
}
