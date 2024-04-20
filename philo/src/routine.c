/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:39:59 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/20 20:15:44 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

bool	routine_finished(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->end_routine));
}

bool	all_threads_running(t_mutex *mutex, long *threads, long philos_number)
{
	bool	aux;

	aux = false;
	ft_mutex(mutex, LOCK);
	if (*threads == philos_number)
		aux = true;
	ft_mutex(mutex, UNLOCK);
	return (aux);
}

void	synchro_philos(t_philo *philo)
{
	if (philo->table->philos_number % 2 == 0)
	{
		if (philo->id % 2 == 0)
			time_counter(1e3, philo->table);
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
	while (!all_threads_running(&table->table_mutex,
			&table->threads_running_nbr, table->philos_number))
		;
	while (!routine_finished(table))
	{
		i = -1;
		while (++i < table->philos_number && !routine_finished(table))
		{
			if (philo_died(&table->philos[i]))
			{
				set_bool(&table->table_mutex, &table->end_routine, true);
				write_status(DIED, &table->philos[i]);
			}
		}
	}
	return (NULL);
}
