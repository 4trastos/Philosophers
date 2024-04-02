/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:52:16 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/01 20:06:44 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

t_philo_test	*ft_new_test(int arc, char **argv)
{
	t_philo_test	*new;

	new = (t_philo_test *)malloc(sizeof(t_philo_test));
	if (!new)
		return (NULL);
	new->philo_number = ft_atoi(argv[1]);
	new->time_to_die = ft_atoi(argv[2]);
	new->time_to_eat = ft_atoi(argv[3]);
	new->time_to_sleep = ft_atoi(argv[4]);
	if (arc == 6)
		new->number_of_times = ft_atoi(argv[5]);
	return (new);
}

void	ft_stacknode(t_philo **a, t_philo *new)
{
	t_philo	*aux;

	aux = *a;
	if (*a == NULL)
	{
		*a = new;
		return ;
	}
	while (aux->next != NULL)
		aux = aux->next;
	new->prev = aux;
	aux->next = new;
	new->next = NULL;
}

t_philo	*ft_createnode(int id, int fork, t_philo_test *test)
{
	t_philo	*new;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->id = id;
	new->fork = fork;
	new->philo_number = test->philo_number;
	new->time_to_die = test->time_to_die;
	new->time_to_eat = test->time_to_eat;
	new->time_to_sleep = test->time_to_sleep;
	new->number_of_times = test->number_of_times;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_stackphilo(t_philo **a, int arc, char **argv)
{
	t_philo_test	*test;
	int				id;
	int				fork;
	int				philo;

	test = ft_new_test(arc, argv);
	id = 1;
	fork = 0;
	philo = ft_atoi(argv[1]);
	if (philo > 200)
		ft_error_msg("🚨 Too many philosophers! 🚨\n", *a);
	while (philo > 0)
	{
		ft_stacknode(a, ft_createnode(id, fork, test));
		id++;
		fork++;
		philo--;
	}
	free(test);
}
