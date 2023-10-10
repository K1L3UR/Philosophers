/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:13:14 by arnduran          #+#    #+#             */
/*   Updated: 2023/10/10 22:29:42 by arnduran         ###   ########.fr       */
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

typedef	struct	s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_eat;
	pthread_mutex_t	*forks;
}				t_data;

typedef	struct	s_philo
{
	t_data			*data;
	int				number_of_eat; // optional
	int				id;
}				t_philo;


int		parsing(int argc, char **argv);
int		check_argv(int argc, char **argv);
int		init(t_data	*ptr, int ac, char **argv);
void	*routine();
int		ft_error(int er);

# endif
