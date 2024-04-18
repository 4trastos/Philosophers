/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:17:10 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/17 16:28:44 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

/* void	ft_leaks(void)
{
	system("leaks -q philo");
} */

int	main(int argc, char **argv)
{
	t_table	table;

/* 	atexit(ft_leaks); */
	if (argc == 5 || argc == 6)
	{
		parse_input(argv, argc);
		data_init(&table, argc, argv);
		eat_start(&table);
		clean_all(&table);
	}
	else
	{
		error_exit("🚨 Wrong input: 🚨\n"
			G"✅ ./philo 5 800 200 200 [7] ✅\n"RST);
	}
	return (0);
}
