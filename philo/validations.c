/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:41:18 by gabriela          #+#    #+#             */
/*   Updated: 2024/11/04 14:02:56 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
		return (1);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_validations(int argc, char **argv)
{
	int	i;
	int	value;

	if (argc < 5 || argc > 6)
		return (ft_error(2));
	value = ft_atoi(argv[1]);
	if (value <= 1 || value > 200)
		return (ft_error(3));
	i = 1;
	while (argv[i])
	{
		if (ft_is_number(argv[i]) == 1)
			return (ft_error(1));
		i++;
	}
	return (0);
}
