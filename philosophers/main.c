/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:16:32 by jooypark          #+#    #+#             */
/*   Updated: 2023/11/04 12:17:55 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_arg	*init_arg(int argc, char **argv);
t_mutex	*init_mutex(t_arg *arg);
t_philo	*init_philo(t_arg *arg, t_mutex	*mutex);

void	think(t_philo *philo)
{
	philo->state = THINKING;
	printf("%d: thinking\n", philo->id);
}

void	eat(t_philo *philo)
{
	philo->state = EATING;
	printf("%d: eating\n", philo->id);
}

void	check(t_philo *philo)
{
	if (philo->left != EATING && philo->right != EATING)
		philo->state = EATING;
}

void	pickup(t_philo *philo)
{
	philo->state = HUNGRY;
	while (philo->state != EATING)
		check(philo);
	pthread_mutex_lock(&philo->mutex->fork[philo->left]);
	pthread_mutex_lock(&philo->mutex->fork[philo->right]);
}

void	putdown(t_philo	*philo)
{
	pthread_mutex_unlock(&philo->mutex->fork[philo->right]);
	pthread_mutex_unlock(&philo->mutex->fork[philo->left]);
}

void	philo_sleep(t_philo *philo)
{
	philo->state = SLEEPING;
	printf("%d: sleeping\n", philo->id);
	usleep(50);
}

void	*philosopher(void	*param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	if (philo->id % 2 == 0)
		usleep(10);
	while (1)
	{
		think(philo);
		pickup(philo);
		eat(philo);
		putdown(philo);
		philo_sleep(philo);
	}
}

void	create_thread(t_arg *arg, t_philo *philo)
{
	int			i;
	pthread_t	tid;

	i = 0;
	while (i < arg->number_of_philosophers)
	{
		printf("creating thread %d...\n", i);
		pthread_create(&tid, NULL, philosopher, (void *)&philo[i]);
		i++;
	}
	i = 0;
	while (i < arg->number_of_philosophers)
	{
		pthread_join(tid, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_arg	*arg;
	t_mutex	*mutex;
	t_philo	*philo;

	printf("%d\n", argc);
	if (argc != 5 && argc != 6)
		return (1);
	arg = init_arg(argc, argv);
	mutex = init_mutex(arg);
	philo = init_philo(arg, mutex);
	printf("init done\n");
	create_thread(arg, philo);
}
