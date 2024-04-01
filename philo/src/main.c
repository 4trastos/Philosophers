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

void	pritlist(t_philo **a)
{
	t_philo	*aux;

	aux = *a;
	printf("Entra a escirbir en el main\n");
	while (aux)
	{
		printf("ID en el nodo:%d\n", aux->id);
		aux = aux->next;
	}
}

int main(int argc, char **argv)
{
	atexit(ft_leaks);
	t_philo	*a;

	a = NULL;
	if (argc == 1)
		ft_error_msg("arguments are necessary!", a);
	else if (argc < 5 || argc > 6)
		ft_error_msg("Invalid number of arguments!", a);
	else
	{
		if (!(ft_checker(argv)))
			ft_error_msg("Invalid arguments!", a);
		ft_stackphilo(a, argc, argv);
	}
	printlist(&a);
	free_matrix(&a);
	write(1, "\n", 1);
	return (0);
}
