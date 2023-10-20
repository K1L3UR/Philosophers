// #include "philosophers.h"
#include <sys/time.h>
#include <time.h>
#include <stdint.h>
#include <unistd.h>

// struct timeval
// {
// 	time_t			tv_sec;
// 	__suseconds_t	tv_usec;
// };


// void	test()
// {
// 	struct	timeval	time;

// 	// if (gettimeofday(&time, NULL) != 0);
// 	// 	return ;
// 	printf("%ld second\n", time.tv_sec);
// 	printf("%ld microseconds\n", time.tv_usec);

// 	printf("%ld years passed since 1970\n", time.tv_sec / 60 / 60 / 24 / 365);
// }

// int main()
// {
//     test();
//     return (0);
// }

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void test() {
    struct timeval time;

    if (gettimeofday(&time, NULL) != 0) {
        perror("gettimeofday");
        return;
    }

    printf("%ld seconds\n", time.tv_sec);
    printf("%ld microseconds\n", time.tv_usec);

    time_t years_passed = time.tv_sec / (60 * 60 * 24 * 365);
    printf("%ld years passed since 1970\n", years_passed);
}

uint64_t  get_time()
{
    struct  timeval tv;

    if (gettimeofday(&tv, NULL) != 0)
        return (0);
    // return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
    return ((tv.tv_sec * 1000LL + tv.tv_usec / 1000));
}

void    example2()
{
    uint64_t    start_time;
    uint64_t    curr_time;
    uint64_t    res = 0;

    start_time = get_time();
    // sleep(2);
    usleep(2000);
    usleep(2000);
    usleep(2000);
    curr_time = get_time();
    res = curr_time - start_time;
    printf("%ld milliseconds passed since the start\n", res);
}

int main()
{
    test();
    example2();
    return 0;
}