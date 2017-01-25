/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:05:56 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/25 05:46:06 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <string.h>

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			size;

	if (!format)
		exit(0);
	if (ft_strlen(format) == 1 && *format == '%')
		return (0);
	if ((size = check_string(format)) >= 0)
		return (size);
	va_start(ap, format);
	size = ft_start_printf(format, &ap);
	va_end(ap);
	return (size);
}

/*int main(int argc, const char *argv[])
{
	int		x;
	x = ft_printf("{%05.Z}\n");
	printf("%d\n", x); 
	x = printf("{%05.Z}\n");
	printf("%d\n", x);
	return 0;
}*/
