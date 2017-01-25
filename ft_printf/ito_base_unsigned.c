/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ito_base_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 17:42:39 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/25 01:54:23 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	itoa_base_unsigned(unsigned long long int value, char board[64],
		int base, char *conv)
{
	int		size;

	size = ft_getsize(value, base);
	ft_memset(board, '\0', 64);
	while (value > 0)
	{
		board[--size] = conv[value % base];

		value = (value / base);
	}
}
