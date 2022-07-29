# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 09:45:57 by mcloarec          #+#    #+#              #
#    Updated: 2022/07/28 14:48:49 by mcloarec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

OBJS = $(SRCS:.c=.o)

NAME = push_swap

CC = gcc

RM = rm -f

CFLAGS = -g3 -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		@make -sC libft
		$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)

clean:
		@make -sC libft clean
		$(RM) $(OBJS)

fclean: clean
		@make -sC libft fclean
		$(RM) $(NAME)

run:
	./$(NAME)
re: fclean all

.PHONY: all clean fclean re
