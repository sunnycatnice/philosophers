/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:08:53 by dmangola          #+#    #+#             */
/*   Updated: 2021/08/02 14:09:01 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static char *get_msg(int msg)
{
	if (msg == EAT_MSG)
		return (" is eating 🍝\n");
	else if (msg == SLEEP_MSG)
		return (" is sleeping 😴\n");
	else if (msg == FORK_MSG)
		return (" has taken a fork 🍴\n");
	else if (msg == THINKING_MSG)
		return (" is thinking 💭\n");
	else if (msg == MUSTEAT_MSG)
		return ("Must eat count reached... stopping\n");
	return (" died\n");
}

void ft_print_msg(t_data *data, int msg)
{
	static int	ok;

	pthread_mutex_lock(&data->philos->print_mutex);
	if(!ok)
	{
		ft_putnbr_fd(get_time() - data->start_time, 1);
		write(1, "\t", 1);
		if (msg != MUSTEAT_MSG)
			ft_putnbr_fd(data->philos->position + 1, 1 );
		if (msg >= DIED_MSG)
			ok = 1;
		//parser messaggi
	}
	pthread_mutex_unlock(&data->philos->print_mutex);
}