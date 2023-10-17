#include "philosophers.h"
#include <sys/time.h>

// struct timeval
// {
// 	time_t			tv_sec;
// 	__suseconds_t	tv_usec;
// };


int	get_time(t_data *ret)
{
	uint64_t		curr_time;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (0);
	return ((tv.tv_sec * 1000LL + tv.tv_usec / 1000));
}

void	test(t_data ret)
{
	struct	timeval	time;

	if (gettimeofday(&time, NULL) != 0)
        return ;
	printf("%ld second\n", time.tv_sec);
	printf("%ld microseconds\n", time.tv_usec);

	printf("%ld years passed since 1970\n", time.tv_sec / 60 / 60 / 24 / 365);
	get_time();
}