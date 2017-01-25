# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    make                                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarette <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 20:59:07 by rcarette          #+#    #+#              #
#    Updated: 2017/01/25 05:13:45 by rcarette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc -Wall -Wextra -Werror


SOURCE_LIB = ft_atoi.c\
			 ft_bzero.c\
			 ft_get_size.c\
			 ft_getwidth.c\
			 ft_isalnum.c\
			 ft_isalpha.c\
			 ft_isascii.c\
			 ft_isdigit.c\
			 ft_isprint.c\
			 ft_issspace.c\
			 ft_itoa.c\
			 ft_memalloc.c\
			 ft_memccpy.c\
			 ft_memchr.c\
			 ft_memcmp.c\
			 ft_memcpy.c\
			 ft_memdel.c\
			 ft_memmove.c\
			 ft_memset.c\
			 ft_modify_dup.c\
			 ft_opendir.c\
			 ft_putchar.c\
			 ft_putchar_fd.c\
			 ft_putendl.c\
			 ft_putendl_fd.c\
			 ft_putnbr.c\
			 ft_putnbr_fd.c\
			 ft_putstr.c\
			 ft_putstr_fd.c\
			 ft_realloc.c\
			 ft_strcat.c\
			 ft_strchr.c\
			 ft_strclr.c\
			 ft_strcmp.c\
			 ft_strcpy.c\
			 ft_strdel.c\
			 ft_strdup.c\
			 ft_strequ.c\
			 ft_striter.c\
			 ft_striteri.c\
			 ft_strjoin.c\
			 ft_strlcat.c\
			 ft_strlen.c\
			 ft_strmap.c\
			 ft_strmapi.c\
			 ft_strncat.c\
			 ft_strncmp.c\
			 ft_strncpy.c\
			 ft_strnequ.c\
			 ft_strnew.c\
			 ft_strsplit.c\
			 ft_strtrim.c\
			 ft_strsub.c\

SOURCE = ft_convert_c.c\
		 ft_convert_d.c\
		 ft_convert_lc.c\
		 ft_convert_ld.c\
		 ft_convert_ls.c\
		 ft_convert_lu.c\
		 ft_convert_mod.c\
		 ft_convert_o.c\
		 ft_convert_p.c\
		 ft_convert_s.c\
		 ft_convert_u.c\
		 ft_convert_x.c\
		 ft_clear_tab.c\
		 ft_print_n.c\
		 ft_puttab.c\
		 ito_base_unsigned.c\
		 ft_getsize.c\
		 ft_putstr_nb.c\
		 ft_show_parameter.c\
		 ft_printf.c\
		 ft_pointor_func.c\
		 ft_check_string.c\
		 ft_start_printf.c\
		 init_t_printf.c\
		 buffer.c\

OBJ = $(SOURCE:.c=.o)
OBJ_LIB = $(SOURCE_LIB:.c=.o)

all: $(NAME)

$(NAME) : objects
	ar rc $(NAME) $(OBJ) $(OBJ_LIB)
	ranlib $(NAME)

objects :
	$(CC) -c $(SOURCE) $(addprefix libft/, $(SOURCE_LIB))

clean:
	rm -rf $(OBJ) $(OBJ_LIB)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all re fclean clean $(NAME)
