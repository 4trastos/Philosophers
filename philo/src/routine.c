/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:39:59 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/15 20:00:50 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

bool    routine_finished(t_table *table)
{
    return(get_bool(&table->table_mutex, &table->end_routine));
}

bool	all_threads_running(t_mutex *mutex, long *threads, long philo_number)
{
	bool	aux;
	aux = false;
	ft_mutex(mutex, LOCK);
	if (*threads == philo_number)
		aux = true;
	ft_mutex(mutex, UNLOCK);
	return (aux);
}

void	philo_is_thinking(t_philo *philo, bool pre_routine)
{
	long	eat;
	long	sleep;
	long	think;
	if (!pre_routine)
		write_status(THINKING, philo, DEBUG_MODE);
	if (philo->table->philos_number % 2 == 0)
		return ;
	eat = philo->table->time_to_eat;
	sleep = philo->table->time_to_sleep;
	think = (eat * 2) - sleep;
	if (think < 0)
		think = 0;
	philo_is_sleeping(think * 0.42, philo->table);
}

void	synchro_philos(t_philo *philo)
{
	if (philo->table->philos_number % 2 == 0)
		{
			if (philo->id % 2 == 0)
				philo_is_sleeping(3e4, philo->table);
		}
		else
		{
			if (philo->id % 2)
				philo_is_thinking(philo, true);
		}
}

void	*monitor_eating(void *data)
{
	int		i;
	t_table	*table;

	table = (t_table *)data;
	write(1, "bucle monitor_01\n", 17);
	while (!all_threads_running(&table->table_mutex, &table->threads_running_nbr, table->philos_number))
		;
	write(1, "bucle monitor_02\n", 17);
	while (!routine_finished(table))
	{
		i = -1;
		while (++i < table->philos_number && !routine_finished(table))
		{
			write(1, "bucle monitor_03\n", 17);
			if (philo_died(table->philos + i))
			{
				set_bool(&table->table_mutex, &table->end_routine, true);
				write_status(DIED, table->philos + i, DEBUG_MODE);
			}
			write(1, "NO MUERTO: bucle monitor\n", 25);
		}
	}
	return (NULL);
}