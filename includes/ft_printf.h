/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaydamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:53:27 by dhaydamo          #+#    #+#             */
/*   Updated: 2022/12/09 19:54:23 by dhaydamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE 64

typedef struct s_buffer
{
	size_t	pos;
	size_t	written;
	char	buff[BUFF_SIZE];
}	t_buffer;

int	ft_printf(const char *str, ...);
int	print_s(char *str, t_buffer *buffer);
int	print_c(char c, t_buffer *buffer);
int	buffer_add(const char *str, t_buffer *buffer, int len);
int	empty_buffer(t_buffer *buffer);
int	put_nbr_hexa_min(unsigned long nb, int *len, t_buffer *buffer);
int	put_nbr_hexa_maj(unsigned long nb, int *len, t_buffer *buffer);
int	print_p(void *p, t_buffer *buffer);
int	print_x(unsigned int c, char type, t_buffer *buffer);
int	print_u(unsigned long c, t_buffer *buffer);
int	print_di(long c, t_buffer *buffer);

#endif
