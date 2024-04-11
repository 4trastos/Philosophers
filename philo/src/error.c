/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:38:04 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/11 20:09:20 by davgalle         ###   ########.fr       */
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

void	clean_all(t_table *table)
{
	t_philo *philo;
	int		i;

	i = -1;
	while (i < table->philo_number)
	{
		philo = table->philos + i;
		ft_mutex(&philo->philo_mutex, DESTROY);
		i++;
	}
	ft_mutex(&table->write_mutex, DESTROY);
	ft_mutex(&table->table_mutex, DESTROY);
	free(table->forks);
	free(table->philos);
}