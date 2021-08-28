/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <rpaderi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:56:15 by dmangola          #+#    #+#             */
/*   Updated: 2021/08/14 16:47:53 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

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

static void	ft_print_time(t_philo *philo)
{
	ft_putstr_fd("\033[1;33m", 1);
	ft_putnbr_fd(get_time() - philo->state->start, 1);
	ft_putstr_fd("\033[0m", 1);
}

void	show_msg(t_philo *philo, int type)
{
	static int	done = 0;

	pthread_mutex_lock(&philo->state->can_print);
	if (!done)
	{
		ft_print_time(philo);
		write(1, "\t", 1);
		if (type != MUSTEAT_MSG)
		{
			ft_putstr_fd("\033[1;91m", 1);
			ft_putnbr_fd(philo->pos + 1, 1);
			ft_putstr_fd("\033[0m", 1);
		}
		if (type == MUSTEAT_MSG)
			printf("Everyone ate at least %d times. Stopping! ✅\n", \
				philo->state->n_musteat);
		else
			write(1, get_message(type), ft_strlen(get_message(type)));
		if (type >= DEAD_MSG)
		{
			done = 1;
			ft_finish();
		}
	}
	pthread_mutex_unlock(&philo->state->can_print);
}
