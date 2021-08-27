/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <rpaderi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:43:04 by dmangola          #+#    #+#             */
/*   Updated: 2021/08/14 17:15:14 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

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
	ft_putstr_fd("               by dmangola && rpaderi            \n\n", 1);
	ft_putstr_fd("\033[0m", 1);
}

void	ft_checker(t_data *state)
{
	if (state->n_philo <= 0)
		ft_printerr(7);
	if (state->todie <= 60)
		ft_printerr(4);
	if (state->toeat <= 60)
		ft_printerr(5);
	if (state->tosleep <= 60)
		ft_printerr(6);
	if (state->n_philo > 200)
		ft_printerr(3);
}

int	ft_parser_checker(int ac, char const **av, t_data *state)
{
	check_string(ac, av);
	state->n_philo = ft_atoi(av[1]);
	state->n_forchette = state->n_philo;
	state->todie = ft_atoi(av[2]);
	state->toeat = ft_atoi(av[3]);
	state->tosleep = ft_atoi(av[4]);
	if (ac == 6)
		state->n_musteat = ft_atoi(av[5]);
	ft_checker(state);
	return (0);
}
