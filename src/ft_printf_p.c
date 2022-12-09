/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaydamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:49:19 by dhaydamo          #+#    #+#             */
/*   Updated: 2022/12/09 19:51:25 by dhaydamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(void *p, t_buffer *buffer)
{
	int				res;
	int				*len;
	unsigned long	p_long;

	if (!p)
		return (buffer_add("(nil)", buffer, 5));
	len = malloc (sizeof(int));
	if (!len)
		return (0);
	*len = 2;
	p_long = (unsigned long) p;
	if (buffer_add("0x", buffer, 2) < 0)
		return (-1);
	if (put_nbr_hexa_min(p_long, len, buffer) < 0)
		return (-1);
	res = *len;
	free(len);
	return (res);
}
