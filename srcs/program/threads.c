/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:05:55 by rpaderi           #+#    #+#             */
/*   Updated: 2021/07/30 20:18:28 by rpaderi          ###   ########.fr       */
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
	while (data->philos->eat_count < data->n_musteat)
	{
		i = 0;
		while (i < data->n_philo)
			pthread_mutex_lock(&data->philos[i++].eat_mutex);
		tot++;
	}
	ft_print_msg();
	pthread_mutex_unlock(data->dead_mutex);
	return ((void *)0);
}

void	*ft_infinite_loop(t_data *data)
{
	data->i++;
	static int i2= 1;
	printf("SORTER %d\n", i2++);
	return ((void *)0);
}

int	ft_start_philo(t_data *data)
{
	int			i;
	pthread_t	tid;

	data->start = get_time();
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
