/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 21:34:23 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/04 19:37:19 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str_s1;
	unsigned char	*str_s2;

	str_s1 = (unsigned char *)s1;
	str_s2 = (unsigned char *)s2;
	while (n != 0)
	{
		if (*str_s1 > *str_s2)
			return (*str_s1 - *str_s2);
		else if (*str_s1 < *str_s2)
			return (*str_s1 - *str_s2);
		++str_s1;
		++str_s2;
		--n;
	}
	return (0);
}
