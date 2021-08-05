/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <rpaderi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:05:55 by rpaderi           #+#    #+#             */
/*   Updated: 2021/08/05 20:34:10 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"
#include "sys/time.h"

void	*ft_musteat(t_data *data)
{
	t_data	*copy;
	int		i;
	int		tot;

	copy = (t_data *)data;
	tot = 0;
	while (copy->philos->eat_count < copy->n_musteat)
	{
		i = 0;
		while (i < copy->n_philo)
			pthread_mutex_lock(&copy->philos[i++].eat_mutex);
		tot++;
	}
	ft_print_msg(data, MUSTEAT_MSG);
	pthread_mutex_unlock(data->dead_mutex);
	return ((void *)0);
}

void	ft_take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork_mutex[philo->lfork]);
	ft_print_msg(philo, FORK_MSG);
	pthread_mutex_lock(&philo->data->fork_mutex[philo->rfork]);
	ft_print_msg(philo, FORK_MSG);
}

void	*ft_infinite_loop(t_data *data)
{
	t_philo		*philo;
	while(1)
	{
		//prende le forchette
		ft_take_forks(philo);
		//mangia
		//lascia le forchette
		//dormire
		//pensa
	}
	return ((void *)0);
}

int	ft_start_philo(t_data *data)
{
	int			i;
	pthread_t	tid;

	data->start_time = get_time();
	if(data->n_musteat > 0)
	{
		if (pthread_create(&tid, NULL, (void *)ft_musteat, (void*)data) != 0)
			return (1);
		pthread_detach(tid);
	}
	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_create(&tid, NULL, (void *)ft_infinite_loop, (void*)data) != 0)
			return (1);
		pthread_detach(tid);
		//per evitare i deadlock fare uno usleep di 10ms
		sleep_ms(2000);
		i++;
	}
	return (0);
}
