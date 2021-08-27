/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <rpaderi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:38:03 by rpaderi           #+#    #+#             */
/*   Updated: 2021/08/12 19:09:29 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

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
