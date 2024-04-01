#include "philo.h"

void	free_func(t_data data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data.finish_mutex);
	while (i < data.n_of_philo)
	{
		pthread_mutex_destroy(&data.forks[i]);
		pthread_detach(*data.thread);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(data));
	if (argc != 5 && argc != 6)
		return (write(2, "Error : Wrong argument!!!\n", 26));
	if (init(&data, argc, argv))
		return (1);
	create_philos(&data);
	free_func(data);
	return (0);
}
