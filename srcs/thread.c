/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:51:03 by seowokim          #+#    #+#             */
/*   Updated: 2022/11/14 15:54:12 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	make_each_fork(t_data *data)
{
	int	i;

	i = 0;
	data -> fork = (t_fork *)malloc(sizeof(t_fork) * data -> num_p);
	while (i < data -> num_p)
	{
		if (pthread_mutex_init(&(data -> fork[i].fork_m), NULL))
			return ;
		data -> fork[i].left = i + 1;
		data -> fork[i].right = ((i + 1) % data -> num_p) + 1;
		i++;
	}
}

void	*each_philo(void *arg)
{
	int	i;

	i = *(int *)arg;
	usleep(10);
	printf("123\n");
	return (NULL);
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	make_each_fork(data);
	data -> philo = (t_philo *)malloc(sizeof(t_philo) * data -> num_p);
	while (i < data -> num_p)
	{
		if (pthread_create(&(data -> philo[i].philo_t), NULL, each_philo, &i))
			return ;
		pthread_detach(data -> philo[i].philo_t);
		data -> philo[i].id = i + 1;
		data -> philo[i].eat = 0;
		i++;
	}
}
