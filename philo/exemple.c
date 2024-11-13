/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exemple.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:41:40 by gabriela          #+#    #+#             */
/*   Updated: 2024/11/13 15:31:39 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "include/philo.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int	x = 0;

void	*routine(void *mutex)
{
	int	i = 0;
	while (i < 100000)
	{
		pthread_mutex_lock(&mutex);
		x++;
		i++;
		pthread_mutex_unlock(&mutex);
	}
}

int	main(int argc, char **argv)
{
	int				i;
	pthread_mutex_t	mutex;
	pthread_t		threads;

	pthread_mutex_init(&mutex, NULL);
	i = 0;
	while (i < argv[1])
	{
		if (pthread_create(&, NULL, &routine, &mutex) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < argv[1] - 1)
	{
		if (pthread_join(t1, NULL) != 0)
			return (1);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	printf("numbers: %i", x);
}

// MUTEX = evita concorrencia de dados que é quando duas ou mais threads acessam o mesmo local
//         de memoria. Por algum motivo algumas das threads podem travar e acontecer de valores
//		   indesejados na execucao do programa ou no final (output)
//pthread_mutex_init(&mutex, NULL); - inicia o mutex
//pthread_mutex_destroy(&mutex); - destroi o mutex contruido
//pthread_mutex_lock(&mutex); - bloqueia outras threads que queiram acessar um lugar de memoria ja ocupado
//pthread_mutex_unlock(&mutex); - desbloqueia e libera o acesso naquele espaco que antes estava ocupado
