/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <rpaderi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:08:53 by dmangola          #+#    #+#             */
/*   Updated: 2021/08/09 16:19:27 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static char	*get_msg(int msg)
{
	if (msg == FORK_MSG)
		return (" has taken a fork 🍴\n");
	else if (msg == EAT_MSG)
		return (" is eating 🍝\n");
	else if (msg == SLEEP_MSG)
		return (" is sleeping 😴\n");
	else if (msg == THINKING_MSG)
		return (" is thinking 💭\n");
	else if (msg == MUSTEAT_MSG)
		return ("Must eat count reached... stopping\n");
	return (" died\n");
}

void	ft_print_msg(t_data *data, int msg)
{
	static int	end;

	pthread_mutex_lock(&data->philos->print_mutex);
<<<<<<< HEAD
	if (!ok)
=======
	if (!end)
>>>>>>> 25c249df296660d8402cde6fd7ca0a0709af5a0a
	{
		ft_putnbr_fd(get_time() - data->start_time, 1);
		write(1, "\t", 1);
		if (msg != MUSTEAT_MSG)
			ft_putnbr_fd(data->philos->position + 1, 1 );
<<<<<<< HEAD
		if (msg >= DIED_MSG)
			ok = 1;
		write(1, get_msg(msg), ft_strlen(get_msg(msg)));
=======
		if (msg >= DEAD_MSG)
			end = 1;
		ft_putstr_fd(get_msg(msg), 1);
>>>>>>> 25c249df296660d8402cde6fd7ca0a0709af5a0a
	}
	pthread_mutex_unlock(&data->philos->print_mutex);
}
