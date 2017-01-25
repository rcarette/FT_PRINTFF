/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 18:03:27 by rcarette          #+#    #+#             */
/*   Updated: 2016/12/15 18:05:01 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

DIR		*ft_opendir(char *name)
{
	DIR		*rep;

	rep = NULL;
	if ((rep = opendir(name)))
		return (rep);
	return (NULL);
}
