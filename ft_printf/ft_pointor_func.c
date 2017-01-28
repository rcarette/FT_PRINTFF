/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointor_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:31:19 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/28 18:56:17 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	no_flags(t_printf *par, char character, t_buff *buff)
{
	int		width;

	width = (par->width_field - 1);
	if (par->subtraction == 0)
	{
		(par->zero == 0) ? print_character(width, ' ', buff) : 0;
		(par->zero == 1) ? print_character(width, '0', buff) : 0;
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

void	(*ft_pointor_func(int position))(t_printf *parameter,
		va_list *ap, t_buff *buff)
{
	void	(*pointor_tab[17])(t_printf *parameter, va_list *ap, t_buff *buff);

	pointor_tab[0] = ft_convert_s;
	pointor_tab[1] = ft_convert_ls;
	pointor_tab[2] = ft_convert_c;
	pointor_tab[3] = ft_convert_lc;
	pointor_tab[4] = ft_convert_d;
	pointor_tab[5] = ft_convert_d;
	pointor_tab[6] = ft_convert_x;
	pointor_tab[7] = ft_convert_x;
	pointor_tab[8] = ft_convert_o;
	pointor_tab[9] = ft_convert_o;
	pointor_tab[10] = ft_convert_p;
	pointor_tab[11] = ft_convert_u;
	pointor_tab[12] = ft_convert_lu;
	pointor_tab[13] = ft_convert_ld;
	pointor_tab[14] = conv_binary;
	pointor_tab[15] = ft_convert_mod;
	pointor_tab[16] = NULL;
	return (pointor_tab[position]);
}
