/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 01:13:21 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/20 17:13:53 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*ft_init_t_printf(void)
{
	t_printf	*parameter;

	if (!(parameter = (t_printf *)malloc(sizeof(t_printf))))
		exit(EXIT_FAILURE);
	parameter->hash = 0;
	parameter->zero = 0;
	parameter->space = 0;
	parameter->subtraction = 0;
	parameter->addition = 0;
	parameter->width_field = 0;
	parameter->precision_point = 0;
	parameter->precision = 0;
	parameter->opt_h = 0;
	parameter->opt_hh = 0;
	parameter->opt_l = 0;
	parameter->opt_ll = 0;
	parameter->opt_j = 0;
	parameter->opt_z = 0;
	parameter->number_of_character = 0;
	parameter->flags_current = '\0';
	parameter->negative = 0;
	return (parameter);
}
