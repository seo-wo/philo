/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:03:35 by seowokim          #+#    #+#             */
/*   Updated: 2022/11/07 21:12:52 by seowokim         ###   ########seoul.kr  */
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
}
