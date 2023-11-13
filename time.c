/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:25:49 by arnduran          #+#    #+#             */
/*   Updated: 2023/11/13 14:26:25 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <sys/time.h>

uint64_t	get_time(void)
{
	uint64_t		curr_time;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (0);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

uint64_t	find_time(t_philo *ptr_ph)
{
	uint64_t	now;

	now = get_time();
	return (now - ptr_ph->data->starting_time);
}

void	ft_usleep(t_philo *ptr_ph, long time)
{
	uint64_t	now;
	uint64_t	start;

	start = get_time();
	while (check_alive(ptr_ph) == 1)
	{
		now = get_time();
		if (now - start >= time)
			break ;
		usleep(200);
	}
}
