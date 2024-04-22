/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:23:44 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/17 14:52:41 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;
//int pthread_mutex_lock(pthread_mutex_t *mutex);
//int pthread_mutex_unlock(pthread_mutex_t *mutex);

static int count = 10;

void	*thread1_routine(void *unused)
{
	int i = 0;
	while(i < 10000)
	{
		pthread_mutex_lock(&mutex);
		i++;
		count++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

void	*thread2_routine(void *unused)
{
	int i = 0;
	while(i < 10000)
	{
		pthread_mutex_lock(&mutex);
		i++;
		count--;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

void	errorExit(char *str)
{
	perror(str);
	printf("%s", str);
	exit (1);
}

int main(int argc, char **argv)
{
	pthread_t thread1, thread2;

	if (0 != pthread_create(&thread1, NULL, thread1_routine, NULL))
		errorExit("thread1 no se ha podido crear");
	if (0 != pthread_create(&thread2, NULL, thread2_routine, NULL))
		errorExit("thread2 no se ha podido crear");

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Valor de count %d", count);
	return (0);
}

