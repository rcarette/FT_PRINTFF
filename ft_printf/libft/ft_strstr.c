/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:38:58 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/03 16:19:10 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (*haystack == '\0' && *needle == '\0')
		return ((char *)haystack);
	else if (*haystack != '\0' && *needle == '\0')
		return ((char *)haystack);
	while (haystack[++i] != '\0')
	{
		while (needle[j] == haystack[i + j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			j++;
		}
		j = 0;
	}
	return (NULL);
}
