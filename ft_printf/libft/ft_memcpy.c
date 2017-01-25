/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 02:59:02 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/13 21:35:28 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*str_d;
	const char		*str_s;

	str_d = (char *)dest;
	str_s = (char *)src;
	if (n)
		while (n > 0)
		{
			*str_d++ = *str_s++;
			--n;
		}
	return (dest);
}
