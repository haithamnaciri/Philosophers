/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:55:36 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/02/03 15:29:24 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*p;

	if (lst && new)
	{
		p = *lst;
		new->next = 0;
		if (p == 0)
		{
			*lst = new;
			return ;
		}
		while (p->next != 0)
			p = p->next;
		p->next = new;
	}
}
