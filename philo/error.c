/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:05:39 by gabriela          #+#    #+#             */
/*   Updated: 2024/11/04 14:10:32 by gabriela         ###   ########.fr       */
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
	return (1);
}
