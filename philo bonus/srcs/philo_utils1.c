/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:47:14 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/02/18 23:28:47 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_digit(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] > '9' || s[i] < '0')
			return (0);
	return (1);
}

int	ft_check_args(int ac, char **av)
{
	while (--ac)
	{
		if (!is_digit (av[ac]))
		{
			printf ("\033[0;31mError : Takes only numeric args\n");
			return (1);
		}
	}
	return (0);
}

void	ft_fill(t_data *data, unsigned int *table)
{
	data->number = table[0];
	data->time_to_die = table[1];
	data->time_to_eat = table[2];
	data->time_to_sleep = table[3];
	data->time = table[4];
	sem_unlink ("PRINT");
	data->forks = sem_open ("PRINT", O_CREAT | O_EXCL, 0777, 1);
	sem_unlink ("FORKS");
	data->forks = sem_open ("FORKS", O_CREAT | O_EXCL, 0777, data->number);
}

int	ft_git_numbers(int ac, char **av, t_data *data)
{
	long long		number;
	unsigned int	table[5];
	t_philo			*last;

	table[4] = -1;
	while (--ac)
	{
		number = ft_atoi (av[ac]);
		if (number > INT_MAX || number <= 0)
		{
			printf ("\033[0;31mError : This numbers are invalid\n");
			return (1);
		}
		table[ac - 1] = number;
	}
	ft_fill (data, table);
	data->is_dead = 0;
	table[4] = 0;
	while (++table[4] <= number)
		ft_lstadd_back (&data->philos, ft_lstnew(table, data));
	last = ft_lstlast (data->philos);
	last->next = data->philos;
	return (0);
}
