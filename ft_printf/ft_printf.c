/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:05:56 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/28 19:40:56 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <string.h>
#include <locale.h>

int		ft_start_printf(const char *format, va_list *ap, int ite, char *t)
{
	int			size;
	t_printf	*parameter;
	t_buff		buff;

	init_buffer(&buff);
	size = 0;
	parameter = ft_init_t_printf();
	while (format[++ite])
	{
		t = (char *)&format[ite];
		if (format[ite] != '%')
			size += manage_buffer_character(&buff, format[ite]);
		else
		{
			ite += ft_parsing(++t, ap, parameter, &buff);
			size += parameter->number_of_character;
			free(parameter);
			parameter = ft_init_t_printf();
		}
	}
	write(1, buff.buffer, buff.position);
	free(parameter);
	return (size);
}

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
	size = ft_start_printf(format, &ap, -1, NULL);
	va_end(ap);
	return (size);
}

/*int main(void)
{
	char c = 'r';
	char *str = "dede";
	int 	nbr = 4444444;
	int		x;
	setlocale(LC_ALL, "");
	x = printf("|%012d| |%%| |%D| |% i| |%-05d| |%+4d| |%+9.6d| |%#-09.0d| |%12d|\n", nbr, 5, -4, 8, 3, 32, 15, -21);
	printf("%d\n", x);
	x = ft_printf("|%012d| |%%| |%D| |% i| |%-05d| |%+4d| |%+9.6d| |%#-09.0d| |%12d|\n", nbr, 5, -4, 8, 3, 32, 15, -21);
	printf("%d\n", x);
	printf("==========================================\n");
	x = printf("|%+3ld| |%-#3.6hd| |%0.0jd| |%+06.12hhd| |%-07lld| |%#-7.3zd|\n", 5, 676, 8, 123456789, -543, 9876); 
	printf("%d\n", x);
	x = ft_printf("|%+3ld| |%-#3.6hd| |%0.0jd| |%+06.12hhd| |%-07lld| |%#-7.3zd|\n", 5, 676, 8, 123456789, -543, 9876); 
	printf("%d\n", x);
	printf("==========================================\n");
	x = ft_printf("|%+3lD| |%-#3.6hD| |%0.0jD| |%+06.12hhD| |%-07llD| |%#-7.3zD|\n", -435, -676, -47478, -123456789, -543, -9876); 
	printf("%d\n", x);
	x = printf("|%+3lD| |%-#3.6hD| |%0.0jD| |%+06.12hhD| |%-07llD| |%#-7.3zD|\n", -435, -676, -47478, -123456789, -543, -9876); 
	printf("%d\n", x);
	x = ft_printf("|%p| |%016p| |%-16p| |%14.4p| |%p|\n", str, str, nbr, c);
	printf("%d\n", x);
	x = printf("|%p| |%016p| |%-16p| |%14.4p| |%p|\n", str, str, nbr, c);
	printf("%d\n", x);

	x = ft_printf("|%+3lp| |%-#3.6hp| |%0.0jp| |%+06.12hhp| |%-07llp| |%#-7.3zp|\n", str, nbr, c, c, nbr, str); 
	printf("%d\n", x);
	x = printf("|%+3lp| |%-#3.6hp| |%0.0jp| |%+06.12hhp| |%-07llp| |%#-7.3zp|\n", str, nbr, c, c, nbr, str); 
	printf("%d\n", x);

	x = ft_printf("|%+05.12c| |%+ 4c| |%13c| |%-07c| |%012c| |%#1c|\n", c, 'a', 'b', 'c', 'd', 'e');
	printf("%d\n", x);
	x = printf("|%+05.12c| |%+ 4c| |%13c| |%-07c| |%012c| |%#1c|\n", c, 'a', 'b', 'c', 'd', 'e');
	printf("%d\n", x);

	x = ft_printf("|%+3lc| |%-#3.6hc| |%0.0jc| |%+06.12hhc| |%-07llc| |%#-7.3zc|\n", 'a', 'b', 'c', 'd', 'e', 'f'); 
	printf("%d\n", x);
	x = printf("|%+3lc| |%-#3.6hc| |%0.0jc| |%+06.12hhc| |%-07llc| |%#-7.3zc|\n", 'a', 'b', 'c', 'd', 'e', 'f'); 
	printf("%d\n", x);
	x = ft_printf("|%#0.23s| |%3s| |%04s| |%-04s| |%+011s| |%07.2s| |%-8.4s|\n", "salut", "42", "32", "wq", "43", "salut", "123456789");
	printf("%d\n", x);
	x = printf("|%#0.23s| |%3s| |%04s| |%-04s| |%+011s| |%07.2s| |%-8.4s|\n", "salut", "42", "32", "wq", "43", "salut", "123456789");
	printf("%d\n", x);

	x = ft_printf("|%-#3.6hs| |%0.0js| |%+06.12hhs| |%-07lls| |%#-7.3zs|\n", "qwerty", "qwerty", "qwerty", "qwerty", "qwerty"); 
	printf("%d\n", x);
	x = printf("|%-#3.6hs| |%0.0js| |%+06.12hhs| |%-07lls| |%#-7.3zs|\n", "qwerty", "qwerty", "qwerty", "qwerty", "qwerty"); 
	printf("%d\n", x);

	x = ft_printf("%x%x%x%x%x%x%x\n", 1, 4, 10, 100, 1000, 10000, 99999999);
	printf("%d\n", x);
	x = printf("%x%x%x%x%x%x%x\n", 1, 4, 10, 100, 1000, 10000, 99999999);
	printf("%d\n", x);
	x = ft_printf("|%x| |%#08x| |%#-08x| |%#x| |%#08.0X| |%#-06x| |%++++++-0-++++06X| |%9.6x|\n", 4, 43, 23, 954, 971, 34, 31, 23);
	printf("%d\n", x);
	x = printf("|%x| |%#08x| |%#-08x| |%#x| |%#08.0X| |%#-06x| |%++++++-0-++++06X| |%9.6x|\n", 4, 43, 23, 954, 971, 34, 31, 23);
	printf("%d\n", x);

	x = ft_printf("|%+3lx| |%8hhx| |%-#3.6hx| |%0.0jx| |%+06.12hhx| |%-07llx| |%#-7.3zx|\n", 5, 7843 ,43, 548, 123456789, 123, 9876);
	printf("%d\n", x);
	x = printf("|%+3lx| |%8hhx| |%-#3.6hx| |%0.0jx| |%+06.12hhx| |%-07llx| |%#-7.3zx|\n", 5, 7843 ,43, 548, 123456789, 123, 9876); 
	printf("%d\n", x);

	x = ft_printf("|%+3lX| |%-#3.6hX| |%0.0jX| |%+06.12hhX| |%-07llX| |%#-7.3zX|\n", -435, -676, -47478, -123456789, -543, -9876); 
	printf("%d\n", x);
	x = printf("|%+3lX| |%-#3.6hX| |%0.0jX| |%+06.12hhX| |%-07llX| |%#-7.3zX|\n", -435, -676, -47478, -123456789, -543, -9876); 
	printf("%d\n", x);
	x = ft_printf("%x%x%x%x%x\n", 1, 100, 999, 42, 999988888);
	printf("%d\n", x);
	x = printf("%x%x%x%x%x\n", 1, 100, 999, 42, 999988888);
	printf("%d\n", x);

	x = ft_printf("|%012u| |%09U| |%#-05u| |% .20u| |%-09.5u| |%+11u|\n", nbr, +21, 5, -4, 8, 3);
	printf("%d\n", x);
	x = printf("|%012u| |%09U| |%#-05u| |% .20u| |%-09.5u| |%+11u|\n", nbr, +21, 5, -4, 8, 3);
	printf("%d\n", x);

	x = ft_printf("|%+3lu| |%-#3.6hu| |%0.0ju| |%+06.12hhu| |%-07llu| |%#-7.3zu|\n", 5, 63, 8, 123456789, 543, 9876); 
	printf("%d\n", x);
	x = printf("|%+3lu| |%-#3.6hu| |%0.0ju| |%+06.12hhu| |%-07llu| |%#-7.3zu|\n", 5, 63, 8, 123456789, 543, 9876); 
	printf("%d\n", x);

	x = ft_printf("|%+3lU| |%-#3.6hU| |%0.0jU| |%+06.12hhU| |%-07llU| |%#-7.3zU|\n", -435, -676, -47478, -123456789, -543, -876); 
	printf("%d\n", x);
	x = printf("|%+3lU| |%-#3.6hU| |%0.0jU| |%+06.12hhU| |%-07llU| |%#-7.3zU|\n", -435, -676, -47478, -123456789, -543, -876); 
	printf("%d\n", x);

	x = ft_printf("%hhu, %hhu\n", 0, UCHAR_MAX);
	printf("%d\n", x);
	x = printf("%hhu, %hhu\n", 0, UCHAR_MAX);
	printf("%d\n", x);
	return 0;
}*/
