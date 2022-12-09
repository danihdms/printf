/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaydamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:47:26 by dhaydamo          #+#    #+#             */
/*   Updated: 2022/12/09 19:47:28 by dhaydamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	buffer_add(const char *str, t_buffer *buffer, int len)
{
	if (!str)
		return (-1);
	while (len > 0)
	{
		if (buffer->pos == BUFF_SIZE)
			empty_buffer(buffer);
		buffer->buff[buffer->pos] = *str;
		str++;
		len--;
		buffer->pos++;
	}
	return (0);
}

int	empty_buffer(t_buffer *buffer)
{
	int	written_char;

	written_char = write(1, buffer->buff, buffer->pos);
	if (written_char < 0)
		return (-1);
	buffer->pos = 0;
	buffer->written += written_char;
	return (0);
}
