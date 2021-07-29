/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 13:31:31 by rpaderi           #+#    #+#             */
/*   Updated: 2021/07/29 15:21:02 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h" 

int	check_string(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (check_bychar(av[i]) == 1)
		{
			ft_printerr(1);
			exit (1);
		}
		i++;
	}
	return (0);
}

int	check_bychar(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] >= '0' && c[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}
