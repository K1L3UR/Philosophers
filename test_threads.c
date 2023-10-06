#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	*routine()
{
	printf("Test from threads\n");
	sleep(3);
	printf("ending thread\n");
}

int main(int argc, char **argv)
{
	pthread_t	t1;
	pthread_t	t2;
	if (pthread_create(&t1,NULL, &routine, NULL) != 0)
		return (1);
	if (pthread_create(&t2,NULL, &routine, NULL) != 0)
		return (1);
	if (pthread_join(t1, NULL) != 0)
		return (1);
	if (pthread_join(t2, NULL) != 0)
		return (1);

	return (0);
}