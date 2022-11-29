/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:03:35 by seowokim          #+#    #+#             */
/*   Updated: 2022/11/29 14:11:35 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	print_error(char *str, t_data *data)
{
	write(2, "\033[0;31m", 8);
	write(2, "Error!\n", 7);
	write(2, str, ft_strlen(str));
	write(2, "\ntype \"make help\"\n", 18);
	write(2, "\033[0;37m", 8);
	free(data);
	return (0);
}

void	print_status(t_philo *philo, char *str)
{
	long long		time;
	struct timeval	now;

	pthread_mutex_lock(&(philo -> data -> m_print));
	if (philo -> data -> fin)
	{
		pthread_mutex_unlock(&(philo -> data -> m_print));
		return ;
	}
	gettimeofday(&now, NULL);
	time = time_cal(now, philo -> data -> start);
	printf("%lld [%d] %s\n", time, philo -> id, str);
	pthread_mutex_unlock(&(philo -> data -> m_print));
}

void	print_eat(t_philo *philo, char *str)
{
	long long		time;

	pthread_mutex_lock(&(philo -> data -> m_print));
	gettimeofday(&(philo -> last_eat), NULL);
	time = time_cal(philo -> last_eat, philo -> data -> start);
	printf("%lld [%d] %s\t (%d time(s))\n", time, \
			philo -> id, str, philo -> eat + 1);
	pthread_mutex_unlock(&(philo -> data -> m_print));
}
