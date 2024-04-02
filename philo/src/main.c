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
	if (argc == 5 || argc == 6)
	{
		ft_parse(argv, argc);
		ft_stackphilo(&a, argc, argv);
		init_philosophers(&a);
		printlist(&a);
		ft_freelist(&a);
	}
	else
	{
		error_exit("🚨 Wrong input: 🚨\n"
			G"✅ ./philo 5 800 200 200 [7] ✅\n"RST);
	}
	return (0);
}
