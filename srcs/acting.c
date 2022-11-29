/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acting.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:11:12 by seowokim          #+#    #+#             */
/*   Updated: 2022/11/29 14:50:40 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_fork(t_philo *philo)
{
	pthread_mutex_lock(philo -> m_rfork);
	print_status(philo, FORK);
	if (philo -> m_rfork == philo -> m_lfork)
	{
		pthread_mutex_unlock(philo -> m_rfork);
		my_sleep(philo -> data -> time_d);
		return ;
	}
	pthread_mutex_lock(philo -> m_lfork);
	print_status(philo, FORK);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo -> data -> m_fin));
	if (!philo -> data -> fin)
	{
		print_eat(philo, EAT);
	}
	else
	{
		pthread_mutex_unlock(&(philo -> data -> m_fin));
		pthread_mutex_unlock(philo -> m_lfork);
		pthread_mutex_unlock(philo -> m_rfork);
		return ;
	}
	philo -> eat++;
	if (philo -> eat == philo -> data -> num_e)
		philo -> data -> fin_num++;
	pthread_mutex_unlock(&(philo -> data -> m_fin));
	philo -> last_eat = get_now_time();
	my_sleep(philo -> data -> time_e);
	pthread_mutex_unlock(philo -> m_lfork);
	pthread_mutex_unlock(philo -> m_rfork);
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&(philo -> data -> m_fin));
	if (philo -> data -> fin)
	{
		pthread_mutex_unlock(&(philo -> data -> m_fin));
		return ;
	}
	pthread_mutex_unlock(&(philo -> data -> m_fin));
	print_status(philo, SLEEP);
	my_sleep(philo -> data -> time_s);
}

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&(philo -> data -> m_fin));
	if (philo -> data -> fin)
	{
		pthread_mutex_unlock(&(philo -> data -> m_fin));
		return ;
	}
	print_status(philo, THINK);
	pthread_mutex_unlock(&(philo -> data -> m_fin));
}

void	*philo_acting(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if ((philo -> id - 1) % 2 == 1)
		my_sleep(philo -> data -> time_e / 2);
	while (!philo -> data -> fin)
	{
		philo_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		usleep(100);
	}
	return (NULL);
}
