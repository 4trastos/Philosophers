/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:13:06 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/02 19:22:25 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	ft_data_init(t_philo_test	*test, t_philo **a)
{
	t_philo	*aux;

	aux = *a;
    test->end_simulation = false;
}
