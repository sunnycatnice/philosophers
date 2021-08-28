/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <rpaderi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:27:25 by dmangola          #+#    #+#             */
/*   Updated: 2021/08/12 18:50:34 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	ft_putstr_fd(char const *s, int fd)
{
	while (*s)
		ft_putchar_fd(*s++, fd);
}

void	ft_putstr_star_fd(char *s, int fd)
{
	char *s_copy;

	s_copy = s;
	ft_printstars(s);
	while (*s)
		ft_putchar_fd(*s++, fd);
	ft_printstars(s_copy);
}
