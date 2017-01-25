/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 11:11:57 by rcarette          #+#    #+#             */
/*   Updated: 2016/12/23 05:57:07 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int		size_s1_s2;
	int					i;

	size_s1_s2 = 0;
	i = 0;
	while ((s1[i] || s2[i]) && size_s1_s2 == 0)
	{
		size_s1_s2 = (s1[i] - s2[i]);
		++i;
	}
	return (size_s1_s2);
}
