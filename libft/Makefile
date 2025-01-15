# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 18:20:13 by kben-tou          #+#    #+#              #
#    Updated: 2024/11/08 16:44:16 by kben-tou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILS = ft_atoi.c \
		ft_calloc.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_itoa.c \
		ft_memcmp.c \
		ft_memmove.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_split.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcpy.c \
		ft_strmapi.c \
		ft_strnstr.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcpy.c \
		ft_memset.c \
		ft_putendl_fd.c \
		ft_putstr_fd.c \
		ft_strchr.c \
		ft_striteri.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strrchr.c \
		ft_substr.c \
		ft_toupper.c 

FLBNS = ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

CFLAGS =  -Wall -Wextra -Werror

CC = cc

NAME = libft.a

OBJS = 	$(FILS:.c=.o)	

OBJS_BN = 	$(FLBNS:.c=.o)

all: $(NAME)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rc $(NAME) $^

bonus: $(OBJS_BN)
	ar -rc $(NAME) $^

clean:
	rm -rf $(OBJS) $(OBJS_BN)

fclean: clean
	rm -rf $(NAME)

re: clean all
