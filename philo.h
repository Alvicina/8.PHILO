/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:09:38 by alvicina          #+#    #+#             */
/*   Updated: 2023/12/26 10:40:43 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo_param
{
	int	philo_num;
	int	time_t_die;
	int	time_t_eat;
	int	time_t_sleep;
	int	times_eat;
}	t_philo_param;

typedef struct s_philo_struct
{
	struct s_philo_struct	*left;
	struct s_philo_struct	*right;
	unsigned int			meal_last;
	char					*start;
	char					*end;
	unsigned int			*time_start;
	int						meal;
	int						position;
	pthread_mutex_t			fork;
	t_philo_param			*param;
	pthread_mutex_t			*lock_print;
	pthread_mutex_t			*lock_param;
	pthread_mutex_t			*lock_end;
}	t_philo_struct;

typedef struct s_control
{
	pthread_mutex_t	lock_param;
	t_philo_param	*pointer_t_param;
	t_philo_struct	*table;
	pthread_t		*threads;
	unsigned int	time_start;
	char			start;
	char			end;
	pthread_mutex_t	lock_print;
	pthread_mutex_t	lock_end;
}	t_control;

int				ft_check_input(int argc, char **argv,
					t_philo_param *philo_param);
void			ft_err_msg(char *string);
int				ft_create_philos(t_control *controller);
void			ft_free_table(t_philo_struct *table, int i);
int				ft_create_threads(t_control *controller);
unsigned int	ft_check_time(unsigned int start);
void			*ft_philo_loop_wait(void *arg);
int				ft_prnt_stat(t_philo_struct *philo,
					unsigned int t_st, int p, int st);
void			*ft_controller_routine(void *arg);
int				ft_wait(t_philo_struct *philo, unsigned int time_to_wait);
void			ft_eat(t_philo_struct *philo);

#endif