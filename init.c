/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:01:34 by arnduran          #+#    #+#             */
/*   Updated: 2023/11/23 14:46:24 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

void	do_init_philo_then_mutex(t_philo *ptr_ph, t_data *info)
{
	philo_init(ptr_ph, info);
	init_mutex(info);
}

void	philo_init(t_philo *ptr_ph, t_data *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		ptr_ph[i].data = info;
		ptr_ph[i].id = i + 1;
		ptr_ph[i].number_of_eat = 0;
		ptr_ph[i].last_meal = 0;
		if (i == info->nb_philo - 1)
			ptr_ph[i].r_fork = 0;
		else
			ptr_ph[i].r_fork = i + 1;
		ptr_ph[i].l_fork = i;
		i++;
	}
}

int	init(t_data *info, int ac, char **argv)
{
	int	n_philo;

	n_philo = ft_atoi(argv[1]);
	if (n_philo == 0)
		return (-1);
	info->nb_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (ac == 5)
		info->number_of_eat = ft_atoi(argv[5]);
	else
		info->number_of_eat = -1;
	if (errno == ERANGE)
		return (printf("Error ERANGE\n"), -1);
	info->meal_counter = 0;
	info->alive = 1;
	if (n_philo > 200 || n_philo < 0 || info->time_to_eat < 60
		|| info->time_to_sleep < 60 || (ac == 5 && ft_atoi(argv[5]) <= 0))
		return (-1);
	info->forks = malloc(sizeof(pthread_mutex_t) * n_philo);
	if (info->forks == NULL)
		return (-1);
	info->starting_time = get_time();
	return (0);
}
