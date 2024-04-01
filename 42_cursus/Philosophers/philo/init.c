#include "philo.h"

int	parsing_arg(t_data *data, int argc, char **argv)
{
	int	c;

	c = is_digit(argc, argv);
	if (c == 0)
	{
		data->n_of_philo = ft_atoi(argv[1]);
		data->t_to_die = ft_atoi(argv[2]);
		data->t_to_eat = ft_atoi(argv[3]);
		data->t_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			data->n_of_philo_must_eat = ft_atoi(argv[5]);
	}
	else
	{
		write(2, "Error: wrong argument\n", 22);
		return (1);
	}
	return (0);
}

int	check_data(t_data *data, int argc)
{
	if (argc == 6 && (data->n_of_philo_must_eat <= 0))
		return (write(2, "Error: wrong num of must eat\n", 29));
	if (data->n_of_philo < 0)
		return (write(2, "Error: wrong num of philo\n", 29));
	if (data->t_to_die < 0)
		return (write(2, "Error: wrong time to die\n", 29));
	if (data->t_to_eat < 0)
		return (write(2, "Error: wrong time to eat\n", 29));
	if (data->t_to_sleep < 0)
		return (write(2, "Error: wrong time to sleep\n", 29));
	return (0);
}

int	init_philos(t_data *data)
{
	int	i;

	pthread_mutex_init(&data->finish_mutex, NULL);
	data->philos = malloc(sizeof(t_philo) * data->n_of_philo);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_of_philo);
	if (!data->philos || !data->forks)
		return (write(2, "Error: malloc failed\n", 21));
	i = 0;
	while (i < data->n_of_philo)
	{
		data->philos[i].id = i + 1;
		pthread_mutex_init(&data->forks[i], NULL);
		data->philos[i].left = &data->forks[i];
		if (i == 0)
			data->philos[i].right = &data->forks[data->n_of_philo - 1];
		else
			data->philos[i].right = &data->forks[i - 1];
		data->philos[i].data = data;
		i++;
	}
	return (0);
}

int	init(t_data *data, int argc, char **argv)
{
	if (parsing_arg(data, argc, argv))
		return (1);
	if (check_data(data, argc))
		return (1);
	if (init_philos(data))
		return (1);
	return (0);
}
