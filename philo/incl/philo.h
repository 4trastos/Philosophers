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
# include <pthread.h>
# include <sys/time.h>

/*
 * PHILO
 *
 * ./philo 5 800 200 200 [5]
*/

# define RST    "\033[0m"      /* Reset to default color */
# define RED	"\033[1;31m"   /* Bold Red */
# define G      "\033[1;32m"   /* Bold Green */
# define Y      "\033[1;33m"   /* Bold Yellow */
# define B      "\033[1;34m"   /* Bold Blue */
# define M      "\033[1;35m"   /* Bold Magenta */
# define C      "\033[1;36m"   /* Bold Cyan */
# define W      "\033[1;37m"   /* Bold White */

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}			t_opcode;

typedef pthread_mutex_t	t_mtx;

typedef struct s_fork
{
	t_mtx			fork;
	int			fork_id;
}	t_fork;

typedef struct s_philo
{
	int			id;
	int			fork;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			philo_number;
	long			number_of_times;
	long			meals_counter;
	long			last_meal_time;
	bool			full;
	struct s_philo	*next;
	struct s_philo	*prev;
}	t_philo;

typedef struct s_philo_test
{
	int			id;
	int			fork;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			number_of_times;
	long			philo_number;
	long			start_simulation;
	bool			end_simulation;
}	t_philo_test;

//*** INIT ****

int				main(int argc, char **argv);

//*** ERRORS ****

void				ft_error_msg(char *str, t_philo *a);
void				free_matrix(t_philo **a);
void				ft_freelist(t_philo **a);
void				error_exit(const char *error);
void				ft_parse(char **argv, int argc);
void				error_msg(char *str);

//*** CHECKER ****

int				ft_checker(char **argv);
int				ft_is_numer(char c);
int				ft_checkerphilo(char **argv, int argc);
bool				is_space(char c);

//*** PHILO ****

void				ft_argcount(t_philo *a, int arc, char **argv);
void				ft_data_init(t_philo_test	*test, t_philo **a);
void				ft_dinner_init(t_philo **a);

//*** NODES ****

void				ft_stackphilo(t_philo_test	*test, t_philo **a, int arc, char **argv);
t_philo				*ft_createnode(int id, int fork,  t_philo_test *aux);
t_philo_test			*ft_new_test(int arc, char **argv);
void				ft_stacknode(t_philo **a, t_philo *new);

//*** AUXILIARS ****

long				ft_atoi(char *str);
void				printlist(t_philo **a);

#endif
