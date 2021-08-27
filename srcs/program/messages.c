/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <rpaderi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:56:15 by dmangola          #+#    #+#             */
/*   Updated: 2021/08/12 19:32:28 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static char	*get_message(int msg)
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
		return ("Everyone eat ... stopping\n");
	return (" died 💀\n");
}

void	show_msg(t_philo *philo, int type)
{
	static int	done = 0;

	pthread_mutex_lock(&philo->state->can_print);
	if (!done)
	{
		if (type == MUSTEAT_MSG)
		{
			printf("Everyone eat %d times. Stopping! ✅", \
				philo->state->n_musteat);
			ft_finish();
		}
		else
		{
			ft_putnbr_fd(get_time() - philo->state->start, 1);
			ft_putstr_fd("\tphilo\t", 1);
			if (type != MUSTEAT_MSG)
				ft_putnbr_fd(philo->pos + 1, 1);
			if (type >= DEAD_MSG)
				done = 1;
			else
				write(1, get_message(type), ft_strlen(get_message(type)));
		}
	}
	pthread_mutex_unlock(&philo->state->can_print);
}
