/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaydamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:51:46 by dhaydamo          #+#    #+#             */
/*   Updated: 2022/12/09 19:52:05 by dhaydamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(unsigned int c, char type, t_buffer *buffer)
{
	int	res;
	int	*len;

	len = malloc (sizeof(int));
	if (!len)
		return (0);
	*len = 0;
	if (type == 'x')
		put_nbr_hexa_min(c, len, buffer);
	else
		put_nbr_hexa_maj(c, len, buffer);
	res = *len;
	free(len);
	return (res);
}
