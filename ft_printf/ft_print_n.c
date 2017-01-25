/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:52:17 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/24 00:08:36 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_n(int x, char character)
{
	int		size;

	size = 0;
	if (x < 0)
		return (0);
	while (x--)
	{
		++size;
		ft_putchar(character);
	}
	return (size);
}
