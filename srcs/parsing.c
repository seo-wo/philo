/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:45:22 by seowokim          #+#    #+#             */
/*   Updated: 2022/11/29 15:20:37 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_data(t_data *data)
{
	data -> num_p = 0;
	data -> num_e = 0;
	data -> time_d = 0;
	data -> time_e = 0;
	data -> time_s = 0;
	data -> fin_num = 0;
	data -> fin = 0;
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (is_digit(str[i]))
			ret = ret * 10 + (str[i] - '0');
		else
			return (0);
		i++;
	}
	if (ret > 2147483647)
		return (0);
	return ((int)ret);
}

int	set_arg(char *argv[], int flag, t_data *data)
{
	init_data(data);
	data -> num_p = ft_atoi(argv[1]);
	data -> time_d = ft_atoi(argv[2]);
	data -> time_e = ft_atoi(argv[3]);
	data -> time_s = ft_atoi(argv[4]);
	if (!data -> num_p || !data -> time_d
		|| !data -> time_e || !data -> time_s)
		return (print_error("OUT OF RANGE!", data));
	if (flag == 1)
	{
		data -> num_e = ft_atoi(argv[5]);
		if (!data -> num_e)
			return (print_error("OUT OF RANGE", data));
	}
	else if (flag == 0)
		data -> num_e = 0;
	return (1);
}
