/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:40:57 by gabriela          #+#    #+#             */
/*   Updated: 2024/11/14 18:21:24 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_dinner t_dinner;

typedef struct s_fork
{
	pthread_mutex_t		fork;
	int					id_fork;
}	t_fork;

typedef struct s_philo
{
	int				id;
	int				count_meals;
	long			last_meals;
	pthread_t		threads;
	t_fork			*fork_left;
	t_fork			*fork_right;
	t_fork			*fork;
	t_dinner		*dinner;
}	t_philo;

typedef struct s_dinner
{
	int				number_philos;
	long			time_die;
	long			time_sleep;
	long			time_eat;
	long			limit_meals;
	long			start;
	int				stop;
	int				decrease_philo;
	int				count_arg;
	t_fork			*forks;
	t_philo			*philos;
	pthread_mutex_t	mutex_dinner;
}	t_dinner;

// introduction
void	ft_page_philo(void);
// philo utils
int		ft_atoi(char *str);
void	ft_putstr(char *str);
// validations
int		ft_validations(int argc, char **argv);
// functions for create array
int		ft_create_fork(int n_fork, t_fork *fork);
int		ft_create_thread(
			t_philo *philo, t_fork *fork, t_dinner *dinner);
int		ft_join(int size, t_philo *philo);
// functions for dinner philosophers
void	*ft_dinner_philo(void *arg);
// get time of day
long	ft_get_timestamp(void);
// monitoring threads
int		ft_monitoring(t_dinner *dinner);
void	ft_init_monitor(t_dinner *dinner, t_philo *philo, \
			char **argv, int argc);
// error
int		ft_error(int n);
// clear memory
void	ft_mutex_destroy(t_fork *fork, t_dinner *dinner, int n_philo);
int		ft_clear_memory(
			t_philo *philo, t_fork *fork, t_dinner *dinner, int n_philo);

#endif