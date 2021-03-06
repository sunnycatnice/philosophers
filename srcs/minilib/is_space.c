/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <rpaderi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:35:32 by rpaderi           #+#    #+#             */
/*   Updated: 2021/08/12 18:50:28 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || \
		c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}
