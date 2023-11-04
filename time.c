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

void	find_time(t_philo *ptr_ph)
{
	uint64_t	now;

	now = get_time();
	printf("%d\n", now - ptr_ph->data->starting_time);
}

// void	test(t_data **ret)
// {
// 	// struct		timeval	time;
// 	uint64_t	curr_time;

// 	// if (gettimeofday(&time, NULL) != 0)
//     //     return ;
// 	(*ret)->starting_time = get_time();
// 	curr_time = get_time();
// 	while (get_time() < (*ret)->starting_time + 2000)
// 	{
// 		usleep(100 * 1000);
// 		curr_time = get_time();
// 		printf("Time in ms = %ld. Time since start = %ld\n",
// 						curr_time, curr_time - (*ret)->starting_time);
// 	}
// }