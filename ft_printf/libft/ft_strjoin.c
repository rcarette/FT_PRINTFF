/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 11:52:42 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/02 21:32:43 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if ((s1 != NULL && s2 == NULL))
	{
		if (!(str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
			return (NULL);
		ft_strcpy(str, s1);
	}
	else if ((s1 == NULL && s2 != NULL))
	{
		if (!(str = (char *)malloc(sizeof(char) * ft_strlen(s2) + 1)))
			return (NULL);
		ft_strcpy(str, s2);
	}
	else if ((s1 == NULL && s2 == NULL))
		return (NULL);
	else
	{
		str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
		if (str == NULL)
			return (NULL);
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
	}
	return (str);
}
