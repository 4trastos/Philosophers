/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:52:16 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/06 20:05:59 by davgalle         ###   ########.fr       */
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
	table->end_simulation = false;
	table->all_threads_ready = false;
	table->philo_number = ft_atoi(argv[1]);
	if (table->philo_number > 200)
		ft_error_msg("🚨 Too many philosophers! 🚨\n", NULL);
	table->time_to_die = ft_atoi(argv[2]) * 1e3;
	table->time_to_eat = ft_atoi(argv[3]) * 1e3;
	table->time_to_sleep = ft_atoi(argv[4]) * 1e3;
	table->philos = safe_malloc(table->philo_number * sizeof(t_philo));
	table->forks = safe_malloc(table->philo_number * sizeof(t_fork));
	while (i <= table->philo_number)
	{
		safe_mutex_handle(&table->forks[i].fork, INIT);
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
		safe_mutex_handle(&philo->philo_mutex, INIT);
		philo->table = table;
		assign_forks(philo, table->forks, id);
		id++;
	}
}

/* t_philo	*ft_createnode(int id, t_table *table)
{
	t_philo	*new;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->id = id;
	new->full = false;
	new->meals_counter = 0;
	new->table = table;
	new->nbr_limit_meals = table->nbr_limit_meals;
	new->first_fork = NULL;
	new->second_fork = NULL;
	return (new);
} */

/* void	data_init(t_table *table, char **argv)
{
	int				id;
	int				philo;

	id = 1;
	philo = ft_atoi(argv[1]);
	if (philo > 200)
		ft_error_msg("🚨 Too many philosophers! 🚨\n", NULL);
	while (philo > 0)
	{
		ft_stacknode(a, ft_createnode(id, table)); 
		ft_createnode(id, table);
		id++;
		philo--;
	}
} */

/* void	ft_stacknode(t_philo **a, t_philo *new)
{
	t_philo	*aux;

	aux = *a;
	if (*a == NULL)
	{
		*a = new;
		return ;
	}
	while (aux->next != NULL)
		aux = aux->next;
	new->prev = aux;
	aux->next = new;
	new->next = NULL;
} */

/* t_table	*ft_new_table(int arc, char **argv)
{
	t_table	*new;

	new = (t_table *)malloc(sizeof(t_table));
	if (!new)
		return (NULL);
	new->end_simulation = false;
	new->all_threads_ready = false;
	new->philo_number = ft_atoi(argv[1]);
	if (new->philo_number > 200)
		ft_error_msg("🚨 Too many philosophers! 🚨\n", NULL);
	new->time_to_die = ft_atoi(argv[2]) * 1e3;
	new->time_to_eat = ft_atoi(argv[3]) * 1e3;
	new->time_to_sleep = ft_atoi(argv[4]) * 1e3;
	if (arc == 6)
		new->nbr_limit_meals = ft_atoi(argv[5]);
	else
		new->nbr_limit_meals = -1;
	return (new);
} */