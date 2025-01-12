# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 18:20:13 by kben-tou          #+#    #+#              #
#    Updated: 2025/01/12 16:45:54 by kben-tou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILS = src/push_stack.c \
		src/push_swap.c \
		src/rotate_stack.c \
		src/rotate_r_stack.c \
		src/swap_stack.c \
		src/check_inputs.c \
		src/tools.c \
		src/tools1.c \
		src/sort_stack.c \
		src/sort_sample.c \
		src/lis.c \
		src/sort_utils.c

FILS_B = src/checker.c \

CFLAGS =  -Wall -Wextra -Werror

NAME = push_swap
CHECK = checker

OBJS = 	$(FILS:.c=.o)
OBJS_B = $(FILS_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) src/push_swap.h ft_printf/libftprintf.a libft/libft.a
	cc $(CFLAGS) $(OBJS) ft_printf/libftprintf.a libft/libft.a -o $@

bonus: $(CHECK) $(NAME)

$(CHECK): $(FILS_B)
	cc $(CFLAGS) $(FILS_B) ft_printf/libftprintf.a libft/libft.a -o $@

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: clean all
