/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_sync.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:45:03 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/20 18:56:42 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	wait_all_threads(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->all_threads_ready))
		;
}

void	set_long(t_mutex *mutex, long *dest, long value)
{
	ft_mutex(mutex, LOCK);
	*dest = value;
	ft_mutex(mutex, UNLOCK);
}

void	numbers_threads(t_mutex *mutex, long *value)
{
	ft_mutex(mutex, LOCK);
	(*value)++;
	ft_mutex(mutex, UNLOCK);
}

void	set_bool(t_mutex *mutex, bool *dest, bool value)
{
	ft_mutex(mutex, LOCK);
	*dest = value;
	ft_mutex(mutex, UNLOCK);
}

bool	get_bool(t_mutex *mutex, bool *value)
{
	bool	aux;

	ft_mutex(mutex, LOCK);
	aux = *value;
	ft_mutex(mutex, UNLOCK);
	return (aux);
}
