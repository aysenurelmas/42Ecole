/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebattal <ebattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:21:45 by ebattal           #+#    #+#             */
/*   Updated: 2022/10/28 15:12:04 by ebattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_eat(t_philo *pl)
{
	sem_wait(pl->data->forks);
	message(now_time(), "has taken a fork", pl);
	sem_wait(pl->data->forks);
	message(now_time(), "has taken a fork", pl);
	message(now_time(), "is eating", pl);
	sem_wait(pl->data->aten);
	pl->eat_c++;
	pl->last_eat = now_time();
	sem_post(pl->data->aten);
	philo_aten(pl->data, pl);
	go_to_sleep(pl->data->t_to_eat);
	sem_post(pl->data->forks);
	sem_post(pl->data->forks);
}

void	one_philo(t_philo *pl)
{
	sem_wait(pl->data->forks);
	message(now_time(), "has taken a fork", pl);
	go_to_sleep(pl->data->t_to_die);
	message(now_time(), "died", pl);
	exit(0);
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

void	life_cycle(void *arg)
{
	t_philo	*pl;

	pl = arg;
	if (pl->id % 2 == 0)
		go_to_sleep(pl->data->t_to_eat);
	if (pl->data->n_of_philo == 1)
		one_philo(pl);
	while (1)
	{
		if (pl->data->all_eat != 1)
			philo_eat(pl);
		if (pl->data->all_eat != 1)
			philo_sleep(pl);
		if (pl->data->all_eat != 1)
			philo_think(pl);
	}
}
