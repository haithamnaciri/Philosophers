/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:54:12 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/02/18 11:26:02 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

unsigned long long	get_time(void)
{
	struct timeval		t;

	gettimeofday (&t, NULL);
	return ((t.tv_sec * 1000000 + t.tv_usec) / 1000);
}

void	print(char *s, t_philo *philo)
{
	pthread_mutex_lock (&philo->data->print);
	if (!philo->data->is_dead)
		printf ("%llu	%d	%s",
			get_time() - philo->data->start_time, philo->number, s);
	pthread_mutex_unlock (&philo->data->print);
}

void	ft_usleep(unsigned long long to_sleep)
{
	unsigned long long	now;

	now = get_time();
	while ((get_time() - now) < to_sleep)
		usleep (300);
}

int	is_all_finish_eating(t_data *data)
{
	int	i;

	i = -1;
	while (++i < (int)data->number)
	{
		if (data->philos->time_he_eat < data->time)
			return (0);
		data->philos = data->philos->next;
	}
	return (1);
}
