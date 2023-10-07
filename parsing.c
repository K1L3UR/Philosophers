#include "philosophers.h"

int	check_argv(int argc, char **argv)
{
	int	i;
	int	j;
	
	i = 1;
	j = 0;
	while (i < argc - 1)
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

int	init(t_philos *ptr, int ac, char **argv)
{
	int	i;
	int	n_philo;

	i = 0;
	n_philo = ft_atoi(argv[1]);
	ptr = ft_calloc(0, n_philo);
	while (i < n_philo)
	{
		ptr[i].nb_philo = ft_atoi(argv[1]);
		ptr[i].time_to_die = ft_atoi(argv[2]);
		ptr[i].time_to_eat = ft_atoi(argv[3]);
		ptr[i].time_to_sleep = ft_atoi(argv[4]);
		ptr[i].number_of_eat = ft_atoi(argv[5]);
		printf("%d \n %d \n %d \n %d \n %d \n", ptr[i].nb_philo, ptr[i].time_to_die, ptr[i].time_to_eat,
			ptr[i].time_to_sleep, ptr[i].number_of_eat);
		i++;
	}
	return (0);
}

int	parsing(int argc, char **argv)
{
	int				i;
	int				ac;
	t_philos		*ptr;
	pthread_t		t1;
	void			*ret;

	
	// if (pthread_create(&t1,NULL, &routine, NULL) != 0)
	// 	return (1);
		// if  (pthread_join(t1, ret) != 0) // bloque en attendant qu'un autre thread se finisse
		// 	ft_error(1);
	i = 1;
	ac = argc - 1;
	if (check_argv(argc, argv) == 1)
		ft_error(1);
	init(ptr, ac, argv);
	return (0);
}