/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 03:59:36 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/24 00:07:39 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_puttab(const char *s1, int size, t_printf *par)
{

	if (par->hash > 0 && par->zero == 0)
		write(1, "0x", 2);
	write(1, s1, size);
	size += (par->hash == 1) ? 2 : 0;
	return (size);
}
