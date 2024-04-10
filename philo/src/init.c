/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:13:06 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/09 16:01:00 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	*unique_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	write(1,"TAKE FIRST FORK\n", 16);

	return (NULL);
}
void	eat(t_philo *philo)
{
	ft_mutex(&philo->first_fork, LOCK);
	ft_mutex(&philo->second_fork, LOCK);
	philo->meals_counter++;
	ft_mutex(&philo->first_fork, UNLOCK);
	ft_mutex(&philo->second_fork, UNLOCK);
}

void	*eat_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILLISECOND));
	while (!simulation_finished(philo->table))
	{
		if (get_bool(&philo->philo_mutex, &philo->full))
			break;
		eat(philo);
	}
	return (NULL);
}

void	eat_start(t_table *table)
{
	int	i;

	i = 0;
	if (table->nbr_limit_meals == 0)
		return ;
	else if (table->philo_number == 1)
			ft_threads(&table->philos[0].thread_id, unique_philo, &table->philos[0], CREATE);
	else
	{
		while (i < table->philo_number)
		{
			ft_threads(&table->philos[i].thread_id, eat_simulation, &table->philos[i], CREATE);
			i++;
		}
		write(1,"SALE DEL HILO\n", 14);
	}
}
