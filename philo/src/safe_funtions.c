/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_funtions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:07:49 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/06 19:46:30 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (NULL == ret)
		error_exit("Error with the malloc");
	return (ret);
}

void	safe_mutex_handle(t_mutex *mutex, t_opcode opcode)
{
	if (opcode == LOCK)
		mutex_handle_error(pthread_mutex_lock(mutex), opcode);
	else if (opcode == UNLOCK)
		mutex_handle_error(pthread_mutex_unlock(mutex), opcode);
	else if (opcode == INIT)
		mutex_handle_error(pthread_mutex_init(mutex, NULL), opcode);
	else if (opcode == DESTROY)
		mutex_handle_error(pthread_mutex_destroy(mutex), opcode);
	else
		error_msg("🚨 Wrong opcode for mutex handle "
			" use <LOCK> <UNLOCK> <INIT> <DESTROY> 🚨\n");
}

void	safe_thread_handle(pthread_t *thread, void *(*foo)(void *),
		void *data, t_opcode opcode)
{
	if (CREATE == opcode)
		mutex_handle_error(pthread_create(thread, NULL, foo, data), opcode);
	else if (JOIN == opcode)
		mutex_handle_error(pthread_join(*thread, NULL), opcode);
	else if (DETACH == opcode)
		mutex_handle_error(pthread_detach(*thread), opcode);
	else
		error_msg(" 🚨 Wrong opcode for thread_handle:"
			" use <CREATE> <JOIN> <DETACH> 🚨\n");
}