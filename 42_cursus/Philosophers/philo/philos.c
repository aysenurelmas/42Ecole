#include "philo.h"

void	philo_eat(t_philo *pl)
{
	if (pl->data->all_ate_c != pl->data->n_of_philo)
		message(now_time(), "has taken a fork", pl);
	pthread_mutex_lock(pl->left);
	if (pl->data->all_ate_c != pl->data->n_of_philo)
		message(now_time(), "has taken a fork", pl);
	pthread_mutex_lock(pl->right);
	if (is_died(pl->data))
	{
		pthread_mutex_lock(&pl->data->finish_mutex);
		message(now_time(), "is eating", pl);
		pl->eat_c++;
		pl->last_eat = now_time();
		pthread_mutex_unlock(&pl->data->finish_mutex);
		go_to_sleep(pl->data->t_to_eat);
	}
	is_died(pl->data);
	pthread_mutex_unlock(pl->left);
	pthread_mutex_unlock(pl->right);
}

void	philo_sleep(t_philo *pl)
{
	message(now_time(), "is sleeping", pl);
	go_to_sleep(pl->data->t_to_sleep);
}

void	philo_think(t_philo *pl)
{
	message(now_time(), "is thinking", pl);
}

void	*life_cycle(void *arg)
{
	t_philo	*pl;

	pl = arg;
	if (pl->id % 2 == 0)
		go_to_sleep(pl->data->t_to_eat);
	if (pl->data->n_of_philo == 1)
	{	
		one_philo(pl);
	}
	else
	{
		while (check_finish(pl) && is_died(pl->data))
		{
			philo_eat(pl);
			if (check_finish(pl) && is_died(pl->data))
				philo_sleep(pl);
			if (check_finish(pl) && is_died(pl->data))
				philo_think(pl);
		}
	}
	return (NULL);
}

void	create_philos(t_data *data)
{
	int	i;

	i = 0;
	data->thread = malloc(sizeof(pthread_t) * data->n_of_philo);
	while (i < data->n_of_philo)
	{
		data->philos[i].start_time = now_time();
		pthread_create(&data->thread[i], NULL, &life_cycle, &data->philos[i]);
		i++;
	}
	i = 0;
	while (data->died_check == 0)
	{
		is_died(data);
		if (data->died_check == 1)
			return ;
		else if (data->all_ate_c == data->n_of_philo)
			break ;
	}
	while (i < data->n_of_philo)
	{
		pthread_join(data->thread[i], NULL);
		i++;
	}
}
