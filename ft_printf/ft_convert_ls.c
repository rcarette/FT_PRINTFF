/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:14:21 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/28 09:48:48 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	no_precision_null(char *null, t_printf *par, t_buff *buff)
{
	int		width;

	width = (par->width_field - ft_strlen(null));
	if (par->subtraction == 0)
	{
		(par->zero == 1) ? print_character(width, '0', buff) : 0;
		(par->zero == 0) ? print_character(width, ' ', buff) : 0;
		manage_buffer(buff, null);
	}
	else if (par->subtraction == 1)
	{
		manage_buffer(buff, null);
		print_character(width, ' ', buff);
	}
	par->number_of_character += (ft_strlen(null));
	(width > 0) ? par->number_of_character += (width) : 0;
}

void	init_null(char *null)
{
	null[0] = '(';
	null[1] = 'n';
	null[2] = 'u';
	null[3] = 'l';
	null[4] = 'l';
	null[5] = ')';
	null[6] = '\0';
}

void	precision_ls_null(char *null, t_printf *par, t_buff *buff)
{
	int		i;
	int		width;

	i = -1;
	(par->precision <= ft_strlen(null)) ? null[par->precision] = '\0' : 0;
	width = (par->width_field - par->precision);
	if (par->subtraction == 0)
	{
		(par->zero == 1) ? print_character(width, '0', buff) : 0;
		(par->zero == 0) ? print_character(width, ' ', buff) : 0;
		manage_buffer(buff, null);
	}
	else if (par->subtraction == 1)
	{
		manage_buffer(buff, null);
		print_character(width, ' ', buff);
	}
	par->number_of_character += (ft_strlen(null));
	(width > 0) ? par->number_of_character += (width) : 0;
	init_null(null);
}

unsigned int		*get_ascii(wchar_t *unicode, unsigned int *size)
{
	int				i;
	unsigned int	*tab_ascii_unicode;

	i = -1;
	*size = 0;
	while (unicode[++i])
		(*size)++;
	tab_ascii_unicode = (unsigned int *)malloc(sizeof(unsigned int) * *size);
	i = -1;
	while (unicode[++i])
		tab_ascii_unicode[i] = (unsigned int)unicode[i];
	return (tab_ascii_unicode);
}

int		ft_strlen_x(char *str, char character)
{
	int		i;
	int		size;

	i = -1;
	size = 0;
	while (str[++i])
		if (str[i] == character)
			++size;
	return (size);
}

void		replace(char *ascii_binary)
{
	int		i;

	i = -1;
	while (ascii_binary[++i])
		if (ascii_binary[i] == 'x')
			ascii_binary[i] = '0';
}

char		*transform_ascii(char *binary_ascii, char *corres)
{
	char	*ascii_binary;
	int		i;
	int		size_binary_ascci;
	int		size_ascii_binary;

	i = -1;
	size_binary_ascci = ft_strlen(binary_ascii);
	ascii_binary = (char *)malloc(sizeof(char) * 64);
	ft_memset(ascii_binary, '\0', 64);
	ft_memcpy(ascii_binary, corres, ft_strlen(corres));
	size_ascii_binary = (ft_strlen(ascii_binary) - 1);
	while (size_ascii_binary)
	{
		if (ascii_binary[size_ascii_binary] == 'x')
			ascii_binary[size_ascii_binary] = binary_ascii[--size_binary_ascci];
		if (size_binary_ascci == 0)
			break;
		--size_ascii_binary;
	}
	replace(ascii_binary);
	return (ascii_binary);
}

char			**creat_tab_ascii(unsigned int *code_ascii, char **tab,
		unsigned int size)
{
	char				**binary;
	unsigned int		i;
	int					j;
	char				temporary[64];

	i = -1;
	ft_memset(temporary, '\0', 64);
	binary = (char **)malloc(sizeof(char *) * (size + 1));
	while (++i < size)
	{
		itoa_base_unsigned(code_ascii[i], temporary, 2, "01");
		j = -1;
		while (tab[++j])
			if (ft_strlen_x(tab[j], 'x') >= ft_strlen(temporary))
			{
				binary[i] = transform_ascii(temporary, tab[j]);
				break ;
			}
	}
	binary[i] = NULL;
	return (binary);
}

char		**treatement_unciode(wchar_t *unicode)
{
	unsigned int		*code_ascii;
	char				*tab[5];
	char				**binary;
	unsigned int		size;

	tab[0] = "0xxxxxxx ";
	tab[1] = "110xxxxx 10xxxxxx ";
	tab[2] = "1110xxxx 10xxxxxx 10xxxxxx ";
	tab[3] = "11110xxx 10xxxxxx 10xxxxxx 10xxxxxx ";
	tab[4] = NULL;
	code_ascii = get_ascii(unicode, &size);
	binary = creat_tab_ascii(code_ascii, tab, size);
	free(code_ascii);
	return (binary);
}

