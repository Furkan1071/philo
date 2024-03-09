/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:08:08 by fekiz             #+#    #+#             */
/*   Updated: 2024/03/07 19:11:29 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *str)
{
	long	num;
	long	sign;
	int		i;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - 48;
		i++;
	}
	num *= sign;
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (sign * num);
}

long	get_ms(unsigned long start_time)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_usec / 1000 + tv.tv_sec * 1000) - start_time);
}

int	data_creat(char **str, t_list *data)
{
	data->number_philo = ft_atoi(str[1]);
	data->time_to_die = ft_atoi(str[2]);
	data->time_to_eat = ft_atoi(str[3]);
	data->time_to_sleep = ft_atoi(str[4]);
	data->start_time = get_ms(data->start_time);
	data->eat_count = 0;
	data->must_eat = -1;
	if (str[5])
		data->must_eat = ft_atoi(str[5]);
	if (pthread_mutex_init(&data->eaten, NULL) != 0
		|| pthread_mutex_init(&data->mutex_dead, NULL) != 0)
		return (1);
	return (0);
}

int	num_control(char **str, t_list *data)
{
	int	i;
	int	j;

	j = 1;
	while (str[j])
	{
		i = 0;
		while (str[j][i] && (str[j][i] == 32
			|| (str[j][i] >= 9 && str[j][i] <= 13)))
			i++;
		while (str[j][i])
		{
			if (str[j][i] >= '0' && str[j][i] <= '9')
				i++;
			else
				return (1);
		}
		j++;
	}
	if (data_creat(str, data) == 1)
		return (1);
	return (0);
}
