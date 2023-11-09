/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:16:14 by arnduran          #+#    #+#             */
/*   Updated: 2023/11/09 18:18:32 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

int	check_dead(t_philo *ptr_ph)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&ptr_ph->data->status);
	while (get_time()- ptr_ph[i].last_meal < (ptr_ph->data->time_to_die * 1000))
	{
		return (ptr_ph->id);
	}
	pthread_mutex_unlock(&ptr_ph->data->status);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	*ptr_ph;

	if (argc <= 4 || argc > 6)
		return (0);
	parsing(argc, argv, ptr_ph);
	while (check_dead != 0)
	{
		
	}
	return (0);
}
