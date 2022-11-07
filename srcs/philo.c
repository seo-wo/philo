/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:46:42 by seowokim          #+#    #+#             */
/*   Updated: 2022/11/07 20:43:12 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	leak_check(void)
{
	system("leaks philo");
}

int	main(int argc, char *argv[])
{
	t_data	*data;
	int		exit;

	data = (t_data *)malloc(sizeof(t_data));
	exit = 1;
	//atexit(leak_check);
	if (argc <= 4 || argc >= 7)
		exit = print_error("WRONG NUM OF INPUTS!", data);
	if (argc == 5)
		exit = set_arg(argv, 0, data);
	else if (argc == 6)
		exit = set_arg(argv, 1, data);
	if (exit == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
