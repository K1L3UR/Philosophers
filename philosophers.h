/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:13:14 by arnduran          #+#    #+#             */
/*   Updated: 2023/11/02 19:02:00 by arnduran         ###   ########.fr       */
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


typedef	struct	s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_eat;
	uint64_t		starting_time;
	// pthread_mutex_t	*forks; // ca segfault
}				t_data;

typedef	struct	s_philo
{
	t_data			*data;
	int				number_of_eat; // optional
	int				id;
	int				is_full;
	// pthread_mutex_t	forks[2]; // ca segfault
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
	pthread_t		thread_id;

}				t_philo;


int			parsing(int argc, char **argv);
int			check_argv(int argc, char **argv);
t_data		*init(t_data **ptr, int ac, char **argv);
void		*routine(t_philo *ptr_ph);
int			ft_error(int er);
void		test(t_data **ret);
uint64_t	get_time();
void		*create_thread(t_philo *ptr_ph);
//int			exec(t_philo *ptr_ph);
void		init_mutex(t_philo *ptr_ph);

# endif
