/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:38:33 by alvicina          #+#    #+#             */
/*   Updated: 2023/12/26 10:04:49 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_end(t_control *controller, t_philo_struct *tab,
					t_philo_param *par, unsigned int t_st)
{
	int	i;
	int	eat;

	i = -1;
	eat = 0;
	while (++i < par->philo_num)
	{
		pthread_mutex_lock(&controller->lock_param);
		if ((unsigned)par->time_t_die < ft_check_time(t_st) - tab->meal_last)
			return (pthread_mutex_unlock(&controller->lock_param),
				ft_prnt_stat(tab, t_st, i + 1, 5), 1);
		if (par->times_eat != -1)
		{
			if (tab->meal >= par->times_eat)
				eat++;
		}
		pthread_mutex_unlock(&controller->lock_param);
		usleep(70);
		tab = tab->right;
	}
	if (eat == par->philo_num)
		return (pthread_mutex_lock(&controller->lock_print), 1);
	return (0);
}

void	*ft_controller_routine(void *arg)
{
	t_control		*controller;
	t_philo_struct	*table;
	t_philo_param	*param;
	unsigned int	time_start;

	controller = (t_control *)arg;
	pthread_mutex_lock(&controller->lock_print);
	controller->start = 1;
	pthread_mutex_unlock(&controller->lock_print);
	table = controller->table;
	param = controller->pointer_t_param;
	time_start = controller->time_start;
	while (1)
	{
		if (ft_end(controller, table, param, time_start))
		{
			pthread_mutex_lock(&controller->lock_end);
			controller->end = 1;
			pthread_mutex_unlock(&controller->lock_end);
			break ;
		}
	}
	return (NULL);
}
