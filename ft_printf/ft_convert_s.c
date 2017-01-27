/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 20:35:05 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/26 17:38:42 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*init_tab_null(char tab[7])
{
	tab[0] = '(';
	tab[1] = 'n';
	tab[2] = 'u';
	tab[3] = 'l';
	tab[4] = 'l';
	tab[5] = ')';
	tab[6] = '\0';
	return (tab);
}

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
		while(++i < size)
		{
			buff->buffer[buff->position] = tab[i];
			++buff->position;
		}
}

void	precision_inf_string(char *str, t_printf *par, t_buff *buff)
{
	int		width;

	width = (par->width_field - par->precision);
	if (par->subtraction == 0)
	{
		(par->zero == 1) ? print_character(width, '0', buff) : 0;
		(par->zero == 0) ? print_character(width, ' ', buff) : 0;
		ft_read_str(str, par->precision, buff);
	}
	else if (par->subtraction == 1)
	{
		ft_read_str(str, par->precision, buff);
		print_character(width, ' ', buff);
	}
	par->number_of_character += (par->precision);
	if (width > 0)
		par->number_of_character += (width);
}

void	no_precision(char *tab, t_printf *par, t_buff *buff)
{
	int		width;

	width = (par->width_field - ft_strlen(tab));
	if (par->subtraction == 0)
	{
		(par->zero == 1) ? print_character(width, '0', buff) : 0;
		(par->zero == 0) ? print_character(width, ' ', buff) : 0;
		manage_buffer(buff, tab);
	}
	else if (par->subtraction == 1)
	{
		manage_buffer(buff, tab);
		print_character(width, ' ', buff);
	}
	par->number_of_character += ft_strlen(tab);
	if (width > 0)
		par->number_of_character += (width);
}

void	precision_sup_string(char *tab, t_printf *par, t_buff *buff)
{
	int		width;

	width = (par->width_field - ft_strlen(tab));
	if (par->subtraction == 0)
	{
		(par->zero == 1) ? print_character(width, '0', buff) : 0;
		(par->zero == 0) ? print_character(width, ' ', buff) : 0;
		manage_buffer(buff, tab);
	}
	else if (par->subtraction == 1)
	{
		manage_buffer(buff, tab);
		print_character(width, ' ', buff);
	}
	if (width > 0)
		par->number_of_character += (width);
	par->number_of_character += ft_strlen(tab);
}

void	ft_convert_s(t_printf *parameter, va_list *ap, t_buff *buff)
{
	char	*str;
	char	tab[7];

	init_tab_null(tab);
	if (parameter->opt_l == 1)
	{
		ft_convert_ls(parameter, ap, buff);
		return ;
	}
	if (!(str = va_arg(*ap, char *)))
	{
		if (parameter->precision_point == 1)
		{
			if (parameter->precision <= ft_strlen(tab))
				precision_inf_string(tab, parameter, buff);
			else if (parameter->precision > ft_strlen(tab))
				precision_sup_string(tab, parameter, buff);
		}
		else if (parameter->precision_point == 0)
			no_precision(tab, parameter, buff);
		return ;
	}
	if (parameter->precision_point == 1)
	{
			if (parameter->precision <= ft_strlen(str))
				precision_inf_string(str, parameter, buff);
			else if (parameter->precision > ft_strlen(str))
				precision_sup_string(str, parameter, buff);
	}
	else if (parameter->precision_point == 0)
		no_precision(str, parameter, buff);
}
