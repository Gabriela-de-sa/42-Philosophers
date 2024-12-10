/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:41:18 by gabriela          #+#    #+#             */
/*   Updated: 2024/11/26 11:46:28 by gabriela         ###   ########.fr       */
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

int	ft_check_args(char **argv)
{
	int	i;
	int	number;

	i = 1;
	number = 0;
	while (argv[i])
	{
		if (ft_is_number(argv[i]) == 1)
			return (ft_error(1));
		number = ft_atoi(argv[i]);
		if (number > INT_MAX)
			return (ft_error(5));
		i++;
	}
	return (0);
}

int	ft_validations(int argc, char **argv)
{
	int	value;

	if (argc < 5 || argc > 6)
		return (ft_error(2));
	value = ft_atoi(argv[1]);
	if (value <= 1 || value > 200)
		return (ft_error(3));
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (ft_error(4));
	if (ft_check_args(argv) == 1)
		return (1);
	return (0);
}

// checar se nenhum arg é 0