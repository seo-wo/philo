/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:07:46 by seowokim          #+#    #+#             */
/*   Updated: 2022/11/29 14:57:35 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	my_sleep(int ms)
{
	long long		time;

	time = 0;
	time = timestamp() + ms;
	while (time > timestamp())
	{
	}
}

long long	time_cal(struct timeval end, struct timeval start)
{
	long long	ret;

	ret = 0;
	ret = end.tv_sec * 1000 + end.tv_usec / 1000;
	ret -= start.tv_sec * 1000 + start.tv_usec / 1000;
	return (ret);
}

struct timeval	get_now_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time);
}
