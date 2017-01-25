/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 12:09:25 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/03 13:12:23 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		size_s;
	int		i;
	char	*str;

	size_s = -1;
	i = -1;
	while (s[++size_s])
		;
	str = (char *)malloc(sizeof(char) * (size_s + 1));
	if (str)
	{
		while (s[++i])
			str[i] = s[i];
		str[i] = '\0';
	}
	else
		return (NULL);
	return (str);
}
