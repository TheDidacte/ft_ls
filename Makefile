# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skiessli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 19:06:07 by skiessli          #+#    #+#              #
#    Updated: 2019/01/12 19:15:33 by cpoirier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = 	srcs/ft_ls.c				\
		srcs/tree_util.c			\
		srcs/print_tree.c			\
		srcs/print_tree_simple.c	\
		srcs/print_tree_long.c		\
		srcs/print_tree_util.c		\
		srcs/read_flags.c			\
		srcs/sort_tree.c			\
		srcs/free_tree.c			\
		srcs/print_name.c			\
		srcs/lonely_tree.c			\
		srcs/handle_buffer.c		\
		srcs/ft_printf_min.c		\
		srcs/b_tree_util.c			\

LIBFT = libft

HDRS =	includes/ft_ls.h		\
		includes/ft_ls_util.h

OBJS = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -O2
#-Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJS) $(HDRS)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)/libft.a

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -I./includes -c $< -o $@

clean:
	@make clean -C $(LIBFT)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	rm -f $(NAME)

re:	fclean all
