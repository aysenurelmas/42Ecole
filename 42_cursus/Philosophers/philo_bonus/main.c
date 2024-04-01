/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebattal <ebattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:29:46 by ebattal           #+#    #+#             */
/*   Updated: 2022/10/28 16:10:04 by ebattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	philo_fork(t_data *data)
{
	int		i;
	int		d;

	i = 0;
	data->thread = malloc(sizeof(pthread_t) * data->n_of_philo);
	while (i < data->n_of_philo)
	{
		data->philo[i].data->start_time = now_time();
		data->philo[i].pid = fork();
		if (data->philo[i].pid < 0)
			return (write(2, "Error: fork failed\n", 19));
		if (data->philo[i].pid == 0)
		{
			pthread_create(&data->thread, NULL, &check_cycle,
				&data->philo[i]);
			life_cycle(&data->philo[i]);
			return (1);
		}
		i++;
	}
	pthread_join(data->thread, NULL);
	waitpid(-1, &d, 0);
	return (0);
}

void	*check_cycle(void *arg)
{
	t_philo	*pl;

	pl = arg;
	while (1)
	{
		dead_finish(pl->data, pl);
	}
}

void	kill_fork(t_data *data)
{
	int	i;

	i = 0;
	sem_unlink("./forks");
	sem_unlink("./finish");
	sem_unlink("./aten");
	while (i < data->n_of_philo)
	{
		kill(data->philo[i].pid, SIGTERM);
		i++;
	}
	pthread_detach(data->thread);
}

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(data));
	if (argc != 5 && argc != 6)
		return (write(2, "Error : Wrong argument!!!\n", 26));
	if (init(&data, argc, argv))
		return (1);
	philo_fork(&data);
	kill_fork(&data);
	return (0);
}
