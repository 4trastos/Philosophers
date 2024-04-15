/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:22:12 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/15 19:35:13 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void    write_status_debug(t_philo_status status, t_philo *philo, long time_elapsed)
{
    if (status == TAKE_FIRST_FORK && !routine_finished(philo->table))
        printf(W"%6ld"RST" %d has taken the 1° fork 🍽"
			"\t\t\tn°"B"[🍴 %d 🍴]\n"RST, time_elapsed, philo->id,
			philo->first_fork->fork_id);
    else if (status ==TAKE_SECOND_FORK && !routine_finished(philo->table))
		printf(W"%6ld"RST" %d has taken the 2° fork 🍽"
			"\t\t\tn°"B"[🍴 %d 🍴]\n"RST, time_elapsed, philo->id,
			philo->second_fork->fork_id);
	else if (status == EATING && !routine_finished(philo->table))
		printf(W"%6ld"C" %d is eating 🍝"
			"\t\t\t"Y"[🍝 %ld 🍝]\n"RST, time_elapsed, philo->id, philo->meals_counter);
	else if (status == SLEEPING && !routine_finished(philo->table))
		printf(W"%6ld"RST" %d is sleeping 😴\n", time_elapsed, philo->id);
	else if (status ==THINKING && !routine_finished(philo->table))
		printf(W"%6ld"RST" %d is thinking 🤔\n", time_elapsed, philo->id);
	else if (status == DIED)
		printf(RED"\t\t💀💀💀 %6ld %d died   💀💀💀\n"RST, time_elapsed, philo->id);
}

void    write_status(t_philo_status status, t_philo *philo, bool debug)
{
    long time_elapsed;

    time_elapsed =  get_time(MICROSECOND) - philo->table->start_routine;
    if (get_bool(&philo->philo_mutex, &philo->full))
        return ;
    ft_mutex(&philo->table->write_mutex, LOCK);
    if (debug)
        write_status_debug(status, philo, time_elapsed);
    else
    {
        if (status == TAKE_FIRST_FORK && !routine_finished(philo->table))
            printf(W"%-6ld"RST" %d has taken a first fork\n", time_elapsed, philo->id);
        else if (status == TAKE_SECOND_FORK && !routine_finished(philo->table))
            printf(W"%-6ld"RST" %d has taken a second fork\n", time_elapsed, philo->id);    
        else if (status == EATING && !routine_finished(philo->table))
            printf(W"%-6ld"C" %d is eating\n"RST, time_elapsed, philo->id);
        else if (status == SLEEPING && !routine_finished(philo->table))
            printf(W"%-6ld"RST" %d is sleeping\n", time_elapsed, philo->id);
        else if (status == THINKING && !routine_finished(philo->table))
            printf(W"%-6ld"RST" %d is thinking\n", time_elapsed, philo->id);
        else if (status == DIED)
            printf(RED"%-6ld %d died\n"RST, time_elapsed, philo->id);
    }
    ft_mutex(&philo->table->write_mutex, UNLOCK);
}
