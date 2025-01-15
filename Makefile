# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 18:20:13 by kben-tou          #+#    #+#              #
#    Updated: 2025/01/15 15:59:51 by kben-tou         ###   ########.fr        #
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
		src/tools2.c \
		src/sort_stack.c \
		src/sort_sample.c \
		src/lis.c \
		src/sort_utils.c \
		src/get_next_line.c

FILS_B = src/checker.c \
		src/push_stack.c \
		src/rotate_stack.c \
		src/rotate_r_stack.c \
		src/swap_stack.c \
		src/check_inputs.c \
		src/tools.c \
		src/tools1.c \
		src/tools2.c \
		src/sort_sample.c \
		src/sort_utils.c \
		src/get_next_line.c

CFLAGS =  -Wall -Wextra -Werror

NAME = push_swap
CHECK = checker

OBJS = 	$(FILS:.c=.o)
OBJS_B = $(FILS_B:.c=.o)

all: $(NAME)

%.o: %.c src/push_swap.h
	cc $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJS) libft/libft.a
	cc $(CFLAGS) $(OBJS)  libft/libft.a -o $@

bonus: $(NAME) $(CHECK)

$(CHECK): $(OBJS_B)
	cc $(CFLAGS) $(OBJS_B) libft/libft.a -o $@

clean: 
	rm -rf $(OBJS)
	rm -rf $(OBJS_B)

fclean: clean
	rm -rf $(NAME) $(CHECK)

re: fclean all
