/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:25:08 by rpaderi           #+#    #+#             */
/*   Updated: 2021/07/30 20:19:49 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_philo(t_data *data, pthread_t tid)
{
	int	ph;

	ph = 0;

	if(data->n_musteat > 0)
		printf("must_eat: ˆ%d", data->n_musteat);
	return (0);
}
