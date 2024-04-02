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

void	printlist(t_philo **a)
{
	t_philo	*aux;

	aux = *a;
	printf("dentro de stackphilo:\n");
	while (aux != NULL)
	{
		printf("%d\n", aux->id);
		aux = aux->next;
	}
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
