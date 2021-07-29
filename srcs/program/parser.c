/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:43:04 by dmangola          #+#    #+#             */
/*   Updated: 2021/07/28 16:43:18 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_init(t_philo *philo)
{
	ft_print_start_msg();
	philo->n_philo = 0;
	philo->todie = 0;
	philo->toeat = 0;
	philo->tosleep = 0;
	philo->n_musteat = 0;
	philo->i = 0;
}

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
	ft_putstr_fd("                   by dmangola                  \n\n", 1);
	ft_putstr_fd("\033[0m", 1);
}

void	ft_print_err_args()
{
	ft_putstr_fd("\033[0;31m***************************************", 2);
	ft_putstr_fd("**********\n", 2);
	ft_putstr_fd("Error: wrong number of arguments. Must be 5 or 6.\n", 2);
	ft_putstr_fd("*************************************************", 2);
	ft_putstr_fd("\033[0m", 2);
}

void	ft_checker(t_philo *philo)
{
	if (!philo->n_philo || !philo->todie || !philo->toeat || !philo->tosleep \
		|| !philo->n_musteat)
	{
		ft_putstr_fd("\033[0;31m****************************************\n", 2);
		ft_putstr_fd("Error: found a char or a sign in argv(s)\n", 2);
		ft_putstr_fd("****************************************\033[0m", 2);
		exit (1);
	}
}

int	ft_parser_checker(int ac, char **av, t_philo *philo)
{
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
