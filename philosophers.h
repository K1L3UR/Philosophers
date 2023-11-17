/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:13:14 by arnduran          #+#    #+#             */
/*   Updated: 2023/11/17 18:23:00 by arnduran         ###   ########.fr       */
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

# define FORKING 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DEADING 4

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
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
	int				number_of_eat; // variable pour gere le nombre de repas a effectuer, je dois m'en occuper
	int				last_meal;
	int				id;
	int				r_fork;
	int				l_fork;
	pthread_t		thread_id;

}				t_philo;

void		parsing(int argc, char **argv);
int			check_argv(int argc, char **argv);
void		init(t_data *info, int ac, char **argv);
void		*routine(void *arg);
int			ft_error(int er);
uint64_t	get_time(void);
void		create_thread(t_philo *ptr_ph);
void		init_mutex(t_philo *ptr_ph, t_data *info);
uint64_t	find_time(t_philo *ptr_ph);
void		ft_usleep(t_philo *ptr_ph, long time);
int			check_alive(t_philo *ptr_ph);
void		write_status(t_philo *ptr_ph, int status);
void		check_dead(t_philo *ptr_ph);
int			special_case(t_philo *ptr_ph, t_data *info);

#endif
