/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:39:59 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/11 20:21:24 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

bool    routine_finished(t_table *table)
{
    return(get_bool(&table->table_mutex, &table->end_routine));
}

void	philo_is_thinking(t_philo *philo, bool pre_routine)
{
	long	eat;
	long	sleep;
	long	think;
	if (!pre_routine)
		write_status(THINKING, philo);
	if (philo->table->philo_number % 2 == 0)
		return ;
	eat = philo->table->time_to_eat;
	sleep = philo->table->time_to_sleep;
	think = (eat * 2) - sleep;
	if (think < 0)
		think = 0;
	philo_is_sleeping(think * 0.2, philo->table);
}