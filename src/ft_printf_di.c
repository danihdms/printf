/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaydamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:47:53 by dhaydamo          #+#    #+#             */
/*   Updated: 2022/12/09 19:47:54 by dhaydamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_di(long nb, t_buffer *buffer)
{
	char	tmp;

	if (nb < 0)
	{
		tmp = '-';
		nb *= -1;
		if (buffer_add(&tmp, buffer, 1) < 0)
			return (-1);
	}
	if (nb < 10)
	{
		tmp = nb + 48;
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
