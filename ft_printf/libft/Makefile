# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarette <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 20:31:54 by rcarette          #+#    #+#              #
#    Updated: 2017/01/02 08:05:58 by rcarette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar
ARFLAG = rc


NAME = libft.a
OBJ = *.o
SRCS = *.c

all : $(NAME)

$(NAME) :
	@$(GCC) -c $(SRCS) $(CFLAGS)
	@$(AR) $(ARFLAG) $(NAME) $(OBJ)

clean :
	rm -f $(OBJ);

fclean : clean
	rm -f $(NAME)

re : clean fclean all

