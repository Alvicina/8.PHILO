/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:10:01 by alvicina          #+#    #+#             */
/*   Updated: 2023/12/21 12:48:26 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_is_digit(char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (argv[i])
	{
		k = 0;
		while (argv[i][k])
		{
			if (argv[i][k] < '0' || argv[i][k] > '9')
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

static int	ft_atoi(const char *str)
{
	int					i;
	int					neg;
	unsigned long int	num_atoi;	

	i = 0;
	neg = 1;
	num_atoi = 0;
	while (str[i] != 0 && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		num_atoi = num_atoi * 10 + str[i] - 48;
		if (num_atoi > 0x7fffffffffffffff)
			return ((neg + 1) / (-2));
		i++;
	}
	return (num_atoi * neg);
}

int	ft_check_input(int argc, char **argv, t_philo_param *philo_param)
{
	if (argc < 5 || argc > 6)
		return (ft_err_msg("number of arguments"), 1);
	if (ft_is_digit(argv))
		return (ft_err_msg("type of args"), 1);
	philo_param->philo_num = ft_atoi(argv[1]);
	if (philo_param->philo_num < 1)
		return (ft_err_msg("number of philos"), 1);
	philo_param->time_t_die = ft_atoi(argv[2]);
	if (philo_param->time_t_die < 1)
		return (ft_err_msg("number of time_to_die"), 1);
	philo_param->time_t_eat = ft_atoi(argv[3]);
	if (philo_param->time_t_eat < 1)
		return (ft_err_msg("number of time_to_eat"), 1);
	philo_param->time_t_sleep = ft_atoi(argv[4]);
	if (philo_param->time_t_sleep < 1)
		return (ft_err_msg("number of time_to_sleep"), 1);
	if (argc == 6)
	{
		philo_param->times_eat = ft_atoi(argv[5]);
		if (philo_param->times_eat < 1)
			return (ft_err_msg("number of times_philo_must_eat"), 1);
	}
	else
		philo_param->times_eat = -1;
	return (0);
}
