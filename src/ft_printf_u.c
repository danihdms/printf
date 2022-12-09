/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaydamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:47:42 by dhaydamo          #+#    #+#             */
/*   Updated: 2022/12/09 19:47:44 by dhaydamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(unsigned long nb, t_buffer *buffer)
{
	char	tmp;

	if (nb < 10)
	{
		tmp = nb + '0';
		if (buffer_add(&tmp, buffer, 1) < 0)
			return (-1);
	}
	else
	{
		print_u(nb / 10, buffer);
		print_u(nb % 10, buffer);
	}
	return (0);
}
