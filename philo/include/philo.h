/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:40:57 by gabriela          #+#    #+#             */
/*   Updated: 2024/11/04 14:00:21 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>

// introduction
void	ft_page_philo(void);
// philo utils
int		ft_atoi(char *str);
// validations
int		ft_validations(int argc, char **argv);
// error
int		ft_error(int n);

#endif