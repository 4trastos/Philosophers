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
}

void	ft_freelist(t_philo	**a)
{
	t_philo	*aux;
	t_philo	*dupl;

	if (a == NULL)
		return ;
	dupl = *a;
	printf("Entra a liberar en el main\n");
	while (dupl)
	{
		printf("libear en main\n");
		aux = dupl->next;
		free(dupl);
		dupl = aux;
	}
	*a = NULL;
}
