/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:25:31 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/02/13 17:47:43 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*ft_lstnew(unsigned int *numbers, t_data *data)
{
	t_philo	*new;

	new = malloc (sizeof(t_philo));
	if (new == 0)
		return (0);
	new->number = numbers[4];
	new->last_time_eat = get_time();
	new->time_he_eat = 0;
	new->is_eating = 0;
	new->data = data;
	pthread_mutex_init(&new->fork, NULL);
	new->next = 0;
	return (new);
}
