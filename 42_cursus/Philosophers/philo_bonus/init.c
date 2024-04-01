/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebattal <ebattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:28:16 by ebattal           #+#    #+#             */
/*   Updated: 2022/10/28 15:45:23 by ebattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		write(2, "Error : wrong argument\n", 22);
		return (1);
	}
	return (0);
}

int	check_data(t_data *data, int argc)
{
	if (argc == 6 && (data->n_of_philo_must_eat <= 0))
		return (write(2, "Error: wrong num of must eat\n", 29));
	if (data->n_of_philo <= 0)
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

	i = 0;
	sem_unlink("./forks");
	sem_unlink("./finish");
	sem_unlink("./aten");
	data->forks = sem_open("./forks", O_CREAT, S_IRWXU, data->n_of_philo);
	data->finish = sem_open("./finish", O_CREAT, S_IRWXU, 1);
	data->aten = sem_open("./aten", O_CREAT, S_IRWXU, 1);
	data->philo = malloc(sizeof(t_philo) * data->n_of_philo);
	if (!data->philo)
		return (write(2, "Error: malloc failed\n", 21));
	while (i < data->n_of_philo)
	{
		data->philo[i].data = data;
		data->philo[i].id = i + 1;
		data->philo[i].eat_c = 0;
		data->philo[i].last_eat = 0;
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
