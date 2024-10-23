/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:41:40 by gabriela          #+#    #+#             */
/*   Updated: 2024/10/22 20:25:25 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void*	routine(void *arg)
{
	char	*str;

	str = (char *)arg;
	printf("primeira threads\n");
	sleep(2);
	printf("%s\n", str);
	return (NULL);
}

int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;
	char		*str;

	str = "gabriela";
	if (pthread_create(&t1, NULL, &routine, str) != 0)
		return (1);
	if (pthread_create(&t2, NULL, &routine, str) != 0)
		return (1);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
}
