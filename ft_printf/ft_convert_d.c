/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:37:31 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/25 05:24:36 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long ft_cast_d(va_list *ap, t_printf *par)
{
	long long int		value;

	if (par->opt_h == 1)
		value = (short)va_arg(*ap, int);
	else if (par->opt_hh == 1)
		value = (signed char)va_arg(*ap, int);
	else if (par->opt_l == 1)
		value = (long)va_arg(*ap, long);
	else if (par->opt_ll == 1 || par->opt_z == 1)
		value = (long long)va_arg(*ap, long long);
	else if (par->opt_j == 1)
		value = (intmax_t)va_arg(*ap, intmax_t);
	else if (par->opt_z == 1)
		value = (size_t)va_arg(*ap , size_t);
	else
		value = (int)va_arg(*ap, int);
	return (value);
}

void	itoa_base_d(long long int nbr, char board[64])
{
	int							negative;
	int							size;
	unsigned long long int		temporary;
	unsigned long long int		t;

	size = 0;
	negative = 0;
	temporary = (nbr);
	t = temporary;
	if (nbr < 0)
	{
		negative = 1;
		temporary = (-temporary);
		t = (-t);
		++size;
	}
	while (t > 0)
	{
		++size;
		t = (t / 10);
	}
	ft_memset(board, '\0', 64);
	while (temporary > 0)
	{
		board[--size] = (temporary % 10) + '0';
		temporary = (temporary / 10);
	}
	if (negative)
		board[0] = '-';
}


void	no_precision_d_null(t_printf *par, t_buff *buff)
{
	int		width;

	par->space = (par->addition == 1) ? 0 : par->space;
	width = (par->width_field - par->addition - 1 - par->space);
	if (par->subtraction == 0)
	{
		(par->space == 1) ? manage_buffer(buff, " ") : 0;
		(par->zero == 0) ? print_character(width, ' ', buff) : 0;
		(par->addition == 1) ? manage_buffer(buff, "+") : 0;
		(par->zero == 1) ? print_character(width, '0', buff) : 0;
		manage_buffer(buff, "0");
	}
	else if (par->subtraction == 1)
	{
		(par->space == 1) ? manage_buffer(buff, " ") : 0;
		(par->addition == 1) ? manage_buffer(buff, "+") : 0;
		manage_buffer(buff, "0");
		print_character(width, ' ', buff);
	}
	par->number_of_character += (1 + par->space + par->addition);
	if (width > 0)
		par->number_of_character += (width);
}

void	precision_d_sup_null(t_printf *par, t_buff *buff)
{
	int		width;
	int		preci;

	par->space = (par->addition == 1) ? 0 : par->space;
	preci = (par->precision - 1);
	width = (par->width_field - par->precision - par->space - par->addition);
	if (par->subtraction == 0)
	{
		(par->space == 1) ? manage_buffer(buff, " ") : 0;
		print_character(width, ' ', buff);
		(par->addition == 1) ? manage_buffer(buff, "+") : 0;
		print_character(preci, '0', buff);
		manage_buffer(buff, "0");
	}
	else if (par->subtraction == 1)
	{
		(par->space == 1) ? manage_buffer(buff, " ") : 0;
		(par->addition == 1) ? manage_buffer(buff, "+") : 0;
		manage_buffer(buff, "0");
		print_character(preci, '0', buff);
		print_character(width, ' ', buff);
	}
	par->number_of_character += ((1) + par->space + par->addition);
	if (width > 0)
		par->number_of_character += (width);
	if (preci > 0)
		par->number_of_character += (preci);
}

void	precision_d_inf_null(t_printf *par, t_buff *buff)
{
	int		width;

	par->space = (par->addition == 1) ? 0 : par->space;
	width = (par->width_field - par->addition - par->space);
	if (par->subtraction == 0)
	{
		(par->space == 1) ? manage_buffer(buff, " ") : 0;
		print_character(width, ' ', buff);
		(par->addition == 1) ? manage_buffer(buff, "+") : 0;
	}
	else if (par->subtraction == 1)
	{
		(par->addition == 1) ? manage_buffer(buff, "+") : 0;
		print_character(width, ' ', buff);
		(par->space == 1) ? manage_buffer(buff, " ") : 0;
	}
	par->number_of_character += (par->addition + par->space);
	if (width > 0)
		par->number_of_character += (width);
}

