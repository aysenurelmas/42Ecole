#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				eat_c;
	int				die;
	struct s_data	*data;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
	long long int	start_time;
	long long int	last_eat;
}	t_philo;

typedef struct s_data
{
	int				n_of_philo;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				n_of_philo_must_eat;
	int				died_check;
	int				all_ate_c;
	pthread_t		*thread;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	finish_mutex;
}	t_data;

int				ft_atoi(const char *str);
int				init(t_data *data, int argc, char **argv);
int				init_philos(t_data *data);
int				check_data(t_data *data, int argc);
int				parsing_arg(t_data *data, int argc, char **argv);
int				is_digit(int argc, char **argv);
long long int	now_time(void);
void			go_to_sleep(int now);
void			create_philos(t_data *data);
void			*life_cycle(void *arg);
int				is_died(t_data *data);
int				check_finish(t_philo *pl);
void			message(int time, char *str, t_philo *pl);
void			philo_eat(t_philo *pl);
void			take_fork(t_philo *pl);
void			one_philo(t_philo *pl);
void			philo_think(t_philo *pl);
void			free_func(t_data data);
#endif