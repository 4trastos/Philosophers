/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:39:37 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/06 19:35:18 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

int	ft_checker(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (is_space(argv[i][j]))
			j++;
		if (argv[i][j] == '+')
			j++;
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

int	ft_checkerphilo(char **argv, int argc)
{
	int	numb;

	if (argc == 6)
	{
		if ((numb = ft_atoi(argv[5]) < 60))
			return (0);
		return (1);
	}
	else
	{
		if ((numb = ft_atoi(argv[1]) == 0))
			return (0);
		if ((numb = ft_atoi(argv[2]) < 60))
			return (0);
		if ((numb = ft_atoi(argv[3]) < 60))
			return (0);
		if ((numb = ft_atoi(argv[4]) < 60))
			return (0);
		return (1);
	}
}

void	parse_input(char **argv, int argc)
{
	if (!(ft_checker(argv)))
		error_msg("🚨 The Invalid characters! 🚨\n");
	if (!(ft_checkerphilo(argv, argc)))
		error_msg("🚨 The input is not a correct digit! 🚨\n");
}
