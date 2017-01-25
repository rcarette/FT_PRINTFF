/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:20:26 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/24 21:28:38 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long		ft_cast_x(va_list *ap, t_printf *parameter)
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
		//(par->zero == 1) ? ft_print_n(width, '0') : 0;
		(par->zero == 1) ? print_character(width, '0', buff) : 0;
		//(par->zero == 0) ? ft_print_n(width, ' ') : 0;
		(par->zero == 0) ? print_character(width, ' ', buff) : 0;
		//write(1, "0", 1);
		manage_buffer(buff, "0");
	}
	else if (par->subtraction == 1)
	{
		manage_buffer(buff, "0");
		//write(1, "0", 1);
		//ft_print_n(width, ' ');
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
			//ft_print_n(par->width_field - par->precision, ' ');
			print_character(par->precision - 1, '0', buff);
			//ft_print_n(par->precision - 1, '0');
			manage_buffer(buff, "0");
			//write(1, "0", 1);
		}
		else if (par->subtraction == 1)
		{
			manage_buffer(buff, "0");
			//write(1, "0", 1);
			print_character(par->precision - 1, '0', buff);
			//ft_print_n(par->precision - 1, '0');
			//ft_print_n(par->width_field - par->precision, ' ');
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
		//ft_print_n(par->width_field, ' ');
	par->number_of_character += (par->width_field);
}

void	ft_treatement_x_xx_null(t_printf *par, t_buff *buff)
{
	if (par->precision_point == 0)
		no_precision_x_xx_null(par, buff);
	else if (par->precision_point == 1)
		precision_x_xx_null(par, buff);
}

void	no_precision_x_xx(char *tab, t_printf *par, t_buff *buff)
{
	int		ox;
	int		width;

	ox = (par->hash == 1) ? 2 : 0;
	width = (par->width_field - ox - ft_strlen(tab));
	if (par->subtraction == 0)
	{
		//(par->zero == 0) ? ft_print_n(width, ' ') : 0;
		(par->zero == 0) ? print_character(width, ' ', buff) : 0;
		//(par->hash == 1) ? write(1, (par->flags_current == 'x') ? "0x" : "0X", 2) : 0;
		(par->hash == 1) ? manage_buffer(buff, (par->flags_current == 'x') ? "0x" : "0X") : 0;
		//(par->zero == 1) ? ft_print_n(width, '0') : 0;
		(par->zero == 1) ? print_character(width, '0', buff) : 0;
		//write(1, tab, ft_strlen(tab));
		manage_buffer(buff, tab);
	}
	else if (par->subtraction == 1)
	{
		//(par->hash == 1) ? write(1, (par->flags_current == 'x') ? "0x" : "0X", 2) : 0;
		(par->hash == 1) ? manage_buffer(buff, (par->flags_current == 'x') ? "0x" : "0X") : 0;
		manage_buffer(buff, tab);
		//write(1, tab, ft_strlen(tab));
		//ft_print_n(width, ' ');
		print_character(width, ' ', buff);
	}
	par->number_of_character += (ft_strlen(tab) + ox);
	if (width > 0)
		par->number_of_character += (width);
}

void	precision_inf_tab(char *tab, t_printf *par, t_buff *buff)
{
	int		width;
	int		ox;

	ox = (par->hash == 1) ? 2 : 0;
	width = (par->width_field - ox - ft_strlen(tab));
	if (par->subtraction == 0)
	{
		//ft_print_n(width, ' ');
		print_character(width, ' ', buff);
		//(par->hash == 1) ? write(1, (par->flags_current == 'x') ? "0x" : "0X", 2) : 0;
		(par->hash == 1) ? manage_buffer(buff, (par->flags_current == 'x') ? "0x" : "0X") : 0;
		manage_buffer(buff, tab);
		//write(1, tab, ft_strlen(tab));
	}
	else if (par->subtraction == 1)
	{
		//(par->hash == 1) ? write(1, (par->flags_current == 'x') ? "0x" : "0X", 2) : 0;
		(par->hash == 1) ? manage_buffer(buff, (par->flags_current == 'x') ? "0x" : "0X") : 0;
		manage_buffer(buff, tab);
		//write(1, tab, ft_strlen(tab));
		print_character(width, ' ', buff);
		//ft_print_n(width, ' ');
	}
	par->number_of_character += (ft_strlen(tab) + ox);
	if (width > 0)
		par->number_of_character += (width);
}

void	precision_sup_tab(char *tab, t_printf *par, t_buff *buff)
{
	int		ox;
	int		width;

	ox = (par->hash == 1) ? 2 : 0;
	width = (par->width_field - ft_strlen(tab) - ox - (par->precision - ft_strlen(tab)));
	if (par->subtraction == 0)
	{
		//ft_print_n(width, ' ');
		print_character(width, ' ', buff);
		//(par->hash == 1) ? write(1, (par->flags_current == 'x') ? "0x" : "0X", 2) : 0;
		(par->hash == 1) ? manage_buffer(buff, (par->flags_current == 'x') ? "0x" : "0X") : 0;
		print_character(par->precision - ft_strlen(tab), '0', buff);
		//ft_print_n(par->precision - ft_strlen(tab), '0');
		manage_buffer(buff, tab);
		//write(1, tab, ft_strlen(tab));
	}
	else if (par->subtraction == 1)
	{
		//(par->hash == 1) ? write(1, (par->flags_current == 'x') ? "0x" : "0X", 2) : 0;
		(par->hash == 1) ? manage_buffer(buff, (par->flags_current == 'x') ? "0x" : "0X") : 0;
		print_character(par->precision - ft_strlen(tab), '0', buff);
		//ft_print_n(par->precision - ft_strlen(tab), '0');
		//write(1, tab, ft_strlen(tab));
		manage_buffer(buff, tab);
		print_character(width, ' ', buff);
		//ft_print_n(width, ' ');
	}
	par->number_of_character += (ft_strlen(tab) + ox);
	if (width > 0)
		par->number_of_character += (width);
	if (par->precision - ft_strlen(tab) > 0)
		par->number_of_character += (par->precision - ft_strlen(tab));
}

void	ft_convert_x(t_printf *par, va_list *ap, t_buff *buffer)
{
	unsigned long long		value;
	char					*tab;

	value = ft_cast_x(ap, par);
	if (value == 0)
	{
		ft_treatement_x_xx_null(par, buffer);
		return ;
	}
	tab = itoa_base_p(value, (par->flags_current == 'X') ? "0123456789ABCDEF" : "0123456789abcdef");
	if (par->precision_point == 0)
		no_precision_x_xx(tab, par, buffer);
	else if (par->precision_point == 1)
	{
		if (par->precision <= ft_strlen(tab))
			precision_inf_tab(tab, par, buffer);
		else if (par->precision > ft_strlen(tab))
			precision_sup_tab(tab, par, buffer);
	}
	free(tab);
}
