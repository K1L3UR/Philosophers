/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:16:14 by arnduran          #+#    #+#             */
/*   Updated: 2023/11/23 14:41:12 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

static int	philo_loop(t_philo *ptr_ph, int i)
{
	if (i == ptr_ph->data->nb_philo)
	{
		usleep(500);
		i = 0;
	}
	return (i);
}

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
		i = philo_loop(ptr_ph, i);
	}
}

int	main(int argc, char **argv)
{
	if (argc <= 4 || argc > 6)
		return (0);
	parsing(argc, argv);
	return (0);
}
