/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:36:32 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/06 19:46:53 by davgalle         ###   ########.fr       */
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

void	mutex_handle_error(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode))
		error_msg("🚨 The value specified by mutex is invalid 🚨\n");
	else if (EINVAL == status && INIT == opcode)
		error_msg("🚨 The value specified by attr is invalid 🚨\n");
	else if (EDEADLK == status)
		error_msg("🚨 Deadlock if the thread was blocked waiting for mutex.🚨\n");
	else if (EPERM == status)
		error_msg("🚨 The current thread does not hold a lock on mutex. 🚨\n");
	else if (ENOMEM == status)
		error_msg("🚨 You cannot allocate enough memory for another mutex. 🚨\n");
	else if (EBUSY == status)
		error_msg("🚨 Mutex is locked. 🚨\n");
}
