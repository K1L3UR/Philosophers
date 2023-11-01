/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:18:42 by arnduran          #+#    #+#             */
/*   Updated: 2023/11/01 18:15:44 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_error(int er)
{
	if (er == 1)
	{
		printf("Error Args\n");
		return (0);
	}
	return (0);
}

// int	exec(t_philo *ptr_ph)
// {
// 	int				i;
// 	pthread_t		rout;

// 	i = 0;
// 	ptr_ph = (t_philo *)malloc(sizeof(t_philo) * ptr_ph->data->nb_philo);
// 	pthread_create(&rout, NULL, (void*)create_thread, (void*)ptr_ph);
// 	while (i < ptr_ph->data->nb_philo)
// 	{
// 		pthread_join(&ptr_ph[i], NULL);	
// 		i++;
// 	}
// 	return (0);
// }

void	init_mutex(t_philo *ptr_ph)
{
	int	i;

	i = 0;
	printf("init mutex fork\n");
	while (i < ptr_ph->data->nb_philo)
	{
		pthread_mutex_init(&ptr_ph[i].l_fork, NULL);
		pthread_mutex_init(&ptr_ph[i].r_fork, NULL);
		// ptr_ph->is_full = 0;
		i++;
	}
}

void	eating(t_philo *ptr_ph)
{
	int	i;

	i = 0;
	while (i < 100)
	{	
		usleep(100);
		i++;
	}
	// ptr_ph->is_full++;
	// printf("%d\n", ptr_ph->is_full);
	printf("philo %d a manger \n", ptr_ph->id);
}

void	*routine(t_philo *ptr_ph)
{
	t_philo *philosopher = (t_philo *)ptr_ph;
	printf("Philosophe %d a commencé.\n", philosopher->id);
	pthread_mutex_lock(&ptr_ph->l_fork);
	pthread_mutex_lock(&ptr_ph->r_fork);
	eating(ptr_ph);
	pthread_mutex_unlock(&ptr_ph->l_fork);
	pthread_mutex_unlock(&ptr_ph->r_fork);
	printf("Philosophe %d a terminé.\n", philosopher->id);
	return NULL;
}