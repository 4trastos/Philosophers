/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:36:32 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/09 14:49:05 by davgalle         ###   ########.fr       */
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
	{
		printf("Te has pasado: %ld\n", result);
		return (0);
	}
	return (result);
}

bool	get_bool(t_mutex *mutex, bool *value)
{
	bool	ret;

	ft_mutex(mutex, LOCK);
	ret = *value;
	ft_mutex(mutex, UNLOCK);
	return (ret);
}