/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:20:06 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/31 19:19:01 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_nbr(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_valid_args(char **argv)
{
	if (ft_atoi(argv[1]) > MAX_PHILO || ft_atoi(argv[1]) <= 0
		|| check_nbr(argv[1]) == 1)
		return (printf(RED "[!]" RESET " Invalid philosophers\n"), -1);
	if (ft_atoi(argv[2]) <= 0 || check_nbr(argv[2]) == 1)
		return (printf(RED "[!]" RESET " Invalid time to die\n"), -1);
	if (ft_atoi(argv[3]) <= 0 || check_nbr(argv[3]) == 1)
		return (printf(RED "[!]" RESET " Invalid time to eat\n"), -1);
	if (ft_atoi(argv[4]) <= 0 || check_nbr(argv[4]) == 1)
		return (printf(RED "[!]" RESET " Invalid time to sleep\n"), -1);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_nbr(argv[5]) == 1))
		return (printf(RED "[!]" RESET " Invalid number of times\n"), -1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_program		program;
	t_philo			philosofer[MAX_PHILO];
	pthread_mutex_t	forks[MAX_PHILO];

	if (argc != 5 && argc != 6)
		return (printf(RED "[!]" RESET " Wrong arguments\n"), 1);
	if (check_valid_args(argv) == -1)
		return (1);
	if (init_program(&program, philosofer) != 0)
		return (1);
	if (init_forks(forks, ft_atoi(argv[1])) != 0)
		return (1);
	init_philos(&program, forks, argv);
	thread_create(&program, forks);
	destory_all(NULL, &program, forks);
	return (0);
}
