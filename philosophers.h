/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:13:14 by arnduran          #+#    #+#             */
/*   Updated: 2023/11/08 18:47:43 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if	!defined(PHILOSOPHERS_H)

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <time.h>
# include "libft/libft.h"
# include <sys/time.h>
# include <stdint.h>

# define FORKING 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3

typedef	struct	s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_eat;
	int				alive;
	uint64_t		starting_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	status;
}				t_data;

typedef	struct	s_philo
{
	t_data			*data;
	int				number_of_eat; // optional
	int				id;
	int				r_fork;
	int				l_fork;
	pthread_t		thread_id;

}				t_philo;


int			parsing(int argc, char **argv);
int			check_argv(int argc, char **argv);
void		init(t_data *info, int ac, char **argv);
void		*routine(void *arg);
int			ft_error(int er);
uint64_t	get_time();
void		create_thread(t_philo *ptr_ph);
void		init_mutex(t_philo *ptr_ph, t_data *info);
uint64_t	find_time(t_philo *ptr_ph);
void		ft_usleep(t_philo *ptr_ph, long	time);

# endif
