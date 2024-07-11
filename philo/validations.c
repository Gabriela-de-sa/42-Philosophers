/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:57:21 by gde-sa            #+#    #+#             */
/*   Updated: 2024/07/11 02:04:27 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	ft_isdigit(char str)
{
	if (str >= '0' && str <= '9')
		return (0);
	return (1);
}

int	ft_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	signal;
	int	result;

	i = 0;
	signal = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || \
			str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		signal = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (signal * result);
}

int	ft_check_number(int number, int index, int argc)
{
	if (number > MAX_PHILO && index == 1)
		return (1);
	if (argc == 6 && index == 5)
		return (0);
	if (number < 0)
		return (1);
	return (0);
}

int	ft_check_args(int argc, char **argv)
{
	int	i;
	int	number;

	if (argc < 5 || argc > 6)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (ft_is_numeric(argv[i]) == 1)
			return (1);
		number = ft_atoi(argv[i]);
		if (ft_check_number(number, i, argc) == 1)
			return (1);
		i++;
	}
	return (0);
}
