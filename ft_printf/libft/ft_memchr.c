/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 07:40:49 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/05 23:47:05 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)s;
	if (n)
	{
		while (i < n)
		{
			if (*str == (char)c)
				return ((void*)str);
			i++;
			str++;
		}
	}
	return (NULL);
}
