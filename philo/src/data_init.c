/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:52:16 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/18 18:38:46 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	assign_forks(t_philo *philo, t_fork *forks, int id)
{
	int	philo_number;

	philo_number = philo->table->philos_number;
	philo->first_fork = &forks[(id + 1) % philo_number];
	philo->second_fork = &forks[id];
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[id];
		philo->second_fork = &forks[(id + 1) % philo_number];
	}	
}

void	data_init(t_table *table, int argc, char **argv)
{
	int	i;

	i = -1;
	table->end_routine = false;
	table->all_threads_ready = false;
	table->philos_number = ft_atoi(argv[1]);
	if (table->philos_number > 200)
		error_msg("🚨 Too many philosophers! 🚨\n");
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->philos = safe_malloc(table->philos_number * sizeof(t_philo));
	table->forks = safe_malloc(table->philos_number * sizeof(t_fork));
	ft_mutex(&table->write_mutex, INIT);
	ft_mutex(&table->table_mutex, INIT);
	while (++i < table->philos_number)
	{
		ft_mutex(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
	}
	if (argc == 6)
		table->nbr_limit_meals = ft_atoi(argv[5]);
	else
		table->nbr_limit_meals = -1;
	philo_init(table);
}

void	philo_init(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = -1;
	ft_mutex(&table->dead_mutex, INIT);
	ft_mutex(&table->meals_counter_mutex, INIT);
	while (++i < table->philos_number)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		table->threads_running_nbr = 0;
		ft_mutex(&philo->philo_mutex, INIT);
		philo->table = table;
		assign_forks(philo, table->forks, i);
	}
}
