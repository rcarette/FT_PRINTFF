/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:18:58 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/24 22:48:42 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long int		ft_cast_u(va_list *ap, t_printf *par)
{
	unsigned long long int value;
	if (par->opt_hh == 1)
		value = (unsigned char)va_arg(*ap, int);
	else if (par->opt_h == 1)
		value = (unsigned short)va_arg(*ap, int);
	else if (par->opt_l == 1)
		value = (unsigned long)va_arg(*ap, unsigned long);
	else if (par->opt_ll == 1)
		value = (unsigned long long)va_arg(*ap, unsigned long long);
	else if (par->opt_j == 1)
		value = (uintmax_t)va_arg(*ap, uintmax_t);
	else if (par->opt_z == 1)
		value = (size_t)va_arg(*ap, size_t);
	else
		value = (unsigned int)va_arg(*ap, unsigned int);
	return (value);
}

void	no_precision_u_null(t_printf *par, t_buff *buff)
{

	if (par->subtraction == 0)
	{
		//(par->zero == 1) ? ft_print_n((par->width_field - 1), '0'): 0;
		//(par->zero == 0) ? ft_print_n((par->width_field - 1), ' '): 0;
		(par->zero == 1) ? print_character(par->width_field - 1, '0', buff): 0;
		(par->zero == 0) ? print_character(par->width_field - 1, ' ', buff): 0;
		manage_buffer(buff, "0");
		//write(1, "0", 1);
	}
	else if (par->subtraction == 1)
	{
		manage_buffer(buff, "0");
		//write(1, "0", 1);
		//ft_print_n((par->width_field - 1), ' ');
		print_character(par->width_field - 1, ' ', buff);
	}
	par->number_of_character += (1);
	if ((par->width_field - 1) > 0)
		par->number_of_character += (par->width_field - 1);
}

void	precision_u_sup_null(t_printf *par, t_buff *buff)
{
	int		width;
	int		preci;

	width = (par->width_field - par->precision);
	preci = (par->precision - 1);
	if (par->subtraction == 0)
	{
		//ft_print_n(width, ' ');
		//ft_print_n(preci, '0');
		print_character(width, ' ', buff);
		print_character(preci, '0', buff);
		manage_buffer(buff, "0");
		//write(1, "0", 1);
	}
	else if (par->subtraction == 1)
	{
		//ft_print_n(preci, '0');
		print_character(preci, '0', buff);
		manage_buffer(buff, "0");
		//write(1, "0", 1);
		print_character(width, '0', buff);
		//ft_print_n(width, ' ');
	}
	par->number_of_character += (1);
	if (preci > 0)
		par->number_of_character += (preci);
	if (width > 0)
		par->number_of_character += (width);
}

void	precision_u_inf_null(t_printf *par, t_buff *buff)
{
	//ft_print_n(par->width_field, ' ');
	print_character(par->width_field, ' ', buff);
	if (par->width_field > 0)
		par->number_of_character += (par->width_field);
}

void	no_precision_u(char *tab, t_printf *par, t_buff *buff)
{
	int		width;

	width = (par->width_field - ft_strlen(tab));
	if (par->subtraction == 0)
	{
		//(par->zero == 1) ? ft_print_n(width, '0') : ft_print_n(width, ' ');
		(par->zero == 1) ? print_character(width, '0', buff) : 0;
		(par->zero == 0) ? print_character(width, ' ', buff) : 0;
		//write(1, tab, ft_strlen(tab));
		manage_buffer(buff, tab);
	}
	else if (par->subtraction == 1)
	{
		//write(1, tab, ft_strlen(tab));
		manage_buffer(buff, tab);
		print_character(width, ' ', buff);
		//ft_print_n(width, ' ');
	}
	par->number_of_character += (ft_strlen(tab));
	if (width > 0)
		par->number_of_character += (width);
}

void	precision_u_inf(char *tab, t_printf *par, t_buff *buff)
{
	int		width;

	width = (par->width_field - ft_strlen(tab));
	if (par->subtraction == 0)
	{
		//ft_print_n(width, ' ');
		print_character(width, ' ', buff);
		manage_buffer(buff, tab);
		//write(1, tab, ft_strlen(tab));
	}
	else if (par->subtraction == 1)
	{
		//write(1, tab, ft_strlen(tab));
		manage_buffer(buff, tab);
		print_character(width, ' ', buff);
		//ft_print_n(width, ' ');
	}
	par->number_of_character += ft_strlen(tab);
	if (width > 0)
		par->number_of_character += (width);
}

void	precision_u_sup(char *tab, t_printf *par, t_buff *buff)
{
	int		width;
	int		preci;

	width = (par->width_field - ft_strlen(tab) -
			(par->precision - ft_strlen(tab)));
	preci = (par->precision - ft_strlen(tab));
	if (par->subtraction == 0)
	{
		//ft_print_n(width, ' ');
		//ft_print_n(preci, '0');
		print_character(width, ' ', buff);
		print_character(preci, '0', buff);
		//write(1, tab, ft_strlen(tab));
		manage_buffer(buff, tab);
	}
	else if (par->subtraction == 1)
	{
		//ft_print_n(preci, '0');
		print_character(preci, '0', buff);
		//write(1, tab, ft_strlen(tab));
		manage_buffer(buff, tab);
		print_character(width, ' ', buff);
		//ft_print_n(width, ' ');
	}
	par->number_of_character += (ft_strlen(tab));
	if (width > 0)
		par->number_of_character += (width);
	if (preci > 0)
		par->number_of_character += (preci);
}

void	precision_u(char *tab, t_printf *par, t_buff *buff)
{
	if (par->precision > ft_strlen(tab))
		precision_u_sup(tab, par, buff);
	else if (par->precision <= ft_strlen(tab))
		precision_u_inf(tab, par, buff);
}

void	ft_convert_u(t_printf *par, va_list *ap, t_buff *buff)
{
	unsigned long long int		value;
	char						tab[64];
	value = ft_cast_u(ap, par);
	if (value == 0)
	{
		if (par->precision_point == 0)
			no_precision_u_null(par, buff);
		else if (par->precision_point == 1)
		{
			if (par->precision >= 1)
				precision_u_sup_null(par, buff);
			else if (par->precision < 1)
				precision_u_inf_null(par, buff);
		}
		return ;
	}
	itoa_base_unsigned(value, tab, 10, "0123456789");
	if (par->precision_point == 0)
		no_precision_u(tab, par, buff);
	else if (par->precision_point == 1)
		precision_u(tab, par, buff);
}
