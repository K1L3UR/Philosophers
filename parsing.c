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

 
t_data	*init(t_data **ptr, int ac, char **argv)
{
	int	i;
	int	n_philo;

	i = 0;
	n_philo = ft_atoi(argv[1]);
	*ptr = (t_data*)ft_calloc(1, sizeof(t_data));
	(*ptr)->nb_philo = ft_atoi(argv[1]);
	(*ptr)->time_to_die = ft_atoi(argv[2]);
	(*ptr)->time_to_eat = ft_atoi(argv[3]);
	(*ptr)->time_to_sleep = ft_atoi(argv[4]);
	(*ptr)->number_of_eat = -1;
	if (ac == 5)
		(*ptr)->number_of_eat = ft_atoi(argv[5]);
	printf("%d \n %d \n %d \n %d \n %d \n", (*ptr)->nb_philo, (*ptr)->time_to_die, (*ptr)->time_to_eat,
		(*ptr)->time_to_sleep, (*ptr)->number_of_eat);
	(*ptr)->starting_time = 0;	
	(*ptr)->starting_time = get_time();	
	printf("allouer\n");
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
	printf("%d\n", ptr->number_of_eat); // bon
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

void	*create_thread(t_philo *ptr_ph)
{
	int	i;

	i = 0;
	// printf("%d\n", ptr_ph->data->nb_philo);
	printf("create thread des philos\n");
	while (i <= ptr_ph->data->nb_philo)
	{
		pthread_create(&ptr_ph[i].thread_id, NULL, routine, (void*)&ptr_ph[i]); // je segfault si je le use
		ptr_ph[i].id = i + 1;
		printf("%d\n", ptr_ph[i].id);
		i++;
	}
	pthread_exit(0);
}

int	parsing(int argc, char **argv)
{
	int				i;
	int				ac;
	t_data			*ptr;
	t_data			**ret;
	t_philo			*ptr_ph;
	pthread_t		t1;
	pthread_t		t2;
	pthread_t		rout;
	
	i = 1;
	ac = argc - 1;
	if (check_argv(argc, argv) == 1)
		ft_error(1);
	*ret = init(&ptr, ac, argv);
	(*ret)->starting_time = get_time();
	printf("%llu\n", (*ret)->starting_time);
	printf("PARSING DONE\n");
	pthread_create(&t1, NULL, (void*)func1, (void*)ret);
	pthread_create(&t2, NULL, func2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	test(ret);
	printf("nb Philo: %d\n", (*ret)->nb_philo);
	ptr_ph->data = *ret;
	// exec(ptr_ph);
	// ptr_ph = (t_philo *)malloc(sizeof(t_philo) * (*ret)->nb_philo);
	printf("ptr :  %d\n", ptr_ph->data->nb_philo); // il segfault
	pthread_create(&rout, NULL, (void*)create_thread, (void*)ptr_ph);
	sleep(1);
	while (i < (*ret)->nb_philo)
	{
		pthread_join(ptr_ph->thread_id, NULL);	
		i++;
	}
	return (0);
}
