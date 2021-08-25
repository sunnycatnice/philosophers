/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <rpaderi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:46:51 by rpaderi           #+#    #+#             */
/*   Updated: 2021/08/12 18:50:23 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

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
