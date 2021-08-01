/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:43:04 by dmangola          #+#    #+#             */
/*   Updated: 2021/07/30 20:00:03 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_print_start_msg(void)
{
	ft_putstr_fd("\033[0;37m\n", 1);
	ft_putstr_fd("         ██╗██████╗ ██╗  ██╗██╗██╗      ██████╗\n", 1);
	ft_putstr_fd("        ██╔╝██╔══██╗██║  ██║██║██║     ██╔═══██╗\n", 1);
	ft_putstr_fd("       ██╔╝ ██████╔╝███████║██║██║     ██║   ██║\n", 1);
	ft_putstr_fd("      ██╔╝  ██╔═══╝ ██╔══██║██║██║     ██║   ██║\n", 1);
	ft_putstr_fd("  ██╗██╔╝   ██║     ██║  ██║██║███████╗╚██████╔╝\n", 1);
	ft_putstr_fd("  ╚═╝╚═╝    ╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ \n", 1);
	ft_putstr_fd("\033[0;32m", 1);
	ft_putstr_fd("               by dmangola && rpaderi             \n\n", 1);
	ft_putstr_fd("\033[0m", 1);
}

void	ft_printerr(int err)
{
	ft_putstr_fd("\033[0;31m*************************************************\n",
		2);
	if (err == 0)
		ft_putstr_fd(ERR_0, 2);
	else if (err == 1)
		ft_putstr_fd(ERR_1, 2);
	else if (err == 2)
		ft_putstr_fd(ERR_2, 2);
	else if (err == 3)
		ft_putstr_fd(ERR_3, 2);
	else if (err == 4)
		ft_putstr_fd(ERR_4, 2);
	else if (err == 5)
		ft_putstr_fd(ERR_5, 2);
	else if (err == 6)
		ft_putstr_fd(ERR_6, 2);
	else if (err == 7)
		ft_putstr_fd(ERR_7, 2);
	else if (err == 8)
		ft_putstr_fd(ERR_8, 2);
	ft_putstr_fd("*************************************************\033[0m\n", 2);
	exit (1);
}

void	ft_init(t_data *philo)
{
	ft_print_start_msg();
	philo->n_philo = 0;
	philo->todie = 0;
	philo->toeat = 0;
	philo->tosleep = 0;
	philo->n_musteat = -1;
	philo->i = 0;
	philo->tid = 0;
	philo->lock = 0;
	philo->shared = 0;
}

void	ft_checker(t_data *philo)
{
	if (philo->n_philo <= 1)
		ft_printerr(7);
	if (philo->todie <= 0)
		ft_printerr(4);
	if (philo->toeat <= 0)
		ft_printerr(5);
	if (philo->tosleep <= 0)
		ft_printerr(6);
	if (philo->n_philo > 200)
		ft_printerr(3);
}

int	ft_parser_checker(int ac, char **av, t_data *philo)
{
	check_string(ac, av);
	philo->n_philo = ft_atoi(av[1]);
	philo->n_forchette = philo->n_philo;
	philo->todie = ft_atoi(av[2]);
	philo->toeat = ft_atoi(av[3]);
	philo->tosleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->n_musteat = ft_atoi(av[5]);
	ft_checker(philo);
	return (0);
}
