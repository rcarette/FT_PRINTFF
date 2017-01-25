/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 15:02:42 by rcarette          #+#    #+#             */
/*   Updated: 2016/12/12 14:38:19 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*s;

	s = ft_strnew((ft_strlen(ptr) + 1 + size));
	ft_memcpy(s, ptr, (ft_strlen(ptr) + 1));
	ft_bzero(s, '\0');
	free(ptr);
	ptr = NULL;
	return (s);
}
