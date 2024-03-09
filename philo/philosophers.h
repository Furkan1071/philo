/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:08:35 by fekiz             #+#    #+#             */
/*   Updated: 2024/03/07 19:11:54 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct philos
{
	int				i;
	int				last_eat;
	bool			is_dead;
	pthread_t		thread;
	struct s_list	*data;
}	t_philo;

typedef struct s_list
{
	long			number_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			start_time;
	int				max_eat;
	int				must_eat;
	int				eat_count;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	eaten;
	pthread_mutex_t	mutex_dead;
}	t_list;

int		ft_atoi(char *str);
int		num_control(char **str, t_list *data);
int		data_creat(char **str, t_list *data);
long	get_ms(unsigned long start_time);

#endif