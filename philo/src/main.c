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

void	ft_dinner_init(t_philo **a)
{
	t_philo	*aux;

	aux = *a;
}

int	main(int argc, char **argv)
{
	t_philo	*a;
	t_philo_test	*test;

	atexit(ft_leaks);
	a = NULL;
	if (argc == 5 || argc == 6)
	{
		test = ft_new_test(argc, argv);
		ft_parse(argv, argc);
		ft_stackphilo(test, &a, argc, argv);
		ft_data_init(test, &a);
		ft_dinner_init(&a);
		printlist(&a);
		ft_freelist(&a);
		free(test);
	}
	else
	{
		error_exit("🚨 Wrong input: 🚨\n"
			G"✅ ./philo 5 800 200 200 [7] ✅\n"RST);
	}
	return (0);
}
