#include "philosophers.h"
#include <sys/time.h>

// struct timeval
// {
// 	time_t			tv_sec;
// 	__suseconds_t	tv_usec;
// };


uint64_t	get_time()
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

void	ft_usleep(t_philo *ptr_ph, long	time)
{
	long	now;
	
	now = 0;
	while (ptr_ph->data->alive == 1)
	{
		if (now >= (time * 1000))
			break ;
		usleep(200);
		now += 200;
	}
}