/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:36:32 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/01 19:53:38 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

long	ft_atoi(char *str)
{
	long	i;
	long	result;

	i = 0;
	result = 0;
	if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (result > INT_MAX)
		return (0);
	return (result);
}

void	mutex_handle(t_mtx *mutex, t_opcode opcode)
{
	if (opcode == LOCK)
		pthread_mutex_lock(mutex);
	else if (opcode == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (opcode == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (opcode == DESTROY)
		pthread_mutex_destroy(mutex);
	else
		error_msg("🚨 Wrogn opcode for mutex handle 🚨\n");
}

void	printlist(t_philo **a)
{
	t_philo	*aux;

	aux = *a;
	while (aux != NULL)
	{
		printf("Número de Filósofo: %d\n", aux->id);
		printf("Número de tenedor: %d\n", aux->fork);
		aux = aux->next;
	}
}
