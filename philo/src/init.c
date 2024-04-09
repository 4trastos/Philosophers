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
	wait_all_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILLISECOND));
	increase_long(&philo->table->table_mutex,
		&philo->table->threads_running_nbr);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	while (!simulation_finished(philo->table))
		precise_usleep(200, philo->table);
	return (NULL);
}

void	*philo_routine(t_table *table)
{
	int	i;

	i = -1;
	if (table->nbr_limit_meals == 0)
		return ;
	else if (table->philo_number == 1)
		{
			ft_threads(&table->philos[0].thread_id, unique_philo, &table->philos[0], CREATE);
		}
}

void	eat_start(t_table *table)
{
	pthread_t	*philos;
	long		dead;
	int			i;

	i = 1;
	philos = malloc(sizeof(pthread_t) * table->philo_number);
	if (!philos)
		return ;
	dead = table->time_to_die;
	while (dead > 0)
	{
		while (i < table->philo_number)
		{
			if (0 != pthread_create(&philos[i], NULL, philo_routine(table), &i))
				error_exit("🚨 Error creating thread 🚨\n");
			i++;
		}
		i = 1;
	}
}
