/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaydamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:44:31 by dhaydamo          #+#    #+#             */
/*   Updated: 2022/12/09 19:44:33 by dhaydamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(char c, t_buffer *buffer)
{
	if (buffer_add(&c, buffer, 1) < 0)
		return (-1);
	return (0);
}

int	print_s(char *str, t_buffer *buffer)
{
	if (!str)
	{
		if (buffer_add("(null)", buffer, 6) < 0)
			return (-1);
	}
	else if (buffer_add(str, buffer, ft_strlen(str)) < 0)
		return (-1);
	return (0);
}