int		get_octets(char **tab)
{
	int		size;
	int		i;
	int		j;
	char	*temporary;

	i = -1;
	j = -1;
	size = 0;
	while (tab[++i])
	{
		temporary = tab[i];
		while (temporary[++j])
			if (temporary[j] == ' ')
				++size;
		j = -1;
	}
	return (size);
}

void	print_x_character(int width, char character)
{
	if (width <= 0)
		return ;
	while (width--)
		write(1, &character, 1);
}

int		puissance(int nbr, int power)
{
	int		i;
	int		size;

	i = -1;
	size = 1;

	if (power == 0)
		return (1);
	while (power)
	{
		size *= nbr;
		power--;
	}
	return (size);
}

void	impr_unicode(char **binary_unicode)
{
	int		i;
	int		j;
	char	*temporary;
	int		size;
	int		power;

	i = -1;
	j = -1;
	size = 0;
	while (binary_unicode[++j])
	{
		temporary = binary_unicode[j];
		power = 7;
		while (temporary[++i])
		{
			if (temporary[i] == '1')
				size += (temporary[i] - 48) * puissance(2, power--);
			else if (temporary[i] == '0')
				size += (temporary[i] - 48) * puissance(2, power--);
			else
			{
				write(1, &size, 1);
				size = 0;
				power = 7;
			}
		}
		i = -1;
	}
}

void	impr_unicode_preci(char **binary_unicode, int nbr)
{
	int		i;
	int		j;
	char	*temporary;
	int		size;
	int		power;

	i = -1;
	j = -1;
	size = 0;
	while (binary_unicode[++j])
	{
		temporary = binary_unicode[j];
		power = 7;
		--nbr;
		while (temporary[++i])
		{
			if (temporary[i] == '1')
				size += (temporary[i] - 48) * puissance(2, power--);
			else if (temporary[i] == '0')
				size += (temporary[i] - 48) * puissance(2, power--);
			else
			{
				write(1, &size, 1);
				size = 0;
				power = 7;
			}
		}
		if (nbr == 0)
			return ;
		i = -1;
	}
}

void	no_precision_ls(wchar_t *unicode, t_printf *par)
{
	char	**binary_unicode;
	int		octets;
	int		width;

	binary_unicode = treatement_unciode(unicode);
	octets = get_octets(binary_unicode);
	width = (par->width_field - octets);
	if (par->subtraction == 0)
	{
		(par->zero == 1) ? print_x_character(width, '0') :
			print_x_character(width, ' ');
		impr_unicode(binary_unicode);
	}
	else if (par->subtraction == 1)
	{
		impr_unicode(binary_unicode);
		print_x_character(width, ' ');
	}
	par->number_of_character += (octets);
	if (width > 0)
		par->number_of_character += (width);
	ft_clear(binary_unicode);
}

int		count_precision_ls(char **binary_unicode, t_printf *par, int *octets)
{
	int		i;
	int		size_character;
	int		preci;
	char	*temporary;

	i = -1;
	preci = par->precision;
	size_character = 0;
	while (binary_unicode[++i])
	{
		temporary = binary_unicode[i];
		if (preci >= ft_strlen_x(temporary, ' '))
		{
			*octets += ft_strlen_x(temporary, ' ');
			++size_character;
			preci -= ft_strlen_x(temporary, ' ');
		}
		else
			break;
		if (preci <= 0)
			break;
	}
	return (size_character);
}

void	precision_ls(wchar_t *unicode, t_printf *par)
{
	char	**binary_unicode;
	int		size_character;
	int		width;
	int		octets;

	octets = 0;
	width = 0;
	binary_unicode = treatement_unciode(unicode);
	size_character = count_precision_ls(binary_unicode, par, &octets);
	width = ((par->width_field - octets) > 0) ? par->width_field - octets : par->width_field;
	if (par->subtraction == 0)
	{
		(par->zero == 1) ? print_x_character(width, '0') : print_x_character(width, ' ');
		(size_character) ? impr_unicode_preci(binary_unicode, size_character) : 0;
	}
	else if (par->subtraction == 1)
	{
		(size_character) ? impr_unicode_preci(binary_unicode, size_character) : 0;
		print_x_character(width, ' ');
	}
	par->number_of_character += octets;
	(width > 0) ? par->number_of_character += (width) : 0;
	ft_clear(binary_unicode);
}

void	ft_convert_ls(t_printf *parameter, va_list *ap, t_buff *buff)
{
	static	char		null[] = "(null)";
	wchar_t				*unicode;

	if (!(unicode = va_arg(*ap, wchar_t *)))
	{
		if (parameter->precision_point == 0)
			no_precision_null(null, parameter, buff);
		else if (parameter->precision_point == 1)
			precision_ls_null(null, parameter, buff);
		return ;
	}
	read_buffer(buff);
	if (parameter->precision_point == 0)
		no_precision_ls(unicode, parameter);
	else if (parameter->precision_point == 1)
		precision_ls(unicode, parameter);
}
