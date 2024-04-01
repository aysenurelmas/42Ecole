/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebattal <ebattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:37:03 by ebattal           #+#    #+#             */
/*   Updated: 2022/10/28 13:15:53 by ebattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	isnegative;

	i = 0;
	res = 0;
	isnegative = 1;
	while ((str[i] == ' ') || (str[i] == '\t'))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			isnegative = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * isnegative);
}

int	is_digit(int argc, char **argv)
{
	int	i;
	int	j;
	int	c;
	int	k;

	i = 1;
	j = 0;
	c = 0;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				k++;
			else
			{
				c = 1;
			}
			j++;
		}
		i++;
	}
	return (c);
}

long long int	now_time(void)
{
	long long int	time;
	struct timeval	now;

	gettimeofday(&now, NULL);
	time = ((now.tv_sec * 1000) + (now.tv_usec / 1000));
	return (time);
}

void	go_to_sleep(int now)
{
	long long int	time;

	time = now_time();
	while (now > now_time() - time)
	{
		usleep(20);
	}
}

void	message(int time, char *str, t_philo *pl)
{
	time = now_time() - pl->data->start_time;
	if (time < 0)
		time = 0;
	printf("%d\t%d\t%s\n", time, pl->id, str);
}
