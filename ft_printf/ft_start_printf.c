/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 00:40:58 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/28 18:08:22 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_parse_modifier(char *t, t_printf *parameter, int j,
		int permut)
{
	while (t[j] && (t[j] == 'j' || t[j] == 'h' || t[j] == 'z' || t[j] == 'l'))
	{
		permut = 0;
		if (t[j] == 'h' && t[j + 1] == 'h')
		{
			++parameter->opt_hh;
			permut = 1;
		}
		else if (t[j] == 'l' && t[j + 1] == 'l')
		{
			++parameter->opt_ll;
			permut = 1;
		}
		else
		{
			parameter->opt_h = (t[j] == 'h') ? 1 : parameter->opt_h;
			parameter->opt_j = (t[j] == 'j') ? 1 : parameter->opt_j;
			parameter->opt_z = (t[j] == 'z') ? 1 : parameter->opt_z;
			parameter->opt_l = (t[j] == 'l') ? 1 : parameter->opt_l;
		}
		j += (permut == 1) ? 2 : 1;
	}
	return (j);
}

int				ft_parse_precision(char *t, t_printf *parameter)
{
	int		i;
	int		size;

	i = 0;
	size = 1;
	parameter->precision_point = 1;
	if (!ft_isdigit(t[i]))
		return (size);
	if (t[i] == '0' && !(ft_isdigit(t[i + 1])))
		return (++size);
	else if (*t == '0' && ft_isdigit(*(t + 1)))
	{
		++i;
		++size;
	}
	parameter->precision = ft_atoi((*t == '0' && ft_isdigit(*(t + 1)) ?
				&t[i] : &t[i]));
	return (ft_getsize(parameter->precision, 10) + size);
}

int				ft_parse_indicateur(char *t, t_printf *parameter)
{
	int		i;

	i = -1;
	while (t[++i] == '#' || t[i] == '-' || t[i] == '+'
			|| t[i] == ' ' || t[i] == '0')
	{
		if (t[i] == '#')
			parameter->hash = 1;
		else if (t[i] == '-')
			parameter->subtraction = 1;
		else if (t[i] == '+')
			parameter->addition = 1;
		else if (t[i] == ' ')
			parameter->space = 1;
		else
			parameter->zero = 1;
	}
	i += ft_getsize(parameter->width_field = ft_atoi(&t[i]), 10);
	if (t[i] == '.')
		i += ft_parse_precision(&t[i + 1], parameter);
	i += ft_parse_modifier(&t[i], parameter, 0, 0);
	return (i);
}

int				ft_parsing(char *temporary, va_list *ap, t_printf *parameter,
		t_buff *buff)
{
	char	**flags;
	int		i;
	int		size;
	void	(*ptr)(t_printf *parameter, va_list *ap, t_buff *buff);

	i = -1;
	size = ft_parse_indicateur(temporary, parameter);
	flags = ft_strsplit("s S c C d i x X o O p u U D b %", ' ');
	while (flags[++i])
		if (temporary[size] == flags[i][0])
		{
			parameter->flags_current = flags[i][0];
			ptr = ft_pointor_func(i);
			(*ptr)(parameter, ap, buff);
			ft_clear(flags);
			return (++size);
		}
	no_flags(parameter, temporary[size], buff);
	++size;
	(flags != NULL) ? ft_clear(flags) : 0;
	return (size);
}
