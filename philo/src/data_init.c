/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:52:16 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/11 20:19:23 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	assign_forks(t_philo *philo, t_fork *forks, int id)
{
	int	philo_number;

	philo_number = philo->table->philo_number;
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
	table->philo_number = ft_atoi(argv[1]);
	if (table->philo_number > 200)
		error_msg("🚨 Too many philosophers! 🚨\n");
	table->time_to_die = ft_atoi(argv[2]) * 1e3;
	table->time_to_eat = ft_atoi(argv[3]) * 1e3;
	table->time_to_sleep = ft_atoi(argv[4]) * 1e3;
	table->philos = safe_malloc(table->philo_number * sizeof(t_philo));
	table->forks = safe_malloc(table->philo_number * sizeof(t_fork));
	while (i <= table->philo_number)
	{
		ft_mutex(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
		i++;
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
	int		id;

	id = 1;
	while (id <= table->philo_number)
	{
		philo = table->philos + id;
		philo->id = id;
		philo->full = false;
		philo->meals_counter = 0;
		ft_mutex(&philo->philo_mutex, INIT);
		philo->table = table;
		assign_forks(philo, table->forks, id);
		id++;
	}
}
