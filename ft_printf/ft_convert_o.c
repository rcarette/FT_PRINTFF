/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:17:23 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/25 05:11:16 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	no_precision_o_null(t_printf *par, t_buff *buff)
{
	if (par->subtraction == 0)
	{
		(par->zero == 0) ? print_character(par->width_field - 1, ' ', buff) : 0;
		(par->zero == 1) ? print_character(par->width_field - 1, '0', buff) : 0;
		manage_buffer_character(buff, '0');
	}
	else if (par->subtraction == 1)
	{
		manage_buffer_character(buff, '0');
		print_character(par->width_field - 1, ' ', buff);
	}
	par->number_of_character += (1);
	((par->width_field - 1) > 0) ? par->number_of_character
		+= (par->width_field - 1) : 0;
}

void	precision_o_sup_null(t_printf *par, t_buff *buff)
{
	if (par->subtraction == 0)
	{
		print_character(par->width_field - par->precision, ' ', buff);
		print_character(par->precision, '0', buff);
	}
	else if (par->subtraction == 1)
	{
		print_character(par->precision, '0', buff);
		print_character(par->width_field - par->precision, ' ', buff);
	}
	if (par->width_field - par->precision > 0)
		par->number_of_character += (par->width_field - par->precision);
	par->number_of_character += (par->precision);
}

void	precision_o_null(t_printf *par, t_buff *buff)
{
	if (par->precision < 1)
	{
		(par->hash == 1 && par->subtraction == 1) ?
			manage_buffer_character(buff, '0') : 0;
		print_character(par->width_field - par->hash, ' ', buff);
		(par->hash == 1 && par->subtraction == 0) ?
			manage_buffer_character(buff, '0') : 0;
		par->number_of_character += (par->hash);
		if (par->width_field - par->hash > 0)
			par->number_of_character += (par->width_field - par->hash);
		return ;
	}
	else if (par->precision >= 1)
		precision_o_sup_null(par, buff);
}

void	no_precision_o(t_printf *par, char *tab, t_buff *buff)
{
	int		width;

	width = (par->width_field - ft_strlen(tab) - par->hash);
	if (par->subtraction == 0)
	{
		(par->zero == 1) ? print_character(width, '0', buff) : 0;
		(par->zero == 0) ? print_character(width, ' ', buff) : 0;
		(par->hash == 1) ? manage_buffer_character(buff, '0') : 0;
		manage_buffer(buff, tab);
	}
	else if (par->subtraction == 1)
	{
		(par->hash == 1) ? manage_buffer_character(buff, '0') : 0;
		manage_buffer(buff, tab);
		print_character(width, ' ', buff);
	}
	par->number_of_character += (ft_strlen(tab) + par->hash);
	(width > 0) ? par->number_of_character += (width) : 0;
}

void	precision_octal_sup(t_printf *par, char *tab, t_buff *buff)
{
	int		width;
	int		preci;

	width = (par->width_field - par->precision);
	preci = (par->precision - ft_strlen(tab));
	if (par->subtraction == 0)
	{
		print_character(width, ' ', buff);
		print_character(preci, '0', buff);
		manage_buffer(buff, tab);
	}
	else if (par->subtraction == 1)
	{
		print_character(preci, '0', buff);
		manage_buffer(buff, tab);
		print_character(width, ' ', buff);
	}
	par->number_of_character += ft_strlen(tab);
	(width > 0) ? par->number_of_character += width : 0;
	(preci > 0) ? par->number_of_character += preci : 0;
}

void	precision_octal_inf(t_printf *par, char *tab, t_buff *buff)
{
	int		width;

	width = (par->width_field - ft_strlen(tab) - par->hash);
	if (par->subtraction == 0)
	{
		print_character(width, ' ', buff);
		(par->hash == 1) ? manage_buffer_character(buff, '0') : 0;
		manage_buffer(buff, tab);
	}
	else if (par->subtraction == 1)
	{
		(par->hash == 1) ? manage_buffer_character(buff, '0') : 0;
		manage_buffer(buff, tab);
		print_character(width, ' ', buff);
	}
	par->number_of_character += (ft_strlen(tab) + par->hash);
	(width > 0) ? par->number_of_character += width : 0;
}

unsigned long long		ft_cast_o(va_list *ap, t_printf *parameter)
{
	unsigned long long		value;

	if (parameter->opt_h == 1 && parameter->flags_current != 'O')
		value = (unsigned short)va_arg(*ap, unsigned long);
	else if (parameter->opt_hh == 1 && parameter->flags_current != 'O')
		value = (unsigned char)va_arg(*ap, unsigned long );
	else if (parameter->opt_l == 1)
		value = (unsigned long)va_arg(*ap, unsigned long);
	else if (parameter->opt_ll == 1)
		value = va_arg(*ap, unsigned long long);
	else if (parameter->opt_j == 1)
		value = (uintmax_t)va_arg(*ap, uintmax_t);
	else if (parameter->opt_z == 1)
		value = (size_t)va_arg(*ap, size_t);
	else if (parameter->flags_current == 'o')
		value = (unsigned int)va_arg(*ap, unsigned int);
	else if (parameter->flags_current == 'O')
		value = (unsigned long)va_arg(*ap, unsigned long);
	else
		value = (unsigned int)va_arg(*ap, unsigned int);
	return (value);
}

void	ft_convert_o(t_printf *par, va_list *ap, t_buff *buff)
{
	unsigned long long		value;
	char					board[64];
	
	value = ft_cast_o(ap, par);
	if (value == 0)
	{
		if (par->precision_point == 0)
			no_precision_o_null(par, buff);
		else if (par->precision_point == 1)
			precision_o_null(par, buff);
		return ;
	}
	itoa_base_unsigned(value, board, 8, "01234567");
	if (par->precision_point == 0 && value != 0)
		no_precision_o(par, board, buff);
	else if (par->precision_point == 1)
	{
		if (par->precision >= ft_strlen(board))
			precision_octal_sup(par, board, buff);
		else if (par->precision < ft_strlen(board))
			precision_octal_inf(par, board, buff);
	}
}
