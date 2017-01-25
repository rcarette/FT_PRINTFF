/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_%.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:40:13 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/25 00:25:20 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_mod(t_printf *par, va_list *ap, t_buff *buff)
{
	(void)ap;
	if (par->subtraction == 0)
	{
		//(par->zero == 0) ? ft_print_n(par->width_field - 1, ' ') : 0;
		//(par->zero == 1) ? ft_print_n(par->width_field - 1, '0') : 0;
		(par->zero == 0) ? print_character(par->width_field - 1, ' ', buff) : 0;
		(par->zero == 1) ? print_character(par->width_field - 1, '0', buff) : 0;
		manage_buffer_character(buff, '%');
		//write(1, "%", 1);
	}
	else if (par->subtraction == 1)
	{
		//write(1, "%", 1);
		manage_buffer_character(buff, '%');
		//ft_print_n(par->width_field - 1, ' ');
		print_character(par->width_field - 1, ' ', buff);

	}
	if (par->width_field > 0)
		par->number_of_character += (par->width_field - 1);
	par->number_of_character += (1);
}
