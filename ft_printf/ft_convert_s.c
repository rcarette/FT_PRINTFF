/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 20:35:05 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/28 15:51:29 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_read_str(char *tab, int size, t_buff *buff)
{
	int		i;

	i = -1;
	if ((buff->position + size) >= BUFF)
		read_buffer(buff);
	if (size >= BUFF)
	{
		while (++i < size)
			write(1, &tab[i], 1);
		return ;
	}
	else
		while (++i < size)
		{
			buff->buffer[buff->position] = tab[i];
			++buff->position;
		}
}

void	no_precision(char *tab, t_printf *par, t_buff *buff)
{
	int		width;
	int		size;

	size = ft_strlen(tab);
	width = (par->width_field - size);
	if (par->subtraction == 0)
	{
		(par->zero == 1) ? print_character(width, '0', buff) : 0;
		(par->zero == 0) ? print_character(width, ' ', buff) : 0;
		manage_buffer(buff, tab);
	}
	else
	{
		manage_buffer(buff, tab);
		print_character(width, ' ', buff);
	}
	par->number_of_character += (size);
	(width > 0) ? par->number_of_character += (width) : 0;
}

void	apply_precision(char *string, t_printf *par, t_buff *buff, int width)
{
	if (par->precision > ft_strlen(string))
		par->precision = ft_strlen(string);
	if (par->subtraction == 0)
	{
		(par->zero == 1) ? print_character(width, '0', buff) : 0;
		(par->zero == 0) ? print_character(width, ' ', buff) : 0;
		ft_read_str(string, par->precision, buff);
	}
	else if (par->subtraction == 1)
	{
		ft_read_str(string, par->precision, buff);
		print_character(width, ' ', buff);
	}
	par->number_of_character += (par->precision);
	(width > 0) ? par->number_of_character += (width) : 0;
}

void	ft_convert_s(t_printf *par, va_list *ap, t_buff *buff)
{
	char	*string;
	int		width;

	if (par->opt_l == 1)
		ft_convert_ls(par, ap, buff);
	else
	{
		if (!(string = va_arg(*ap, char *)))
			string = "(null)\0";
		if (par->precision_point == 1)
		{
			if (par->precision > ft_strlen(string))
				width = (par->width_field - ft_strlen(string));
			else
				width = (par->width_field - par->precision);
			apply_precision(string, par, buff, width);
		}
		else if (par->precision_point == 0)
			no_precision(string, par, buff);
	}
}
