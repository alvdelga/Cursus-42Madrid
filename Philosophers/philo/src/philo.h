/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:20:06 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/31 19:22:07 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h>

# define MAX_PHILO 200
# define DEBUG 0

# define RESET    "\033[0m"
# define RED      "\033[31m"
# define GREEN    "\033[32m" 

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	struct s_program	*progra;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*write_lock;
	pthread_mutex_t		*dead_lock;
	pthread_mutex_t		*meal_lock;
	bool				eating;
	int					meals_eaten;
	size_t				last_meal;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				start_time;
	int					num_of_philos;
	int					num_times_to_eat;
	int					*dead;

}					t_philo;

typedef struct s_program
{
	bool			observer_ready;
	pthread_mutex_t	observer_lock;
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_program;

// Main functions
int					check_arg_content(char *arg);
int					check_valid_args(char **argv);
void				destory_all(char *str, t_program *program,
						pthread_mutex_t *forks);
int					init_program(t_program *program, t_philo *philos);
int					init_forks(pthread_mutex_t *forks, int philo_num);
void				init_philos(t_program *program,
						pthread_mutex_t *forks, char **argv);
void				init_input(t_philo *philo, char **argv);

// Threads
int					thread_create(t_program *program, pthread_mutex_t *forks);
void				*philo_observer(void *pointer);
void				*philo_routine(void *pointer);

// Actions
void				eat(t_philo *philo);
void				ft_sleep(t_philo *philo);
void				think(t_philo *philo);

// observer utils
int					dead_loop(t_philo *philo);
int					check_all_ate(t_philo *philos);
int					check_dead(t_philo *philos);
int					philosopher_dead(t_philo *philo, size_t time_to_die);

// Utils
int					ft_atoi(const char *str);
int					ft_usleep(size_t microseconds);
int					ft_strlen(char *str);
void				print_message(char *str, t_philo *philo, int id);
size_t				get_current_time(void);

#endif
