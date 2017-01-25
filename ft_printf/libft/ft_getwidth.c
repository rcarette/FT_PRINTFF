/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:55:08 by rcarette          #+#    #+#             */
/*   Updated: 2016/12/11 14:33:21 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getwidth(long long int number, int base)
{
	int		len;

	len = 0;
	while (number)
	{
		++len;
		number = (number / base);
	}
	return (len);
}
