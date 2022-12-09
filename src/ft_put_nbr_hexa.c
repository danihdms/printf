/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaydamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:46:36 by dhaydamo          #+#    #+#             */
/*   Updated: 2022/12/09 19:47:16 by dhaydamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_nbr_hexa_min(unsigned long nb, int *len, t_buffer *buffer)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb < 16)
	{
		if (buffer_add(&base[nb], buffer, 1) < 0)
			return (-1);
		(*len)++;
	}
	else
	{
		put_nbr_hexa_min(nb / 16, len, buffer);
		put_nbr_hexa_min(nb % 16, len, buffer);
	}
	return (0);
}

int	put_nbr_hexa_maj(unsigned long nb, int *len, t_buffer *buffer)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nb < 16)
	{
		if (buffer_add(&base[nb], buffer, 1) < 0)
			return (-1);
		(*len)++;
	}
	else
	{
		put_nbr_hexa_maj(nb / 16, len, buffer);
		put_nbr_hexa_maj(nb % 16, len, buffer);
	}
	return (0);
}
