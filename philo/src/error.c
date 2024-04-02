/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:38:04 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/01 19:41:55 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	free_matrix(t_philo **a)
{
	t_philo	*aux;

	aux = *a;
	while (aux != NULL)
	{
		*a = aux->next;
		free(aux);
		aux = *a;
	}
	*a = NULL;
}

void	ft_error_msg(char *str, t_philo *a)
{
	int	i;

	if (a)
		free_matrix(&a);
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	exit (1);
}

void	ft_freelist(t_philo	**a)
{
	t_philo	*aux;
	t_philo	*dupl;

	if (a == NULL)
		return ;
	dupl = *a;
	while (dupl)
	{
		aux = dupl->next;
		free(dupl);
		dupl = aux;
	}
	*a = NULL;
}
void	error_msg(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	exit (1);
}

void	error_exit(const char *error)
{
	printf(RED" %s \n"RST, error);
	exit(EXIT_FAILURE);
}
