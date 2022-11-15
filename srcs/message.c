/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:03:35 by seowokim          #+#    #+#             */
/*   Updated: 2022/11/15 15:38:07 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	error_ctl(t_data *data)
{
}

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

void	print_status(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (i < data -> num_p)
	{
		printf("%d : %d\n", data -> fork[i].left, data -> fork[i].right);
		i++;
	}
	printf("%s\n", str);
}
