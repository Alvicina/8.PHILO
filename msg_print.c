/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:52:41 by alvicina          #+#    #+#             */
/*   Updated: 2023/12/22 18:43:04 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_prnt_stat(t_philo_struct *philo, unsigned int t_st, int p, int st)
{
	pthread_mutex_lock(philo->lock_end);
	if (*philo->end)
	{
		pthread_mutex_unlock(philo->lock_end);
		return (1);
	}
	pthread_mutex_unlock(philo->lock_end);
	pthread_mutex_lock(philo->lock_print);
	if (st == 1)
		printf("%u %d has taken a fork\n", ft_check_time(t_st), p);
	else if (st == 2)
		printf("%u %d is eating\n", ft_check_time(t_st), p);
	else if (st == 3)
		printf("%u %d is sleeping\n", ft_check_time(t_st), p);
	else if (st == 4)
		printf("%u %d is thinking\n", ft_check_time(t_st), p);
	else if (st == 5)
		printf("%u %d died\n", ft_check_time(t_st), p);
	if (st < 5)
		pthread_mutex_unlock(philo->lock_print);
	return (0);
}
