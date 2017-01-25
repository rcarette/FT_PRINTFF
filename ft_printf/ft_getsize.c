/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:14:35 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/24 00:09:00 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_getsize(unsigned long long nbr, int base)
{
	int		size;

	size = 0;
	while (nbr > 0)
	{
		++size;
		nbr = (nbr / base);
	}
	return (size);
}
