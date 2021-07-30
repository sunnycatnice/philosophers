/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:30:19 by rpaderi           #+#    #+#             */
/*   Updated: 2021/07/30 19:44:22 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_create_mutex(t_data *philo)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = malloc (sizeof(pthread_mutex_t) * philo->n_forchette);
	while (i < philo->n_forchette)
	{
		if (pthread_mutex_init(&forks[i], NULL) == -1)
		{
			ft_printerr(8);
			exit (1);
		}
		i++;
	}
	printf("Correctly created %d forks (mutex)\n", i);
}
