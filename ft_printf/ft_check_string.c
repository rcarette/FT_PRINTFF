/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 02:45:45 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/24 03:55:46 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_string(const char *format)
{
	if (*format == '\0')
		return (0);
	if (!(ft_strchr(format, '%')))
	{
		write(1, format, ft_strlen(format));
		return (ft_strlen(format));
	}
	return (-1);
}
