/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:40:57 by gabriela          #+#    #+#             */
/*   Updated: 2024/11/09 18:48:50 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_fork
{
	pthread_mutex_t		fork;
	int					id_fork;
}	t_fork;

typedef struct s_philo
{
	int			id;
	int			count_meals;
	long		last_meals;
	pthread_t	threads;
	t_fork		*fork_left;
	t_fork		*fork_right;
}	t_philo;

// introduction
void	ft_page_philo(void);
// philo utils
int		ft_atoi(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
// validations
int		ft_validations(int argc, char **argv);
// functions for create array
int		ft_create_fork(int n_fork, t_fork *fork);
int		ft_create_thread(int n_philo, t_philo *philo, t_fork *fork);
int		ft_join(int size, t_philo *philo);
// functions for dinner philosophers
// error
int		ft_error(int n);
// clear memory
void	ft_mutex_destroy(t_fork *fork, int n_philo);
int		ft_clear_memory(t_philo *philo, t_fork *fork, int n_philo);

#endif