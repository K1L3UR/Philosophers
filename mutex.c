/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:56:26 by arnduran          #+#    #+#             */
/*   Updated: 2023/11/23 15:05:40 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

void	init_mutex(t_data *info)
{
	int	i;

	i = 0;
	pthread_mutex_init(&info->status, NULL);
	pthread_mutex_init(&info->meal, NULL);
	pthread_mutex_init(&info->writing, NULL);
	pthread_mutex_init(&info->meal_counter_mutex, NULL);
	while (i < info->nb_philo)
	{
		pthread_mutex_init(&info->forks[i], NULL);
		i++;
	}
	return ;
}

void	destroy_mutex(t_data *info, t_philo *ptr_ph)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		pthread_mutex_destroy(&(info->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(info->writing));
	pthread_mutex_destroy(&(info->status));
	pthread_mutex_destroy(&(info->meal));
	pthread_mutex_destroy(&(info->meal_counter_mutex));
	free(info->forks);
	free(ptr_ph);
}

int	check_alive(t_philo *ptr_ph)
{
	int	tmp;

	tmp = 0;
	pthread_mutex_lock(&ptr_ph->data->status);
	tmp = ptr_ph->data->alive;
	pthread_mutex_unlock(&ptr_ph->data->status);
	return (tmp);
}

void	lock_meal_unlock_meal(t_philo *ptr_ph)
{
	pthread_mutex_lock(&ptr_ph->data->meal);
	ptr_ph->last_meal = find_time(ptr_ph);
	pthread_mutex_unlock(&ptr_ph->data->meal);
}
