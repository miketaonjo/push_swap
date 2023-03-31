# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 09:45:57 by mcloarec          #+#    #+#              #
#    Updated: 2022/08/04 15:35:52 by mcloarec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -g3 -Wall -Wextra -Werror

SRCS = 	srcs/main.c
SRCS += srcs/check.c
SRCS += srcs/free.c
SRCS += srcs/error.c
SRCS += srcs/utils.c
SRCS += srcs/stack.c
SRCS += srcs/moves.c
SRCS += srcs/rotate.c
SRCS += srcs/algo.c
SRCS += srcs/index.c
SRCS += srcs/moves_rotate.c
SRCS += srcs/push_swap.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		@make -sC libft
		echo "Libft compilation completed"
		$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)
		echo "Push_swap compilation completed"

clean:
		@make -sC libft clean
		$(RM) $(OBJS)
		echo "clean done"

fclean: clean
		@make -sC libft fclean
		$(RM) $(NAME)
		echo "fclean done"

re: fclean all

.SILENT: 

.PHONY: all clean fclean re
