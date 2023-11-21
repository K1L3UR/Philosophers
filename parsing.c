/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:26:49 by arnduran          #+#    #+#             */
/*   Updated: 2023/11/20 19:19:02 by arnduran         ###   ########.fr       */
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

void	philo_init(t_philo *ptr_ph, t_data *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		ptr_ph[i].data = info;
		ptr_ph[i].id = i + 1;
		ptr_ph[i].number_of_eat = 0;
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
	info->nb_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (ac == 5)
		info->number_of_eat = ft_atoi(argv[5]);
	else
		info->number_of_eat = -1;
	if (errno == ERANGE)
	{
		printf("Error ERANGE\n");
		return (-1);
	}
	info->meal_counter = 0;
	info->alive = 1;
	if (n_philo > 200 || n_philo < 0)
		return (-1);
	if (info->time_to_eat < 60 || info->time_to_sleep < 60)
		return (-1);
	info->forks = malloc(sizeof(pthread_mutex_t) * n_philo);
	info->starting_time = get_time();
	info->finish = 1;
	return (0);
}

void	create_thread(t_philo *ptr_ph)
{
	int	i;

	i = 0;
	while (i < ptr_ph->data->nb_philo)
	{
		pthread_create(&ptr_ph[i].thread_id, NULL, routine, (void *)&ptr_ph[i]);
		pthread_mutex_lock(&ptr_ph->data->meal);		
		ptr_ph[i].last_meal = 0;
		pthread_mutex_unlock(&ptr_ph->data->meal);		
		i++;
	}
	// if (ptr_ph->data->finish == 0)
	// 	return ;
}

void free_data(t_data *info)
{
	free(info);
}

void free_philo(t_philo *ptr_ph)
{
	int i;

	i = 0;
	while (i < ptr_ph->data->nb_philo)
	{
		if (ptr_ph[i].data != NULL)
		{
			// printf("Freeing ptr_ph[%d].data\n", i);
			free(ptr_ph[i].data);
		}
	i++;
	}
	// printf("Freeing ptr_ph\n");
	free(ptr_ph);
}

void	parsing(int argc, char **argv)
{
	int				i;
	t_data			ptr;
	t_philo			*ptr_ph;
	pthread_t		rout;
	int				ret;

	i = 0;
	if (check_argv(argc, argv) == 1)
	{
		printf("Error Arguments\n");
		return ;
	}
	ret = init(&ptr, (argc - 1), argv);
	if (ret == -1)
		return ;
	ptr_ph = (t_philo *)malloc(sizeof(t_philo) * ptr.nb_philo);
	ptr_ph->data = &ptr;
	ptr.starting_time = get_time();
	// if (ptr_ph->data->nb_philo == 1)
	// {
	// 	special_case(ptr_ph, &ptr);
	// 	free(ptr.forks);
	// 	free(ptr_ph);
	// 	return ;
	// }
	philo_init(ptr_ph, &ptr);
	// gerer ici le cas avec un seul philo
	init_mutex(ptr_ph, &ptr);
	if (ptr_ph->data->nb_philo == 1)
		pthread_create(&ptr_ph[i].thread_id, NULL, routine_alone, (void *)&ptr_ph[i]);		
	else
		create_thread(ptr_ph);
	check_dead(ptr_ph);
	usleep(2000);
	while (i < ptr_ph->data->nb_philo)
	{
		pthread_join(ptr_ph[i].thread_id, NULL);
		i++;
	}
	// unlock_mutex(ptr_ph);
	destroy_mutex(&ptr);
	free(ptr.forks);
	free(ptr_ph);
}
