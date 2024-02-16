/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:47:44 by alvicina          #+#    #+#             */
/*   Updated: 2023/12/22 19:09:04 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_table(t_philo_struct *table, int i)
{
	t_philo_struct	*temp;
	int				j;

	j = 0;
	temp = table->right;
	while (j < i)
	{
		pthread_mutex_destroy(&table->fork);
		free(table);
		table = temp;
		if (j == i - 1)
			break ;
		temp = temp->right;
		j++;
	}
}
