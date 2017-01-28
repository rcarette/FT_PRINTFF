/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:35:39 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/28 13:47:28 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_character(int x, char character, t_buff *buff)
{
	int		ite;
	char	*new;

	ite = -1;
	if (x <= 0)
		return ;
	if ((buff->position + x) > BUFF)
		read_buffer(buff);
	if (x >= BUFF)
	{
		if (!(new = (char *)malloc(sizeof(char) * (x + 1))))
			exit(EXIT_FAILURE);
		ft_memset(new, '\0', (x + 1));
		stock_character(character, x, new);
		write(1, buff->buffer, buff->position);
		init_buffer(buff);
		write(1, new, x);
		free(new);
		return ;
	}
	while (++ite < x)
	{
		buff->buffer[buff->position] = character;
		++buff->position;
	}
}

char		*itoa_base_p(unsigned long long x, char *board)
{
	char	*tab;
	int		size;

	size = ft_getsize(x, 16);
	if (!(tab = (char *)malloc(sizeof(char) * (size + 1))))
		exit(EXIT_FAILURE);
	ft_memset(tab, '\0', (size + 1));
	while (x)
	{
		tab[--size] = board[x % 16];
		x = (x / 16);
	}
	return (tab);
}

void		no_precision_p_null(t_printf *par, t_buff *buff)
{
	int		width;

	width = (par->width_field - 3);
	if (par->subtraction == 0)
	{
		(par->zero == 0) ? print_character(width, ' ', buff) : 0;
		manage_buffer(buff, "0x0");
		(par->zero == 1) ? print_character(width, '0', buff) : 0;
	}
	else if (par->subtraction == 1)
	{
		manage_buffer(buff, "0x0");
		print_character(width, ' ', buff);
	}
	par->number_of_character += (3);
	if (width > 0)
		par->number_of_character += (width);
}

void		precision_p_inf_null(t_printf *par, t_buff *buff)
{
	int		width;

	width = (par->width_field - 2);
	if (par->subtraction == 0)
	{
		print_character(width, ' ', buff);
		manage_buffer(buff, "0x");
	}
	else if (par->subtraction == 1)
	{
		manage_buffer(buff, "0x");
		print_character(width, ' ', buff);
	}
	par->number_of_character += (2);
	if (width > 0)
		par->number_of_character += (width);
}

void		precision_p_sup_null(t_printf *par, t_buff *buff)
{
	int		width;
	int		preci;

	preci = (par->precision - 1);
	width = (par->width_field - preci - 3);
	if (par->subtraction == 0)
	{
		print_character(width, ' ', buff);
		manage_buffer(buff, "0x0");
		print_character(preci, '0', buff);
	}
	else if (par->subtraction == 1)
	{
		manage_buffer(buff, "0x0");
		print_character(preci, '0', buff);
		print_character(width, ' ', buff);
	}
	par->number_of_character += (3);
	if (width > 0)
		par->number_of_character += (width);
	if (preci > 0)
		par->number_of_character += (preci);
}

void		no_precision_p(char *tab, t_printf *par, t_buff *buff)
{
	int		width;

	width = (par->width_field - ft_strlen(tab) - 2);
	if (par->subtraction == 0)
	{
		(par->zero == 0) ? print_character(width, ' ', buff) : 0;
		manage_buffer(buff, "0x");
		(par->zero == 1) ? print_character(width, '0', buff) : 0;
		manage_buffer(buff, tab);
	}
	else if (par->subtraction == 1)
	{
		manage_buffer(buff, "0x");
		manage_buffer(buff, tab);
		print_character(width, ' ', buff);
	}
	par->number_of_character += (2) + ft_strlen(tab);
	if (width > 0)
		par->number_of_character += (width);
}

void		precision_p_inf(char *tab, t_printf *par, t_buff *buff)
{
	int		width;

	width = (par->width_field - ft_strlen(tab) - 2);
	if (par->subtraction == 0)
	{
		print_character(width, ' ', buff);
		manage_buffer(buff, "0x");
		manage_buffer(buff, tab);
	}
	else if (par->subtraction == 1)
	{
		manage_buffer(buff, "0x");
		manage_buffer(buff, tab);
		print_character(width, ' ', buff);
	}
	if (width > 0)
		par->number_of_character += (width);
	par->number_of_character += (2) + ft_strlen(tab);
}

void		precision_p_sup(char *tab, t_printf *par, t_buff *buff)
{
	int		width;
	int		preci;

	preci = (par->precision - ft_strlen(tab));
	width = (par->width_field - ft_strlen(tab) - preci - 2);
	if (par->subtraction == 0)
	{
		print_character(width, ' ', buff);
		manage_buffer(buff, "0x");
		print_character(preci, '0', buff);
		manage_buffer(buff, tab);
	}
	else if (par->subtraction == 1)
	{
		manage_buffer(buff, "0x");
		print_character(preci, '0', buff);
		manage_buffer(buff, tab);
		print_character(width, ' ', buff);
	}
	par->number_of_character += (ft_strlen(tab) + 2);
	if (width > 0)
		par->number_of_character += (width);
	if (preci > 0)
		par->number_of_character += (preci);
}

void		precision_p(char *tab, t_printf *par, t_buff *buff)
{
	if (par->precision > ft_strlen(tab))
		precision_p_sup(tab, par, buff);
	else if (par->precision <= ft_strlen(tab))
		precision_p_inf(tab, par, buff);
}

void		ft_convert_p(t_printf *par, va_list *ap, t_buff *buff)
{
	unsigned long	nbr;
	char			*tab;

	nbr = (unsigned long)va_arg(*ap, unsigned long);
	if (nbr == 0)
	{
		if (par->precision_point == 0)
			no_precision_p_null(par, buff);
		else if (par->precision_point == 1)
		{
			if (par->precision >= 1)
				precision_p_sup_null(par, buff);
			else if (par->precision < 1)
				precision_p_inf_null(par, buff);
		}
		return ;
	}
	tab = itoa_base_p(nbr, "0123456789abcdef");
	if (par->precision_point == 0)
		no_precision_p(tab, par, buff);
	else if (par->precision_point == 1)
		precision_p(tab, par, buff);
	free(tab);
}
