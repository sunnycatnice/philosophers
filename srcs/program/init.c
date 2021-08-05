/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:56:15 by dmangola          #+#    #+#             */
/*   Updated: 2021/08/05 18:56:17 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h" 

void	ft_init_args(t_data *philo)
{
	ft_print_start_msg();
	philo->n_philo = 0;
	philo->todie = 0;
	philo->toeat = 0;
	philo->tosleep = 0;
	philo->n_musteat = -1;
	philo->i = 0;
	philo->tid = 0;
}

void	ft_init_philos(t_data *data)
{
	short	i;

	i = 0;
	while (i < data->n_philo)
	{
		data->philos[i].is_eating = 0;
		data->philos[i].position = i;
		data->philos[i].lfork = i;
		data->philos[i].rfork = (i + 1) % data->n_philo;
		data->philos[i].eat_count = 0;
		data->philos[i].data = data;
		pthread_mutex_init(&data->philos[i].print_mutex, NULL);
		pthread_mutex_init(&data->philos[i].eat_mutex, NULL);
		pthread_mutex_lock(&data->philos[i].eat_mutex);
		i++;
	}
}
