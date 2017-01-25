/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:50:59 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/24 20:57:46 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	stock_character(char character, int x, char *new_string)
{
	int		ite;

	ite = -1;
	while (++ite < x)
		new_string[ite] = character;
}

void	init_buffer(t_buff *buff)
{
	ft_memset(buff->buffer, '\0', (BUFF + 1));
	buff->position = 0;
}

void	read_buffer(t_buff *buff)
{
	write(1, buff->buffer, buff->position);
	init_buffer(buff);
}

void	manage_buffer(t_buff *buff, char *new_string)
{
	int		ite;

	ite = -1;
	if ((buff->position + ft_strlen(new_string)) >= BUFF)
		read_buffer(buff);
	while (++ite < ft_strlen(new_string))
	{
		buff->buffer[buff->position] = new_string[ite];
		++buff->position;
	}
}

int		manage_buffer_character(t_buff *buff, char character)
{
	if ((buff->position + 1) >= BUFF)
		read_buffer(buff);
	buff->buffer[buff->position] = character;
	++buff->position;
	return (1);
}

