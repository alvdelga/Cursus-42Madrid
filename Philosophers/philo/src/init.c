/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:20:06 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/31 19:21:00 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_input(t_philo *philo, char **argv)
{
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->num_of_philos = ft_atoi(argv[1]);
	if (argv[5])
		philo->num_times_to_eat = ft_atoi(argv[5]);
	else
		philo->num_times_to_eat = -1;
}

void	init_philos(t_program *program, pthread_mutex_t *forks, char **argv)
{
	int		i;
	int		num_philos;
	t_philo	*philosofer;

	i = 0;
	num_philos = ft_atoi(argv[1]);
	while (i < num_philos)
	{
		philosofer = &program->philos[i];
		philosofer->id = i + 1;
		philosofer->eating = 0;
		philosofer->meals_eaten = 0;
		init_input(philosofer, argv);
		philosofer->start_time = get_current_time();
		philosofer->last_meal = philosofer->start_time;
		philosofer->write_lock = &program->write_lock;
		philosofer->dead_lock = &program->dead_lock;
		philosofer->meal_lock = &program->meal_lock;
		philosofer->dead = &program->dead_flag;
		philosofer->progra = program;
		philosofer->l_fork = &forks[i];
		philosofer->r_fork = &forks[(i - 1 + num_philos) % num_philos];
		i++;
	}
}

int	init_forks(pthread_mutex_t *forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			fprintf(stderr, "Failed to init fork mutex\n");
			while (--i >= 0)
				pthread_mutex_destroy(&forks[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_program(t_program *program, t_philo *philosofer)
{
	program->dead_flag = 0;
	program->philos = philosofer;
	program->observer_ready = false;
	if (pthread_mutex_init(&program->write_lock, NULL) != 0)
		return (printf("[!] Failed to init write_lock\n"), 1);
	if (pthread_mutex_init(&program->dead_lock, NULL) != 0)
		return (printf("[!] Failed to init dead_lock\n"), 1);
	if (pthread_mutex_init(&program->meal_lock, NULL) != 0)
		return (printf("[!] Failed to init meal_lock\n"), 1);
	if (pthread_mutex_init(&program->observer_lock, NULL) != 0)
		return (printf("[!] Failed to init monitor_lock\n"), 1);
	return (0);
}
