/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_parameter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:31:18 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/24 00:09:10 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_show_parameter(t_printf *parameter)
{
	printf("Hash = %d\n", parameter->hash);
	printf("Subtraction = %d\n", parameter->subtraction);
	printf("Addition = %d\n", parameter->addition);
	printf("space = %d\n", parameter->space);
	printf("zero = %d\n", parameter->zero);
	printf("Width field = %d\n", parameter->width_field);
	printf("Precision : = %d\n", parameter->precision);
	printf("Precision {.} : = %d\n", parameter->precision_point);
	printf("hh = %d\n", parameter->opt_hh);
	printf("h = %d\n", parameter->opt_h);
	printf("l = %d\n", parameter->opt_l);
	printf("ll = %d\n", parameter->opt_ll);
	printf("j = %d\n", parameter->opt_j);
	printf("z = %d\n", parameter->opt_z);
}
