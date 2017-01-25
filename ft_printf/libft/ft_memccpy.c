/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 05:13:20 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/03 13:03:00 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*str_d;
	char		*str_s;
	size_t		i;

	str_d = (char *)dest;
	str_s = (char *)src;
	i = 0;
	while (i < n)
	{
		str_d[i] = str_s[i];
		if (str_s[i] == (char)c)
			return ((void*)&str_d[i + 1]);
		i++;
	}
	return (NULL);
}
