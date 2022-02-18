/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:01:45 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/02/18 23:28:22 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	eating(t_philo *philo)
{
	sem_wait (philo->data->forks);
	print ("has taken a fork\n", philo);
	sem_wait (philo->data->forks);
	print ("has taken a fork\n", philo);
	philo->is_eating = 1;
	philo->last_time_eat = get_time();
	print ("is eating\n", philo);
	ft_usleep (philo->data->time_to_eat);
	philo->is_eating = 0;
	philo->time_he_eat++;
	sem_post (philo->data->forks);
	sem_post (philo->data->forks);
}

void	*check(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		if (philo->time_he_eat >= philo->data->time
			&& (int)philo->data->time != -1)
			exit (0);
		if (get_time() - philo->last_time_eat
			>= philo->data->time_to_die && !philo->is_eating)
			break ;
	}
	sem_wait (philo->data->print);
	printf ("\033[0;31m%llu	%d	die\n",
		get_time() - philo->data->start_time, philo->number);
	kill (philo->pid, SIGINT);
	return (NULL);
}

void	actions(t_philo *philo)
{
	if (!(philo->number % 2))
		usleep (1500);
	pthread_create (&philo->check, NULL, check, philo);
	while (1)
	{
		eating (philo);
		print ("is sleeping\n", philo);
		ft_usleep (philo->data->time_to_sleep);
		print ("is thinking\n", philo);
	}
}

int	exec(t_data *data)
{
	int			i;

	i = -1;
	data->start_time = get_time();
	while (++i < (int)data->number)
	{
		data->philos->pid = fork ();
		if (!data->philos->pid)
			actions (data->philos);
		data->philos = data->philos->next;
	}
	i = -1;
	while (++i < (int)data->number)
	{
		waitpid (data->philos->pid, 0, 0);
		data->philos = data->philos->next;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
	{
		printf("\033[0;31mError : missing arguments\n");
		return (1);
	}
	if (ft_check_args (ac, av))
		return (1);
	if (ft_git_numbers (ac, av, &data))
		return (1);
	if (exec (&data))
		return (1);
	return (0);
}
