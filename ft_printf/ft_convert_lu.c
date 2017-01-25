/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_lu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:19:32 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/24 23:08:27 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	no_precision_uu_null(t_printf *par, t_buff *buff)
{

	if (par->subtraction == 0)
	{
		//(par->zero == 1) ? ft_print_n((par->width_field - 1), '0'): 0;
		//(par->zero == 0) ? ft_print_n((par->width_field - 1), ' '): 0;
		(par->zero == 1) ? print_character(par->width_field - 1, '0', buff): 0;
		(par->zero == 0) ? print_character(par->width_field - 1, ' ', buff): 0;
		//write(1, "0", 1);
		manage_buffer(buff, "0");
	}
	else if (par->subtraction == 1)
	{
		//write(1, "0", 1);
		manage_buffer(buff, "0");
		//ft_print_n((par->width_field - 1), ' ');
		print_character(par->width_field - 1, ' ', buff);
	}
	par->number_of_character += (1);
	if ((par->width_field - 1) > 0)
		par->number_of_character += (par->width_field - 1);
}

void	precision_uu_sup_null(t_printf *par, t_buff *buff)
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
		//write(1, "0", 1);
		manage_buffer(buff, "0");
	}
	else if (par->subtraction == 1)
	{
		//ft_print_n(preci, '0');
		print_character(preci, '0', buff);
		//write(1, "0", 1);
		manage_buffer(buff, "0");
		//ft_print_n(width, ' ');
		print_character(width, ' ', buff);
	}
	par->number_of_character += (1);
	if (preci > 0)
		par->number_of_character += (preci);
	if (width > 0)
		par->number_of_character += (width);
}

void	precision_uu_inf_null(t_printf *par, t_buff *buff)
{
	//ft_print_n(par->width_field, ' ');
	print_character(par->width_field, ' ', buff);
	if (par->width_field > 0)
		par->number_of_character += (par->width_field);
}

void	no_precision_uu(char *tab, t_printf *par, t_buff *buff)
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

void	precision_uu_inf(char *tab, t_printf *par, t_buff *buff)
{
	int		width;

	width = (par->width_field - ft_strlen(tab));
	if (par->subtraction == 0)
	{
		//ft_print_n(width, ' ');
		print_character(width, ' ', buff);
		//write(1, tab, ft_strlen(tab));
		manage_buffer(buff, tab);
	}
	else if (par->subtraction == 1)
	{
		//write(1, tab, ft_strlen(tab));
		manage_buffer(buff, tab);
		//ft_print_n(width, ' ');
		print_character(width, ' ', buff);
	}
	par->number_of_character += ft_strlen(tab);
	if (width > 0)
		par->number_of_character += (width);
}

void	precision_uu_sup(char *tab, t_printf *par, t_buff *buff)
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
		manage_buffer(buff, tab);
		//write(1, tab, ft_strlen(tab));
	}
	else if (par->subtraction == 1)
	{
		//ft_print_n(preci, '0');
		print_character(preci, '0', buff);
		//write(1, tab, ft_strlen(tab));
		manage_buffer(buff, tab);
		//ft_print_n(width, ' ');
		print_character(width, ' ', buff);
	}
	par->number_of_character += (ft_strlen(tab));
	if (width > 0)
		par->number_of_character += (width);
	if (preci > 0)
		par->number_of_character += (preci);
}

void	precision_uu(char *tab, t_printf *par, t_buff *buff)
{
	if (par->precision > ft_strlen(tab))
		precision_uu_sup(tab, par, buff);
	else if (par->precision <= ft_strlen(tab))
		precision_uu_inf(tab, par, buff);
}

void	ft_convert_lu(t_printf *par, va_list *ap, t_buff *buff)
{
	unsigned long  int			value;
	char						tab[64];

	value = (unsigned long int)va_arg(*ap, unsigned long int);
	if (value == 0)
	{
		if (par->precision_point == 0)
			no_precision_uu_null(par, buff);
		else if (par->precision_point == 1)
		{
			if (par->precision >= 1)
				precision_uu_sup_null(par, buff);
			else if (par->precision < 1)
				precision_uu_inf_null(par, buff);
		}
		return ;
	}
	itoa_base_unsigned(value, tab, 10, "0123456789");
	if (par->precision_point == 0)
		no_precision_uu(tab, par, buff);
	else if (par->precision_point == 1)
		precision_uu(tab, par, buff);
}
