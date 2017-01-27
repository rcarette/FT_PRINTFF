/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:05:56 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/27 18:27:33 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <string.h>
#include <locale.h>

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

/*int main(void)
{
	int		x;
	setlocale(LC_ALL, "");
	x = ft_printf("%s %d %p %x %% %S", "bonjour ", 42, &free, 42, L"لحم خنزير");
	printf("%d\n", x);
	x = printf("%s %d %p %x %% %S", "bonjour ", 42, &free, 42, L"لحم خنزير");
	printf("%d\n", x);
	return 0;
}*/
