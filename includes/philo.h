/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:15:04 by seowokim          #+#    #+#             */
/*   Updated: 2022/11/14 13:37:46 by seowokim         ###   ########seoul.kr  */
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

typedef struct s_fork
{
	pthread_mutex_t	fork_m;
	int				left;
	int				right;
}	t_fork;

typedef struct s_philo
{
	pthread_t	philo_t;
	int			id;
	int			eat;
}	t_philo;

typedef struct s_data
{
	int				num_p;
	int				time_d;
	int				time_e;
	int				time_s;
	int				num_e;
	t_philo			*philo;
	t_fork			*fork;
}	t_data;

int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	init_data(t_data *data);
int		set_arg(char *argv[], int flag, t_data *data);
int		print_error(char *str, t_data *data);
void	print_status(t_data *data, char *str);

void	init_philo(t_data *data);
#endif