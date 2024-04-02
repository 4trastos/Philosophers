/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:18:47 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/01 19:40:19 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <stdbool.h>

typedef struct s_philo
{
	int				id;
	int				fork;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				numb_phy;
	int				number_of_times;
	struct s_philo	*next;
	struct s_philo	*prev;
}	t_philo;

typedef struct s_philo_test
{
	int				id;
	int				fork;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times;
	int				numb_phy;
}	t_philo_test;

//*** INIT ****

int					main(int argc, char **argv);

//*** ERRORS ****

void					ft_error_msg(char *str, t_philo *a);
void					free_matrix(t_philo **a);
void					ft_freelist(t_philo **a);

//*** CHECKER ****

int					ft_checker(char **argv);
int					ft_is_numer(char c);
int					ft_checkerphilo(char **argv);

//*** PHILO ****

void					ft_argcount(t_philo *a, int arc, char **argv);

//*** NODES ****

void					ft_stackphilo(t_philo **a, int arc, char **argv);
t_philo					*ft_createnode(int id, t_philo_test *aux);
t_philo_test				*ft_new_test(int arc, char **argv);
void					ft_stacknode(t_philo **a, t_philo *new);

//*** AUXILIARS ****

int					ft_atoi(char *str);
void					printlist(t_philo **a);

#endif
