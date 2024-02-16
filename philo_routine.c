/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:20:06 by alvicina          #+#    #+#             */
/*   Updated: 2023/12/26 10:48:15 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_philo_sleep_think(t_philo_struct *philo)
{
	if (ft_prnt_stat(philo, *philo->time_start, philo->position, 3))
		return (1);
	if (ft_wait(philo, philo->param->time_t_sleep))
		return (1);
	if (ft_prnt_stat(philo, *philo->time_start, philo->position, 4))
		return (1);
	return (0);
}

static int	ft_philo_end(t_philo_struct *philo)
{
	pthread_mutex_lock(philo->lock_end);
	if (*philo->end)
	{
		pthread_mutex_unlock(philo->lock_end);
		return (1);
	}
	pthread_mutex_unlock(philo->lock_end);
	return (0);
}

int	ft_wait(t_philo_struct *philo, unsigned int time_to_wait)
{
	unsigned int	start_time;
	unsigned int	waited;

	start_time = ft_check_time(0);
	waited = 0;
	pthread_mutex_lock(philo->lock_end);
	if (*philo->end)
	{
		pthread_mutex_unlock(philo->lock_end);
		return (1);
	}
	pthread_mutex_unlock(philo->lock_end);
	while (waited < time_to_wait)
	{
		usleep(500);
		waited = ft_check_time(start_time);
	}
	return (0);
}

static void	ft_philo_life(t_philo_struct *philo)
{
	while (1)
	{
		if (ft_philo_end(philo))
			break ;
		pthread_mutex_lock(&philo->fork);
		if (ft_prnt_stat(philo, *philo->time_start, philo->position, 1))
			break ;
		if (philo->param->philo_num == 1)
			break ;
		pthread_mutex_lock(&philo->right->fork);
		if (ft_prnt_stat(philo, *philo->time_start, philo->position, 1))
			break ;
		if (ft_prnt_stat(philo, *philo->time_start, philo->position, 2))
			break ;
		pthread_mutex_lock(philo->lock_param);
		philo->meal_last = ft_check_time(*philo->time_start);
		philo->meal++;
		pthread_mutex_unlock(philo->lock_param);
		if (ft_wait(philo, philo->param->time_t_eat))
			break ;
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->right->fork);
		if (ft_philo_sleep_think(philo))
			break ;
	}
}

void	*ft_philo_loop_wait(void *arg)
{
	t_philo_struct	*philo;

	philo = (t_philo_struct *)arg;
	while (1)
	{
		pthread_mutex_lock(philo->lock_print);
		if (*philo->start)
		{
			pthread_mutex_unlock(philo->lock_print);
			break ;
		}
		pthread_mutex_unlock(philo->lock_print);
	}
	if (philo->position % 2 == 0)
		usleep(15000);
	ft_philo_life(philo);
	return (NULL);
}
