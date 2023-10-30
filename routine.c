/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:18:42 by arnduran          #+#    #+#             */
/*   Updated: 2023/10/08 17:19:53 by arnduran         ###   ########.fr       */
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

int	exec(t_philo *ptr_ph)
{
	int				i;
	pthread_t		rout;

	i = 0;
	ptr_ph = (t_philo *)malloc(sizeof(t_philo) * ptr_ph->data->nb_philo);
	pthread_create(&rout, NULL, (void*)create_thread, (void*)ptr_ph);
	while (i < ptr_ph->data->nb_philo)
	{
		pthread_join(&ptr_ph[i], NULL);	
		i++;
	}
	return (0);
}

void	*routine(t_philo *ptr_ph)
{
	t_philo *philosopher = (t_philo *)ptr_ph;
    // printf("Philosophe %d a commencé.\n", ptr_ph->id);
    printf("Philosophe %d a commencé.\n", philosopher->id);
	printf("Philosophe %d a terminé.\n", philosopher->id);
	// printf("Philosophe %d a terminé.\n", ptr_ph->id);
    return NULL;
}