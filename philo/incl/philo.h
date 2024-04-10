/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:18:47 by davgalle          #+#    #+#             */
/*   Updated: 2024/04/09 14:50:15 by davgalle         ###   ########.fr       */
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
# include <errno.h>

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

# ifndef DEBUG_MODE
#  define DEBUG_MODE 0
# endif

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}			t_philo_status;

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

typedef enum e_time_code
{
	SECONDS,
	MILLISECOND,
	MICROSECOND,
}	t_time_code;

typedef pthread_mutex_t	t_mutex;
typedef struct s_table	t_table;

typedef struct s_fork
{
	t_mutex			fork;
	int				fork_id;
}	t_fork;

typedef struct s_philo
{
	int				id;
	bool			full;
	long			meals_counter;
	long			last_meal_time;
	pthread_t		thread_id;
	t_fork			*first_fork;
	t_fork			*second_fork;
	t_mutex			philo_mutex;
	t_table			*table;
}	t_philo;

struct s_table
{
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nbr_limit_meals;
	long			philo_number;
	long			start_simulation;
	bool			end_simulation;
	bool			all_threads_ready;
	long			threads_running_nbr;
	pthread_t		monitor;
	t_fork			*forks;
	t_philo			*philos;
	t_mutex			table_mutex;
	t_mutex			write_mutex;
};	

//*** INIT ****

int					main(int argc, char **argv);

//*** ERRORS ****

void				ft_error_msg(char *str, t_philo *a);
void				error_exit(const char *error);
void				parse_input(char **argv, int argc);
void				error_msg(char *str);
void				ft_mutex_error(int status, t_opcode opcode);
void				ft_threads_error(int status, t_opcode opcode);

//*** CHECKER ****

int					ft_checker(char **argv);
int					ft_is_numer(char c);
int					ft_checkerphilo(char **argv, int argc);
bool				is_space(char c);

//*** PHILO ****

void				ft_argcount(t_philo *a, int arc, char **argv);
void				data_init(t_table *table, int argc, char **argv);
void				eat_start(t_table *table);
void				assign_forks(t_philo *philo, t_fork *forks, int id);
void				philo_init(t_table *table);
void				*unique_philo(void *arg);
void				eat(t_philo *philo);

//*** NODES ****

t_table				*ft_new_table(int arc, char **argv);
void				ft_stacknode(t_philo **a, t_philo *new);

//*** AUXILIARS ****

long				ft_atoi(char *str);

//*** ROUTINE ****

void				*philo_routine(t_table *table);
void				*eat_simulation(void *data);
void				eat(t_philo *philo);

//*** MUTEX ****

void				*safe_malloc(size_t bytes);
void				ft_mutex(t_mutex *mutex, t_opcode opcode);
void				ft_threads(pthread_t *thread, void *(*foo)(void *),
						void *data, t_opcode opcode);

//*** BOOL ****

bool				get_bool(t_mutex *mutex, bool *value);
bool    			simulation_finished(t_table *table);

//*** THREADS ****

void				wait_all_threads(t_table *table);
void				set_long(t_mutex *mutex, long *dest, long value);
void				increase_long(t_mutex *mutex, long *value);

#endif
