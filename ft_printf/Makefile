# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 10:16:44 by kben-tou          #+#    #+#              #
#    Updated: 2024/11/19 10:16:45 by kben-tou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c \
		ft_printf_char.c \
		ft_printf_str.c \
		ft_printf_number.c \
		ft_printf_unsigned.c \
		ft_printf_pointer.c \
		ft_print_hex.c 

OBJECTS = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

%.o:%.c ft_printf.h
	cc -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJECTS)
	ar -rcs $@ $^

clean:
	rm -rf $(OBJECTS)

fclean:clean
	rm -rf $(NAME)

re: fclean all