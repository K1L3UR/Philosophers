/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:18:42 by arnduran          #+#    #+#             */
/*   Updated: 2023/11/13 14:37:15 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdio.h>

int	ft_error(int er)
{
	if (er == 1)
	{
		printf("Error Args\n");
	}
	return (0);
}

void	init_mutex(t_philo *ptr_ph, t_data *info)
{
	int	i;

	i = 0;
	pthread_mutex_init(&info->status, NULL);
	pthread_mutex_init(&info->meal, NULL);
	pthread_mutex_init(&info->writing, NULL);
	while (i < info->nb_philo)
	{
		pthread_mutex_init(&info->forks[i], NULL);
		i++;
	}
	return ;
}

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
	ptr_ph->last_meal = find_time(ptr_ph);
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
	usleep(1000);
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