void	precision_d_inf(char *tab, t_printf *par, int sub, t_buff *buff)
{
	int		width;

	width = (par->width_field - par->addition - par->space - sub - ft_strlen(tab));
	if (par->subtraction == 0)
	{
		(par->space == 1) ? manage_buffer(buff, " ") : 0;
		print_character(width, ' ', buff);
		(par->addition == 1) ? manage_buffer(buff, "+") :0;
		(sub == 1) ? manage_buffer(buff, "-") : 0;
		manage_buffer(buff, tab);
	}
	else if (par->subtraction == 1)
	{
		(par->space == 1) ? manage_buffer(buff, " ") : 0;
		(par->addition == 1) ? manage_buffer(buff, "+") :0;
		(sub == 1) ? manage_buffer(buff, "-") : 0;
		manage_buffer(buff, tab);
		print_character(width, ' ', buff);
	}
	par->number_of_character += (ft_strlen(tab) + par->addition + sub + par->space);
	if (width > 0)
		par->number_of_character += (width);
}

void	precision_d_sup(char *tab, t_printf *par, int sub, t_buff *buff)
{
	int		width;
	int		preci;
	
	preci = (par->precision - ft_strlen(tab));
	width = (par->width_field - par->addition - sub - par->space - ft_strlen(tab) - preci);
	if (par->subtraction == 0)
	{
		print_character(width, ' ', buff);
		(par->space == 1) ? manage_buffer(buff, " ") : 0;
		(par->addition == 1) ? manage_buffer(buff, "+") :0;
		(sub == 1) ? manage_buffer(buff, "-") : 0;
		print_character(preci, '0', buff);
		manage_buffer(buff, tab);
	}
	else if (par->subtraction == 1)
	{
		(par->space == 1) ? manage_buffer(buff, " ") : 0;
		(par->addition == 1) ? manage_buffer(buff, "+") :0;
		(sub == 1) ? manage_buffer(buff, "-") : 0;
		print_character(preci, '0', buff);
		manage_buffer(buff, tab);
		print_character(width, ' ', buff);
	}
	par->number_of_character += (ft_strlen(tab) + par->addition + par->space + sub);
	if (width > 0)
		par->number_of_character += (width);
	if (preci > 0)
		par->number_of_character += (preci);

}

void	no_precision_d(char *tab, t_printf *par, int sub, t_buff *buff)
{
	int		width;
	
	par->space = (par->addition == 1 || tab[0] == '-') ? 0 : par->space;
	par->addition = (sub == 1) ? 0 : par->addition;
	(tab[0] == '-') ? ++tab : 0;
	width = (par->width_field - par->space - par->addition - sub - ft_strlen(tab));
	if (par->subtraction == 0)
	{
		(par->zero == 0) ? print_character(width, ' ', buff) : 0;
		(par->space == 1) ? manage_buffer(buff, " ") : 0;
		(par->addition == 1) ? manage_buffer(buff, "+") :0;
		(sub == 1) ? manage_buffer(buff, "-") : 0;
		(par->zero == 1) ? print_character(width, '0', buff) : 0;
		manage_buffer(buff, tab);
	}
	else if (par->subtraction == 1)
	{
		(par->space == 1) ? manage_buffer(buff, " ") : 0;
		(par->addition == 1) ? manage_buffer(buff, "+") :0;
		(sub == 1) ? manage_buffer(buff, "-") : 0;
		manage_buffer(buff, tab);
		print_character(width, ' ', buff);
	}
	par->number_of_character += (ft_strlen(tab) + par->space + par->addition + sub);
	if (width > 0)
		par->number_of_character += (width);
}

void	precision_d(char *tab, t_printf *par, int sub, t_buff *buff)
{
	par->space = (par->addition == 1 || tab[0] == '-') ? 0 : par->space;
	par->addition = (sub == 1) ? 0 : par->addition;
	(tab[0] == '-') ? ++tab : 0;
	if (par->precision > ft_strlen(tab))
		precision_d_sup(tab, par, sub, buff);
	else if (par->precision <= ft_strlen(tab))
		precision_d_inf(tab, par, sub, buff);
}


void	ft_convert_d(t_printf *par, va_list *ap, t_buff *buff)
{
	long long int			value;
	char					board[64];
	int						sub;
	
	if (par->opt_l == 1)
	{
		ft_convert_ld(par, ap, buff);
		return ;
	}
	value = ft_cast_d(ap, par);
	if (value == 0)
	{
		if (par->precision_point == 0)
			no_precision_d_null(par, buff);
		else if (par->precision_point == 1)
		{
			if (par->precision >= 1)
				precision_d_sup_null(par, buff);
			else if (par->precision < 1)
				precision_d_inf_null(par, buff);
		}
		return ;
	}
	itoa_base_d(value, board);
	sub = (board[0] == '-') ? 1 : 0;
	if (par->precision_point == 0)
		no_precision_d(board, par, sub, buff);
	else if (par->precision_point == 1)
		precision_d(board, par, sub, buff);
}
