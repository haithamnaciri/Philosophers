/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:01:45 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/02/18 11:23:27 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock (&philo->fork);
	print ("has taken a fork\n", philo);
	pthread_mutex_lock (&philo->next->fork);
	print ("has taken a fork\n", philo);
	philo->is_eating = 1;
	philo->last_time_eat = get_time();
	print ("is eating\n", philo);
	ft_usleep (philo->data->time_to_eat);
	philo->is_eating = 0;
	philo->time_he_eat++;
	pthread_mutex_unlock (&philo->fork);
	pthread_mutex_unlock (&philo->next->fork);
}

void	*actions(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (!(philo->number % 2))
		usleep (1500);
	while (!philo->data->is_dead)
	{
		eating (philo);
		if (philo->time_he_eat == philo->data->time)
			break ;
		print ("is sleeping\n", philo);
		ft_usleep (philo->data->time_to_sleep);
		print ("is thinking\n", philo);
	}
	return (0);
}

void	death(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (philo)
	{
		if (philo->time_he_eat >= philo->data->time)
			if (is_all_finish_eating(philo->data))
				return ;
		if (get_time() - philo->last_time_eat
			>= philo->data->time_to_die && !philo->is_eating)
			break ;
		philo = philo->next;
	}
	philo->data->is_dead = 1;
	pthread_mutex_lock (&philo->data->print);
	printf ("\033[0;31m%llu	%d	die\n",
		get_time() - philo->data->start_time, philo->number);
	pthread_mutex_unlock (&philo->data->print);
}

int	exec(t_data *data)
{
	int			i;

	i = -1;
	data->start_time = get_time();
	while (++i < (int)data->number)
	{
		pthread_create (&data->philos->thread, NULL, actions, data->philos);
		data->philos = data->philos->next;
	}
	death (data->philos);
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
