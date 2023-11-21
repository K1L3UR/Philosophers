#include <stdio.h>
#include <pthread.h>

#define NC	"\e[0m"
#define YELLOW	"\e[33m"
#define BYELLOW	"\e[1;33m"
#define RED	"\e[31m"
#define GREEN	"\e[32m"

// The first thread invokes this routine:
void	*thread_1_routine(void *data)
{

	pthread_t tid = pthread_self();
	printf("%sThread [%ld]: wants lock 1%s\n", YELLOW, tid, NC);
}

int	main(void)
{
	pthread_t	tid1;	// ID of the first thread
	pthread_create(&tid1, NULL, thread_1_routine, NULL);
	pthread_join(tid1, NULL);
	return (0);
}