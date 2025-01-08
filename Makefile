# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 18:20:13 by kben-tou          #+#    #+#              #
#    Updated: 2025/01/06 10:38:20 by kben-tou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILS = src/push_stack.c \
		src/push_swap.c \
		src/rotate_stack.c \
		src/rotate_r_stack.c \
		src/swap_stack.c \
		src/check_inputs.c \
		src/tools.c \
		src/sort_stack.c \
		src/lis.c

CFLAGS =  -Wall -Wextra -Werror

NAME = push_swap

OBJS = 	$(FILS:.c=.o)	

all: $(NAME)

$(NAME): $(OBJS) src/push_swap.h ft_printf/libftprintf.a libft/libft.a
	cc $(CFLAGS) $(OBJS) ft_printf/libftprintf.a libft/libft.a -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)ß

re: clean all
