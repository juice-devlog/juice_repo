/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:01:13 by jooypark          #+#    #+#             */
/*   Updated: 2023/11/04 12:22:57 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_arg	*init_arg(int argc, char **argv)
{
	t_arg	*arg;

	argc = 0;
	arg = (t_arg *)malloc(sizeof(t_arg));
	arg->number_of_philosophers = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		arg->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		arg->number_of_times_each_philosopher_must_eat = 0;
	return (arg);
}

t_mutex	*init_mutex(t_arg *arg)
{
	t_mutex	*mutex;
	int		i;

	mutex = (t_mutex *)malloc(sizeof(t_mutex));
	mutex->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* arg->number_of_philosophers);
	i = 0;
	while (i < arg->number_of_philosophers)
		pthread_mutex_init(&mutex->fork[i++], NULL);
	return (mutex);
}

t_philo	*init_philo(t_arg *arg, t_mutex	*mutex)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)malloc(sizeof(t_philo) * arg->number_of_philosophers);
	i = 0;
	while (i < arg->number_of_philosophers)
	{
		philo[i].arg = arg;
		philo[i].mutex = mutex;
		philo[i].id = i;
		philo[i].left = (i + arg->number_of_philosophers - 1)
			% arg->number_of_philosophers;
		philo[i].right = (i + 1) % arg->number_of_philosophers;
		philo[i].state = THINKING;
		i++;
	}
	return (philo);
}