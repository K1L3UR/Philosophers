/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:16:14 by arnduran          #+#    #+#             */
/*   Updated: 2023/11/21 19:38:55 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

void	check_dead(t_philo *ptr_ph)
{
	int	i;

	i = 0;
	while (check_alive(ptr_ph) == 1)
	{
		pthread_mutex_lock(&ptr_ph->data->meal);
		if (get_time() - ptr_ph->data->starting_time - ptr_ph[i].last_meal
			> (ptr_ph->data->time_to_die))
		{
			pthread_mutex_lock(&ptr_ph->data->status);
			ptr_ph->data->alive = 0;
			pthread_mutex_unlock(&ptr_ph->data->status);
			pthread_mutex_lock(&ptr_ph->data->writing);
			printf("%lu %d is dead\n", find_time(ptr_ph), ptr_ph[i].id);
			pthread_mutex_unlock(&ptr_ph->data->writing);
			pthread_mutex_unlock(&ptr_ph->data->meal);
			break ;
		}
		pthread_mutex_unlock(&ptr_ph->data->meal);
		i++;
		if (i == ptr_ph->data->nb_philo)
		{
			usleep(2000);
			i = 0;
		}
	}
}

int	special_case(t_philo *ptr_ph, t_data *info)
{
	ptr_ph->data = info;
	ptr_ph->id = 1;
	ptr_ph->number_of_eat = 0;
	ptr_ph->r_fork = 0;
	printf("%lu %d has taken a fork\n", find_time(ptr_ph), (ptr_ph->id));
	usleep(ptr_ph->data->time_to_die * 1000);
	printf("%lu %d is dead\n", find_time(ptr_ph), (ptr_ph->id));
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc <= 4 || argc > 6)
		return (0);
	parsing(argc, argv);
	return (0);
}
