#include "philosophers.h"
#include <sys/time.h>

// struct timeval
// {
// 	time_t			tv_sec;
// 	__suseconds_t	tv_usec;
// };


void	test()
{
	struct	timeval	time;

	// gettimeofday(&time, NULL);
	// 	return ;
	printf("%ld second\n", time.tv_sec);
	printf("%ld microseconds\n", time.tv_usec);

	printf("%ld years passed since 1970\n", time.tv_sec / 60 / 60 / 24 / 365);
}