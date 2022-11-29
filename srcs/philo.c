/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:46:42 by seowokim          #+#    #+#             */
/*   Updated: 2022/11/29 14:14:02 by seowokim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	leak_check(void)
{
	system("leaks philo");
}

void	free_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data -> num_p)
	{
		pthread_join(data -> philo[i].philo_t, NULL);
		i++;
	}
	free(data -> philo);
	i = 0;
	while (i < data -> num_p)
	{
		pthread_mutex_destroy(&(data -> m_fork[i]));
		i++;
	}
	pthread_mutex_destroy(&(data -> m_fin));
	pthread_mutex_destroy(&(data -> m_print));
	free(data -> m_fork);
	free(data);
}

int	main(int argc, char *argv[])
{
	t_data	*data;
	int		exit;

	data = (t_data *)malloc(sizeof(t_data));
	exit = 1;
	// atexit(leak_check);
	if (argc <= 4 || argc >= 7)
		exit = print_error("WRONG NUM OF INPUTS!", data);
	else if (argc == 5)
		exit = set_arg(argv, 0, data);
	else if (argc == 6)
		exit = set_arg(argv, 1, data);
	if (exit == 0)
		return (EXIT_FAILURE);
	init_philo(data);
	free_philo(data);
	return (EXIT_SUCCESS);
}
