/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:51:03 by seowokim          #+#    #+#             */
/*   Updated: 2022/11/29 15:14:04 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_allocate(t_data *data)
{
	int	i;

	i = 0;
	data -> philo = (t_philo *)malloc(sizeof(t_philo) * data -> num_p);
	data -> m_fork = malloc(sizeof(pthread_mutex_t) * data -> num_p);
	if (data -> philo == NULL || data -> m_fork == NULL)
		return (0);
	if (pthread_mutex_init(&(data -> m_fin), NULL) || \
		pthread_mutex_init(&(data -> m_print), NULL))
		return (0);
	gettimeofday(&(data -> start), NULL);
	while (i < data -> num_p)
	{
		if (pthread_mutex_init(&(data -> m_fork[i]), NULL))
			return (0);
		data -> philo[i].id = i + 1;
		data -> philo[i].eat = 0;
		data -> philo[i].m_lfork = &(data -> m_fork[i]);
		data -> philo[i].m_rfork = &(data -> m_fork[(i + 1) % data -> num_p]);
		data -> philo[i].last_eat = data -> start;
		data -> philo[i].data = data;
		i++;
	}
	return (1);
}

void	*no_must(void *arg)
{
	t_philo			*philo;
	struct timeval	now;
	long long		time;

	philo = arg;
	while (!philo -> data -> fin)
	{
		pthread_mutex_lock(&(philo -> data -> m_fin));
		now = get_now_time();
		time = time_cal(now, philo -> last_eat);
		if (time >= philo -> data -> time_d && !philo -> data -> fin)
		{
			pthread_mutex_lock(&(philo -> data -> m_print));
			printf("\033[0;31m%lld [%d] %s\n", \
					time_cal(now, philo -> data -> start), philo -> id, DIED);
			philo -> data -> fin = 1;
			pthread_mutex_unlock(&(philo -> data -> m_print));
		}
		pthread_mutex_unlock(&(philo -> data -> m_fin));
	}
	return (NULL);
}

void	*must_eat(void *arg)
{	
	t_philo			*philo;
	struct timeval	now;
	long long		time;

	philo = arg;
	while (!philo -> data -> fin)
	{
		pthread_mutex_lock(&(philo -> data -> m_fin));
		now = get_now_time();
		time = time_cal(now, philo -> last_eat);
		if (time >= philo -> data -> time_d && !philo -> data -> fin)
		{
			pthread_mutex_lock(&(philo -> data -> m_print));
			printf("\033[0;31m%lld [%d] %s\n", \
					time_cal(now, philo -> data -> start), philo -> id, DIED);
			philo -> data -> fin = 1;
			pthread_mutex_unlock(&(philo -> data -> m_print));
		}
		if (philo -> data -> fin_num == philo -> data -> num_p)
			philo -> data -> fin = 1;
		pthread_mutex_unlock(&(philo -> data -> m_fin));
	}
	return (NULL);
}

int	init_philo(t_data *data)
{
	int			i;
	pthread_t	monintor;

	i = 0;
	if (!ft_allocate(data))
		return (0);
	while (i < data -> num_p)
	{
		if (pthread_create(&(data -> philo[i].philo_t), NULL, philo_acting, \
				&(data -> philo[i])))
			return (0);
		if (data -> num_e == 0)
		{
			if (pthread_create(&monintor, NULL, no_must, &(data -> philo[i])))
				return (0);
		}
		else
		{
			if (pthread_create(&monintor, NULL, must_eat, &(data -> philo[i])))
				return (0);
		}
		pthread_detach(monintor);
		i++;
	}
	return (1);
}
