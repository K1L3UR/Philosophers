/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:26:49 by arnduran          #+#    #+#             */
/*   Updated: 2023/11/23 15:15:41 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <errno.h>

int	check_argv(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	create_thread(t_philo *ptr_ph)
{
	int	i;

	i = 0;
	while (i < ptr_ph->data->nb_philo)
	{
		pthread_create(&ptr_ph[i].thread_id, NULL, routine, (void *)&ptr_ph[i]);
		i++;
	}
}

void	free_philo(t_philo *ptr_ph)
{
	int	i;

	i = 0;
	while (i < ptr_ph->data->nb_philo)
	{
		if (ptr_ph[i].data != NULL)
		{
			free(ptr_ph[i].data);
		}
	i++;
	}
	free(ptr_ph);
}

void	parsing(int argc, char **argv)
{
	int				i;
	t_data			ptr;
	t_philo			*ptr_ph;

	i = 0;
	if (check_argv(argc, argv) == 1)
		return ((void)(printf("Error Arguments\n")));
	if (init(&ptr, (argc - 1), argv) == -1)
		return ((void)(printf("Error Arguments\n")));
	ptr_ph = (t_philo *)malloc(sizeof(t_philo) * ptr.nb_philo);
	if (ptr_ph == NULL)
		return ;
	ptr_ph->data = &ptr;
	ptr.starting_time = get_time();
	do_init_philo_then_mutex(ptr_ph, &ptr);
	if (ptr_ph->data->nb_philo == 1)
		pthread_create(&ptr_ph[i].thread_id, NULL, routine_alone,
			(void *)&ptr_ph[i]);
	else
		create_thread(ptr_ph);
	check_dead(ptr_ph);
	while (i < ptr_ph->data->nb_philo)
		pthread_join(ptr_ph[i++].thread_id, NULL);
	destroy_mutex(&ptr, ptr_ph);
}
