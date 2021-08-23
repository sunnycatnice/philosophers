/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <rpaderi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:08:23 by rpaderi           #+#    #+#             */
/*   Updated: 2021/08/12 19:32:26 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	clear_state(t_data *state)
{
	int	i;

	if (state->forks_m)
	{
		i = 0;
		while (i < state->n_philo)
			pthread_mutex_destroy(&state->forks_m[i++]);
		free(state->forks_m);
	}
	if (state->philos)
	{
		i = 0;
		while (i < state->n_philo)
		{
			pthread_mutex_destroy(&state->philos[i].mtx);
			pthread_mutex_destroy(&state->philos[i++].eat_m);
		}
		free(state->philos);
	}
	pthread_mutex_destroy(&state->can_print);
	pthread_mutex_destroy(&state->somebody_dead_m);
	return (1);
}

int	exit_error(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	return (1);
}
