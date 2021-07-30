/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:36:29 by dmangola          #+#    #+#             */
/*   Updated: 2021/07/29 15:23:20 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	is_neg(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || \
		c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

long int	ft_atoi(const char *str)
{
	int			i;
	int			neg;
	long long	result;

	result = 0;
	i = 0;
	while (is_space(str[i]))
		i++;
	neg = is_neg(str[i]);
	if (neg == -1)
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		result = result * 10 + (str[i] - '0');
		i++;
		if (result > 2147483648)
			break ;
	}
	return (neg * (long int)result);
}
