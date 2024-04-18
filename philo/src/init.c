/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:13:06 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/18 19:54:23 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	philo_is_thinking(t_philo *philo, bool pre_routine)
{
	long	time_eat;
	long	time_sleep;
	long	time_think;

	if (!pre_routine)
		write_status(THINKING, philo);
	if (philo->table->philos_number % 2 == 0)
		return ;
	time_eat = philo->table->time_to_eat;
	time_sleep = philo->table->time_to_sleep;
	time_think = (time_eat * 2) - time_sleep;
	if (time_think < 0)
		time_think = 0;
	philo_is_sleeping(time_think * 0.42, philo->table);
}

void	philo_is_sleeping(long sleep_time, t_table *table)
{
	long	start;
	long	time_elapsed;
	long	time_left;

	start = world_clock(MILLISECOND);
	while (world_clock(MILLISECOND) - start < sleep_time)
	{
		if (routine_finished(table))
			break ;
		time_elapsed = world_clock(MILLISECOND) - start;
		time_left = sleep_time - time_elapsed;
		if (time_left > 1e4)
			usleep(time_left / 2);
		else
		{
			while (world_clock(MILLISECOND) - start < sleep_time)
				;
		}
	}
}

void	philo_is_eating(t_philo *philo)
{
	ft_mutex(&philo->first_fork->fork, LOCK);
	write_status(TAKE_FIRST_FORK, philo);
	if (philo->table->philos_number == 1)
	{
		philo_is_sleeping(philo->table->time_to_die + 1, philo->table);
		return ;
	}
	ft_mutex(&philo->second_fork->fork, LOCK);
	write_status(TAKE_SECOND_FORK, philo);
	set_long(&philo->philo_mutex, &philo->last_meal_time, world_clock(MILLISECOND));
	write_status(EATING, philo);
	philo_is_sleeping(philo->table->time_to_eat, philo->table);
	if (philo->table->nbr_limit_meals > 0 && philo->meals_counter == philo->table->nbr_limit_meals)
		set_bool(&philo->philo_mutex, &philo->full, true);
	ft_mutex(&philo->first_fork->fork, UNLOCK);
	ft_mutex(&philo->second_fork->fork, UNLOCK);
}

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	/* wait_all_threads(philo->table); */
	set_long(&philo->philo_mutex, &philo->last_meal_time, world_clock(MILLISECOND));
	/* synchro_philos(philo); */
	while (!routine_finished(philo->table))
	{
		if (get_bool(&philo->philo_mutex, &philo->full))
			break ;
		philo_is_eating(philo);
		numbers_threads(&philo->table->meals_counter_mutex, &philo->meals_counter);
		/* philo->meals_counter++; */
		/* printf("Comidas: %ld\n", philo->meals_counter); */
		write_status(SLEEPING, philo);
		philo_is_sleeping(philo->table->time_to_sleep, philo->table);
		philo_is_thinking(philo, false);
	}
	return (NULL);
}

void	eat_start(t_table *table)
{
	int	i;
	table->start_routine = world_clock(MILLISECOND);
	i = -1;
	if (table->nbr_limit_meals == 0)
		return ;
	while (++i < table->philos_number)
	{
		ft_threads(&table->philos[i].thread_id, philo_routine, &table->philos[i], CREATE);
		numbers_threads(&table->table_mutex, &table->threads_running_nbr);
	}
	ft_threads(&table->monitor, monitor_eating, table, CREATE);
	set_bool(&table->table_mutex, &table->all_threads_ready, true);
	i = -1;
	while (++i < table->philos_number)
	{	
		ft_threads(&table->philos[i].thread_id, NULL, NULL, JOIN);
	}
	set_bool(&table->table_mutex, &table->end_routine, true);
	ft_threads(&table->monitor, NULL, NULL, JOIN);
}

/* void	*unique_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal_time, get_time(MILLISECOND));
	numbers_threads(&philo->table->table_mutex, &philo->table->threads_running_nbr);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	while (!routine_finished(philo->table)) 
		philo_is_sleeping(200, philo->table);
	return (NULL);
} */