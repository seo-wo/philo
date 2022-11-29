/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:15:04 by seowokim          #+#    #+#             */
/*   Updated: 2022/11/29 15:51:37 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died"

typedef struct s_philo
{
	pthread_t		philo_t;
	int				id;
	int				eat;
	pthread_mutex_t	*m_lfork;
	pthread_mutex_t	*m_rfork;
	struct timeval	last_eat;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				num_p;
	int				time_d;
	int				time_e;
	int				time_s;
	int				num_e;
	int				fin_num;
	int				fin;
	pthread_mutex_t	m_fin;
	pthread_mutex_t	*m_fork;
	pthread_mutex_t	m_print;
	struct timeval	start;
	t_philo			*philo;
}	t_data;

/*
	philo.c (main)
	|-> free_philo() : join & free all
*/
void			free_philo(t_data *data);

/*
	parsing.c
	|-> init_data() : set @data 0
	|-> is_digit() : check ascii code is digit
	|-> ft_strlen() : return string's length
	|-> ft_atoi() : similar to atoi(), only works positive int
	|-> set_arg() : put input args to @data
*/
void			init_data(t_data *data);
int				is_digit(char c);
int				ft_strlen(char *str);
int				ft_atoi(char *str);
int				set_arg(char *argv[], int flag, t_data *data);

/*
	message.c
	|->	print_error() : print error msg & free @data 
	|-> print_status() : print time_stamp ,philo's id and acitng(sleep and think)
	|-> print_eat() : print eating case 
*/
int				print_error(char *str, t_data *data);
void			print_status(t_philo *philo, char *str);
void			print_eat(t_philo *philo, char *str);

/*
	time.c
	|-> timestamp() : get now time 
	|-> my_sleep() : similar to sleep(), but @arg is millisecond
	|-> time_cal() : get the difference between two @args 
	|-> get_now_time() : get now time's strcut
*/
long long		timestamp(void);
void			my_sleep(int ms);
long long		time_cal(struct timeval end, struct timeval start);
struct timeval	get_now_time(void);

/*
	thread.c
	|-> ft_allocate() : allocate each philo and fork, then set data
	|-> no_must() : case when didn't put number_of_times_each_philosopher_must_eat
	|-> must_eat() : opposite case no_must()
	|-> init_philo : create threads
*/
int				ft_allocate(t_data *data);
void			*no_must(void *arg);
void			*must_eat(void *arg);
int				init_philo(t_data *data);

/*
	acting.c
		: each philo's routine
*/
void			philo_fork(t_philo *philo);
void			philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);
void			*philo_acting(void *arg);

#endif