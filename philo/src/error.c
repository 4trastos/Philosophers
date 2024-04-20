/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:38:04 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/20 20:41:06 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	error_msg(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	exit (1);
}

void	error_exit(const char *error)
{
	printf(RED" %s \n"RST, error);
	exit(EXIT_FAILURE);
}

long	get_long(t_mutex *mutex, long *value)
{
	long	aux;

	ft_mutex(mutex, LOCK);
	aux = *value;
	ft_mutex(mutex, UNLOCK);
	return (aux);
}

void	clean_all(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < table->philos_number)
	{
		philo = table->philos + i;
		ft_mutex(&philo->philo_mutex, DESTROY);
	}
	ft_mutex(&table->write_mutex, DESTROY);
	ft_mutex(&table->table_mutex, DESTROY);
	ft_mutex(&table->dead_mutex, DESTROY);
	ft_mutex(&table->philos->meals_counter_mutex, DESTROY);
	free(table->forks);
	free(table->philos);
}

bool	philo_died(t_philo *philo)
{
	long	time_elapsed;

	ft_mutex(&philo->table->dead_mutex, LOCK);
	time_elapsed = world_clock(MILLISECOND) - get_long(&philo->philo_mutex,
			&philo->last_meal_time);
	ft_mutex(&philo->table->dead_mutex, UNLOCK);
	if (time_elapsed > philo->table->time_to_die)
		return (true);
	return (false);
}
