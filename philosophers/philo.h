/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:54:04 by jooypark          #+#    #+#             */
/*   Updated: 2023/11/04 11:58:15 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

# define HUNGRY 0
# define THINKING 1
# define EATING 2
# define SLEEPING 3

typedef struct s_arg
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_arg;

typedef struct s_mutex
{
	pthread_mutex_t	*fork;
}	t_mutex;

typedef struct s_philo
{
	t_arg		*arg;
	t_mutex		*mutex;
	pthread_t	tid;
	int			id;
	int			left;
	int			right;
	int			state;
}	t_philo;

int	ft_atoi(const char *str);

#endif 