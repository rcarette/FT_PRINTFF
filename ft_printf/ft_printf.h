/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 23:50:46 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/25 05:38:20 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <limits.h>

#define BUFF 2048

typedef struct		s_printf
{
	int				hash;
	int				zero;
	int				space;
	int				subtraction;
	int				addition;
	int				width_field;
	int				precision_point;
	int				precision;
	int				opt_h;
	int				opt_hh;
	int				opt_l;
	int				opt_ll;
	int				opt_j;
	int				opt_z;
	int				number_of_character;
	char			flags_current;
	int				negative;
}					t_printf;

typedef struct		s_buff
{
	char			buffer[BUFF + 1];
	int				position;
}					t_buff;

t_printf					*ft_init_t_printf(void);
int							check_string(const char *format);
int							ft_start_printf(const char *format, va_list *ap);
void						ft_show_parameter(t_printf *parameter);
void						ft_clear(char **tab);
int							ft_getsize(unsigned long long  nbr, int base);
void						ft_convert_p(t_printf *parameter, va_list *ap, t_buff *buff);
void						ft_convert_d(t_printf *parameter, va_list *ap, t_buff *buff);
void						ft_convert_s(t_printf *parameter, va_list *ap, t_buff *buff);
void						(*ft_pointor_func(int position))
					(t_printf *parameter, va_list *ap, t_buff *buff);
void						ft_convert_ls(t_printf *parameter, va_list *ap, t_buff *buff);
void						ft_convert_c(t_printf *parameter, va_list *ap, t_buff *buff);
void						ft_convert_lc(t_printf *parameter, va_list *ap, t_buff *buff);
void						ft_convert_u(t_printf *parameter, va_list *ap, t_buff *buff);
void						ft_convert_lu(t_printf *parameter, va_list *ap, t_buff *buff);
void						ft_convert_o(t_printf *parameter, va_list *ap, t_buff *buff);
void						ft_convert_x(t_printf *parameter, va_list *ap, t_buff *buff);
void						ft_convert_ld(t_printf *parameter, va_list *ap, t_buff *buff);
void						ft_convert_mod(t_printf *parameter, va_list *ap, t_buff *buff);
int							ft_print_n(int x, char character);
int							ft_putstr_nb(const char *s1, int size, int choice);
char						*itoa_base_p(unsigned long long x, char *board);
void						ft_precision(char *tab, int size, t_printf *par);
void						ft_no_precision(char *tab, int size, t_printf *par);
int							ft_puttab(const char *s1, int size, t_printf *hash);
void						itoa_base_unsigned(unsigned long long int value,
					char board[64], int base, char *conv);
void						no_flags(t_printf *par, char character, t_buff *buff);
void						init_buffer(t_buff *buff);
void						read_buffer(t_buff *buff);
void						manage_buffer(t_buff *buff, char *new_string);
int							manage_buffer_character(t_buff *buff, char character);
void						print_character(int x, char character, t_buff *buff);
void						stock_character(char character, int x, char *new_string);
#endif

