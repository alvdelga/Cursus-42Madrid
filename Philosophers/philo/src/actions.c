/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:20:06 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/31 19:20:12 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if (!dead_loop(philo))
		printf(GREEN"[%ld]"RESET" %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

void	think(t_philo *philo)
{
	print_message("is thinking", philo, philo->id);
	ft_usleep(1);
}

void	ft_sleep(t_philo *philo)
{
	print_message("is sleeping", philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}

static int	take_and_lock_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		print_message("has taken a fork", philo, philo->id);
		if (philo->num_of_philos == 1)
			return (ft_usleep(philo->time_to_die),
				pthread_mutex_unlock(philo->l_fork), 1);
		pthread_mutex_lock(philo->r_fork);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		print_message("has taken a fork", philo, philo->id);
		if (philo->num_of_philos == 1)
			return (ft_usleep(philo->time_to_die),
				pthread_mutex_unlock(philo->r_fork), 1);
		pthread_mutex_lock(philo->l_fork);
	}
	print_message("has taken a fork", philo, philo->id);
	return (0);
}

void	eat(t_philo *philo)
{
	if (take_and_lock_forks(philo))
		return ;
	pthread_mutex_lock(philo->meal_lock);
	philo->eating = true;
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	print_message("is eating", philo, philo->id);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_lock(philo->meal_lock);
	philo->eating = false;
	pthread_mutex_unlock(philo->meal_lock);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

// void	eat(t_philo *philo)
// {
// 	pthread_mutex_lock(philo->r_fork);
// 	print_message("has taken a fork", philo, philo->id);
// 	if (philo->num_of_philos == 1)
// 	{
// 		ft_usleep(philo->time_to_die);
// 		pthread_mutex_unlock(philo->r_fork);
// 		return ;
// 	}
// 	pthread_mutex_lock(philo->l_fork);
// 	print_message("has taken a fork", philo, philo->id);
// 	philo->eating = 1;
// 	print_message("is eating", philo, philo->id);
// 	pthread_mutex_lock(philo->meal_lock);
// 	philo->last_meal = get_current_time();
// 	philo->meals_eaten++;
// 	pthread_mutex_unlock(philo->meal_lock);
// 	// DEBUG: imprime cuántas veces ha comido
// 	// printf("[DEBUG] Philo %d has eaten %d times\n",
// 	// philo->id, philo->meals_eaten;
// 	ft_usleep(philo->time_to_eat);
// 	philo->eating = 0;
// 	pthread_mutex_unlock(philo->l_fork);
// 	pthread_mutex_unlock(philo->r_fork);
// }
