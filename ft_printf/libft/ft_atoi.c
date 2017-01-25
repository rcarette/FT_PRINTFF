/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 12:05:56 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/05 15:51:11 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int					negative;
	long long			result;
	int					size;

	size = *nptr;
	if (size < 0)
		return (0);
	negative = 1;
	result = 0;
	while (*nptr <= 32)
		nptr++;
	if (*nptr == '-')
	{
		nptr++;
		negative = -1;
	}
	if ((*nptr == '-' || *nptr == '+') && negative == -1)
		return (0);
	(*nptr == '+') ? nptr++ : 0;
	while (*nptr >= '0' && *nptr <= '9')
		result = ((result * 10) + *nptr++ - '0');
	return (result * negative);
}
