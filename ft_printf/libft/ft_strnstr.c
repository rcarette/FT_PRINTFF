/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 20:05:27 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/02 20:40:23 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*s1;
	int		i;
	int		j;
	int		size;

	i = -1;
	j = 0;
	size = ft_strlen(little);
	s1 = (char *)big;
	if (size == 0)
		return (s1);
	while (little[++i])
		while (len-- && s1[j])
		{
			if (little[i] == s1[j])
			{
				--size;
				if (size == 0)
					return (s1 + j - i);
				i++;
			}
			j++;
		}
	return (NULL);
}
