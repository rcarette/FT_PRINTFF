/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_lc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:22:31 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/28 10:37:57 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	value_null_lc(t_printf *par, t_buff *buff, wchar_t character)
{
	int		width;

	width = (par->width_field - 1);
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
	(width > 0) ? par->number_of_character += (width) : 0;
}

char	*transform_ascii_lc(char *temporary, char *board)
{
	int		size_temporary;
	int		size_board;

	size_temporary = (ft_strlen(temporary) - 1);
	size_board = ft_strlen(board);
	while (size_temporary)
	{
		if (temporary[size_temporary] == 'x')
			temporary[size_temporary] = board[--size_board];
		if (size_board == 0)
			break;
		--size_temporary;
	}
	replace(temporary);
	return (temporary);
}

char	*search(char *board, t_printf *par)
{
	char	*tab[5];
	int		i;
	char	*temporary;
	char	*ascii;
	
	temporary = NULL;
	i = -1;
	tab[0] = "0xxxxxxx ";
	tab[1] = "110xxxxx 10xxxxxx ";
	tab[2] = "1110xxxx 10xxxxxx 10xxxxxx ";
	tab[3] = "11110xxx 10xxxxxx 10xxxxxx 10xxxxxx ";
	tab[4] = NULL;
	while (tab[++i])
		if (ft_strlen_x(tab[i], 'x') >= ft_strlen(board))
		{
			temporary = ft_strdup(tab[i]);
			break;
		}
	ascii = transform_ascii_lc(temporary, board);
	free(temporary);
	par->width_field -= ft_strlen_x(ascii, ' ');
	return (ascii);
}

void	impr_unicode_lc(char *ascii)
{
	int		i;
	int		power;
	int		size;

	i = -1;
	size = 0;
	power = 7;
	while (ascii[++i])
	{
		if (ascii[i] == '1')
			size += (ascii[i] - 48) * puissance(2, power--);
		else if (ascii[i] == '0')
			size += (ascii[i] - 48) * puissance(2, power--);
		else
		{
			write(1, &size, 1);
			size = 0;
			power = 7;
		}
	}
}

void	value_not_null_lc(t_printf *par, wchar_t character, int octets)
{
	unsigned int	code_ascii;
	char			board[64];
	char			*ascii;

	code_ascii = (unsigned int)character;
	ft_memset(board, '\0', 64);
	itoa_base_unsigned(code_ascii, board, 2, "01");
	ascii = search(board, par);
	octets = ft_strlen_x(ascii, ' ');
	if (par->subtraction == 0)
	{
		if (par->width_field > 0)
			(par->zero) ? print_x_character(par->width_field, '0') :
				print_x_character(par->width_field, ' ');
		impr_unicode_lc(ascii);
	}
	else if (par->subtraction == 1)
	{
		impr_unicode_lc(ascii);
		if (par->width_field > 0)
			print_x_character(par->width_field,  ' ');
	}
	par->number_of_character += (octets);
	if (par->width_field > 0)
		par->number_of_character += (par->width_field);
}

void	ft_convert_lc(t_printf *parameter, va_list *ap, t_buff *buff)
{
	wchar_t		character;

	character = va_arg(*ap, wchar_t);
	if (character == 0)
		value_null_lc(parameter, buff, character);
	else
	{
		read_buffer(buff);
		value_not_null_lc(parameter, character, 0);
	}
}

