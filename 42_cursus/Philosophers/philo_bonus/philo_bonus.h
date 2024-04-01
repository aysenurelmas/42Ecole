/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebattal <ebattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:30:13 by ebattal           #+#    #+#             */
/*   Updated: 2022/10/28 16:08:26 by ebattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <semaphore.h>
# include <pthread.h>
# include <sys/time.h>
# include <signal.h>
# include <sys/stat.h>

typedef struct s_philo
{
	int				id;
	int				eat_c;
	pid_t			pid;
	struct s_data	*data;
	long long int	last_eat;
}	t_philo;

typedef struct s_data
{
	int				n_of_philo;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				n_of_philo_must_eat;
	int				all_eat;
	int				control;
	long long int	start_time;
	pthread_t		thread;
	sem_t			*forks;
	sem_t			*finish;
	sem_t			*aten;
	struct s_philo	*philo;
}	t_data;

int				ft_atoi(const char *str);
int				is_digit(int argc, char **argv);
long long int	now_time(void);
void			go_to_sleep(int now);
void			message(int time, char *str, t_philo *pl);
int				parsing_arg(t_data *data, int argc, char **argv);
int				init(t_data *data, int argc, char **argv);
void			life_cycle(void *arg);
void			philo_eat(t_philo *pl);
void			kill_fork(t_data *data);
int				dead_finish(t_data *data, t_philo *pl);
void			one_philo(t_philo *pl);
int				philo_aten(t_data *data, t_philo *pl);
void			*check_cycle(void *arg);
#endif