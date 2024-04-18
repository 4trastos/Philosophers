/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:07:49 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/18 17:23:00 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	ft_threads(pthread_t *thread, void *(*foo)(void *),
		void *data, t_opcode opcode)
{
	if (opcode == CREATE)
		pthread_create(thread, NULL, foo, data);
	else if (opcode == JOIN)
		pthread_join(*thread, NULL);
	else if (opcode == DETACH)
		pthread_detach(*thread);
	else
		error_msg(" 🚨 Wrong opcode for thread_handle:"
			" use <CREATE> <JOIN> <DETACH> 🚨\n");
}

void	ft_mutex(t_mutex *mutex, t_opcode opcode)
{
	if (opcode == LOCK)
		pthread_mutex_lock(mutex);
	else if (opcode == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (opcode == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (opcode == DESTROY)
		pthread_mutex_destroy(mutex);
	else
		error_msg("🚨 Wrong opcode for mutex handle "
			" use <LOCK> <UNLOCK> <INIT> <DESTROY> 🚨\n");
}