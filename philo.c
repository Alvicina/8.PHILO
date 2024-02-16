/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:09:48 by alvicina          #+#    #+#             */
/*   Updated: 2023/12/22 18:55:24 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo_param	philo_param;
	t_control		controller;

	if (ft_check_input(argc, argv, &philo_param))
		return (1);
	controller.pointer_t_param = &philo_param;
	if (ft_create_philos(&controller))
		return (1);
	if (ft_create_threads(&controller))
	{
		pthread_mutex_destroy(&controller.lock_param);
		pthread_mutex_destroy(&controller.lock_print);
	}
	free(controller.threads);
	ft_free_table(controller.table, controller.pointer_t_param->philo_num);
	return (0);
}
