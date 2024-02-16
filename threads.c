/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:29:38 by alvicina          #+#    #+#             */
/*   Updated: 2023/12/22 18:45:18 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	ft_check_time(unsigned int start)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec * 1000) + (time.tv_usec / 1000)) - start);
}

int	ft_create_threads(t_control *controller)
{
	int			i;
	pthread_t	controller_thread;
	int			philo_num;

	philo_num = controller->pointer_t_param->philo_num;
	i = 0;
	while (i < controller->pointer_t_param->philo_num)
	{
		if (pthread_create(&controller->threads[i], NULL,
				ft_philo_loop_wait, controller->table))
			return (ft_free_table(controller->table, i),
				free(controller->threads), 1);
		controller->table = controller->table->right;
		i++;
	}
	controller->time_start = ft_check_time(controller->time_start);
	if (pthread_create(&controller_thread, NULL,
			ft_controller_routine, controller))
		return (ft_free_table(controller->table, i),
			free(controller->threads), 1);
	pthread_join(controller_thread, NULL);
	i = -1;
	while (++i < philo_num)
		pthread_join(controller->threads[i], NULL);
	return (0);
}
