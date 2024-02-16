/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:10:27 by alvicina          #+#    #+#             */
/*   Updated: 2023/12/22 18:41:09 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_sit_philo(t_philo_struct **table, t_philo_struct *new, int i)
{
	t_philo_struct	*last;

	if (i == 0)
		*table = new;
	else
	{
		last = *table;
		while (last->right)
			last = last->right;
		last->right = new;
		new->left = last;
	}
	if (i == (*table)->param->philo_num - 1)
	{
		new->right = *table;
		(*table)->left = new;
	}
}

static t_philo_struct	*ft_initialize_philos(t_control *controller, int i)
{
	t_philo_struct	*temp;

	temp = malloc(sizeof(t_philo_struct));
	if (temp == NULL)
		return (NULL);
	temp->left = NULL;
	temp->right = NULL;
	temp->meal_last = 0;
	temp->start = &controller->start;
	temp->end = &controller->end;
	temp->time_start = &controller->time_start;
	temp->meal = 0;
	temp->position = i + 1;
	if (pthread_mutex_init(&temp->fork, NULL))
		return (free(temp), NULL);
	temp->param = controller->pointer_t_param;
	temp->lock_param = &controller->lock_param;
	temp->lock_print = &controller->lock_print;
	temp->lock_end = &controller->lock_end;
	return (temp);
}

static int	ft_create_controller(t_control *controller)
{
	controller->threads = malloc(controller->pointer_t_param->philo_num
			* (sizeof(pthread_t)));
	if (controller->threads == NULL)
		return (1);
	controller->start = 0;
	controller->time_start = 0;
	controller->end = 0;
	if (pthread_mutex_init(&controller->lock_print, NULL))
		return (free(controller->threads), 1);
	if (pthread_mutex_init(&controller->lock_param, NULL))
		return (free(controller->threads),
			pthread_mutex_destroy(&controller->lock_print), 1);
	if (pthread_mutex_init(&controller->lock_end, NULL))
		return (free(controller->threads),
			pthread_mutex_destroy(&controller->lock_print),
			pthread_mutex_destroy(&controller->lock_param), 1);
	controller->table = NULL;
	return (0);
}

int	ft_create_philos(t_control *controller)
{
	int				i;
	t_philo_struct	*temp;

	i = 0;
	if (ft_create_controller(controller))
		return (1);
	while (i < controller->pointer_t_param->philo_num)
	{
		temp = ft_initialize_philos(controller, i);
		if (temp == NULL)
		{
			pthread_mutex_destroy(&controller->lock_param);
			pthread_mutex_destroy(&controller->lock_print);
			ft_free_table(controller->table, i);
			return (1);
		}
		ft_sit_philo(&controller->table, temp, i);
		i++;
	}
	return (0);
}
