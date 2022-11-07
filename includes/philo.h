/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:15:04 by seowokim          #+#    #+#             */
/*   Updated: 2022/11/07 20:54:53 by seowokim         ###   ########seoul.kr  */
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

typedef struct s_philo
{
	pthread_t	thread;
}	t_philo;

typedef struct s_data
{
	int		num_p;
	int		time_d;
	int		time_e;
	int		time_s;
	int		num_e;
	t_philo	*philo;
}	t_data;

int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	init_data(t_data *data);
int		set_arg(char *argv[], int flag, t_data *data);
int		print_error(char *str, t_data *data);

void	make_philo(t_data *data);
#endif