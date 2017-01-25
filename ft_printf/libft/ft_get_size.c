/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:17:39 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/10 18:11:32 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_size(int x, int base)
{
	int		size;

	size = 0;
	while (x > 0)
	{
		++size;
		x = (x / base);
	}
	return (size);
}