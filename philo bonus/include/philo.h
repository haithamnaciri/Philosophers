/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:59:00 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/02/18 23:22:41 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <signal.h>
# include <semaphore.h>

struct	s_data;
typedef struct s_philo
{
	unsigned int		number;
	unsigned int		time_he_eat;
	unsigned long long	last_time_eat;
	unsigned int		is_eating;
	pthread_t			check;
	int					pid;
	struct s_data		*data;
	struct s_philo		*next;
}	t_philo;

typedef struct s_data
{	
	unsigned int		number;
	unsigned int		time_to_sleep;
	unsigned int		time_to_die;
	unsigned int		time_to_eat;
	unsigned long long	start_time;
	sem_t				*print;
	sem_t				*forks;
	int					is_dead;
	t_philo				*philos;
	unsigned int		time;
}	t_data;

void				ft_lstadd_back(t_philo **lst, t_philo *a);
long long			ft_atoi(const char *str);
t_philo				*ft_lstnew(unsigned int *numbers, t_data *data);
t_philo				*ft_lstlast(t_philo *lst);
int					ft_lstsize(t_philo *lst);
unsigned long long	get_time(void);
int					is_digit(char *s);
int					ft_check_args(int ac, char **av);
int					ft_git_numbers(int ac, char **av, t_data *data);
void				print(char *s, t_philo *philo);
void				ft_usleep(unsigned long long to_sleep);
int					is_all_finish_eating(t_data *data);

#endif
