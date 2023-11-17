/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:26:49 by arnduran          #+#    #+#             */
/*   Updated: 2023/11/17 18:45:04 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

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

void	init(t_data *info, int ac, char **argv)
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
	info->meal_counter = 0;
	info->alive = 1;
	info->forks = malloc(sizeof(pthread_mutex_t) * n_philo);
	info->starting_time = get_time();
}

void	create_thread(t_philo *ptr_ph)
{
	int	i;

	i = 0;
	while (i < ptr_ph->data->nb_philo)
	{
		pthread_create(&ptr_ph[i].thread_id, NULL, routine, (void *)&ptr_ph[i]);
		ptr_ph[i].last_meal = 0;
		i++;
	}
}

void	parsing(int argc, char **argv)
{
	int				i;
	t_data			ptr;
	t_philo			*ptr_ph;
	pthread_t		rout;

	i = 0;
	if (check_argv(argc, argv) == 1)
		ft_error(1);
	init(&ptr, (argc - 1), argv);
	ptr_ph = (t_philo *)malloc(sizeof(t_philo) * ptr.nb_philo);
	ptr_ph->data = &ptr;
	ptr.starting_time = get_time();
	if (ptr_ph->data->nb_philo == 1)
		special_case(ptr_ph, &ptr);
	// jai tj un probleme de maniere random de temps en temps
	// si jamais je ne return pas ici donc il va falloir verifier et return
	philo_init(ptr_ph, &ptr);
	// gerer ici le cas avec un seul philo
	init_mutex(ptr_ph, &ptr);
	create_thread(ptr_ph);
	check_dead(ptr_ph);
	usleep(2000);
	while (i < ptr_ph->data->nb_philo)
	{
		pthread_join(ptr_ph->thread_id, NULL);
		i++;
	}
}
