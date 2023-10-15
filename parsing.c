#include "philosophers.h"

int	check_argv(int argc, char **argv)
{
	int	i;
	int	j;
	
	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

 
t_data	init(t_data *ptr, int ac, char **argv)
{
	int	i;
	int	n_philo;

	i = 0;
	n_philo = ft_atoi(argv[1]);
	ptr = ft_calloc(1, sizeof(t_data));
	ptr->nb_philo = ft_atoi(argv[1]);
	ptr->time_to_die = ft_atoi(argv[2]);
	ptr->time_to_eat = ft_atoi(argv[3]);
	ptr->time_to_sleep = ft_atoi(argv[4]);
	ptr->number_of_eat = ft_atoi(argv[5]); // je segfault si il existe pas
	printf("%d \n %d \n %d \n %d \n %d \n", ptr->nb_philo, ptr->time_to_die, ptr->time_to_eat,
		ptr->time_to_sleep, ptr->number_of_eat);
	return (*ptr);
}

// void	*func1(t_data *ptr) celle ci marche
// {
// 	int		i = 0;

// 	// pthread_mutex_init(&ptr.l_fork, NULL);
// 	// pthread_mutex_lock(&ptr.l_fork);
// 	printf("FUNCTION 1 PTR->NB_EAT\n");
// 	printf("%d\n", ptr->number_of_eat);
// 	sleep(3);
// 	while (i < 100)
// 	{
// 		printf("%s\n", "Hello\n");
// 		i++;
// 	}
// 	// pthread_mutex_unlock(&ptr.l_fork);
// 	// pthread_mutex_destroy(&ptr.l_fork);
// 	return (NULL);
// }

void	*func1(t_data *ptr)
{
	int		i = 0;

	//pthread_mutex_init(ptr->forks, NULL);
	//pthread_mutex_lock(ptr->forks);
	printf("FUNCTION 1 PTR->NB_EAT\n");
	printf("%d\n", ptr->number_of_eat);
	sleep(3);
	while (i < 100)
	{
		printf("%s\n", "Hello\n");
		i++;
	}
	//pthread_mutex_unlock(ptr->forks);
	//pthread_mutex_destroy(ptr->forks);
	return (NULL);
}

void	*func2()
{
	int	i = 0;
	t_philo	*ptr;

	while (i < 100)
	{
		printf("\t\t%s\n", "World\n");
		i++;
	}
	pthread_exit(0);
}

int	parsing(int argc, char **argv)
{
	int				i;
	int				ac;
	t_data			*ptr;
	t_data			*ret;
	pthread_t		t1;
	pthread_t		t2;
	// if (pthread_create(&t1,NULL, &routine, NULL) != 0)
	// 	return (1);
		// if  (pthread_join(t1, ret) != 0) // bloque en attendant qu'un autre thread se finisse
		// 	ft_error(1);
	i = 1;
	ac = argc - 1;
	if (check_argv(argc, argv) == 1)
		ft_error(1);
	*ret = init(ptr, ac, argv);
	printf("PARSING DONE\n");

	pthread_create(&t1, NULL, (void*)func1, (void*)ret);
	pthread_create(&t2, NULL, func2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}
