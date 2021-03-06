/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:20:26 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/28 17:22:52 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ULL		ft_cast_x(va_list *ap, t_printf *parameter)
{
	unsigned long long value;

	if (parameter->opt_h == 1)
		value = (unsigned short)va_arg(*ap, unsigned long);
	else if (parameter->opt_hh == 1)
		value = (unsigned char)va_arg(*ap, unsigned long);
	else if (parameter->opt_l == 1)
		value = (unsigned long)va_arg(*ap, unsigned long);
	else if (parameter->opt_ll == 1)
		value = (unsigned long long)va_arg(*ap, unsigned long long);
	else if (parameter->opt_j == 1)
		value = (uintmax_t)va_arg(*ap, unsigned long);
	else if (parameter->opt_z == 1)
		value = (size_t)va_arg(*ap, unsigned long);
	else
		value = (unsigned int)va_arg(*ap, unsigned long long);
	return (value);
}

void	no_precision_x_xx_null(t_printf *par, t_buff *buff)
{
	int		width;

	width = (par->width_field - 1);
	if (par->subtraction == 0)
	{
		(par->zero == 1) ? print_character(width, '0', buff) : 0;
		(par->zero == 0) ? print_character(width, ' ', buff) : 0;
		manage_buffer(buff, "0");
	}
	else if (par->subtraction == 1)
	{
		manage_buffer(buff, "0");
		print_character(width, ' ', buff);
	}
	par->number_of_character += (1);
	if (width > 0)
		par->number_of_character += (width);
}

void	precision_x_xx_null(t_printf *par, t_buff *buff)
{
	if (par->precision >= 1)
	{
		if (par->subtraction == 0)
		{
			print_character(par->width_field - par->precision, ' ', buff);
			print_character(par->precision - 1, '0', buff);
			manage_buffer(buff, "0");
		}
		else if (par->subtraction == 1)
		{
			manage_buffer(buff, "0");
			print_character(par->precision - 1, '0', buff);
			print_character(par->width_field - par->precision, ' ', buff);
		}
		par->number_of_character += (1);
		if ((par->width_field - par->precision) > 0)
			par->number_of_character += (par->width_field - par->precision);
		if ((par->precision - 1) > 0)
			par->number_of_character += (par->precision - 1);
		return ;
	}
	else if (par->precision < 1)
		print_character(par->width_field, ' ', buff);
	par->number_of_character += (par->width_field);
}

void	ft_treatement_x_xx_null(t_printf *par, t_buff *buff)
{
	if (par->precision_point == 0)
		no_precision_x_xx_null(par, buff);
	else if (par->precision_point == 1)
		precision_x_xx_null(par, buff);
}

void	no_precision_x(char *tab, t_printf *par, t_buff *buff)
{
	int		ox;
	int		width;

	ox = (par->hash == 1) ? 2 : 0;
	width = (par->width_field - ox - ft_strlen(tab));
	if (par->subtraction == 0)
	{
		(par->zero == 0) ? print_character(width, ' ', buff) : 0;
		if (par->hash == 1)
			manage_buffer(buff, (par->flags_current == 'x') ? "0x" : "0X");
		(par->zero == 1) ? print_character(width, '0', buff) : 0;
		manage_buffer(buff, tab);
	}
	else if (par->subtraction == 1)
	{
		if (par->hash == 1)
			manage_buffer(buff, (par->flags_current == 'x') ? "0x" : "0X");
		manage_buffer(buff, tab);
		print_character(width, ' ', buff);
	}
	par->number_of_character += (ft_strlen(tab) + ox);
	(width > 0) ? par->number_of_character += (width) : 0;
}

void	precision_inf(char *tab, t_printf *par, t_buff *buff)
{
	int		width;
	int		ox;

	ox = (par->hash == 1) ? 2 : 0;
	width = (par->width_field - ox - ft_strlen(tab));
	if (par->subtraction == 0)
	{
		print_character(width, ' ', buff);
		if (par->hash == 1)
			manage_buffer(buff, (par->flags_current == 'x') ? "0x" : "0X");
		manage_buffer(buff, tab);
	}
	else if (par->subtraction == 1)
	{
		if (par->hash == 1)
			manage_buffer(buff, (par->flags_current == 'x') ? "0x" : "0X");
		manage_buffer(buff, tab);
		print_character(width, ' ', buff);
	}
	par->number_of_character += (ft_strlen(tab) + ox);
	(width > 0) ? par->number_of_character += (width) : 0;
}

void	sub_preci_null(t_printf *par, t_buff *buff, char *tab, int width)
{
	print_character(width, ' ', buff);
	if (par->hash == 1)
		manage_buffer(buff, (par->flags_current == 'x') ? "0x" : "0X");
	print_character(par->precision - ft_strlen(tab), '0', buff);
	manage_buffer(buff, tab);
}

void	precision_sup(char *tab, t_printf *par, t_buff *buff)
{
	int		ox;
	int		width;

	ox = (par->hash == 1) ? 2 : 0;
	width = (par->width_field - ft_strlen(tab) - ox -
			(par->precision - ft_strlen(tab)));
	if (par->subtraction == 0)
		sub_preci_null(par, buff, tab, width);
	else if (par->subtraction == 1)
	{
		if (par->hash == 1)
			manage_buffer(buff, (par->flags_current == 'x') ? "0x" : "0X");
		print_character(par->precision - ft_strlen(tab), '0', buff);
		manage_buffer(buff, tab);
		print_character(width, ' ', buff);
	}
	par->number_of_character += (ft_strlen(tab) + ox);
	(width > 0) ? par->number_of_character += (width) : 0;
	if (par->precision - ft_strlen(tab) > 0)
		par->number_of_character += (par->precision - ft_strlen(tab));
}

void	ft_convert_x(t_printf *par, va_list *ap, t_buff *buffer)
{
	unsigned long long		value;
	char					*tab;
	static char				*x = "0123456789abcdef";
	static char				*xx = "0123456789ABCDEF";

	value = ft_cast_x(ap, par);
	if (value == 0)
	{
		ft_treatement_x_xx_null(par, buffer);
		return ;
	}
	tab = itoa_base_p(value, (par->flags_current == 'X') ? xx : x);
	if (par->precision_point == 0)
		no_precision_x(tab, par, buffer);
	else if (par->precision_point == 1)
	{
		if (par->precision <= ft_strlen(tab))
			precision_inf(tab, par, buffer);
		else if (par->precision > ft_strlen(tab))
			precision_sup(tab, par, buffer);
	}
	free(tab);
}
