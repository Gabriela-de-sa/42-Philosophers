/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:40:57 by gabriela          #+#    #+#             */
/*   Updated: 2024/12/09 16:54:49 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

# define RESET "\033[0m"
# define RED "\033[31m"
# define MAGENTA "\033[35m"
# define INT_MAX 2147483647

typedef struct s_dinner	t_dinner;

typedef enum e_act
{
	INIT,
	LOCK,
	UNLOCK,
	DESTROY,
	DETACH,
	CREATE,
	JOIN,
}	t_act;

typedef enum e_act_dinner
{
	EAT,
	SLEEP,
	THINK,
	FIRST_FORK,
	SECOND_FORK,
	DEAD,
}	t_act_dinner;

typedef struct s_fork
{
	pthread_mutex_t		fork;
	long				id_fork;
}	t_fork;

typedef struct s_philo
{
	long			id;
	long			count_meals;
	long			last_meals;
	bool			philo_full;
	pthread_t		threads;
	t_fork			*first_fork;
	t_fork			*second_fork;
	t_fork			*fork;
	t_dinner		*dinner;
	pthread_mutex_t	philo_mutex;
}	t_philo;

typedef struct s_dinner
{
	int				number_philos;
	long			time_die;
	long			time_sleep;
	long			time_eat;
	long			limit_meals;
	long			start;
	bool			stop;
	bool			threads_ready;
	long			count_arg;
	t_fork			*forks;
	t_philo			*philos;
	pthread_t		monitor;
	pthread_mutex_t	mutex_dinner;
	pthread_mutex_t	print_mutex;
}	t_dinner;

// introduction
void	ft_page_philo(void);
// utils
int		ft_atoi(char *str);
// mutex and threads utils
int		ft_act_mutex(t_act act, pthread_mutex_t *mutex);
int		ft_act_thread(t_act act, pthread_t *thread, \
		void *(*foo)(void *), void *data);
void	ft_threads_ready(t_dinner *dinner);
bool	ft_simulation_end(t_dinner *dinner);
// utils get and set
void	ft_set_bool(pthread_mutex_t *mutex, bool *value, bool new);
bool	ft_get_bool(pthread_mutex_t *mutex, bool *value);
void	ft_set_long(pthread_mutex_t *mutex, long *value, long new);
bool	ft_get_long(pthread_mutex_t *mutex, long *value);
// functions of dinner
int		ft_dinner_start(t_dinner *dinner);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);
// end thread
void	ft_threads_end(t_dinner *dinner);
// validations
int		ft_validations(int argc, char **argv);
// init values struct
int		ft_init(t_dinner *dinner, t_philo *philo, t_fork *fork, char **argv);
// get time of day
long	ft_get_timestamp(void);
long	ft_time(long time);
void	ft_usleep(t_dinner *dinner, long sleep_duration);
// monitor
void	*ft_table(void *arg);
// message
int		ft_error(int n);
void	ft_print_message(pthread_mutex_t *mutex, t_act_dinner act_dinner, \
			t_philo *philo);
// clear memory
void	ft_mutex_destroy_philo(t_philo *philo, t_dinner *dinner);
void	ft_mutex_destroy_fork(t_fork *fork, t_dinner *dinner);
int		ft_clear_memory(t_dinner *dinner, t_philo *philo, t_fork *fork);
#endif