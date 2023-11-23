/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:13:14 by arnduran          #+#    #+#             */
/*   Updated: 2023/11/23 14:46:14 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <sys/time.h>
# include <stdint.h>
# include <errno.h>

# define FORKING 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DEADING 4

typedef struct s_data
{
	int				nb_philo;
	uint64_t		time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_eat;
	int				alive;
	int				meal_counter;
	uint64_t		starting_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writing;
	pthread_mutex_t	status;
	pthread_mutex_t	meal;
	pthread_mutex_t	meal_counter_mutex;
}				t_data;

typedef struct s_philo
{
	t_data			*data;
	int				number_of_eat;
	int				last_meal;
	int				id;
	int				r_fork;
	int				l_fork;
	pthread_t		thread_id;

}				t_philo;

void		parsing(int argc, char **argv);
int			check_argv(int argc, char **argv);
int			init(t_data *info, int ac, char **argv);
void		philo_init(t_philo *ptr_ph, t_data *info);
void		*routine(void *arg);
uint64_t	get_time(void);
void		create_thread(t_philo *ptr_ph);
void		init_mutex(t_data *info);
uint64_t	find_time(t_philo *ptr_ph);
void		ft_usleep(t_philo *ptr_ph, long time);
int			check_alive(t_philo *ptr_ph);
void		write_status(t_philo *ptr_ph, int status);
void		check_dead(t_philo *ptr_ph);
int			special_case(t_philo *ptr_ph, t_data *info);
void		destroy_mutex(t_data *info, t_philo *ptr_ph);
void		unlock_mutex(t_philo *ptr_ph);
int			is_full(t_philo *ptr_ph);
void		*routine_alone(void *arg);
void		lock_meal_unlock_meal(t_philo *ptr_ph);
int			check_alive(t_philo *ptr_ph);
void		do_init_philo_then_mutex(t_philo *ptr_ph, t_data *info);

#endif
