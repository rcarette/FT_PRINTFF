/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:21:53 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/25 00:21:53 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_c(t_printf *par, va_list *ap, t_buff *buff)
{
	char	character;
	int		width;
	
	width = (par->width_field - 1);
	character = va_arg(*ap, int);
	if (par->opt_l == 1)
	{
		// Action !
	}
	if (par->subtraction == 0)
	{
		//(par->zero == 1) ? ft_print_n(width, '0') : 0;
		//(par->zero == 0) ? ft_print_n(width, ' ') : 0;
		(par->zero == 1) ? print_character(width, '0', buff) : 0;
		(par->zero == 0) ? print_character(width, ' ', buff) : 0;
		//write(1, &character, 1);
		manage_buffer_character(buff, character);
	}
	else if (par->subtraction == 1)
	{
		//write(1, &character, 1);
		manage_buffer_character(buff, character);
		//ft_print_n(width, ' ');
		print_character(width, ' ', buff);
	}
	par->number_of_character += (1);
	if (width > 0)
		par->number_of_character += (width);
}
