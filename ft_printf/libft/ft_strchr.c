/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 16:58:56 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/23 22:38:41 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	char		*s1;

	i = 0;
	s1 = (char *)s;
	while (i < ft_strlen(s) + 1)
	{
		if (*s1 == (char)c)
			return (s1);
		s1++;
		i++;
	}
	return (NULL);
}
