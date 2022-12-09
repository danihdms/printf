/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaydamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:44:45 by dhaydamo          #+#    #+#             */
/*   Updated: 2022/12/09 19:52:49 by dhaydamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

static void	create_buffer(t_buffer *buffer)
{
	buffer->pos = 0;
	buffer->written = 0;
}

static int	convert(char type, va_list args, t_buffer *buffer)
{
	if (type == 'c')
		return (print_c(va_arg(args, int), buffer));
	if (type == 's')
		return (print_s(va_arg(args, char *), buffer));
	if (type == 'p')
		return (print_p(va_arg(args, void *), buffer));
	if (type == 'i' || type == 'd')
		return (print_di(va_arg(args, int), buffer));
	if (type == 'u')
		return (print_u(va_arg(args, unsigned int), buffer));
	if (type == 'x' || type == 'X')
		return (print_x(va_arg(args, unsigned int), type, buffer));
	if (type == '%')
		if (buffer_add("%", buffer, 1) < 0)
			return (-1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	va_list		args;
	t_buffer	buffer;

	i = 0;
	create_buffer(&buffer);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			convert(str[i], args, &buffer);
		}
		else
		{
			buffer_add(&str[i], &buffer, 1);
		}
		i++;
	}
	va_end(args);
	empty_buffer(&buffer);
	return (buffer.written);
}
