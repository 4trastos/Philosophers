/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:07:49 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/20 20:37:03 by davgalle         ###   ########.fr       */
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

void	write_status(t_philo_status status, t_philo *philo)
{
	long	time_elapsed;

	time_elapsed = world_clock(MILLISECOND) - philo->table->start_routine;
	if (get_bool(&philo->philo_mutex, &philo->full))
		return ;
	ft_mutex(&philo->table->write_mutex, LOCK);
	if (status == TAKE_FIRST_FORK && !routine_finished(philo->table))
		printf(W"%-6ld"RST" %d has taken a first fork 🍽\n",
			time_elapsed, philo->id);
	else if (status == TAKE_SECOND_FORK && !routine_finished(philo->table))
		printf(W"%-6ld"RST" %d has taken a second fork 🍽\n",
			time_elapsed, philo->id);
	else if (status == EATING && !routine_finished(philo->table))
		printf(W"%-6ld"C" %d is eating 🍝\n"RST, time_elapsed, philo->id);
	else if (status == SLEEPING && !routine_finished(philo->table))
		printf(W"%-6ld"RST" %d is sleeping 😴\n", time_elapsed, philo->id);
	else if (status == THINKING && !routine_finished(philo->table))
		printf(W"%-6ld"RST" %d is thinking 🤔\n", time_elapsed, philo->id);
	else if (status == DIED)
		printf(RED"%-6ld 💀💀💀 %d died 💀💀💀\n"RST, time_elapsed, philo->id);
	ft_mutex(&philo->table->write_mutex, UNLOCK);
}
