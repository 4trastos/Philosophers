/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:13:06 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/06 20:18:38 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	*philo_routine(t_table *table)
{
	t_table *aux;

	aux = table;
	long	i;

	i = 0;
	return(NULL);
}

void	eat_start(t_table *table)
{
	pthread_t	philos;
	long		dead;
	int			i;

	i = 0;
	philos = table->philo_number;
	dead = table->time_to_die;
	while (dead > 0)
	{
		while (i <= philos)
		{
			if (0 != pthread_create(&philos, NULL, philo_routine(table), NULL))
				error_exit("🚨 Error creating thread 🚨\n");
			i++;
		}
		i = 0;
	}
}

/* static void	assign_forks(t_philo *philo, t_fork *forks,
		int philo_position)
{
	int	philo_number;

	philo_number = philo->table->philo_number;
	philo->first_fork = &forks[(philo_position + 1) % philo_number];
	philo->second_fork = &forks[philo_position];
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[philo_position];
		philo->second_fork = &forks[(philo_position + 1) % philo_number];
	}	
}

static void	ft_data_init(t_table *table, t_philo **a)
{
	int		i;

	i = 0;
	table->end_simulation = false;
	table->philos = safe_malloc(sizeof(t_philo) * table->philo_number);
	table->forks = safe_malloc(sizeof(t_philo) * table->philo_number);
	while (i < table->philo_number)
	{
		safe_mutex_handle(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
		i++;
	}
	assing_forks(&a, table->forks, i);
}

static void	data_init(t_table *table)
{
	int		i;

	i = -1;
	table->end_simulation = false;
	table->all_threads_ready = false;
	table->threads_running_nbr = 0;
	table->philos = safe_malloc(table->philo_number * sizeof(t_philo));
	table->forks = safe_malloc(table->philo_number * sizeof(t_fork));
	safe_mutex_handle(&table->write_mutex, INIT);
	safe_mutex_handle(&table->table_mutex, INIT);
	while (++i < table->philo_number)
	{
		safe_mutex_handle(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
	}
	philo_init(table);
}

static void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->philo_number)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		safe_mutex_handle(&philo->philo_mutex, INIT);
		philo->table = table;
		assign_forks(philo, table->forks, i);
	}
} */
