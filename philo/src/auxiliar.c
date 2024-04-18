/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:36:32 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/18 17:56:15 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
		error_exit("Error with the malloc");
	return (ret);
}

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

long	world_clock(int time_code)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		error_exit("Gettimeofday failed");
	if (time_code == MILLISECOND)
		return (tv.tv_sec * 1e3 + tv.tv_usec / 1e3);
	else if (time_code == MICROSECOND)
		return (tv.tv_sec * 1e6 + tv.tv_usec);
	else if (time_code == SECONDS)
		return (tv.tv_sec + tv.tv_usec / 1e6);
	else
		error_exit("Wrong input to synchro_time:"
			"use <MILLISECOND> <MICROSECOND> <SECONDS>");
	return (1337);
}
