/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:11:13 by fekiz             #+#    #+#             */
/*   Updated: 2024/03/10 21:24:57 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	writes(t_philo *p, int num)
{
	if (num == 0)
	{
		p->data->ms = get_ms(p->data, false, false);
		pthread_mutex_lock(&p->data->mutex_dead);
		printf("%lu %d has taken a fork\n", p->data->ms, p->id);
		pthread_mutex_unlock(&p->data->mutex_dead);
	}
	else if (num == 1)
	{
		pthread_mutex_lock(&p->data->mutex_dead);
		printf("%lu %d is sleeping\n", get_ms(p->data, false, false), p->id);
		pthread_mutex_unlock(&p->data->mutex_dead);
	}
	else if (num == 2)
	{
		pthread_mutex_lock(&p->data->mutex_dead);
		printf("%lu %d is thinking\n", get_ms(p->data, false, false), p->id);
		pthread_mutex_unlock(&p->data->mutex_dead);
	}
	else if (num == 3)
	{
		pthread_mutex_lock(&p->data->mutex_dead);
		printf("%lu %d is eating\n", get_ms(p->data, false, false), p->id);
		pthread_mutex_unlock(&p->data->mutex_dead);
	}
}

void	main_thread(t_list *data)
{
	int	i;

	i = 1;
	while (1)
	{
		pthread_mutex_lock(&data->is_eat);
		if (data->must_eat > -1
			&& data->eat_count >= (data->max_eat * data->number_philo))
		{
			pthread_mutex_lock(&data->mutex_dead);
			return ;
		}
		data->cont = (i % data->number_philo);
		if (get_ms(data, false, false) - data->philos[data->cont].last_eat
			>= data->time_to_die)
		{
			pthread_mutex_lock(&data->mutex_dead);
			printf("%lu %d died\n", get_ms(data, false, false), data->cont + 1);
			return ;
		}
		pthread_mutex_unlock(&data->is_eat);
		i++;
		usleep(100);
	}
}

void	ms_sleep(t_philo *p, long time)
{
	unsigned long	dest_time;

	dest_time = get_ms(p->data, false, false) + time;
	while (get_ms(p->data, false, false) < dest_time)
		usleep(100);
}

int	main(int ac, char **av)
{
	t_list	*data;

	data = (t_list *)malloc(sizeof(t_list));
	if ((ac != 5 && ac != 6) || !data)
		return (1);
	if (num_control(av, data) == 1)
		return (1);
	main_thread(data);
	return (0);
}
