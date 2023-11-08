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

void	philo_init(t_philo *ptr_ph, t_data *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		ptr_ph[i].data = info;
		ptr_ph[i].id = i + 1;
		ptr_ph[i].number_of_eat = 0;
		if (i == info->nb_philo - 1)
			ptr_ph[i].r_fork = 0;
		else
			ptr_ph[i].r_fork = i + 1;
		ptr_ph[i].r_fork = i;
		i++;
	}
}

void	init(t_data *info, int ac, char **argv)
{
	int	i;
	int	n_philo;

	i = 0;
	n_philo = ft_atoi(argv[1]);
	info->nb_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (ac == 5)
		info->number_of_eat = ft_atoi(argv[5]);
	else
		info->number_of_eat = -1;
	// printf("%d \n %d \n %d \n %d \n %d \n", info->nb_philo, info->time_to_die, info->time_to_eat,
	// 	info->time_to_sleep, info->number_of_eat);
	info->alive = 1;
	info->forks = malloc(sizeof(pthread_mutex_t) * n_philo);
	info->starting_time = get_time();	
	printf("---------\n");
}

void	create_thread(t_philo *ptr_ph)
{
	int	i;

	i = 0;
	printf("create thread des philos\n");
	while (i < ptr_ph->data->nb_philo)
	{
		pthread_create(&ptr_ph[i].thread_id, NULL, routine, (void*)&ptr_ph[i]);
		// usleep(1000); // obliger de wait sinon l'id s'incremente pas
		i++;
	}
}

int	parsing(int argc, char **argv)
{
	int				i;
	int				ac;
	t_data			ptr;
	t_philo			*ptr_ph;
	// pthread_t		t1;
	// pthread_t		t2;
	pthread_t		rout;
	
	i = 1;
	ac = argc - 1;
	if (check_argv(argc, argv) == 1)
		ft_error(1);
	init(&ptr, ac, argv);
	ptr_ph = (t_philo *)malloc(sizeof(t_philo) * ptr.nb_philo);
	ptr_ph->data = &ptr;
	ptr.starting_time = get_time();
	//find_time(ptr_ph);
	philo_init(ptr_ph, &ptr);
	// ptr_ph = (t_philo *)malloc(sizeof(t_philo) * 1);
	// ptr_ph->data = *ret;
	// ptr_ph->l_fork = (pthread_mutex_t*)malloc((*ret)->nb_philo * sizeof(pthread_mutex_t));
	// printf("%p\n", ptr_ph->l_fork);
	init_mutex(ptr_ph, &ptr);
	create_thread(ptr_ph);
	while (i < ptr.nb_philo)
	{
		pthread_join(ptr_ph->thread_id, NULL);	
		i++;
	}
	return (0);
}
