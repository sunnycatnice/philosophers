/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:33:58 by dmangola          #+#    #+#             */
/*   Updated: 2021/07/29 13:59:45 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;

	ft_init(&philo);
	if (ac == 5 || ac == 6)
		ft_parser_checker(ac, av, &philo);
	else
		ft_printerr(0);
	return (0);
}
