/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:21:53 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/28 10:18:48 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_c(t_printf *par, va_list *ap, t_buff *buff)
{
	char	character;
	int		width;

	if (par->opt_l == 1)
	{
		ft_convert_lc(par, ap, buff);
		return ;
	}
	width = (par->width_field - 1);
	character = va_arg(*ap, int);
	if (par->subtraction == 0)
	{
		(par->zero == 1) ? print_character(width, '0', buff) : 0;
		(par->zero == 0) ? print_character(width, ' ', buff) : 0;
		manage_buffer_character(buff, character);
	}
	else if (par->subtraction == 1)
	{
		manage_buffer_character(buff, character);
		print_character(width, ' ', buff);
	}
	par->number_of_character += (1);
	if (width > 0)
		par->number_of_character += (width);
}
