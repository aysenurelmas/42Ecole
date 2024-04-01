/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebattal <ebattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:02:30 by ebattal           #+#    #+#             */
/*   Updated: 2022/10/28 15:55:42 by ebattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	dead_finish(t_data *data, t_philo *pl)
{
	sem_wait(data->finish);
	if (pl->last_eat != 0
		&& ((data->t_to_die) < (int)((now_time() - pl->last_eat))))
	{
		if (pl->data->all_eat == 0 && data->control != 1)
		{
			message (now_time(), "died", pl);
			data->control = 1;
		}
		exit (1);
	}
	sem_post(data->finish);
	return (1);
}

int	philo_aten(t_data *data, t_philo *pl)
{
	sem_wait(data->aten);
	if (pl->eat_c == data->n_of_philo_must_eat)
	{
		data->all_eat++;
		sem_post(data->aten);
		return (0);
	}
	sem_post(data->aten);
	return (0);
}
