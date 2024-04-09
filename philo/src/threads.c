/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:07:49 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/09 14:49:56 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
		error_exit("Error with the malloc");
	return (ret);
}

void	ft_mutex(t_mutex *mutex, t_opcode opcode)
{
	if (opcode == LOCK)
		ft_mutex_error(pthread_mutex_lock(mutex), opcode);
	else if (opcode == UNLOCK)
		ft_mutex_error(pthread_mutex_unlock(mutex), opcode);
	else if (opcode == INIT)
		ft_mutex_error(pthread_mutex_init(mutex, NULL), opcode);
	else if (opcode == DESTROY)
		ft_mutex_error(pthread_mutex_destroy(mutex), opcode);
	else
		error_msg("🚨 Wrong opcode for mutex handle "
			" use <LOCK> <UNLOCK> <INIT> <DESTROY> 🚨\n");
}

void	ft_mutex_error(int status, t_opcode opcode) //Errores en los mutex
{
	if (status == 0)
		return ;
	if (status == EINVAL && (opcode == LOCK || opcode == UNLOCK))
		error_exit("The value specified by mutex is invalid");
	else if (status == EINVAL && opcode == INIT)
		error_exit("The value specified by attr is invalid.");
	else if (status == EDEADLK)
		error_exit("A deadlock would occur if the thread "
			"blocked waiting for mutex.");
	else if (status == EPERM)
		error_exit("The current thread does not hold a lock on mutex.");
	else if (status == ENOMEM)
		error_exit("The process cannot allocate enough memory"
			" to create another mutex.");
	else if (status == EBUSY)
		error_exit("Mutex is locked");
}

void	ft_threads(pthread_t *thread, void *(*foo)(void *),
		void *data, t_opcode opcode)
{
	if (opcode == CREATE)
		ft_threads_error(pthread_create(thread, NULL, foo, data), opcode);
	else if (opcode == JOIN)
		ft_threads_error(pthread_join(*thread, NULL), opcode);
	else if (opcode == DETACH)
		ft_threads_error(pthread_detach(*thread), opcode);
	else
		error_msg(" 🚨 Wrong opcode for thread_handle:"
			" use <CREATE> <JOIN> <DETACH> 🚨\n");
}

void	ft_threads_error(int status, t_opcode opcode) //errores en los hilos
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		error_exit("No resources to create another thread");
	else if (status == EPERM)
		error_exit("The caller does not have appropriate permission\n");
	else if (status == EINVAL && opcode == CREATE)
		error_exit("The value specified by attr is invalid.");
	else if (status == EINVAL && (opcode == JOIN || opcode == DETACH))
		error_exit("The value specified by thread is not joinable\n");
	else if (status == ESRCH)
		error_exit("No thread could be found corresponding to that"
			"specified by the given thread ID, thread.");
	else if (status == EDEADLK)
		error_exit("A deadlock was detected or the value of"
			"thread specifies the calling thread.");
}