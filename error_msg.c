/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:10:22 by alvicina          #+#    #+#             */
/*   Updated: 2023/12/21 12:38:41 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i] != 0)
		write(fd, &s[i], 1);
}

void	ft_err_msg(char *string)
{
	ft_putstr_fd("Invalid ", 2);
	ft_putstr_fd(string, 2);
	ft_putstr_fd("\n", 2);
}
