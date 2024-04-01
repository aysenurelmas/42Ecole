#include "philo.h"

int	check(t_data *data, int i)
{
	pthread_mutex_lock(&data->finish_mutex);
	if (data->philos[i].last_eat != 0
		&& data->t_to_die < (int)(now_time() - data->philos[i].last_eat))
	{
		pthread_mutex_unlock(&data->finish_mutex);
		return (1);
	}
	else if (data->n_of_philo_must_eat != 0)
	{
		if (data->philos[i].eat_c == data->n_of_philo_must_eat)
		{
			data->all_ate_c++;
			data->philos[i].eat_c = 0;
			pthread_mutex_unlock(&data->finish_mutex);
			return (3);
		}
	}
	pthread_mutex_unlock(&data->finish_mutex);
	return (0);
}

int	is_died(t_data *data)
{
	int	i;

	i = 0;
	if (data->all_ate_c == data->n_of_philo)
		return (0);
	while (i < data->n_of_philo)
	{
		if (check(data, i) == 1)
		{
			if (data->philos->die == 0)
			{
				pthread_mutex_lock(data->philos[i].left);
				message(now_time(), "died", &data->philos[i]);
				data->died_check = 1;
				data->philos->die = 1;
				pthread_mutex_unlock(data->philos[i].left);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	check_finish(t_philo *pl)
{
	if (pl->data->died_check == 1)
	{
		return (0);
	}
	else if (pl->data->all_ate_c == pl->data->n_of_philo)
	{
		return (0);
	}
	return (1);
}

void	one_philo(t_philo *pl)
{
	pthread_mutex_lock(pl->left);
	message(now_time(), "has taken a fork", pl);
	go_to_sleep(pl->data->t_to_die);
	message(now_time(), "died", pl);
	pl->data->died_check = 1;
	pl->die = 1;
	pthread_mutex_unlock(pl->left);
	return ;
}
