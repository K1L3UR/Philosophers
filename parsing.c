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
	if (ac == 5)
		(*ptr)->number_of_eat = ft_atoi(argv[5]);
	else
		(*ptr)->number_of_eat = -1;
	printf("%d \n %d \n %d \n %d \n %d \n", (*ptr)->nb_philo, (*ptr)->time_to_die, (*ptr)->time_to_eat,
		(*ptr)->time_to_sleep, (*ptr)->number_of_eat);
	(*ptr)->starting_time = get_time();	
	printf("init finit\n");
	printf("%p\n", *ptr);
	printf("---------\n");
	return (*ptr);
}

void	*func1(t_data *ptr)
{
	int		i = 0;

	//pthread_mutex_init(ptr->forks, NULL);
	//pthread_mutex_lock(ptr->forks);
	printf("FUNCTION 1 PTR->NB_EAT\n");
	printf("%d\n", ptr->number_of_eat); // bon // pas bon sur linux/dell
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
	printf("create thread des philos\n");
	while (i < ptr_ph->data->nb_philo)
	{
		if (ptr_ph->id % 2 == 0)
			usleep(2000);
		pthread_create(&ptr_ph[i].thread_id, NULL, routine, (void*)&ptr_ph[i]);
		ptr_ph[i].id = i + 1;
		usleep(1000); // obliger de wait sinon l'id s'incremente pas
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
	ret = (t_data **)malloc(sizeof(t_data *)); 
	*ret = NULL;
	if (check_argv(argc, argv) == 1)
		ft_error(1);
	*ret = init(&ptr, ac, argv);
	ptr_ph = (t_philo *)malloc(sizeof(t_philo) * (*ret)->nb_philo);
	ptr_ph->data = *ret;
	printf("%d \n %d \n %d \n %d \n %d \n %lu \n", ptr_ph->data->nb_philo, ptr_ph->data->time_to_die, ptr_ph->data->time_to_eat,
			ptr_ph->data->time_to_sleep, ptr_ph->data->number_of_eat, ptr_ph->data->starting_time);
	printf("--------\n");
	(*ret)->starting_time = get_time();
	usleep(10000);
	find_time(ptr_ph);
	printf("PARSING DONE\n");
	//// pthread_create(&t1, NULL, (void*)func1, (void*)*ret);
	//// pthread_create(&t2, NULL, func2, NULL);
	//// pthread_join(t1, NULL);
	//// pthread_join(t2, NULL);
	// test(ret);
	printf("nb Philo: %d\n", (*ret)->nb_philo);
	// ptr_ph = (t_philo *)malloc(sizeof(t_philo) * 1);
	// ptr_ph->data = *ret;
	// ptr_ph->l_fork = (pthread_mutex_t*)malloc((*ret)->nb_philo * sizeof(pthread_mutex_t));
	// printf("%p\n", ptr_ph->l_fork);
	// if (ptr_ph->l_fork == NULL);
	// 	exit(0);
	// if (ptr_ph->l_fork != NULL)
	// 	printf("alloced\n");
	init_mutex(ptr_ph);
	create_thread(ptr_ph);
	printf("ptr :  %d\n", ptr_ph->data->nb_philo); // il segfault
	while (i < (*ret)->nb_philo)
	{
		pthread_join(ptr_ph->thread_id, NULL);	
		i++;
	}
	return (0);
}
