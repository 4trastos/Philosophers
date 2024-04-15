/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:13:06 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/15 19:49:40 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	philo_is_sleeping(long sleep_time, t_table *table)
{
	long	start;
	long	time_elapsed;
	long	time_left;
	start = get_time(MICROSECOND);
	while (get_time(MICROSECOND) - start < sleep_time)
	{
		if (routine_finished(table))
			break;
		time_elapsed = get_time(MICROSECOND) - start;
		time_left = sleep_time - time_elapsed;
		if (time_left > 1e4)
			usleep(time_left / 2);
		else
		{
			while (get_time(MICROSECOND) - start < sleep_time);
		}
	}
}

void	philo_is_eating(t_philo *philo)
{
	ft_mutex(&philo->first_fork->fork, LOCK);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	ft_mutex(&philo->second_fork->fork, LOCK);
	write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);
	set_long(&philo->philo_mutex, &philo->last_meal_time, get_time(MILLISECOND));
	philo->meals_counter++;
	write_status(EATING, philo, DEBUG_MODE);
	philo_is_sleeping(philo->table->time_to_sleep, philo->table);
	if (philo->table->nbr_limit_meals > 0 && philo->meals_counter == philo->table->nbr_limit_meals)
		set_bool(&philo->philo_mutex, &philo->full, true);
	ft_mutex(&philo->first_fork->fork, UNLOCK);
	ft_mutex(&philo->second_fork->fork, UNLOCK);
}

void	*unique_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	write(1, "OK_01\n", 6);
	wait_all_threads(philo->table);
	write(1, "OK_02\n", 6);
	set_long(&philo->philo_mutex, &philo->last_meal_time, get_time(MILLISECOND));
	write(1, "OK_04\n", 6);
	increase_threads(&philo->table->table_mutex, &philo->table->threads_running_nbr);
	write(1, "OK_03\n", 6);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	write(1, "OK_04\n", 6);
	while (!routine_finished(philo->table))
		philo_is_sleeping(200, philo->table);
	return (NULL);
}

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal_time, get_time(MILLISECOND));
	increase_threads(&philo->table->table_mutex, &philo->table->threads_running_nbr);
	synchro_philos(philo);
	while (!routine_finished(philo->table))
	{
		if (get_bool(&philo->philo_mutex, &philo->full))
			break;
		philo_is_eating(philo);
		write_status(SLEEPING, philo, DEBUG_MODE);
		philo_is_sleeping(philo->table->time_to_sleep, philo->table);
		philo_is_thinking(philo, false);
	}
	return (NULL);
}

void	eat_start(t_table *table)
{
	int	i;

	i = -1;
	if (table->nbr_limit_meals == 0)
		return ;
	else if (table->philos_number == 1)
			ft_threads(&table->philos[0].thread_id, unique_philo, &table->philos[0], CREATE);
	else
	{
		while (++i < table->philos_number)
		{
			ft_threads(&table->philos[i].thread_id, philo_routine, &table->philos[i], CREATE);
		}
	}
	ft_threads(&table->monitor, monitor_eating, table, CREATE);
	table->start_routine = get_time(MILLISECOND);
	set_bool(&table->table_mutex, &table->all_threads_ready, true);
	i = -1;
	while (++i < table->philos_number)
	{
		ft_threads(&table->philos[i].thread_id, NULL, NULL, JOIN);
	}
	set_bool(&table->table_mutex, &table->end_routine, true);
	ft_threads(&table->monitor, NULL, NULL, JOIN);
}