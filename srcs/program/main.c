/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:33:58 by dmangola          #+#    #+#             */
/*   Updated: 2021/07/30 20:13:42 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	main(int ac, char **av)
{
	t_data	philo;
	t_data	data;

	ft_init_args(&philo);
	ft_init_philos(&philo);
	if (ac == 5 || ac == 6)
	{
		ft_parser_checker(ac, av, &philo);
		ft_start_philo(&data);
	}
	else
		ft_printerr(0);
	return (0);
}
