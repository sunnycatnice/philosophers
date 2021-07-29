/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:05:55 by rpaderi           #+#    #+#             */
/*   Updated: 2021/07/29 15:45:11 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/*
**	trylock:
**	1.	not blocking (for avoidind deadlocks)
**	2.	it's the same of lock() but if the mutex is already in possess of another
** 		thread (thus remaining locked), it returns immediatly the control with
**		the resoult EBUSY.
**	return:
**	0		in case of success, thus obtaining mutex propriety.
**	EBUSY	if mutex is opccuppied.
*/
void	*trylock(t_philo *philo)
{
	unsigned long	i;

	pthread_mutex_lock(&g_lock);
	i = 0;
}

void	ft_create_threads(t_philo *philo)
{
	int	i;
	int	error;

	i = 0;
	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		ft_putstr_fd("Mutex init failed.\n", 1);
	}
}
