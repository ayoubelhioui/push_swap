# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 14:13:59 by ael-hiou          #+#    #+#              #
#    Updated: 2022/01/15 15:19:47 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @gcc
CFLAGS = -Wextra -Werror -Wall -g
SRC = push_swap.c operations.c quick_sort.c
NAME = a.out
LIBFT = libft/libft.a

all:$(NAME)
$(NAME):
		@cd libft && make && make bonus && cd ..
		@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
clean:
		@cd libft && make clean && cd ..
fclean:clean
	@rm -f $(NAME)
re:fclean all