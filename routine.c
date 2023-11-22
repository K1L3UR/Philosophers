/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:18:42 by arnduran          #+#    #+#             */
/*   Updated: 2023/11/22 18:11:13 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdio.h>

void	write_status(t_philo *ptr_ph, int status)
{
	if (check_alive(ptr_ph) == 1)
	{
		pthread_mutex_lock(&ptr_ph->data->writing);
		if (status == FORKING)
			printf("%lu %d has taken a fork\n", find_time(ptr_ph), ptr_ph->id);
		if (status == EATING)
			printf("%lu %d is eating\n", find_time(ptr_ph), ptr_ph->id);
		if (status == SLEEPING)
			printf("%lu %d is sleeping\n", find_time(ptr_ph), ptr_ph->id);
		if (status == THINKING)
			printf("%lu %d is thinking\n", find_time(ptr_ph), ptr_ph->id);
		pthread_mutex_unlock(&ptr_ph->data->writing);
	}
}

void	eating(t_philo *ptr_ph)
{
	if (ptr_ph->id % 2)
		pthread_mutex_lock(&ptr_ph->data->forks[ptr_ph->l_fork]);
	else
		pthread_mutex_lock(&ptr_ph->data->forks[ptr_ph->r_fork]);
	write_status(ptr_ph, FORKING);
	if (ptr_ph->id % 2)
		pthread_mutex_lock(&ptr_ph->data->forks[ptr_ph->r_fork]);
	else
		pthread_mutex_lock(&ptr_ph->data->forks[ptr_ph->l_fork]);
	write_status(ptr_ph, FORKING);
	write_status(ptr_ph, EATING);
	is_full(ptr_ph);
	lock_meal_unlock_meal(ptr_ph);
	ft_usleep(ptr_ph, ptr_ph->data->time_to_eat);
	if (ptr_ph->id % 2)
		pthread_mutex_unlock(&ptr_ph->data->forks[ptr_ph->l_fork]);
	else
		pthread_mutex_unlock(&ptr_ph->data->forks[ptr_ph->r_fork]);
	if (ptr_ph->id % 2)
		pthread_mutex_unlock(&ptr_ph->data->forks[ptr_ph->r_fork]);
	else
		pthread_mutex_unlock(&ptr_ph->data->forks[ptr_ph->l_fork]);
	write_status(ptr_ph, SLEEPING);
	ft_usleep(ptr_ph, ptr_ph->data->time_to_sleep);
	write_status(ptr_ph, THINKING);
}

int	is_full(t_philo *ptr_ph)
{
	int	i;

	i = 0;
	if (ptr_ph->data->number_of_eat == ptr_ph->number_of_eat)
	{
		pthread_mutex_lock(&ptr_ph->data->status);
		ptr_ph->data->alive = 0;
		pthread_mutex_unlock(&ptr_ph->data->status);
		return (0);
	}
	pthread_mutex_lock(&ptr_ph->data->meal_counter_mutex);
	ptr_ph->number_of_eat++;
	pthread_mutex_unlock(&ptr_ph->data->meal_counter_mutex);
	i++;
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*ptr_ph;

	ptr_ph = (t_philo *)arg;
	if (ptr_ph->id % 2)
		usleep(2000);
	while ((check_alive(ptr_ph)) == 1)
	{
		eating(ptr_ph);
	}
	return (NULL);
}

void	*routine_alone(void *arg)
{
	t_philo	*ptr_ph;

	ptr_ph = (t_philo *)arg;
	pthread_mutex_lock(&ptr_ph->data->forks[ptr_ph->l_fork]);
	write_status(ptr_ph, FORKING);
	usleep(ptr_ph->data->time_to_die * 1000);
	pthread_mutex_unlock(&ptr_ph->data->forks[ptr_ph->l_fork]);
	return (NULL);
}
