/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:17:10 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/01 20:02:25 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	ft_leaks(void)
{
	system("leaks -q philo");
}

void	init_philosophers(t_philo **a)
{
	t_philo	*aux;

	aux = *a;
}

int	main(int argc, char **argv)
{
	t_philo	*a;

	atexit(ft_leaks);
	a = NULL;
	if (argc == 1)
		ft_error_msg("arguments are necessary!", a);
	else if (argc < 5 || argc > 6)
		ft_error_msg("Invalid number of arguments!", a);
	else
	{
		if (!(ft_checker(argv)))
			ft_error_msg("Invalid arguments!", a);
		ft_stackphilo(&a, argc, argv);
	}
	init_philosophers(&a);
	printlist(&a);
	ft_freelist(&a);
	return (0);
}
