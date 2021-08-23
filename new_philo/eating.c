/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <rpaderi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:43:04 by dmangola          #+#    #+#             */
/*   Updated: 2021/08/12 19:32:29 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void
	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mtx);
	philo->is_eating = 1;
	philo->last_eat = get_time();
	philo->limit = philo->last_eat + philo->state->todie;
	show_msg(philo, EAT_MSG);
	usleep(philo->state->toeat * 1000);
	philo->eat_count++;
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->mtx);
	pthread_mutex_unlock(&philo->eat_m);
}
