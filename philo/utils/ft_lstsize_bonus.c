/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:02:26 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/02/08 16:00:48 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_lstsize(t_philo *lst)
{
	t_philo	*begin;
	int		size;

	size = 0;
	begin = lst;
	if (begin == 0)
		return (0);
	size++;
	while (begin->next != 0)
	{
		size++;
		return (size);
		begin = begin->next;
	}
	return (size);
}
