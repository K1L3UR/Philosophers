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

int	parsing(int argc, char **argv)
{
	int	i;
	int	ac;

	i = 1;
	ac = argc - 1;
	if (check_argv(argc, argv) == 1)
	{
		printf("Error Args\n");
		return (0);
	}
	return (0);
}