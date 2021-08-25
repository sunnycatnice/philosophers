/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <rpaderi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:51:46 by rpaderi           #+#    #+#             */
/*   Updated: 2021/08/12 19:32:29 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void
	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->state->forks_m[philo->lfork]);
	show_msg(philo, FORK_MSG);
	pthread_mutex_lock(&philo->state->forks_m[philo->rfork]);
	show_msg(philo, FORK_MSG);
}

void
	clean_forks(t_philo *philo)
{
	show_msg(philo, SLEEP_MSG);
	pthread_mutex_unlock(&philo->state->forks_m[philo->lfork]);
	pthread_mutex_unlock(&philo->state->forks_m[philo->rfork]);
	usleep(philo->state->tosleep * 1000);
}