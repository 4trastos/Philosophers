/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:39:37 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/01 18:17:19 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	ft_is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

int	ft_checker(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_is_number(argv[i][j]) == 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
