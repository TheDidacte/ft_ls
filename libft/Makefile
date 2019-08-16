# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skiessli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 19:06:07 by skiessli          #+#    #+#              #
#    Updated: 2019/01/12 16:21:13 by cpoirier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = 		srcs/ft_atoi.c		\
			srcs/ft_bzero.c		\
			srcs/ft_calloc.c		\
			srcs/ft_isalnum.c	\
			srcs/ft_isalpha.c	\
			srcs/ft_isascii.c	\
			srcs/ft_isdigit.c	\
			srcs/ft_isprint.c	\
			srcs/ft_isspace.c	\
			srcs/ft_itoa.c		\
			srcs/ft_lstadd.c		\
			srcs/ft_lstdel.c		\
			srcs/ft_lstdelone.c	\
			srcs/ft_lstiter.c	\
			srcs/ft_lstmap.c		\
			srcs/ft_lstnew.c		\
			srcs/ft_memalloc.c	\
			srcs/ft_memccpy.c	\
			srcs/ft_memchr.c		\
			srcs/ft_memcmp.c		\
			srcs/ft_memcpy.c		\
			srcs/ft_memdel.c		\
			srcs/ft_memmove.c	\
			srcs/ft_memset.c		\
			srcs/ft_min.c		\
			srcs/ft_putchar.c	\
			srcs/ft_putchar_fd.c	\
			srcs/ft_putendl.c	\
			srcs/ft_putendl_fd.c	\
			srcs/ft_putnbr.c		\
			srcs/ft_putnbr_fd.c	\
			srcs/ft_putstr.c		\
			srcs/ft_putstr_fd.c	\
			srcs/ft_strcat.c		\
			srcs/ft_strchr.c		\
			srcs/ft_strclen.c	\
			srcs/ft_strclr.c		\
			srcs/ft_strcmp.c		\
			srcs/ft_strcpy.c		\
			srcs/ft_strdel.c		\
			srcs/ft_strdup.c		\
			srcs/ft_strequ.c		\
			srcs/ft_striter.c	\
			srcs/ft_striteri.c	\
			srcs/ft_strjoin.c	\
			srcs/ft_strlcat.c	\
			srcs/ft_strlen.c		\
			srcs/ft_strmap.c		\
			srcs/ft_strmapi.c	\
			srcs/ft_strncat.c	\
			srcs/ft_strncmp.c	\
			srcs/ft_strncpy.c	\
			srcs/ft_strnequ.c	\
			srcs/ft_strnew.c		\
			srcs/ft_strnlen.c 	\
			srcs/ft_strnstr.c	\
			srcs/ft_strrchr.c	\
			srcs/ft_strsplit.c	\
			srcs/ft_strstr.c		\
			srcs/ft_strsub.c		\
			srcs/ft_strtrim.c	\
			srcs/ft_tolower.c	\
			srcs/ft_toupper.c	\
			srcs/add_format.c	\
			srcs/ft_printf.c	\
			srcs/ft_double_cnv.c	\
			srcs/ft_write_colors.c	\
			srcs/ft_itoa_base.c		\
			srcs/ft_str_safe.c		\
			srcs/logic.c		\
			srcs/populate_flags.c	\
			srcs/write_extra.c		\
			srcs/write_int.c			\
			srcs/write_types.c

OBJS = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Werror -Wextra

CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I./includes -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all
