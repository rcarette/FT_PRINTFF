/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 09:30:22 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/02 08:09:36 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = -1;
	if (s == NULL)
		return (NULL);
	str = ft_memalloc((ft_strlen(s) + 1), sizeof(char));
	if (str)
	{
		while (s[++i])
			str[i] = (*f)(i, s[i]);
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
