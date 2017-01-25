/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:16:21 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/24 00:07:24 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr_nb(const char *s1, int size, int choice)
{
	if (choice == 1)
		write(1, "0x", 2);
	write(1, s1, size);
	return ((size + 2));
}
