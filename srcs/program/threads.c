/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:05:55 by rpaderi           #+#    #+#             */
/*   Updated: 2021/07/30 19:01:46 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"
#include "sys/time.h"

/*
**	trylock:
**	1.	not blocking (for avoidind deadlocks)
**	2.	it's the same of lock() but if the mutex is already in possess of another
** 		thread (thus remaining locked), it returns immediatly the control with
**		the resoult EBUSY.
**	return:
**	0		in case of success, thus obtaining mutex propriety.
**	EBUSY	if mutex is opccuppied.

void	*trylock(t_philo *data)
{
	unsigned long	i;

	pthread_mutex_lock(&g_lock);
	i = 0;
}

void	ft_create_threads(t_data *data)
{
	int	i;
	int	error;

	i = 0;
	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		ft_putstr_fd("Mutex init failed.\n", 1);
	}
}

static void *print_and_pexit(t_data *data, void *p)
{
	printf("Valore ricevuto come argomento nell'inizializzazione: %i\n", * (int*)p);
	return ((int)pthread_exit(&data->i0));
}
*/

void	*ft_musteat(t_data *data)
{
	data->n_musteat--;
	printf("\nMUST EAT %d\n", data->n_musteat);
	return ((void *)0);
}

void	*ft_sorter(t_data *data)
{
	data->i++;
	static int i2= 1;
	printf("SORTER %d\n", i2++);
	return ((void *)0);
}

int	ft_start_threads(t_data *data)
{
	int			i;
	pthread_t	tid;

	if(data->n_musteat > 0)
	{
		if (pthread_create(&tid, NULL, (void *)ft_musteat, (void*)data) != 0)
			return (1);
		pthread_detach(tid);
	}
	data->start = get_time();
	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_create(&tid, NULL, (void *)ft_sorter, (void*)data) != 0)
			return (1);
		pthread_detach(tid);
		usleep(100);
		i++;
	}
	return (0);
}
