/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:20:06 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/31 20:43:38 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	pthread_mutex_lock(&philo->progra->observer_lock);
	while (!philo->progra->observer_ready)
	{
		pthread_mutex_unlock(&philo->progra->observer_lock);
		usleep(50);
		pthread_mutex_lock(&philo->progra->observer_lock);
	}
	pthread_mutex_unlock(&philo->progra->observer_lock);
	ft_usleep((philo->id % 2) * 5);
	while (!dead_loop(philo))
	{
		eat(philo);
		ft_sleep(philo);
		think(philo);
	}
	return (pointer);
}

int	thread_create(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			i;
	int			num_philos;

	i = 0;
	num_philos = program->philos[0].num_of_philos;
	if (pthread_create(&observer, NULL, philo_observer, program->philos) != 0)
		destory_all("Thread creation error", program, forks);
	while (i < num_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &philo_routine,
				&program->philos[i]) != 0)
			destory_all("Thread creation error", program, forks);
		i++;
	}
	if (pthread_join(observer, NULL) != 0)
		destory_all("Thread join error", program, forks);
	i = 0;
	while (i < num_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			destory_all("Thread join error", program, forks);
		i++;
	}
	return (0);
}
