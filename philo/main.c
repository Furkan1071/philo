/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:11:13 by fekiz             #+#    #+#             */
/*   Updated: 2024/03/07 19:08:49 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_list	*data;

	data = (t_list *)malloc(sizeof(t_list));
	if ((ac != 5 && ac != 6) || !data)
		return (1);
	if (num_control(av, data) == 1)
		return (1);
	if (philo_creates(data) == 1)
		return (1);
	if (start_threads(data) == 1)
		return (1);
	main_thread(data);
	return (0);
}
